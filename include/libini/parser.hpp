#ifndef __LIBINI_PARSER_HPP__
#define __LIBINI_PARSER_HPP__

#include <iostream>
#include <sstream>
#include <string>
#include <stdexcept>
#include <vector>

#include <libini/file.hpp>

namespace libini {

    file parse(std::string);
    file parse(std::vector<char>&);

}

#endif
