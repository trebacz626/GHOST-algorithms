#include <iostream>
#include <string>

using namespace std;

long long mod = 1000000000 + 696969;
long long pow(long long base, long long power) {
  if (power == 0)
    return 1;
  if (power % 2 == 0) {
    long long result = pow(base, power / 2);
    return (result * result) % mod;
  } else
    return (base * pow(base, power - 1)) % mod;
}

int main() {
  unsigned long long a, b, c, d;
  cin >> a >> b >> c >> d;
  unsigned long long ab = ((a % mod) * (b % mod)) % mod;
  unsigned long long cd = ((c % mod) * (d % mod)) % mod;
  unsigned long long cdinverse = pow(cd, mod - 2);
  cout << (ab * cdinverse) % mod << endl;
}
