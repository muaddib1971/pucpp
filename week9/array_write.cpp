#include <exception>
#include <fstream>
#include <iostream>
#include <string_view>
#include <vector>

using byte = char;

void write_vector(std::vector<int>& theints, std::string_view name) {
    std::ofstream out(name.data(), std::ios::binary);
    out.exceptions(std::ios::badbit | std::ios::failbit);
    if (out.good()) {
        try {
            std::size_t size = theints.size();
            out.write(reinterpret_cast<char*>(&size), sizeof(std::size_t));
            out.write(reinterpret_cast<char*>(&theints[0]), sizeof(int) * size);
        } catch (std::exception& ex) {
            perror("failed to write");
        }
    }
}

void read_vector(std::vector<int>& theints, std::string_view name) {
    /*
    2000000000
    4
    */
    std::ifstream in(name.data(), std::ios::binary);
    in.exceptions(std::ios::badbit | std::ios::failbit);
    if (in.good()) {
        try {
            std::size_t size;
            in.read(reinterpret_cast<char*>(&size), sizeof(std::size_t));
            theints.reserve(size);
            in.read(reinterpret_cast<char*>(&theints[0]), sizeof(int) * size);
        } catch (std::exception& ex) {
            if (!in.eof()) {
                perror("read error ");
            }
        }
    }
}
#if 0
int main(void) {
    std::vector<int> myints{1, 3, 5, 7, 9};
    write_vector(myints, "myints");
}
#endif

int main() {
    std::vector<int> myints;
    read_vector(myints, "myints");
    for (auto& item : myints) {
        std::cout << item << "\n";
    }
}
