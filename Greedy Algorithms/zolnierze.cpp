#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
  int n;
  cin>>n;
  vector<int> firstRow(n);
  vector<int> secondRow(n);
  for(int i = 0; i < n;i++){
      cin >> firstRow[i]>>secondRow[i];
  }
  sort(firstRow.begin(),firstRow.end());
  sort(secondRow.begin(),secondRow.end());
  int sum=0;
  for(int i = 0; i < n;i++){
      if(secondRow[i]<firstRow[i]){
          cout<<"NIE";
          return 0;
      }
      sum+=secondRow[i]-firstRow[i];
  }

  cout<<sum<<endl;
}