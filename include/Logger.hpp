#include <string>
#include <ostream>
#include <vector>
#include <iostream>

#ifndef LOGGER_HPP
#define LOGGER_HPP

#include "./ANSIColorTable.h"

namespace Commandline {
    class Logger {
        private:
            static const std::string createHighlightedString(const std::string& ansiColor, const std::string& str) noexcept {
                return ansiColor + str + reset;
            };

        public:
            static std::ostream& write(std::ostream&, const std::string&) noexcept;
            static void displayHighlightText(std::ostream& os, std::string&, const std::string&, std::vector<size_t>&) noexcept; 
    };
}

#endif
