#include "StringUtil.h"
#include <algorithm>
#include <sstream>

std::vector<std::string> StringUtil::split(const std::string &text, char delimiter) {
    std::vector<std::string> result;
    std::stringstream ss(text);
    std::string item;
    while (std::getline(ss, item, delimiter)) {
        result.emplace_back(item);
    }
    return result;
}

std::string StringUtil::trim(const std::string &text) {
    if (text.empty()) {
        return text;
    }
    size_t start = 0;
    while (start < text.size() && std::isspace(static_cast<unsigned char>(text[start]))) {
        ++start;
    }
    size_t end = text.size();
    while (end > start && std::isspace(static_cast<unsigned char>(text[end - 1]))) {
        --end;
    }
    return text.substr(start, end - start);
}
