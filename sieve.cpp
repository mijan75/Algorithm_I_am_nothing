#include <bits/stdc++.h>
using namespace std;

bool arr[2000000000];

int main()
{
    int n;
    cin >> n;
    for(int i=3; i*i<=n; i=i+2)
    {
        for(int j=i+i; j<=n; j=j+i)
            arr[j] = 1;
    }
    cout <<"2"<<" ";

    for(int i=3; i<=n; i++)
    {
        if(arr[i] == 0 && i%2 != 0)
            cout <<i<<" ";
    }
    cout << endl;
    return 0;
}
