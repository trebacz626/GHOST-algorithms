#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define PB emplace_back
#define ALL(x) (x).begin(),(x).end()
#define endl '\n'

using ll = long long;
using ld = long double;
using vi = vector<int>;
using vll = vector<ll>;
using pi = pair<int,int>;
using pll = pair<ll,ll>;

constexpr int IN = 1000005;
constexpr int INF = 1e9+5;
constexpr int INI = -1;


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, m;
    cin >> n >> m;
    vll a(n);
    for(int i=0; i<n; ++i)
        cin >> a[i];

    ll l=-1, r=0;
    ll ans = 0;
    while(r<n){
        if(a[r] >= m)
            l = r;
        ans += l+1;
        ++r;
    }
    cout << ans;
    return 0;
}
