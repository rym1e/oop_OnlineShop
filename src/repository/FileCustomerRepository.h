#ifndef REPOSITORY_FILECUSTOMERREPOSITORY_H
#define REPOSITORY_FILECUSTOMERREPOSITORY_H

#include "ICustomerRepository.h"
#include <string>
#include <vector>

/**
 * @brief FileCustomerRepository 通过 TXT 文件实现 ICustomerRepository 接口。
 */
class FileCustomerRepository : public ICustomerRepository {
private:
    std::string filePath;

    std::vector<Customer> loadAll();
    bool saveAll(const std::vector<Customer> &customers);

public:
    explicit FileCustomerRepository(const std::string &filePath);

    bool saveCustomer(const Customer &customer) override;
    bool updateCustomerPassword(const std::string &username, const std::string &newPassword) override;
    bool existsByUsername(const std::string &username) override;
    bool findByUsername(const std::string &username, Customer &outCustomer) override;
    std::vector<Customer> findAll() override;
};

#endif // REPOSITORY_FILECUSTOMERREPOSITORY_H
