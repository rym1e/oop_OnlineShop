#ifndef REPOSITORY_ICUSTOMERREPOSITORY_H
#define REPOSITORY_ICUSTOMERREPOSITORY_H

#include "../model/Customer.h"
#include <vector>

/**
 * @brief ICustomerRepository 定义了顾客数据访问需要实现的方法。
 */
class ICustomerRepository {
public:
    virtual ~ICustomerRepository() = default;

    virtual bool saveCustomer(const Customer &customer) = 0;
    virtual bool updateCustomerPassword(const std::string &username, const std::string &newPassword) = 0;
    virtual bool existsByUsername(const std::string &username) = 0;
    virtual bool findByUsername(const std::string &username, Customer &outCustomer) = 0;
    virtual std::vector<Customer> findAll() = 0;
};

#endif // REPOSITORY_ICUSTOMERREPOSITORY_H
