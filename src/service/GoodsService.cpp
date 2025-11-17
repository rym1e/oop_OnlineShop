#include "GoodsService.h"

GoodsService::GoodsService(IGoodsRepository &repo)
    : goodsRepo(repo) {}

std::vector<Goods> GoodsService::listAllGoods() {
    return goodsRepo.findAll();
}
