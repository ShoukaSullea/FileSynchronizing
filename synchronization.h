#pragma once
#include <string>
#include <iostream>
#include <filesystem>
#include <fstream>

namespace fs = std::filesystem;
void synchronization(std::string path1, std::string path2, std::string path3, std::string& log);