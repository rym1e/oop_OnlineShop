#include "CustomerService.h"

CustomerService::CustomerService(ICustomerRepository &repo)
    : customerRepo(repo) {}

bool CustomerService::registerCustomer(const Customer &customer, std::string &errorMsg) {
    if (customer.getUsername().empty()) {
        errorMsg = "用户名不能为空";
        return false;
    }
    if (customerRepo.existsByUsername(customer.getUsername())) {
        errorMsg = "用户名已存在";
        return false;
    }
    if (!customerRepo.saveCustomer(customer)) {
        errorMsg = "保存用户信息失败";
        return false;
    }
    return true;
}

bool CustomerService::changePassword(const std::string &username,
                                     const std::string &oldPassword,
                                     const std::string &newPassword,
                                     std::string &errorMsg) {
    Customer existing;
    if (!customerRepo.findByUsername(username, existing)) {
        errorMsg = "用户不存在";
        return false;
    }
    if (existing.getPassword() != oldPassword) {
        errorMsg = "原密码错误";
        return false;
    }
    if (newPassword.length() < 3) {
        errorMsg = "新密码长度至少 3 位";
        return false;
    }
    if (!customerRepo.updateCustomerPassword(username, newPassword)) {
        errorMsg = "更新密码失败";
        return false;
    }
    return true;
}

std::vector<Customer> CustomerService::listAllCustomers() {
    return customerRepo.findAll();
}
