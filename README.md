# 在线商城 TXT 版 (C++)

该项目是一个基于 C++ 控制台的简单在线商城演示，实现了顾客注册/登录、管理员登录、商品浏览等功能，所有数据均通过 TXT 文本进行持久化存储。

## 编译运行

```bash
mkdir -p build
cd build
cmake ..  # 如果你安装了 CMake
make
./oop_OnlineShop
```

也可以直接使用 g++ 编译：

```bash
g++ -std=c++17 -Isrc -o shop \
    src/main.cpp \
    src/model/*.cpp \
    src/service/*.cpp \
    src/repository/*.cpp \
    src/util/*.cpp
./shop
```

## 目录结构

- `src/model`：领域模型，包括用户、顾客、管理员、商品等类。
- `src/repository`：数据访问层，封装对 TXT 文件的读写。
- `src/service`：业务逻辑层，包括认证、顾客、商品、菜单等服务。
- `src/util`：工具类，例如字符串处理、文件读写。
- `data`：存放 `customers.txt`、`goods.txt`。

## 默认账号

- 管理员：用户名 `admin`，密码 `123456`。
- 顾客：初始无账号，可自行注册。
