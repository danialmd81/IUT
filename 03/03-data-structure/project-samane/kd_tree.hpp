#include <iostream>
#include <memory>
#include <optional>

struct Coordinates
{
    int x, y;
    Coordinates();
    Coordinates(int x, int y);
};

class Coordinates_vector
{
    std::shared_ptr<Coordinates> arr;
    int capacity; // the total storage
    int current;  // number of elements

public:
    Coordinates_vector();
    ~Coordinates_vector();
    void push(Coordinates point);
    std::optional<Coordinates> get(int index);
    void pop();
    int size();
    int get_capacity();
};

class kd_tree
{
private:
    struct Node
    {
        Coordinates point;
        std::shared_ptr<Node> left, right;
        Node();
        Node(Coordinates point);
    };
    using nodeptr = std::shared_ptr<Node>;
    nodeptr root;
    nodeptr insert(nodeptr root, Coordinates &point, int depth);

public:
    kd_tree();
    void insert(Coordinates point);
    void insert(int x, int y);
    void insert(Coordinates_vector points_vec);
    
};
