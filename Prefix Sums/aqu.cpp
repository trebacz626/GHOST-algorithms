#include <iostream>
#include <string>

using namespace std;

long long sums[2000][2000];
int questions[1000000][3];

int rX(int i, int j) { return i + j - 1; }

int rY(int i, int j, int n) { return -i + j + n; }

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, t;
  cin >> n >> t;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> sums[rX(i, j)][rY(i, j, n)];
    }
  }
  for (int i = 0; i < t; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> questions[i][j];
    }
  }

  for (int i = 1; i <= 2 * n - 1; i++) {
    for (int j = 1; j <= 2 * n - 1; j++) {
      sums[i][j] += sums[i - 1][j] + sums[i][j - 1] - sums[i - 1][j - 1];
    }
  }
  int score = 0;
  for (int i = 0; i < t; i++) {
    int x = questions[i][0];
    int y = questions[i][1];
    int l = questions[i][2];

    int rx = rX(x, y);
    int ry = rY(x, y, n);

    int a = max(rx - l, 1);
    int b = max(ry - l, 1);

    int c = min(rx + l, 2 * n - 1);
    int d = min(ry + l, 2 * n - 1);

    cout << sums[c][d] - sums[a - 1][d] - sums[c][b - 1] + sums[a - 1][b - 1]
         << endl;
  }
}