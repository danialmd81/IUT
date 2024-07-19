#include "kd_tree.hpp"

using namespace std;

Coordinates::Coordinates()
{
    x = INT_MIN;
    y = INT_MIN;
}

Coordinates::Coordinates(int x, int y)
{
    this->x = x;
    this->y = y;
}

kd_tree::Node::Node()
{
    left = nullptr;
    right = nullptr;
}

kd_tree::Node::Node(Coordinates point)
{
    this->point = point;
    left = nullptr;
    right = nullptr;
}

Coordinates_vector::Coordinates_vector()
{
    arr = shared_ptr<Coordinates>(new Coordinates[1]);
    capacity = 1;
    current = 0;
}

Coordinates_vector::~Coordinates_vector()
{
    delete[] arr.get();
}

void Coordinates_vector::push(Coordinates point)
{
    if (current == capacity)
    {
        shared_ptr<Coordinates> temp(new Coordinates[2 * capacity]);
        for (int i = 0; i < capacity; i++)
        {
            temp.get()[i] = arr.get()[i];
        }
        delete[] arr.get();
        capacity *= 2;
        arr = temp;
    }

    arr.get()[current] = point;
    current++;
}

optional<Coordinates> Coordinates_vector::get(int index)
{
    if (index < current)
        return arr.get()[index];
    return nullopt;
}

void Coordinates_vector::pop()
{
    current--;
}

int Coordinates_vector::size()
{
    return current;
}

int Coordinates_vector::get_capacity()
{
    return capacity;
}

kd_tree::kd_tree()
{
    root = nullptr;
}

kd_tree::nodeptr kd_tree::insert(nodeptr root, Coordinates &point, int depth)
{
    if (root == nullptr)
    {
        return nodeptr(new Node(point));
    }

    if (depth % 2 == 0) //
    {
        if (point.x < (root.get()->point.x))
            root.get()->left = insert(root->left, point, depth + 1);
        else
            root->right = insert(root->right, point, depth + 1);
    }
    else
    {
        if (point.y < (root.get()->point.y))
            root.get()->left = insert(root->left, point, depth + 1);
        else
            root->right = insert(root->right, point, depth + 1);
    }

    return root;
}

void kd_tree::insert(Coordinates point)
{
    root = insert(root, point, 0);
    return;
}

void kd_tree::insert(int x, int y)
{
    Coordinates point(x, y);
    insert(point);
    return;
}

void kd_tree::insert(Coordinates_vector points_vec)
{
    for (int i = 0; i < points_vec.size(); i++)
    {
        insert(points_vec.get(i).value());
    }
    return;
}