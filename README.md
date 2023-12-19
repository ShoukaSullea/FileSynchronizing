Program was made for windows with C++ 17 standard

To run the compiled program you need to provide paths to two folders and time interval between checks. 
example: main.exe C:\path\source C:\path\replica 60 

Given those parameters the program will copy check if data in the second folder match the first and if not, it will copy all files and directories and leave behind a .txt log file. The function will repeat itself again every 60 minutes until the program has been terminated by user. 
