#include <iostream>
#include "src/OBJParser.h"

int main( int argc, char** argv )
{
    Util::OBJParser parser{"test"};
    parser.ReadTextOBJFile();

    std::cin.get();
}