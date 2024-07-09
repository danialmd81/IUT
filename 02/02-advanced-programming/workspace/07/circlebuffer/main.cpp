#include "CircleBuffer.h"

int main()
{
    CircleBuffer<int> buf;
    try
    {
        for (int i = 0; i < 10; i++)
        {
            buf.push_back(i);
        }
        for (int i = 0; i < 10; i++)
        {
            buf.pop_front();
        }
        for (int i = 0; i < 1; i++)
        {
            buf.push_back(i);
        }
        for (int i = 0; i < 1; i++)
        {
            buf.pop_front();
        }
    }
    catch (PushException &e)
    {
        cerr << e.what() << endl;
    }
    catch (PopException &e)
    {
        cerr << e.what() << endl;
    }
}