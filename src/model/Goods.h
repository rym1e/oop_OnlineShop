#ifndef MODEL_GOODS_H
#define MODEL_GOODS_H

#include <string>

/**
 * @brief Goods 用于描述一个商品的基本信息。
 */
class Goods {
private:
    int id = 0;                   ///< 商品编号
    std::string name;             ///< 商品名称
    double price = 0.0;           ///< 商品价格
    int stock = 0;                ///< 库存数量
    std::string description;      ///< 商品描述

public:
    Goods() = default;
    Goods(int id,
          const std::string &name,
          double price,
          int stock,
          const std::string &description);

    int getId() const;
    const std::string &getName() const;
    double getPrice() const;
    int getStock() const;
    const std::string &getDescription() const;

    std::string toLine() const;
    static Goods fromLine(const std::string &line);
};

#endif // MODEL_GOODS_H
