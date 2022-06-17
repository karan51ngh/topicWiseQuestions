#include<bits/stdc++.h>
using namespace std;

int f2(string x)
{
    if(x[0] == '1')
        return 1;
    if(x[0] == '2')
    {
        if(x[1] >= '0' && x[1] <= '6')
            return 1;
    }

    return 0;
}

int f(string str)
{
    int n = str.size();
    str.insert(0," ");

    // cout << str << endl;
    // cout << n<< endl;
    vector<int> O(n+1);
    vector<int> T(n+1);

    O[0] = 1; // special case;
    T[0] = 0; // special case;
    O[1] = 1; 
    T[1] = 0;

    for(int i=2; i <= n; i++)
    {
        if(str[i] != '0')
            O[i] = O[i-1] + T[i-1];
        else
            O[i] = 0;

        if(f2(str.substr(i-1,i)))
            T[i] = O[i-2] +T[i-2];
        else
            T[i] = 0;
    }

    // for(int i=0;i<=n;i++)
    // {
    //     cout << O[i] << " ";
    // }
    // cout << endl;
    // for(int i=0;i<=n;i++)
    // {
    //     cout << T[i] << " ";
    // }
    // cout << endl;

    return O[n] + T[n];
}

int main()
{
    string str;
    cin >> str;
    cout << f(str) << endl;
    // cout <<str.substr(1,2) << endl;
}