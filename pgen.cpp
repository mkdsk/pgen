// pgen.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <filesystem>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <Windows.h>
#include <sys/stat.h>

const std::string APP_VERSION = "v1.0";
const std::string APP_AUTHOR = "mkdsk";
LPCSTR p_Folder = "C:\\pgen";

namespace fs = std::filesystem;

void p_Generate(int length, std::string name)
{
	std::string password;
	srand(time(NULL));

	static const char alphanum[] =
		"0123456789"
		"!@#$%^&*()-=[]\;',./<>?:"
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz";

	for (int i = 0; i < length; i++)
	{
		password += alphanum[rand() % sizeof(alphanum) - 1];
	}

	password.erase(remove(password.begin(), password.end(), ' '), password.end());
	std::ofstream outfile("C:\\pgen\\" + name + ".gen");
	outfile << password << std::endl;
	outfile.close();
	printf("Successfully saved password.\n");
}

inline bool isInt(const std::string& s)
{
	if (s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false;
	
	char *p;
	strtol(s.c_str(), &p, 10);
	return (*p == 0);
}

bool p_FolderExists()
{
	struct stat buffer;

	std::string path = "C:\\pgen";
	return (stat (path.c_str(), &buffer) == 0);
}

int main(int argc, char* argv[])
{
	// ================= //
	// COMMAND PROCESSOR //
	// ================= //

	if (argc > 1) 
	{
		if (strcmp(argv[1], "init") == 0)
		{
			if (argc > 2) {
				return 0;
			}
			if (!(CreateDirectoryA(p_Folder, NULL)))
			{
				if (GetLastError() == ERROR_ALREADY_EXISTS)
				{
					printf("pgen folder already exists.\n");
				}
				else
				{
					printf("Unable to create pgen folder.\n");
				}
			}
			else
			{
				printf("Successfully created pgen folder.\n");
			}
			
		}
		else if (strcmp(argv[1], "lib") == 0) 
		{
			if (argc > 2)
			{
				return 0;
			}

			if (!p_FolderExists())
			{
				printf("Password library can't be accessed because pgen folder doesn't exist.\n");
				printf("Use \"pgen init\" first.\n");
				return 0;
			}

			for (const auto & entry : fs::directory_iterator(p_Folder))
				std::cout << entry.path() << std::endl;
						
		}
		else if (strcmp(argv[1], "gen") == 0) 
		{
			if (argc != 4)
			{
				printf("Usage: pgen gen [name] [length] [options]\n");
				return 0;
			}

			if (!p_FolderExists())
			{
				printf("Cannot store password because pgen folder doesn't exist.\n");
				printf("Use \"pgen init\" first.\n");
				return 0;
			}

			if (isInt(argv[3]))
			{
				if (atoi(argv[3]) <= 2048 && atoi(argv[3]) >= 5)
				{
					int length = atoi(argv[3]);
					p_Generate(length, argv[2]);
					return 0;
				}
				else
				{
					printf("Enter a length between 5 and 2048.\n");
				}
			}
			else
			{
				printf("Length needs to be a number between 5 and 2048.\n");
				return 0;
			}
			
		}
		else if (strcmp(argv[1], "cpy") == 0) 
		{
			if (argc != 3)
			{
				printf("Usage: pgen cpy [name]\n");
				return 0;
			}
			
			if (!p_FolderExists())
			{
				printf("Passwords can't be copied because pgen folder doesn't exist.\n");
				printf("Use \"pgen init\" first.");
				return 0;
			}

			std::string pass;
			std::string name = argv[2];
			
			std::ifstream infile;
			infile.open("C:\\pgen\\" + name + ".gen");
			std::getline(infile, pass);

			const char* output = pass.c_str(); //Convert to C-string so we can copy to clipboard

			//Convuluted hack to copy to the clipboard.
			//Why make it this hard, Billy Gates?
			const size_t len = strlen(output) + 1;
			HGLOBAL hMem = GlobalAlloc(GMEM_MOVEABLE, len);
			memcpy(GlobalLock(hMem), output, len);
			GlobalUnlock(hMem);
			OpenClipboard(0);
			EmptyClipboard();
			SetClipboardData(CF_TEXT, hMem);
			CloseClipboard();
			
			printf("Copied password to clipboard.\n");
			return 0;
			
		}
	}
	else 
	{
		printf("\npgen v1.0 by mkdsk");
		printf("\nEasy to use, command line password manager");
		printf("https://github.com/mkdsk/pgen\n");
		printf("\n");
		printf("\npgen init"); 
		printf("\npgen lib");
		printf("\npgen gen [name] [length]");
		printf("\npgen cpy [name]");
		printf("\n");
	}

	return 0;
}

