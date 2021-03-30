// https://www.hackerrank.com/challenges/candies/problem?isFullScreen=true
#include <iostream>
using namespace std;
int main()
{
    long long n;
    cin >> n;
    long long arr[n];
    long long can[n];
    for (long long i = 0; i < n; i++)
    {

        cin >> arr[i];
        can[i] = 1;
    }

    for (long long i = 0; i <= n - 2; i++)
    {
        if (arr[i + 1] > arr[i])
        {
            can[i + 1] = can[i] + 1;
        }
    }
    for (long long i = n - 1; i > 0; i--)
    {
        if (arr[i - 1] > arr[i])
        {
            if (can[i - 1] > can[i])
                continue;
            else
                can[i - 1] = can[i] + 1;
        }
    }
    long long sum = 0;
    for (long long i = 0; i < n; i++)
    {
        sum += can[i];
    }
    cout << sum << endl;
}