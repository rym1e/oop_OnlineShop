#ifndef SERVICE_CUSTOMERSERVICE_H
#define SERVICE_CUSTOMERSERVICE_H

#include "../repository/ICustomerRepository.h"
#include <string>
#include <vector>

/**
 * @brief CustomerService 处理顾客注册、修改密码等业务逻辑。
 */
class CustomerService {
private:
    ICustomerRepository &customerRepo;

public:
    explicit CustomerService(ICustomerRepository &repo);

    bool registerCustomer(const Customer &customer, std::string &errorMsg);
    bool changePassword(const std::string &username,
                        const std::string &oldPassword,
                        const std::string &newPassword,
                        std::string &errorMsg);

    std::vector<Customer> listAllCustomers();
};

#endif // SERVICE_CUSTOMERSERVICE_H
