#ifndef UTIL_STRINGUTIL_H
#define UTIL_STRINGUTIL_H

#include <string>
#include <vector>

/**
 * @brief StringUtil 集中放置字符串相关的工具函数，例如拆分和去空格。
 */
class StringUtil {
public:
    static std::vector<std::string> split(const std::string &text, char delimiter);
    static std::string trim(const std::string &text);
};

#endif // UTIL_STRINGUTIL_H
