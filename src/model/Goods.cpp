#include "Goods.h"
#include "../util/StringUtil.h"
#include <vector>

Goods::Goods(int id,
             const std::string &name,
             double price,
             int stock,
             const std::string &description)
    : id(id), name(name), price(price), stock(stock), description(description) {}

int Goods::getId() const {
    return id;
}

const std::string &Goods::getName() const {
    return name;
}

double Goods::getPrice() const {
    return price;
}

int Goods::getStock() const {
    return stock;
}

const std::string &Goods::getDescription() const {
    return description;
}

std::string Goods::toLine() const {
    return std::to_string(id) + "|" + name + "|" + std::to_string(price) + "|" +
           std::to_string(stock) + "|" + description;
}

Goods Goods::fromLine(const std::string &line) {
    std::vector<std::string> parts = StringUtil::split(line, '|');
    while (parts.size() < 5) {
        parts.emplace_back("");
    }
    int id = parts[0].empty() ? 0 : std::stoi(parts[0]);
    double price = parts[2].empty() ? 0.0 : std::stod(parts[2]);
    int stock = parts[3].empty() ? 0 : std::stoi(parts[3]);
    return {id, parts[1], price, stock, parts[4]};
}
