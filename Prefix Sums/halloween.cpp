#include <iostream>
#include <string>

using namespace std;

int sumOfR[1000000];
int questions[100000][2];

int main(){
    int n,t;
    cin>>t>>n;
    for(int i=1; i<=n;i++){
        cin>>sumOfR[i];
    }
    for(int i=0; i<t;i++){
        cin>>questions[i][0]>>questions[i][1];
    }
    sumOfR[0] = 0;
    for(int i=1; i <=n;i++){
            sumOfR[i]+=sumOfR[i-1];
    }

    for(int i = 0; i < t; i++){
        int result = sumOfR[questions[i][1]] - sumOfR[questions[i][0]-1];
        cout<<result<<endl;
    }
    
}