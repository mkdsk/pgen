# pgen
Command line password manager

Allows you to store/organize passwords and access them through the command line

# Commands

pgen init - Initializes the program, must be run first before anything else. Creates pgen folder. 

pgen lib - Lists the available passwords on the drive

pgen cpy [name] - Copies the specified password to the clipboard

pgen gen [name] [length] - Generates password with name with length length

[Download](http://www.mediafire.com/file/me88yyzm17nyvf1/pgen.exe/file)

# Notes

Occasionally passwords will get cut off after spaces due to an error when converting the password to a C string, I don't know how to fix this but help would be appreciated

Passwords with very high lengths can create unexpecting results. In testing, creating passwords with over 600 characters corrupts it somehow. 

The program becomes alot more useful if you add the exe file's location to your system PATH. 
