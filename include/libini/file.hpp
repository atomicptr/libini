#ifndef __LIBINI_FILE_HPP__
#define __LIBINI_FILE_HPP__

#include <map>
#include <string>
#include <utility>

namespace libini {

    using ini_model = std::map<std::string, std::map<std::string, std::string>>;

    class file {
    public:
        file();
        file(file&&);
        file(const file&&);

        void set(std::string, std::string, std::string);
        std::string get(std::string, std::string);

    private:
        ini_model data_;
    };
}

#endif
