#include "Exception.hpp"
#include "Parser.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    zappy::Parser parser;

    try {
        parser.parse(argc, argv);
    } catch (zappy::Exception &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    return 0;
}
