#ifndef SERVICE_MENUVIEW_H
#define SERVICE_MENUVIEW_H

#include "AuthService.h"
#include "CustomerService.h"
#include "GoodsService.h"

/**
 * @brief MenuView 负责控制台界面的展示与用户输入。
 */
class MenuView {
private:
    AuthService &authService;
    CustomerService &customerService;
    GoodsService &goodsService;

    void showMainMenu();
    void handleCustomerLogin();
    void handleCustomerRegister();
    void handleAdminLogin();
    void showGoodsList();
    void showCustomerMenu(const Customer &customer);
    void showAdminMenu();

public:
    MenuView(AuthService &authService,
             CustomerService &customerService,
             GoodsService &goodsService);

    void run();
};

#endif // SERVICE_MENUVIEW_H
