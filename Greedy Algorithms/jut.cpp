#include <bits/stdc++.h>
#include <iostream>
#include <string>

using namespace std;


struct Assignment{
    long long length;
    long long deadline;
};
Assignment assignments[1000000];

bool compare(Assignment &a, Assignment &b) { return a.deadline < b.deadline; }

int main() {
  // READING DATA
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> assignments[i].length >> assignments[i].deadline;
  }
  sort(assignments, assignments + n, compare);
  long long sumLength = 0;
  long long minDistance = 9999999999;
  for(int i =0; i<n; i++){
      sumLength += assignments[i].length;
      minDistance=min(minDistance, assignments[i].deadline - sumLength);
  }
  cout << minDistance << endl;
}