#include <fstream>
#include <iostream>
#include <string>
bool read(std::string& fname) {
    std::ifstream in(fname, std::ios::in | std::ios::binary);

    /* operators logical: || or , && being and */
    /* bitwise operators: | or, & for and */

    in = 10100000;
    binary = 00011000;
    10111000 & 10000000 = 10000000;

    io flags -

        in.good(),
        in.bad(), in.fail() in.eof() in.rdstate std::getline(in, line);
    if (!in.good()) {
        /* handle errors */
    }
    /* used a great deal in operating systems programming where time matters */
}
