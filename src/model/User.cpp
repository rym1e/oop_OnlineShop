#include "User.h"

/**
 * @brief 带参构造函数，用于一次性设置用户名与密码。
 */
User::User(const std::string &username, const std::string &password)
    : username(username), password(password) {}

const std::string &User::getUsername() const {
    return username;
}

void User::setUsername(const std::string &username) {
    this->username = username;
}

const std::string &User::getPassword() const {
    return password;
}

void User::setPassword(const std::string &password) {
    this->password = password;
}
