// https://www.hackerrank.com/challenges/marcs-cakewalk/problem?isFullScreen=true
#include <iostream>
#include <algorithm>
using namespace std;
int pow(int x)
{
    int prod = 1;
    for (int i = 0; i < x; i++)
    {
        prod *= 2;
    }
    return prod;
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
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += pow(i) * arr[n - i - 1];
    }
    cout << sum << endl;
}