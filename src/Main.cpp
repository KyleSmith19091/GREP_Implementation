#include <algorithm>
#include <cstddef>
#include <iostream>
#include <vector>
#include <string>
#include <utility>

#include "../include/ANSIColorTable.h"
#include "../include/Parser.hpp"

#define NUM_OF_CHARS 256
#define MIN_SHIFT 1
#define HIGHLIGHT_COLOR RED
#define HIGHLIGHT_COLOR_LENGTH 8
#define RESET_CODE_LENGTH 3

using namespace std;

constexpr int calcMax(const int& a, const int& b) noexcept {
    return a > b ? a : b;
}

constexpr int calaculateMaxShift(const int& length, const int& idx) noexcept {
    return calcMax(1, length - idx - 1);
}

std::string createHighlightedString(const std::string& pattern) noexcept {
    return RED + pattern + reset;
}

constexpr const int getLengthOfANSICode() noexcept {
    return HIGHLIGHT_COLOR_LENGTH + RESET_CODE_LENGTH;
}

void constructBadMatchTable(int (&badMatchTable)[NUM_OF_CHARS], const std::string& str) noexcept {
    int patternLength = str.length();

    for (int i = 0; i < patternLength; i++) {
        badMatchTable[static_cast<int>(str[i])] = calaculateMaxShift(patternLength, i);
    }

}

// TODO: This is deceiving when printing the table for a pattern with repeated characters
void printBadMatchTable(const int (&table)[NUM_OF_CHARS], const std::string& pattern) noexcept {
    int patternLength = pattern.length();

    std::cout << pattern << "\n";
    for(int i = 0; i < patternLength; i++){
        std::cout << table[static_cast<int>(pattern[i])] << " ";
    }

    std::cout << "\n";

}

std::vector<size_t> boyerMooreAlgo(const int (&table)[NUM_OF_CHARS], const std::string& pattern, const std::string& text) noexcept {
    unsigned int textLength = text.length();
    unsigned int patternLength = pattern.length();
    unsigned skips = 0;

    std::vector<size_t> matchedIndices;

    for(int i = 0; i <= textLength - patternLength; i += skips) {
        skips = 0;

        for(int j = patternLength - 1; j >= 0; j--) {
            if(pattern[j] != text[i+j]) {
                if(table[static_cast<int>(text[i+j])]) {
                    skips = table[static_cast<int>(text[i+j])]; 
                    break;
                } else {
                    skips = patternLength;
                    break;
                }
            }
        }

        if(skips == 0) { // Found a match
            matchedIndices.push_back(i++);
        }

    } 

    return matchedIndices;
}

int main(int argc, const char* argv[]){

    std::pair<std::string,std::string> data = Commandline::Parser::parseArgs(argc, argv);

    if(data.first != "") {
        int badMatchTable[NUM_OF_CHARS];
        const std::string pattern = data.first;
        std::string text = data.second;

        constructBadMatchTable(badMatchTable, data.first);
        std::vector<size_t> indices = boyerMooreAlgo(badMatchTable, pattern, text);

        const std::string highlightPattern = createHighlightedString(pattern);
    
        int offset = 0;
        const int ansiLength = getLengthOfANSICode();
        for(size_t& i : indices) {
            text.replace(i+offset,pattern.size(),highlightPattern); 
            offset += ansiLength; 
        }

        std::cout << text << "\n";
    } else {
        exit(1);
    }
    
    return 0;
}
