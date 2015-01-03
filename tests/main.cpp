#include <fstream>
#include <iostream>
#include <string>

#include <libini/parser.hpp>

int main() {
    std::ifstream istream{"tests/test.ini"};

    auto content = std::string {std::istreambuf_iterator<char>(istream),
        std::istreambuf_iterator<char>()};

    auto ini = libini::parse(content);

    std::cout << ini.get("Category", "Key2") << std::endl;

    return 0;
}
