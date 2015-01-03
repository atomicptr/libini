#ifndef __LIBINI_PARSER_HPP__
#define __LIBINI_PARSER_HPP__

#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <stdexcept>
#include <vector>
#include <utility>

namespace libini {

    using key_val = std::map<std::string, std::string>;
    using ini_model = std::map<std::string, key_val>;

    static inline std::vector<std::string> split(const std::string string, const char delimeter) {
        std::vector<std::string> strings;

        std::istringstream f(string);
        std::string s;

        while(std::getline(f, s, delimeter)) {
            strings.push_back(s);
        }

        return strings;
    }

    static inline std::string &ltrim(std::string &s) {
        s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
        return s;
    }


    static inline std::string &rtrim(std::string &s) {
        s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
        return s;
    }

    static inline std::string &trim(std::string &s) {
        return ltrim(rtrim(s));
    }

    ini_model parse(std::string data) {
        ini_model model;

        std::istringstream stream(data);

        std::string line;
        std::string last_category = "";

        while(std::getline(stream, line)) {
            auto start = line.find("[");

            if(start != std::string::npos) {
                auto end = line.find("]");

                last_category = line.substr(start + 1, end - 1);
            } else if(last_category.size() > 0) {
                auto equals = line.find("=");

                if(equals != std::string::npos) {
                    auto parts = split(line, '=');

                    if(parts.size() > 2) {
                        throw std::runtime_error("Invalid INI file");
                    }

                    auto key = trim(parts[0]);
                    auto value = trim(parts[1]);

                    model[last_category][key] = value;
                }
            }
        }

        return model;
    }
}

#endif
