#include <iostream>
#include <utility>
#include <vector>

#ifndef PARSER_HPP
#define PARSER_HPP

namespace Commandline {
    class Parser {
        private:
            static int argc;
            static const char* (&argv)[];
            void tokenise();

        public: 
            Parser();
            static std::pair<std::string,std::string> parseArgs(const int& argc, const char* argv[]);
    };
};
    
#endif
