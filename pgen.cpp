// pgen.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <string>
#include <cstdio>
#include <stdio.h>
#include <Windows.h>

const std::string APP_VERSION = "v0.01";
const std::string APP_AUTHOR = "mkdsk";

//TODO: Read this from a file so it keeps it. 
std::string p_Folder = "C:\\Program Files\\pgen";

/* Generate a password based off of various parameters provided by the user */
/* Similar characters: i, l, 1, L, o, 0, O */
/* Ambiguous characters: { } [ ] ( ) / \ ' " ` ~ , ; : . < >      */
std::string p_Generate(int length, bool symbols, bool numbers, bool lowercase, bool uppercase, bool excludeSimilar, bool excludeAmbiguous)
{
	return "placeholder";
}
	 
int main(int argc, char* argv[])
{		
	//Template:
	//Example cmd line call: pgen hi test text arg
	//argv[0] would be pgen, argv[1] would be hi, and so on. 

	if (argc > 1) // More arguments than just the program name. 
	{
		if (strcmp(argv[1], "init") == 0)
		{
			//First, check if C:\Program Files\pgen exists
			//If not, tell the user they must use pgen init	
			//Make sure argv[2] doesn't exist also.
		}
		else if (strcmp(argv[1], "lib") == 0) //pgen lib
		{
			//First, check if C:\Program Files\pgen exists
			//If not, tell the user they must use pgen init
			//Make sure argv[2] doesn't exist also.
		}
		else if (strcmp(argv[1], "gen") == 0) //pgen gen
		{
			//First, check if C:\Program Files\pgen exists
			//If not, tell the user they must use pgen init	
			//Get argv[2] == name and argv[3] == length and make sure no other args are there.
		}
		else if (strcmp(argv[1], "cpy") == 0) //pgen cpy
		{
			//First, check if C:\Program Files\pgen exists
			//If not, tell the user they must use pgen init	
			//Get argv[2] == name. and make sure no other args are there.
		}
	}
	else // User entered no arguments, display help menu
	{
		printf("\npgen v1.0 by mkdsk");
		printf("\nEasy to use, portable command line password manager");
		printf("\n");
		printf("\npgen init"); //Creates p_Folder (MUST BE USED FIRST)
		printf("\npgen lib");
		printf("\npgen gen [name] [length]");
		printf("\npgen cpy [name]");
		printf("\n");
	}

	/*if (!(CreateDirectoryA("C:\\pgen", NULL))) 
	{
		if (GetLastError() == ERROR_ALREADY_EXISTS)
		{
			printf("pgen directory already exists...\n");
		}
		Add more error handlers here!
	}*/
	

    return 0;
}

