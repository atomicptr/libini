#include <libini/file.hpp>

libini::file::file() {}

libini::file::file(file&& other) : data_(std::move(other.data_)) {}

libini::file::file(const file&& other) : data_(std::move(other.data_)) {}

void libini::file::set(std::string category, std::string key, std::string value) {
    auto cat_it = data_.find(category);

    if(cat_it == data_.end()) {
        std::map<std::string, std::string> m;

        m.insert(std::make_pair(key, value));
        data_.emplace(std::make_pair(category, m));
    } else {
        data_[category][key] = value;
    }
}

std::string libini::file::get(std::string category, std::string key) {
    return data_[category][key];
}
