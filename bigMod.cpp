#include <bits/stdc++.h>
using namespace std;

int big_mod(int base, int power, int mod);

int main(){
    int base, power, mod;

    while(cin >> base >> power >> mod){
        cout << big_mod(base, power, mod);
    }
    return 0;
}

int big_mod(int base, int power, int mod){
    if(power==0) return 1;
    
    if(power % 2 == 1){
        int p1 = base % mod;
        int p2 = (big_mod(base, power-1, mod)) % mod;
        return (p1*p2)%mod;
    }
    else{
        int p1 = (big_mod(base, power/2, mod)) % mod;
        return (p1*p1) % mod;
    }
}

