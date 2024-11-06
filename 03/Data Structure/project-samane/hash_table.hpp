#include <string>
#include <memory>
#include <optional>

template <class T>
class My_Hash_table
{
private:
    struct Node
    {
        std::string key;
        T value;
        std::shared_ptr<Node> next;
        Node();
        Node(std::string key, T value);
    };
    using nodeptr = std::shared_ptr<Node>;
    static const int SIZE = 100;
    nodeptr hash_table[SIZE];
    std::hash<std::string> hash_function;
    int hash(std::string &key);

public:
    My_Hash_table();
    void set(std::string key, T value);
    std::optional<T> get(std::string key);
};
