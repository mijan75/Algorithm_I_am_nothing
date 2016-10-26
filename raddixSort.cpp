#include <bits/stdc++.h>
using namespace std;

void raddix(int *arr, int n);
void Count(int *arr, int n, int exp);

int main(){
    int n;
    cin >>n;
    int arr[n];
    for(int i=0; i<n; i++)
        cin >> arr[i];
    raddix(arr, n);
    for(int i=0; i<n; i++)
        cout << arr[i]<<" ";
    cout << endl;
}

void raddix(int *arr, int n){
    int m = *max_element(arr, arr+n);
    for(int exp=1; m/exp>0; exp = exp * 10)
        Count(arr,n,exp);
}

void Count(int *arr, int n, int exp){
    int output[n],coun[10]={0};
    for(int i=0; i<n; i++)
        coun[(arr[i]/exp)%10] = coun[(arr[i]/exp)%10] + 1;
    for(int i=1; i<10; i++)
        coun[i] = coun[i] + coun[i-1];
    for(int i=n-1; i>=0; i--){
        output[coun[(arr[i]/exp)%10]-1] =  arr[i];
        coun[(arr[i]/exp)%10] = coun[(arr[i]/exp)%10] - 1;
    }
    for(int i=0; i<n; i++)
        arr[i] = output[i];
}
