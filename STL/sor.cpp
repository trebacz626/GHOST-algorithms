#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

bool comparator(const string&a, const string&b){
    if( a.length() != b.length()){
        return a.length() < b.length();
    }
    return a < b;
}

string chains[150];
int main(){
    //READING DATA
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>chains[i];
    }
    sort(chains, chains+n, comparator);
    for(int i=0;i<n;i++){
        cout<<chains[i]<<endl;
    }
}