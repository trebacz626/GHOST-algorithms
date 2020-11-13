#include <iostream>
#include <string>

using namespace std;

bool was[1000001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,p, temp, q;
    cin >> n;
    int sum = 0;
    was[0] = true;
    for (int i = 0; i < n; i++){
        cin >>temp;
        sum+=temp;
        was[sum]=true;
    }
    cin>>p;
    for (int i = 0; i <p; i++){
        cin >>q;
        if(was[q]){
            cout<<"TAK"<<endl;
        }else{
            cout<<"NIE"<<endl;
        }
    }
}