#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,t,m;;
    cin>>n;
    vector<int> days(n+1);
    for(int i = 1; i <= n; i++){
        cin>>days[i];
    }
    sort(days.begin(),days.end());
    for(int i = 1; i<=n; i++){
        days[i]+=days[i-1];
    }
    cin>>t;
    for(int i = 0; i < t; i++){
        cin>>m;
        cout<<days[m]<<endl;
    }
}