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

bool key(pi a, pi b){
    return a.S < b.S;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector <pi> tygrysy(n);
    for(int i=0; i<n; ++i){
        int a, k;
        cin >> a >> k;
        tygrysy[i] = make_pair(a,a/k);
    }
    sort(tygrysy.begin(), tygrysy.end(), key);
   // for(auto u: tygrysy){
   //     cout << u.F << " " << u.S << endl;
   // }
    int ans = 1;
    int smallest = tygrysy[0].F;

    for(int i=1; i<n; ++i){
        if(tygrysy[i].S >= smallest){
            ++ans;
            smallest = tygrysy[i].F;
            continue;
        }
        smallest = min(smallest, tygrysy[i].F);
    }
    cout << ans;
    return 0;
}
