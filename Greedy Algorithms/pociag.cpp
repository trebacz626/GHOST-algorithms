#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
  int n;
  string train;
  cin >> n >> train;
  int curChar = 0;
  int curCharStart = -1;
  int needsPainting = 0;
  for (int i = 0; i < n; i++) {
    if (train[i] != curChar) {
      needsPainting += (i - curCharStart) / 3;
      curChar = train[i];
      curCharStart = i;
    }
  }
  needsPainting += (n - curCharStart) / 3;
  cout << needsPainting << endl;
}