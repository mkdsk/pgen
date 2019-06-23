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

std::string p_Folder;

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
		if (strcmp(argv[1], "f") == 0) //pgen f
		{
			if (strcmp(argv[2], "set") == 0) //pgen f set
			{
				printf("set"); 
			}
			else if (strcmp(argv[2], "create") == 0)
			{
				printf("create");
			}
		}
	}
	else // User entered no arguments, display help menu
	{
		printf("\npgen v1.0 by mkdsk");
		printf("\nEasy to use, portable command line password manager");
		printf("\n");
		printf("\npgen f set [location]");
		printf("\npgen f create [location]");
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
	
	//COMMANDS AVAILABLE FOR USE FROM COMMAND LINE
	//pgen f set D:\\usr\\example: Sets the folder to be used by the program to store passwords
	//pgen f create D:\\usr\\example NAME: Creates a folder and sets it to be used by the program
	//pgen (no other arguments): Lists what the program does and its commands
	//pgen lib: Lists each file in the pgen directory
	//pgen gen <NAME> <LENGTH> : Generate a password of file NAME with length LENGTH (max 8096)
	//pgen cpy <NAME> : Copies the specified password to clipboard	

    return 0;
}

