#include <iostream>
#include <map>
#include <set>
#include <vector>

template<typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &vec) {
    os << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        os << vec[i] << (i == vec.size() - 1 ? "" : ", ");
    }
    os << "]";
    return os;
}

// 打印 std::pair
template<typename T1, typename T2>
std::ostream &operator<<(std::ostream &os, const std::pair<T1, T2> &p) {
    os << "(" << p.first << ", " << p.second << ")";
    return os;
}

// 打印 std::map
template<typename Key, typename Value>
std::ostream &operator<<(std::ostream &os, const std::map<Key, Value> &m) {
    os << "{";
    bool first = true;
    for (const auto &pair : m) {
        if (!first) {
            os << ", ";
        }
        os << pair.first << ": " << pair.second;
        first = false;
    }
    os << "}";
    return os;
}

// 打印 std::set
template<typename T>
std::ostream &operator<<(std::ostream &os, const std::set<T> &s) {
    os << "{";
    bool first = true;
    for (const auto &val : s) {
        if (!first) {
            os << ", ";
        }
        os << val;
        first = false;
    }
    os << "}";
    return os;
}

template<typename T>
void printVector(const std::vector<T> &vec) {
    std::cout << vec << std::endl;
}

template<typename T>
void printMatrix(const std::vector<std::vector<T>> &mat) {
    std::cout << "[" << std::endl;
    for (const auto &row : mat) {
        std::cout << "  " << row << std::endl;
    }
    std::cout << "]" << std::endl;
}

template<typename T>
class LValueVec {
    public:
    std::vector<T> data;
    LValueVec(std::initializer_list<T> il) : data(il) {}
    operator std::vector<T> &() { return data; }
};

template<typename T>
std::ostream &operator<<(std::ostream &os, const LValueVec<T> &lv) {
    os << lv.data;
    return os;
}

//! 用以方便地对非 const 的 vector<T>& 的函数参数进行传递。
//! 这可能会造成危险的悬垂引用，慎用！
//! 不应修改或引用这样传入的临时 vector。
#define VEC(...) LValueVec<int>({__VA_ARGS__})
#define VECSTR(...) LValueVec<std::string>({__VA_ARGS__})
#define MAT(...) LValueVec<std::vector<int>>({__VA_ARGS__})
