#include "synchronization.h"

void synchronization(std::string path1, std::string path2, std::string path3, std::string& log) {
    
    //for loop that goes through the folder
    for (auto& source : fs::directory_iterator(path1)) {

        //Checks if the file names match
        if (fs::is_regular_file(path2 + "/" + source.path().filename().string())) {
            std::cout << source.path().filename().string() << " -file already exists at location\n";
            log += source.path().filename().string() + " -file already exists at location\n";
            continue;
        }
            
        //takes the binary data of source file and then outputs it into destination
        if (fs::is_regular_file(source)) {
            std::ifstream in(source.path(), std::ios::binary);
            std::ofstream out(path2 + "/" + source.path().filename().string(), std::ios::binary);
            out << in.rdbuf();

            std::cout << source.path().filename().string() << " -regular file coppied\n";
            log += source.path().filename().string() + " -regular file coppied\n";
        }

        //if the folder exists outputs a log message and recursively calls the function inside the folder
        if (fs::is_directory(path2 + "/" + source.path().filename().string())) {
            std::cout << source.path().filename().string() << " -folder already exists at location\n";
            log += source.path().filename().string() + " -folder already exists at location\n";

            synchronization(source.path().string(), path2 + "/" + source.path().filename().string(), path3, log);
        }

        //copies directory at location and recursively calls the function inside the folder
        else if (fs::is_directory(source)) {

            fs::create_directory(path2 + "/" + source.path().filename().string());

            std::cout << source.path().filename().string() << " -folder coppied\n";
            log += source.path().filename().string() + " -folder coppied\n";

            synchronization(source.path().string(), path2 + "/" + source.path().filename().string(), path3, log);
        }
        
    }
    std::ofstream out(path3 + "/log.txt", std::ios::app);
    out << log;
    log.clear();
    
}