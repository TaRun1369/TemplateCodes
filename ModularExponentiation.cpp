#include<bits/stdc++.h>
using namespace std;

long long modular(long long no,long long power,long long mod){

    if(power<=1 ) return no%mod;

    long long res = modular(no,power/2,mod)%mod;

    res = (res*res)%mod;
    if(power%2 != 0){
        res = ((res%mod)*(no%mod))%mod;

    }

    return res%mod;
}

long long main(){
    long long n;
    cin>>n;
    cout<<modular(2,n,100000);
}