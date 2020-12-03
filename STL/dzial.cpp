#include <bits/stdc++.h>
#include <iostream>
#include <string>

using namespace std;

int land[2001][2001];

int main() {
  // READING DATA

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> land[i][j];
      land[i][j] = (land[i][j] == 0) ? 1 : 0;
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (land[i][j] == 1) {
        land[i][j] = land[i - 1][j] + 1;
      } else {
        land[i][j] = 0;
      }
    }
  }

  int maxArea = 0;
  for (int i = 1; i <= n; i++) {
    stack<pair<int, int>> previousHeights;
    for (int j = 1; j <= n; j++) {
      if (previousHeights.empty() ||
          land[i][j] > previousHeights.top().second) {
        previousHeights.push(make_pair(j, land[i][j]));
      } else if (land[i][j] < previousHeights.top().second) {
        pair<int, int> lastTaken;
        while ((!previousHeights.empty()) &&
               land[i][j] < previousHeights.top().second) {
          lastTaken = previousHeights.top();
          previousHeights.pop();
          maxArea = max(maxArea, lastTaken.second * (j - lastTaken.first));
        }
        lastTaken.second = land[i][j];
        previousHeights.push(lastTaken);
      }
    }

    while (!previousHeights.empty()) {
      pair<int, int> leftower = previousHeights.top();
      previousHeights.pop();
      maxArea = max(maxArea, (n - leftower.first + 1) * leftower.second);
    }
  }
  cout << maxArea << endl;
}