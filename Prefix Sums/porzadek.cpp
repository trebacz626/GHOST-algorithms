#include <iostream>
#include <string>

using namespace std;

int sumOfR[1000000];
int sumOfDeorderings[1000000];
int questions[100000][2];

int main(){
    int n,t;
    string seq;
    cin>>n;
    cin>>seq;
    cin>>t;
    for(int i=0; i<t;i++){
        cin>>questions[i][0]>>questions[i][1];
    }
    sumOfR[0] = 0;
    for(int i=1; i <=n;i++){
        int i_seq = i-1;
        if(seq[i_seq]=='R'){
            sumOfR[i]=sumOfR[i-1]+1;
            sumOfDeorderings[i]=sumOfDeorderings[i-1];
        }else{
            sumOfR[i]=sumOfR[i-1];
            sumOfDeorderings[i] = sumOfDeorderings[i-1]+sumOfR[i];
        }
    }

    for(int i = 0; i < t; i++){
        int length = questions[i][1]-questions[i][0]+1;
        int numberOfR = sumOfR[questions[i][1]]-sumOfR[questions[i][0]-1];
        int result = sumOfDeorderings[questions[i][1]] - sumOfDeorderings[questions[i][0]-1] - (length-numberOfR)*sumOfR[questions[i][0]-1];
        cout<<result<<endl;
    }
    
}