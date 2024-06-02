#include "progressBar.hpp"
void printProgressBar(int time)
{
    cout << endl;
    for (int m = 0; m < 31; m++)
    {
        string res = "\033[0;32m";
        for (int i = 0; i < m; i++)
        {
            res += "\26";
        }
        res += "\033[0m";
        for (int i = 0; i < 30 - m; i++)
        {
            res += "\26";
        }
        cout << res << "\r";
        sleep_for(milliseconds(time) / 30);
    }
}