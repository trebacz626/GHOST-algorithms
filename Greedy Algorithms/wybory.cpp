#include <bits/stdc++.h>
#include <iostream>

using namespace std;

struct State{
    int population;
    int costOfVote;
};

int main() {
  int n,k;
  cin>>n>>k;
  vector<State> states(n,{0,0});
  for(int i=0;i<n;i++){
      cin>>states[i].population;
  }
  for(int i=0;i<n;i++){
      cin>>states[i].costOfVote;
  }
  vector<int> victoryCost(n,0);
  for(int i=0;i<n;i++){
      victoryCost[i] = (states[i].population/2+1)*states[i].costOfVote;
  };
  sort(victoryCost.begin(),victoryCost.end());
  for(int i=0;i<n;i++){
      if(k<victoryCost[i]){
          cout<< i<<endl;
          return 0;
      }
      k-=victoryCost[i];
  }
  cout<<n<<endl;
}