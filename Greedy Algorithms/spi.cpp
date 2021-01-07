#include <bits/stdc++.h>
#include <iostream>
#include <string>

using namespace std;

bool place[1000002];
int main() {
  // READING DATA

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    char temp;
    cin >> temp;
    place[i] = (temp == 'Z');
  }
  bool lastHas = false;
  int result = 0;
  for (int i = 1; i <= n; i++) {
      if(place[i]){
          if(!lastHas){
              if(place[i-1]){
                  result++;
                  lastHas=true;
                  place[i+1]=0;
              }else if(!place[i+1]){
                  result++;
                  lastHas=true;
                  place[i+1]=0;
              }
          }else{
              lastHas=false;
          }
      }else{
          lastHas = false;
      }
  }
  cout<<result<<endl;
}