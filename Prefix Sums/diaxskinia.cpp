#include <iostream>
#include <string>

using namespace std;

int sums[1001][1001];
int questions[100000][4];

int main() {
  int n, m, k;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> sums[i][j];
    }
  }

  cin >> k;
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < 4; j++) {
      cin >> questions[i][j];
    }
  }

  for (int i = 0; i < n; i++) {
    sums[i][0] = 0;
    sums[0][i] = 0;
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      sums[i][j] += sums[i - 1][j] + sums[i][j - 1] - sums[i - 1][j - 1];
    }
  }
  int score = 0;
  for (int i = 0; i < k; i++) {
    int a = questions[i][0];
    int b = questions[i][1];
    int c = questions[i][2];
    int d = questions[i][3];
    score = max(score, sums[c][d] - sums[a - 1][d] - sums[c][b - 1] +
                           sums[a - 1][b - 1]);
  }
  cout << score;
}