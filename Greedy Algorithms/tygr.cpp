#include <bits/stdc++.h>
#include <iostream>
#include <string>

using namespace std;

int weights[1000000];
int indexes[1000000];
int consumeLimits[1000000];

bool compare(int& a, int& b){
    return consumeLimits[a] < consumeLimits[b];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for(int i = 0; i < n;i++){
      cin>>weights[i]>>consumeLimits[i];
      consumeLimits[i]= weights[i]/consumeLimits[i];
      indexes[i]=i;
  }
  sort(indexes, indexes + n, compare);
  long long minWeight = -1;
  long long result=0;
  int i=0;
  for(int i = 0; i < n;i++){
      if(consumeLimits[indexes[i]]<minWeight){
          minWeight = min(minWeight,(long long)weights[indexes[i]]);

      }else{
          minWeight = weights[indexes[i]];
          result++;
      }
  }
  cout<<result<<endl;
}