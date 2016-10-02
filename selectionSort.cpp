#include <bits/stdc++.h>
using namespace std;

void selectionSort(int arr[], int n);

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++)
        cin >> arr[i];

    selectionSort(arr,n);
    return 0;
}

void selectionSort(int arr[], int n)
{
    for(int i=0; i<n-1; i++)
    {
        int Min = i;

        for(int j=i+1; j<n; j++)
        {
            if(arr[Min]>arr[j])
            {
                Min = j;
            }
        }

        if(Min != i)
        {
            int key = arr[i];
            arr[i] = arr[Min];
            arr[Min] = key ;
        }
    }
    for(int i=0; i<n; i++)
        cout << arr[i] <<" ";
    cout << endl;
}
