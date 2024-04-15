//
// Created by Jingfeng Sun on 2024/4/7.
//
#include <iostream>
#include <boost/filesystem.hpp>
namespace fs = boost::filesystem;
int main() {
    std::cout << "Hello World!" << std::endl;
    fs::path dir_path("./");
    return 0;
}