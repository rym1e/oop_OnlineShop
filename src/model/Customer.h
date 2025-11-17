#ifndef MODEL_CUSTOMER_H
#define MODEL_CUSTOMER_H

#include "User.h"
#include <string>

/**
 * @brief Customer 表示普通顾客用户，继承自 User，并包含注册时填写的个人信息。
 */
class Customer : public User {
private:
    std::string realName;   ///< 真实姓名
    std::string phone;      ///< 联系电话
    std::string email;      ///< 邮箱
    std::string address;    ///< 收货地址

public:
    Customer() = default;
    Customer(const std::string &username,
             const std::string &password,
             const std::string &realName,
             const std::string &phone,
             const std::string &email,
             const std::string &address);

    const std::string &getRealName() const;
    void setRealName(const std::string &realName);

    const std::string &getPhone() const;
    void setPhone(const std::string &phone);

    const std::string &getEmail() const;
    void setEmail(const std::string &email);

    const std::string &getAddress() const;
    void setAddress(const std::string &address);

    std::string toLine() const;                     ///< 将对象序列化为一行文本
    static Customer fromLine(const std::string &line); ///< 从一行文本反序列化
};

#endif // MODEL_CUSTOMER_H
