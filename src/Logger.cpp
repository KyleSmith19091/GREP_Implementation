#include "../include/Logger.hpp"

std::ostream& Commandline::Logger::write(std::ostream& os, const std::string& data) noexcept {
    return os << data;    
}

void Commandline::Logger::displayHighlightText(std::ostream& os, std::string& str, const std::string& pattern, std::vector<size_t>& indices) noexcept {
    const int ansiLength = getLengthOfANSICode(REGULAR_TEXT_LEN);
    const int patternSize = pattern.size();
    const std::string highlightText = createHighlightedString(RED,pattern);

    int offset = 0;
    for (size_t& i : indices) {
        str.replace(i + offset,patternSize,highlightText);
        offset += ansiLength;
    }

    Commandline::Logger::write(os, str + "\n");
}
