#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[], int n);

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++)
        cin >> arr[i];

    bubbleSort(arr,n);
    return 0;
}

void bubbleSort(int arr[], int n)
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(arr[i]>arr[j])
            {
                int key = arr[i];
                arr[i] = arr[j];
                arr[j] = key;
            }
        }
    }
    for(int i=0; i<n; i++)
        cout << arr[i] <<" ";
    cout << endl;
}
