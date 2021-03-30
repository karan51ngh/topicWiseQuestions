// https://www.hackerrank.com/challenges/priyanka-and-toys/problem?isFullScreen=true
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    int ctr = 0;
    cin >> n;
    int w[n];
    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
    }
    sort(w, w + n);
    // cout << "sorted";

    int itr = 0;
    while (1)
    {
        int x = itr;
        while (w[itr] <= w[x] + 4)
        {
            itr = itr + 1;
            if (itr == n)
            {
                break;
            }
        }
        ctr += 1;
        if (itr == n)
        {
            break;
        }
    }
    cout << ctr << endl;
}
