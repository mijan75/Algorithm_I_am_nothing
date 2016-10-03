#include <bits/stdc++.h>
using namespace std;

void Merge(int arr[],int low,int high,int n);
void mergeSort(int arr[],int low,int mid,int high,int n);

int main()
{
    int n;
    cin >>n;
    int arr[n];
    for(int i=0; i<n; i++)
        cin >> arr[i];
    Merge(arr,0,n-1,n);
    for(int i=0; i<n; i++)
        cout << arr[i] << " ";
    return 0;
}

void Merge(int arr[], int low, int high,int n)
{
    int mid=0;
    if(low<high){
         mid=(low+high)/2;
         Merge(arr,low,mid,n);
         Merge(arr,mid+1,high,n);
         mergeSort(arr,low,mid,high,n);
    }
}

void mergeSort(int arr[],int low,int mid,int high,int n)
{
    int i=low, j=mid+1, k=low,temp[n];
    while(i<=mid && j<=high)
    {
        if(arr[i]<=arr[j])
        {
            temp[k] = arr[i];
            i++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }
    while(i<=mid)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }
    while(j<=high)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }
    for(int i=low; i<=high; i++)
    {
        arr[i] = temp[i];
    }
}

