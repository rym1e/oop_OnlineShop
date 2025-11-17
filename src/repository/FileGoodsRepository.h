#ifndef REPOSITORY_FILEGOODSREPOSITORY_H
#define REPOSITORY_FILEGOODSREPOSITORY_H

#include "IGoodsRepository.h"
#include <string>

/**
 * @brief FileGoodsRepository 从 TXT 文件中读取商品信息。
 */
class FileGoodsRepository : public IGoodsRepository {
private:
    std::string filePath;

public:
    explicit FileGoodsRepository(const std::string &filePath);
    std::vector<Goods> findAll() override;
};

#endif // REPOSITORY_FILEGOODSREPOSITORY_H
