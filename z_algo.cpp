/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

vector<ll> z_algo(string str){
    ll len = str.size();
    ll l = 0,r = 0;
    vector<ll> z(len);
    for(ll i = 1;i < len;i++){
        if(i > r){
            // cout<<"i - "<<i<<"  yaha"<<endl;
            l = r = i;
            while(r < len and str[r] == str[r - l]){
                r++;
            }
            z[i] = r - l;
            r--;
        }
        else{
            ll idx = i - l;
            if(i + z[idx] <= r)
                z[i] = z[idx];
            else{
                l = i;
                while(r < len and str[r] == str[r - l]){
                    r++;
                }
                z[i] = r - l;
                r--;
            }
        }
    }
    return z;
}
int main()
{
    string s;
    cin>>s;
    string pat;
    cin>>pat;
    // auto z = z_algo(s);
    // for(auto it : z){
    //     cout<<it<<" ";
    // }
    
    // for pattern finding 
    string temp = pat + "$" + s;
    auto zt = z_algo(temp);
    for(int i = 0;i<zt.size();i++){
        if(zt[i] >= pat.size()){
            cout<<i - pat.size() - 1<<endl;
        }
        
    }   
}