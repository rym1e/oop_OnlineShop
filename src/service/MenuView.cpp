#include "MenuView.h"
#include "../util/StringUtil.h"
#include <iostream>
#include <limits>

MenuView::MenuView(AuthService &authService,
                   CustomerService &customerService,
                   GoodsService &goodsService)
    : authService(authService), customerService(customerService), goodsService(goodsService) {}

void MenuView::run() {
    bool exit = false;
    while (!exit) {
        showMainMenu();
        std::cout << "请选择操作: ";
        int choice = 0;
        std::cin >> choice;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "输入无效，请输入数字。" << std::endl;
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        switch (choice) {
            case 1:
                handleCustomerLogin();
                break;
            case 2:
                handleCustomerRegister();
                break;
            case 3:
                handleAdminLogin();
                break;
            case 4:
                showGoodsList();
                break;
            case 0:
                exit = true;
                break;
            default:
                std::cout << "无效的菜单编号。" << std::endl;
        }
    }
    std::cout << "欢迎下次使用，再见！" << std::endl;
}

void MenuView::showMainMenu() {
    std::cout << "\n==== 在线商城（TXT 版）====" << std::endl;
    std::cout << "1. 顾客登录" << std::endl;
    std::cout << "2. 顾客注册" << std::endl;
    std::cout << "3. 管理员登录" << std::endl;
    std::cout << "4. 浏览商品" << std::endl;
    std::cout << "0. 退出系统" << std::endl;
}

void MenuView::handleCustomerLogin() {
    std::string username, password;
    std::cout << "请输入用户名: ";
    std::getline(std::cin, username);
    std::cout << "请输入密码: ";
    std::getline(std::cin, password);

    Customer customer;
    if (authService.loginCustomer(username, password, customer)) {
        std::cout << "登录成功，欢迎您，" << customer.getRealName() << "！" << std::endl;
        showCustomerMenu(customer);
    } else {
        std::cout << "用户名或密码错误。" << std::endl;
    }
}

void MenuView::handleCustomerRegister() {
    std::string username, password, realName, phone, email, address;
    std::cout << "请输入用户名: ";
    std::getline(std::cin, username);
    std::cout << "请输入密码: ";
    std::getline(std::cin, password);
    std::cout << "请输入真实姓名: ";
    std::getline(std::cin, realName);
    std::cout << "请输入手机号: ";
    std::getline(std::cin, phone);
    std::cout << "请输入邮箱: ";
    std::getline(std::cin, email);
    std::cout << "请输入地址: ";
    std::getline(std::cin, address);

    Customer customer(username, password, realName, phone, email, address);
    std::string errorMsg;
    if (customerService.registerCustomer(customer, errorMsg)) {
        std::cout << "注册成功，请使用账号登录。" << std::endl;
    } else {
        std::cout << "注册失败: " << errorMsg << std::endl;
    }
}

void MenuView::handleAdminLogin() {
    std::string username, password;
    std::cout << "请输入管理员账号: ";
    std::getline(std::cin, username);
    std::cout << "请输入管理员密码: ";
    std::getline(std::cin, password);

    if (authService.loginAdmin(username, password)) {
        std::cout << "管理员登录成功。" << std::endl;
        showAdminMenu();
    } else {
        std::cout << "管理员账号或密码错误。" << std::endl;
    }
}

void MenuView::showGoodsList() {
    std::vector<Goods> goods = goodsService.listAllGoods();
    if (goods.empty()) {
        std::cout << "暂无商品数据。" << std::endl;
        return;
    }
    std::cout << "\n---- 商品列表 ----" << std::endl;
    for (const auto &item : goods) {
        std::cout << "编号:" << item.getId()
                  << " 名称:" << item.getName()
                  << " 价格:" << item.getPrice()
                  << " 库存:" << item.getStock()
                  << " 描述:" << item.getDescription() << std::endl;
    }
}

void MenuView::showCustomerMenu(const Customer &customer) {
    bool back = false;
    while (!back) {
        std::cout << "\n---- 顾客菜单 ----" << std::endl;
        std::cout << "1. 修改密码" << std::endl;
        std::cout << "2. 浏览商品" << std::endl;
        std::cout << "0. 返回主菜单" << std::endl;
        std::cout << "请选择: ";
        int choice;
        std::cin >> choice;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "输入无效。" << std::endl;
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        switch (choice) {
            case 1: {
                std::string oldPassword, newPassword;
                std::cout << "请输入原密码: ";
                std::getline(std::cin, oldPassword);
                std::cout << "请输入新密码: ";
                std::getline(std::cin, newPassword);
                std::string errorMsg;
                if (customerService.changePassword(customer.getUsername(), oldPassword, newPassword, errorMsg)) {
                    std::cout << "密码修改成功。" << std::endl;
                } else {
                    std::cout << "密码修改失败: " << errorMsg << std::endl;
                }
                break;
            }
            case 2:
                showGoodsList();
                break;
            case 0:
                back = true;
                break;
            default:
                std::cout << "菜单选项无效。" << std::endl;
        }
    }
}

void MenuView::showAdminMenu() {
    bool back = false;
    while (!back) {
        std::cout << "\n---- 管理员菜单 ----" << std::endl;
        std::cout << "1. 查看所有顾客" << std::endl;
        std::cout << "2. 查看商品列表" << std::endl;
        std::cout << "0. 返回主菜单" << std::endl;
        std::cout << "请选择: ";
        int choice;
        std::cin >> choice;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "输入无效。" << std::endl;
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        switch (choice) {
            case 1: {
                std::vector<Customer> customers = customerService.listAllCustomers();
                if (customers.empty()) {
                    std::cout << "暂无顾客数据。" << std::endl;
                } else {
                    std::cout << "\n---- 顾客列表 ----" << std::endl;
                    for (const auto &customer : customers) {
                        std::cout << "用户名:" << customer.getUsername()
                                  << " 姓名:" << customer.getRealName()
                                  << " 电话:" << customer.getPhone()
                                  << " 邮箱:" << customer.getEmail()
                                  << " 地址:" << customer.getAddress() << std::endl;
                    }
                }
                break;
            }
            case 2:
                showGoodsList();
                break;
            case 0:
                back = true;
                break;
            default:
                std::cout << "菜单选项无效。" << std::endl;
        }
    }
}
