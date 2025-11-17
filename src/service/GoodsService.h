#ifndef SERVICE_GOODSSERVICE_H
#define SERVICE_GOODSSERVICE_H

#include "../repository/IGoodsRepository.h"
#include <vector>

/**
 * @brief GoodsService 封装了商品查询相关的业务方法。
 */
class GoodsService {
private:
    IGoodsRepository &goodsRepo;

public:
    explicit GoodsService(IGoodsRepository &repo);
    std::vector<Goods> listAllGoods();
};

#endif // SERVICE_GOODSSERVICE_H
