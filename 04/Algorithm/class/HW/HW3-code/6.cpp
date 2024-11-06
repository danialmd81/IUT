/*
Array A is assumed.
An algorithm with a dynamic programming approach to find the
indices s, r, q, p of this array with the condition s > r > q > p so
that the value of A[s]-A[r]+A[q]-A[p] is maximum.
*/

#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

int maxExpression(vector<int> &A)
{
    int max_s = INT_MIN;
    int max_r = INT_MIN;
    int max_q = INT_MIN;
    int max_p = INT_MIN;

    for (int i = 0; i < A.size(); i++)
    {
        max_s = max(max_s, A[i]);
        if (i > 0)
        {
            max_r = max(max_r, max_s - A[i]);
        }
        if (i > 1)
        {
            max_q = max(max_q, max_r + A[i]);
        }
        if (i > 2)
        {
            max_p = max(max_p, max_q - A[i]);
        }
    }

    return max_p;
}