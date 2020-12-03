#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;
int days[1000000];
multiset<int> colors;
int main(){
    //READING DATA
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,k;
    if(k<n){
        cout<<"NIE";
        return 0;
    }
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>days[i];
    }
    for(int i=0;i<k;i++){
        int temp;
        cin>>temp;
        colors.insert(temp);
    }
    sort(days,days+n);
    int numberOfColors = 0;
    for(int i=n-1;i>=0;i--){
        multiset<int>::iterator iter1=colors.lower_bound(days[i]*5);
        if(iter1 != colors.end()){
            numberOfColors++;
            colors.erase(iter1);
            continue;
        }
        multiset<int>::iterator iter2=colors.lower_bound(days[i]*3);
        if(iter2 == colors.end()){
            cout<<"NIE";
            return 0;
        }
        colors.erase(iter2);
        multiset<int>::iterator iter3=colors.lower_bound(days[i]*2);
        if(iter3 == colors.end()){
            cout<<"NIE";
            return 0;
        }
        colors.erase(iter3);
        numberOfColors+=2;
    }
    cout<<numberOfColors;
    
}