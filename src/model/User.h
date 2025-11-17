#ifndef MODEL_USER_H
#define MODEL_USER_H

#include <string>

/**
 * @brief User 为系统中所有用户的抽象基类，封装用户名和密码等公共属性。
 *        使用中文注释是为了方便阅读和后续维护。
 */
class User {
protected:
    std::string username;  ///< 用户名
    std::string password;  ///< 密码（明文存储，演示项目中不进行加密）

public:
    User() = default;
    User(const std::string &username, const std::string &password);

    virtual ~User() = default;

    const std::string &getUsername() const;
    void setUsername(const std::string &username);

    const std::string &getPassword() const;
    void setPassword(const std::string &password);
};

#endif // MODEL_USER_H
