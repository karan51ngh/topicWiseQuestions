// https://www.codechef.com/problems/CHEFRTU
#include <iostream>
using namespace std;
void swap(int *a, int *b)
{
    int t;
    t = *a;
    *a = *b;
    *b = t;
}
int shiftLeft(int *arr, int n)
{
    int base = -1;
}
int shiftRight(int *arr, int n)
{
    int base = n;
    int finder = n;
    int ctr = 0;
    while (base > 1)
    {
        if (arr[base - 1] % 2 == 0)
        {
            base -= 1;
            continue;
        }
        else
        {
            finder = base - 2; //add extra condition
            while (1)
            {
                if (arr[finder] % 2 == 0)
                {
                    break;
                }
                else
                {
                    --finder;
                }
            }
        }
    }

    return ctr;
}
int main()
{
    int T;
    cin >> T;
    while (T)
    {
        int N;
        int arr[N];
        cin >> N;
        for (int i = 0; i < N; i++)
        {
            cin >> N;
        }
        //check which side to swap(Left side or Right side, by comparing the number of even on left and even on right).
        int ctrR = 0;
        int ctrL = 0;
        for (int i = 0; i < N / 2; i++)
        {
            if (arr[i] % 2 == 0)
            {
                ctrL += 1;
            }
        }
        for (int i = N / 2; i < N; i++)
        {
            if (arr[i] % 2 == 0)
            {
                ctrR += 1;
            }
        }
        if (ctrL >= ctrR)
        {
            int x = shiftLeft(arr, N);
            cout << x;
        }
        else
        {
            int x = shiftRight(arr, N);
            cout << x;
        }

        --T;
    }
}