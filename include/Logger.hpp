#include <string>
#include <ostream>

#ifndef LOGGER_HPP
#define LOGGER_HPP

namespace Commandline {
    class Logger {
        public:
            static std::ostream& write(std::ostream&, const std::string&) noexcept;
    };
}

#endif
