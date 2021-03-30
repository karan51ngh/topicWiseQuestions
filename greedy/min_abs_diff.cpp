// https://www.hackerrank.com/challenges/minimum-absolute-difference-in-an-array/problem
#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;
int abs_diff(int a, int b)
{
    return a - b >= 0 ? a - b : b - a;
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    int min = INT_MAX;
    for (int i = 0; i <= n - 2; i++)
    {
        int x = abs_diff(arr[i], arr[i + 1]);
        if (min >= x)
        {
            min = x;
        }
    }
    cout << min << endl;
}