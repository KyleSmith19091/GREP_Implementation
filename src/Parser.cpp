#include "../include/Parser.hpp"
#include <utility>

// Default Constructor
Commandline::Parser::Parser() {
}

// Extract pattern and input text from args
std::pair<std::string, std::string> Commandline::Parser::parseArgs(const int &argc, const char *argv[]) {
    if (argc == 3) { // Check if input is valid first
        return std::make_pair(argv[1],argv[2]);
    } else { // Incorrect number of inputs
        std::cerr << "Incorrect Number of Args Provided\n";
        return std::make_pair("", "");
    }
    return std::make_pair("", "");
}
