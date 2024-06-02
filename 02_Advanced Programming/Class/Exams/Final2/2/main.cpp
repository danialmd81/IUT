#include <bits/stdc++.h>

using namespace std;

class Point
{
private:
    int Name;
    vector<Point *> yal;

public:
    Point(int name)
    {
        Name = name;
    }
    void set_yal(Point *point)
    {
        yal.push_back(point);
    }
    vector<Point *> &ref_yal()
    {
        return yal;
    }
};

class Graph
{
private:
    vector<Point *> graph;

public:
    Graph()
    {
    }
    void set_point(Point *point)
    {
        graph.push_back(point);
    }
    vector<Point *> &ref_graph()
    {
        return graph;
    }
};

int main()
{
    int n;
    Graph g;
    Point *p;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        int name;
        std::cin >> name;
        p = new Point(name);
        while (1)
        {
            char c = getchar();
            if (c == '\n')
                break;
            else if (c == ' ')
                continue;
            else
            {
                Point yal(int(c - 48));
                p->set_yal(&yal);
            }
        }
        g.set_point(p);
    }
    int max = g.ref_graph().at(0)->ref_yal().size();
    for (auto &&i : g.ref_graph())
    {
        if (max < i->ref_yal().size())
        {
            max = i->ref_yal().size();
        }
    }
    std::cout << max;
}