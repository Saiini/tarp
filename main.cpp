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

static void create_project(std::string const& project_name) {
    std::cout << rang::fg::red << "Creating project: " + project_name << "...\n" << rang::fg::reset;
    std::string const bin = project_name+"/bin";
    std::string const source_dir = project_name+"/src";
    std::string const lib_dir = project_name+"/lib";
    std::string const build_dir = project_name+"/build";
    std::string const doc_dir = project_name+"/doc";
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
    appFile << "// Main entry point for: " << project_name << R"(
#include <stdio.h>

int main()
{
    printf("Hello world!\n");
    return 0;
}
)";

    // setup comments for the generated makefile.
    makefile << "# Makfile for " << project_name << " (compiling a single file project)\n\n\n\n"
             << "CFLAGS=-g -Wall\n"
             << "SRCS = src/" << project_name << ".c\n"
             << "OBJS = $(SRCS:.c=.o)\n"
             << "all: \n"
             << "\tcc $(CFLAGS) $(SRCS) -o build/" << project_name;

    std::cout << "status:Finished -- Created: " << rang::bg::blue
              << bin << "\t"
              << source_dir << "\t"
              << lib_dir << "\t"
              << build_dir << "\t"
              << doc_dir << rang::bg::reset << '\n';
}

static void print_help()
{
    std::cout << 
R"(Usage:
    tarp <project_name>
Example:
    tarp HelloWorld
)";
}

int main(int argc, char const *argv[]) {
    if (argc == 2) {
        create_project(argv[1]);
    }
    else
        print_help();
}
