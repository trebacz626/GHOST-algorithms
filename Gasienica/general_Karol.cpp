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

int x[IN];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    for(int i=0; i<n; ++i)
        cin >> x[i];
    int l=0, r=1;
    vi ans(n, n);
    while(r < n){
        if(abs(x[r] - x[l]) <= k){
            ++r;
        }
        else{
            ans[l] = r;
            ++l;
        }
    }
    for(int i=0; i<n; ++i)
        cout << ans[i] << " ";
    return 0;
}
