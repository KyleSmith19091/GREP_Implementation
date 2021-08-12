#include <algorithm>
#include <cstddef>
#include <iostream>
#include <vector>
#include <string>
#include <utility>

#include "../include/ANSIColorTable.h"
#include "../include/Parser.hpp"
#include "../include/BoyerMoore.hpp"
#include "../include/Logger.hpp"

#define MIN_SHIFT 1
#define HIGHLIGHT_COLOR RED
#define HIGHLIGHT_COLOR_LENGTH 8
#define RESET_CODE_LENGTH 3

using namespace std;

int main(int argc, const char *argv[])
{

    // Extract data from args
    std::pair<std::string, std::string> data = Commandline::Parser::parseArgs(argc, argv);

    // Check if data given is valid
    if (data.first != "")
    {
        // BoyerMoore
        std::vector<size_t> indices = Grep::BoyerMoore::match(data.first, data.second); 

        // Output
        if(indices.size() != 0) {
            Commandline::Logger::displayHighlightText(std::cout, data.second, data.first, indices);
        } else {
            Commandline::Logger::write(std::cerr,"No matches found!");
        }
        
    }
    else
    {
        exit(1);
    }

    return 0;
}
