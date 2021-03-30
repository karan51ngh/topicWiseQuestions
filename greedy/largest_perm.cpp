// https://www.hackerrank.com/challenges/largest-permutation/problem
// not complete
#include <iostream>
#include <limits.h>
using namespace std;
void swap(long long *, long long *);
int main()
{
    long long n, k;
    cin >> n >> k;
    long long arr[n];
    for (long long i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (long long i = 0; i < k; i++)
    {
        long long max = INT_MIN;
        long long index;
        for (long long j = i; j < n; j++)
        {
            if (arr[j] > max)
            {
                max = arr[j];
                // cout << "max " << max << endl;
                index = j;
                // cout << "index " << index << endl;
            }
        }
        if (i == index)
        {
            if (k <= n - 1)
            {
                k++;
                continue;
            }
            else
            {
                break;
            }
        }
        swap(arr + i, arr + index);
    }
    for (long long i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void swap(long long *a, long long *b)
{
    long long t;
    t = *a;
    *a = *b;
    *b = t;
}