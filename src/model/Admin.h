#ifndef MODEL_ADMIN_H
#define MODEL_ADMIN_H

#include "User.h"

/**
 * @brief Admin 表示系统管理员账号，当前仅包含用户名和密码两个字段，
 *        通过继承 User 保持代码结构的一致性。
 */
class Admin : public User {
public:
    Admin(const std::string &username, const std::string &password);
};

#endif // MODEL_ADMIN_H
