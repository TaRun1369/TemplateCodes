#include<bits/stdc++.h>
using namespace std;
void prlong longDivisors(long long n){
    for(long long i = 1;i*i<=n;i++){
        if(n%i==0){
            cout<<i<<endl;
            if(i != n/i)
            cout<<n/i<<endl;
        }
    }
}

long long main(){
    long long n;
    cin>>n;
    prlong longDivisors(n);
    return 0;
}