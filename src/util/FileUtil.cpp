#include "FileUtil.h"
#include <fstream>
#include <iostream>

bool FileUtil::ensureFileExists(const std::string &path) {
    std::ifstream in(path);
    if (in.good()) {
        return true;
    }
    in.close();
    std::ofstream out(path);
    bool ok = out.good();
    if (!ok) {
        std::cerr << "无法创建文件: " << path << std::endl;
    }
    return ok;
}

std::vector<std::string> FileUtil::readAllLines(const std::string &path) {
    std::vector<std::string> lines;
    std::ifstream in(path);
    if (!in.is_open()) {
        std::cerr << "读取文件失败: " << path << std::endl;
        return lines;
    }
    std::string line;
    while (std::getline(in, line)) {
        lines.emplace_back(line);
    }
    return lines;
}

bool FileUtil::writeAllLines(const std::string &path, const std::vector<std::string> &lines) {
    std::ofstream out(path, std::ios::trunc);
    if (!out.is_open()) {
        std::cerr << "写入文件失败: " << path << std::endl;
        return false;
    }
    for (size_t i = 0; i < lines.size(); ++i) {
        out << lines[i];
        if (i + 1 < lines.size()) {
            out << '\n';
        }
    }
    return true;
}
