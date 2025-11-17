#ifndef UTIL_FILEUTIL_H
#define UTIL_FILEUTIL_H

#include <string>
#include <vector>

/**
 * @brief FileUtil 封装了对 TXT 文件的常用操作，例如读取所有行、写入所有行等。
 */
class FileUtil {
public:
    static bool ensureFileExists(const std::string &path);
    static std::vector<std::string> readAllLines(const std::string &path);
    static bool writeAllLines(const std::string &path, const std::vector<std::string> &lines);
};

#endif // UTIL_FILEUTIL_H
