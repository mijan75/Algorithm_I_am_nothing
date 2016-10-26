#include <bits/stdc++.h>
using namespace std;

void max_heapify(int arr[], int i, int n);
void build_maxheap(int arr[], int n);

int main(){
    int n;
    cin >>n;
    int arr[n];
    for(int i=1; i<=n; i++)
        cin >> arr[i];
    build_maxheap(arr,n);
    for(int i=n; i>=2; i--){
        swap(arr[i],arr[1]);
        max_heapify(arr, 1, i-1);
    }
    for(int i=1; i<=n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void build_maxheap(int arr[], int n){
    for(int i=n/2; i>=1; i--)
        max_heapify(arr,i,n);
}

void max_heapify(int arr[], int i, int n){
    int j, temp;
    temp = arr[i];
    j = 2*i;
    while(j<=n){
        if(j<n && arr[j+1] > arr[j])
            j = j + 1;
        if(temp > arr[j])
            break;
        else if(temp <=arr[j])
            arr[j/2] = arr[j];
            j = j * 2;
    }
    arr[j/2] = temp;
    return;
}
