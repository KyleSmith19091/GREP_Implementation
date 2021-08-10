#include "../include/Logger.hpp"

std::ostream& Commandline::Logger::write(std::ostream& os, const std::string& data) noexcept {
    return os << data;    
}
