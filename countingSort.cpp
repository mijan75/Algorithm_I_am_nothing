#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout << "Enter the number of element you want to sort" << endl;
    cin >> n;
    cout << "*****************" << endl;
    cout << "Some constrains for this sort" <<endl;
    cout << "The highest number must be lesser than the number of element of the array " << endl;
    cout << "You can only insert non negative integer value " << endl;
    cout << "*****************"<< endl;
    int number=0;
    int a[n];
    int b[n];
    int c[n];
    int Count = 0;
    for(int i=0; ; i++){
        cin >> number;
        if(number < n && number>-1){
            a[Count] = number;
            Count++;
            //cout << Count << " ";
        }
        if(Count == n) break;
        if(number >= n || n <0){
            cout << "Your number is larger then or equal to the number of element element of the array or a negative number"<< endl;
            cout << "Please input another one" << endl;
        }
    }
    for(int i=0; i<n; i++)
        b[i] = 0;
    for(int i=0; i<n; i++)
        b[a[i]] = b[a[i]] + 1;
    for(int i=1; i<n; i++)
        b[i] = b[i] + b[i-1];
    for(int i=n-1; i>=0; i--){
        c[b[a[i]]-1] = a[i];
        b[a[i]] = b[a[i]] - 1;
    }
    cout << "Here is your sorted array" << endl;
    for(int i=0; i<n; i++)
        cout << c[i] <<" ";
    cout << endl;

}
