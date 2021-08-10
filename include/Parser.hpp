#include <iostream>
#include <utility>
#include <vector>

#ifndef PARSER_HPP
#define PARSER_HPP

namespace CommandlineParser {
    void _tokenise(const int& argc, const char* (argv)[], std::vector<std::string>& tokens) {
        for(int i = 0; i < argc; i++){
            tokens[i] = argv[i];
        }
    }

    std::pair<std::string,std::string> parseArgs(const int& argc, const char* (argv)[]) {
        if (argc >= 3) { // Check if input is valid first

            std::vector<std::string> tokens(argc);
            _tokenise(argc, argv, tokens);

            return std::make_pair(argv[1], argv[2]);

        } else { // Incorrect number of inputs
            std::cerr << "Incorrect Number of Args Provided\n";
            return std::make_pair("","");
        }
        return std::make_pair("","");
    }
};
    
#endif
