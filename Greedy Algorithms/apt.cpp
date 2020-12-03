#include <bits/stdc++.h>
#include <iostream>
#include <string>

using namespace std;

int costs[1000000];
int indexes[1000000];

bool compare(int &a, int &b) { return costs[a] < costs[b]; }

int main() {
  // READING DATA

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> costs[i];
    indexes[i] = i;
  }
  sort(indexes, indexes + n, compare);
  long long curPos = -1;
  long long totalCost = 0;
  for (int i = 0; i < n; i++) {
    if (indexes[i] > curPos) {
      totalCost += (indexes[i] - curPos) * costs[indexes[i]];
      curPos = indexes[i];
    }
  }
  cout << totalCost << endl;
}