#include "Customer.h"
#include "../util/StringUtil.h"
#include <vector>

Customer::Customer(const std::string &username,
                   const std::string &password,
                   const std::string &realName,
                   const std::string &phone,
                   const std::string &email,
                   const std::string &address)
    : User(username, password), realName(realName), phone(phone), email(email), address(address) {}

const std::string &Customer::getRealName() const {
    return realName;
}

void Customer::setRealName(const std::string &realName) {
    this->realName = realName;
}

const std::string &Customer::getPhone() const {
    return phone;
}

void Customer::setPhone(const std::string &phone) {
    this->phone = phone;
}

const std::string &Customer::getEmail() const {
    return email;
}

void Customer::setEmail(const std::string &email) {
    this->email = email;
}

const std::string &Customer::getAddress() const {
    return address;
}

void Customer::setAddress(const std::string &address) {
    this->address = address;
}

std::string Customer::toLine() const {
    // 将所有字段使用竖线拼接，方便在 TXT 中读取
    return username + "|" + password + "|" + realName + "|" + phone + "|" + email + "|" + address;
}

Customer Customer::fromLine(const std::string &line) {
    // 按照竖线切分字符串，如果字段不足则补空字符串
    std::vector<std::string> parts = StringUtil::split(line, '|');
    while (parts.size() < 6) {
        parts.emplace_back("");
    }
    return {parts[0], parts[1], parts[2], parts[3], parts[4], parts[5]};
}
