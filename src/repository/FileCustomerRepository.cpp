#include "FileCustomerRepository.h"
#include "../util/FileUtil.h"
#include "../util/StringUtil.h"
#include <iostream>

FileCustomerRepository::FileCustomerRepository(const std::string &filePath)
    : filePath(filePath) {
    FileUtil::ensureFileExists(filePath);
}

std::vector<Customer> FileCustomerRepository::loadAll() {
    std::vector<std::string> lines = FileUtil::readAllLines(filePath);
    std::vector<Customer> customers;
    for (const auto &line : lines) {
        if (StringUtil::trim(line).empty()) {
            continue;
        }
        customers.emplace_back(Customer::fromLine(line));
    }
    return customers;
}

bool FileCustomerRepository::saveAll(const std::vector<Customer> &customers) {
    std::vector<std::string> lines;
    lines.reserve(customers.size());
    for (const auto &customer : customers) {
        lines.emplace_back(customer.toLine());
    }
    return FileUtil::writeAllLines(filePath, lines);
}

bool FileCustomerRepository::saveCustomer(const Customer &customer) {
    std::vector<Customer> customers = loadAll();
    customers.emplace_back(customer);
    return saveAll(customers);
}

bool FileCustomerRepository::updateCustomerPassword(const std::string &username, const std::string &newPassword) {
    std::vector<Customer> customers = loadAll();
    bool found = false;
    for (auto &customer : customers) {
        if (customer.getUsername() == username) {
            customer.setPassword(newPassword);
            found = true;
            break;
        }
    }
    if (!found) {
        std::cerr << "未找到用户: " << username << std::endl;
        return false;
    }
    return saveAll(customers);
}

bool FileCustomerRepository::existsByUsername(const std::string &username) {
    Customer tmp;
    return findByUsername(username, tmp);
}

bool FileCustomerRepository::findByUsername(const std::string &username, Customer &outCustomer) {
    std::vector<Customer> customers = loadAll();
    for (const auto &customer : customers) {
        if (customer.getUsername() == username) {
            outCustomer = customer;
            return true;
        }
    }
    return false;
}

std::vector<Customer> FileCustomerRepository::findAll() {
    return loadAll();
}
