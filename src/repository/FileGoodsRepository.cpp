#include "FileGoodsRepository.h"
#include "../util/FileUtil.h"
#include "../util/StringUtil.h"
#include <iostream>

FileGoodsRepository::FileGoodsRepository(const std::string &filePath)
    : filePath(filePath) {
    FileUtil::ensureFileExists(filePath);
}

std::vector<Goods> FileGoodsRepository::findAll() {
    std::vector<Goods> goodsList;
    std::vector<std::string> lines = FileUtil::readAllLines(filePath);
    for (const auto &line : lines) {
        if (StringUtil::trim(line).empty()) {
            continue;
        }
        try {
            goodsList.emplace_back(Goods::fromLine(line));
        } catch (const std::exception &ex) {
            std::cerr << "解析商品失败: " << ex.what() << " 原始行: " << line << std::endl;
        }
    }
    return goodsList;
}
