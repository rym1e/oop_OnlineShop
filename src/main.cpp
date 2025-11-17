#include "model/Customer.h"
#include "repository/FileCustomerRepository.h"
#include "repository/FileGoodsRepository.h"
#include "service/AuthService.h"
#include "service/CustomerService.h"
#include "service/GoodsService.h"
#include "service/MenuView.h"
#include <iostream>

/**
 * @brief main 函数是程序入口，负责组装依赖并启动菜单循环。
 */
int main() {
    std::string customerFile = "data/customers.txt";
    std::string goodsFile = "data/goods.txt";

    FileCustomerRepository customerRepo(customerFile);
    FileGoodsRepository goodsRepo(goodsFile);

    AuthService authService(customerRepo);
    CustomerService customerService(customerRepo);
    GoodsService goodsService(goodsRepo);

    MenuView view(authService, customerService, goodsService);
    view.run();
    return 0;
}
