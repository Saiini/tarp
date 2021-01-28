/**
 * ------------------------
 *  FILE: main.cpp
 *
 *  Author: Saiini
 * ------------------------
 * Description:
 *   Tarp is a basic C project initializer i lazily coupled up.
 *
 * Copyright (C) Sutinder S. Saini. All rights reserved.
 *
 */

#include "rang.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <filesystem>

void create_project(std::string project_name) {
    std::cout << rang::fg::red << "Creating project: " + project_name << "...\n" << rang::fg::reset;
    std::string bin = project_name+"/bin";
    std::string source_dir = project_name+"/src";
    std::string lib_dir = project_name+"/lib";
    std::string build_dir = project_name+"/build";
    std::string doc_dir = project_name+"/doc";
    std::filesystem::create_directory(project_name);
    std::filesystem::create_directory(source_dir);
    std::filesystem::create_directory(lib_dir);
    std::filesystem::create_directory(build_dir);
    std::filesystem::create_directory(doc_dir);
    std::filesystem::create_directory(bin);

    std::ofstream makefile (project_name + "/Makefile");
    std::ofstream appFile  (project_name + "/src/"+ project_name +".c");
    std::ofstream readme   (project_name + "/README.md");
    //write our file contents for our c file.
    appFile << "// Main entry point for: " <<
    project_name <<
    "\n#include <iostream>"
    "\n\n\nint main() { "
    "\n \n std::cout << 'c' << std::endl;\n\n\n"
    "}" <<
    std::endl;

    // setup comments for the generated makefile.
    makefile << "# Makfile for " << project_name << " (compiling a single file project)\n\n\n\n";
    std::cout << "status:Finished -- Created: "<< rang::bg::blue <<
    bin<<
    "\t" <<
    source_dir<<
    "\t" <<lib_dir
    << "\t" <<build_dir << "\t" <<doc_dir
    <<rang::bg::reset;
}

int main(int argc, char *argv[]) {
    if (argc == 2) {
        create_project(argv[1]);
    }
    return 0;
}
