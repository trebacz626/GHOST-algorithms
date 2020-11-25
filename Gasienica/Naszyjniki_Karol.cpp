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
    int n;
    cin >> n;
    string sam = "aeiouyAEIOUY"; // duze maja <91, ,male >91
    while(n--){
        string s;
        cin >> s;
        int jasnemax = 0, jasnemin = 1000001,  ciemnemax = 0, ciemnemin = 1000001;
        int JASNEMAX = 0, JASNEMIN = 1000001,  CIEMNEMAX = 0, CIEMNEMIN = 1000001;
        s += s;
        int len = s.length();
        string akt, tmp;
        if(sam.find(s[0]) < 12){
                if(s[0] < 91)
                    akt = "JASNE";
                else
                    akt = "jasne";
            }
        else{
            if(s[0] < 91)
                akt = "CIEMNE";
            else
                akt = "ciemne";
        }
        int i = 1, l = 0;
        while(i < len){
            if(sam.find(s[i]) < 12){
                if(s[i] < 91)
                    tmp = "JASNE";
                else
                    tmp = "jasne";
            }
            else{
                if(s[i] < 91)
                    tmp = "CIEMNE";
                else
                    tmp = "ciemne";
            }

            if(tmp == akt){
                ++i;
            }
            else{
                if(akt == "JASNE"){
                    JASNEMAX = max(JASNEMAX, i-l);
                    if(l != 0)
                        JASNEMIN = min(JASNEMIN, i-l);
                }
                if(akt == "jasne"){
                    jasnemax = max(jasnemax, i-l);
                    if(l != 0)
                        jasnemin = min(jasnemin, i-l);
                }
                if(akt == "ciemne"){
                    ciemnemax = max(ciemnemax, i-l);
                    if(l != 0)
                        ciemnemin = min(ciemnemin, i-l);
                }
                if(akt == "CIEMNE"){
                    CIEMNEMAX = max(CIEMNEMAX, i-l);
                    if(l != 0)
                        CIEMNEMIN = min(CIEMNEMIN, i-l);
                }
                l = i;
                akt = tmp;
                ++i;
            }
        }
        if(akt == "JASNE"){
                JASNEMAX = max(JASNEMAX, i-l);
        }
        if(akt == "jasne"){
                jasnemax = max(jasnemax, i-l);
        }
        if(akt == "ciemne"){
                ciemnemax = max(ciemnemax, i-l);
        }
        if(akt == "CIEMNE"){
                CIEMNEMAX = max(CIEMNEMAX, i-l);
        }
        pair <string, int> krotkie, dlugie;
        int x = max(jasnemax,max(JASNEMAX, max(ciemnemax, CIEMNEMAX)));
        int y = min(jasnemin,min(JASNEMIN, min(ciemnemin, CIEMNEMIN)));

        if(x == JASNEMAX){
            dlugie = make_pair("JASNE", JASNEMAX);
        }
        else if(x == CIEMNEMAX){
            dlugie = make_pair("CIEMNE", CIEMNEMAX);
        }
        else if(x == jasnemax){
            dlugie = make_pair("jasne", jasnemax);
        }
        else
            dlugie = make_pair("ciemne", ciemnemax);

        if(y == JASNEMIN){
            krotkie = make_pair("JASNE", JASNEMIN);
        }
        else if(y == CIEMNEMIN){
            krotkie = make_pair("CIEMNE", CIEMNEMIN);
        }
        else if(y == jasnemin){
            krotkie = make_pair("jasne", jasnemin);
        }
        else
            krotkie = make_pair("ciemne", ciemnemin);
        if(dlugie.S == len){
            dlugie.S /= 2;
            krotkie = dlugie;
        }
        cout << dlugie.S << " " << dlugie.F << endl;
        cout << krotkie.S << " " << krotkie.F << endl;
    }
    return 0;
}
