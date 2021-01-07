#include <bits/stdc++.h>
#include <iostream>

using namespace std;

struct State {
  int population;
  int costOfVote;
};

int main() {
  int n;
  int minX = 200;
  int maxX = 0;
  int minY = 200;
  int maxY = 0;
  int x, y;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    minX = min(minX, x);
    maxX = max(maxX, x);
    minY = min(minY, y);
    maxY = max(maxY, y);
  }
  cout << max(1,(maxX - minX)) * max(1,(maxY - minY)) << endl;
}