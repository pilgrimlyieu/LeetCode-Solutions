#include <iostream>
#include <map>
#include <optional>
#include <set>
#include <vector>

#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
#endif

template<typename T>
std::ostream &operator<<(std::ostream &os, const std::optional<T> &opt) {
    if (opt.has_value()) {
        os << opt.value();
    }
    else {
        os << "null";
    }
    return os;
}

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

/* --- ListNode --- */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    explicit ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
    explicit ListNode(const std::vector<int> &v) : val(0), next(nullptr) {
        if (v.empty()) {
            return;
        }
        val = v[0];
        ListNode *current = this;
        for (int i = 1; i < v.size(); ++i) {
            current->next = new ListNode(v[i]);
            current = current->next;
        }
    }
};

std::ostream &operator<<(std::ostream &os, const ListNode *node) {
    os << "[";
    const ListNode *current = node;
    while (current) {
        os << current->val;
        current = current->next;
        if (current) {
            os << " -> ";
        }
    }
    os << "]";
    return os;
}

void printListNode(ListNode *node) { std::cout << node << std::endl; }

ListNode *createListNode(const std::vector<int> &v) { return new ListNode(v); }

/* --- TreeNode --- */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    explicit TreeNode(const std::vector<std::optional<int>> &v) : val(0), left(nullptr), right(nullptr) {
        if (v.empty() || !v[0].has_value()) {
            throw std::invalid_argument("Vector must have at least one non-null value for root");
        }
        val = v[0].value();
        std::vector<TreeNode *> nodes;
        nodes.push_back(this);
        size_t index = 1;
        for (size_t i = 0; i < nodes.size() && index < v.size(); ++i) {
            TreeNode *current = nodes[i];
            if (current) {
                // Left child
                if (index < v.size() && v[index].has_value()) {
                    current->left = new TreeNode(v[index].value());
                    nodes.push_back(current->left);
                }
                else {
                    nodes.push_back(nullptr);
                }
                ++index;
                // Right child
                if (index < v.size() && v[index].has_value()) {
                    current->right = new TreeNode(v[index].value());
                    nodes.push_back(current->right);
                }
                else {
                    nodes.push_back(nullptr);
                }
                ++index;
            }
        }
    }
    explicit operator std::vector<std::optional<int>>() const {
        std::vector<std::optional<int>> result;
        std::vector<const TreeNode *> queue;
        queue.push_back(this);
        size_t index = 0;
        while (index < queue.size()) {
            const TreeNode *current = queue[index++];
            if (current) {
                result.emplace_back(current->val);
                queue.push_back(current->left);
                queue.push_back(current->right);
            }
            else {
                result.emplace_back(std::nullopt);
            }
        }
        while (!result.empty() && !result.back().has_value()) {
            result.pop_back();
        }
        return result;
    }

    TreeNode *visualize() {
        _visualized = true;
        return this;
    }
    TreeNode *devisualize() {
        _visualized = false;
        return this;
    }
    [[nodiscard]] bool visualized() const { return _visualized; }

    private:
    bool _visualized = false;
};

void visualizeBinaryTreeHelper(std::ostream &os, const TreeNode *node, const std::string &prefix, bool isLeftChild) {
    if (!node) {
        return;
    }
    visualizeBinaryTreeHelper(os, node->right, prefix + (isLeftChild ? "│   " : "    "), false);
    os << prefix;
    os << (isLeftChild ? "└── " : "┌── ");
    os << node->val << std::endl;
    visualizeBinaryTreeHelper(os, node->left, prefix + (isLeftChild ? "    " : "│   "), true);
}

/**
 * @brief (替换) 可视化打印的入口函数
 */
std::ostream &visualizeBinaryTree(std::ostream &os, const TreeNode *root) {
    if (!root) {
        os << "(empty tree)";
        return os;
    }
#if defined(_WIN32) || defined(_WIN64)
    SetConsoleOutputCP(CP_UTF8);
#endif
    visualizeBinaryTreeHelper(os, root->right, "", false);
    os << root->val << std::endl;
    visualizeBinaryTreeHelper(os, root->left, "", true);
    return os;
}

std::ostream &operator<<(std::ostream &os, const TreeNode *node) {
    if (node->visualized()) {
        return visualizeBinaryTree(os, node);
    }
    else {
        if (!node) {
            os << "[]";
            return os;
        }
        os << static_cast<std::vector<std::optional<int>>>(*node);
        return os;
    }
}

template<typename... Args>
std::vector<std::optional<int>> create_tree_vec(Args &&...args) {
    std::vector<std::optional<int>> v;
    auto process = [&](auto &&arg) {
        using T = std::decay_t<decltype(arg)>;
        if constexpr (std::is_null_pointer_v<T>) {
            v.emplace_back(std::nullopt);
        }
        else {
            v.emplace_back(arg);
        }
    };
    (process(std::forward<Args>(args)), ...);
    return v;
}

#define BINTREE(...)                                                                                                   \
    [&]() -> TreeNode * {                                                                                              \
        std::vector<std::optional<int>> v = create_tree_vec(__VA_ARGS__);                                              \
        if (v.empty() || !v[0].has_value()) {                                                                          \
            return nullptr;                                                                                            \
        }                                                                                                              \
        return new TreeNode(v);                                                                                        \
    }()

/* --- VEC macros --- */

template<typename T>
class LValueVec {
    public:
    std::vector<T> data;
    LValueVec(std::initializer_list<T> il) : data(il) {}
    operator std::vector<T> &() { return data; } // NOLINT(google-explicit-constructor)
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

// string --> vector<char>
inline std::vector<char> S2V(const std::string &s) { return {s.begin(), s.end()}; }
// vector<char> --> string
inline std::string V2S(const std::vector<char> &v) { return {v.begin(), v.end()}; }
