# libini

Simple header-only .ini parser written in C++

## Usage

Put the libini.hpp file somewhere into your project, include it and get started:


    #include "path/to/libini.hpp"

    auto ini = libini::parse("[Category]\nKey=Value");

    auto val = ini["Category"]["Key"];


## License

MIT
