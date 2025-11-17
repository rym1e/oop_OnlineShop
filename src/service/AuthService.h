#ifndef SERVICE_AUTHSERVICE_H
#define SERVICE_AUTHSERVICE_H

#include "../model/Customer.h"
#include "../repository/ICustomerRepository.h"
#include <string>

/**
 * @brief AuthService 提供顾客与管理员的登录校验逻辑。
 */
class AuthService {
private:
    ICustomerRepository &customerRepo;
    const std::string adminUsername = "admin";
    const std::string adminPassword = "123456";

public:
    explicit AuthService(ICustomerRepository &customerRepo);

    bool loginCustomer(const std::string &username,
                       const std::string &password,
                       Customer &outCustomer);

    bool loginAdmin(const std::string &username, const std::string &password);
};

#endif // SERVICE_AUTHSERVICE_H
