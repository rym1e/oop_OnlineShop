#ifndef REPOSITORY_IGOODSREPOSITORY_H
#define REPOSITORY_IGOODSREPOSITORY_H

#include "../model/Goods.h"
#include <vector>

/**
 * @brief IGoodsRepository 抽象商品数据的读取能力。
 */
class IGoodsRepository {
public:
    virtual ~IGoodsRepository() = default;
    virtual std::vector<Goods> findAll() = 0;
};

#endif // REPOSITORY_IGOODSREPOSITORY_H
