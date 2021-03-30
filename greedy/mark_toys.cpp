// https://www.hackerrank.com/challenges/mark-and-toys/problem?isFullScreen=true
#include <bits/stdc++.h>
#include <limits.h>
using namespace std;
long long Min(long long *arr, long long n)
{
    long long x = LLONG_MAX;
    long long index;
    for (long long i = 0; i < n; i++)
    {
        if (arr[i] <= x)
        {
            x = arr[i];
            index = i;
        }
    }
    *(arr + index) = LLONG_MAX;
    return x;
}

int main()
{
    long long n, k, ctr = 0;
    cin >> n;
    cin >> k;
    long long arr[n];
    for (long long i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    long long x = 1;
    while (x)
    {
        long long min = Min(arr, n);
        if (k > min)
        {
            k -= min;
            ctr += 1;
        }
        else
        {
            break;
        }
    }
    cout << ctr << endl;
}