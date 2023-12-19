#include <windows.h>
#include <ctime>
#include "synchronization.h"


int main(int argc, char* argv[]) {
    std::string sourcePath(argv[1]);
    std::string destinationPath(argv[2]);
    
    while (true) {
        //string that we'll use to store output messages in
        std::string output;
        //takes current time of system and converts for local timezone
        time_t now = time(0);
        tm* localtm = localtime(&now);

        std::cout << asctime(localtm);
        output += asctime(localtm);

        //converts user input to an interger. calculates miliseconds in x minutes.
        int sleepTime = std::stoi(argv[3]) * 60000;
        std::cout << sleepTime;
        
        synchronization(sourcePath, destinationPath, destinationPath, output);

        

        if (sleepTime == 0) {
            std::cout << "please enter 1 minute or more time between synchronizations if you want the program to repeat itselfs";
            return 0;
        }

        Sleep(sleepTime);
    }
    return 0; 
        
}
