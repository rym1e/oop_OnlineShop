#include "AuthService.h"

AuthService::AuthService(ICustomerRepository &customerRepo)
    : customerRepo(customerRepo) {}

bool AuthService::loginCustomer(const std::string &username,
                                const std::string &password,
                                Customer &outCustomer) {
    if (!customerRepo.findByUsername(username, outCustomer)) {
        return false;
    }
    return outCustomer.getPassword() == password;
}

bool AuthService::loginAdmin(const std::string &username, const std::string &password) {
    return username == adminUsername && password == adminPassword;
}
