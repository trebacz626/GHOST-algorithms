#include <iostream>
#include <string>

using namespace std;

int a[1000001];
int b[1000001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m,z;
    cin >> n >> m;
    for(int i = 1; i <=n; i++){
        cin >>a[i];
        a[i]+=a[i-1];
    }
    for(int i = 1; i <=m; i++){
        cin >>b[i];
        b[i]+=b[i-1];
    }
    cin >> z;
    for(int i = 1; i <=z; i++){
        int day,month;
        char c;
        cin>>day>>month>>c;
        if( c =='A'){
            int daySum = a[month-1]+day;
            int beg=1, end= m,s;
            while(beg < end){
                s = (beg+end)/2;
                if(daySum <= b[s]){
                    end = s;
                }else{
                    beg = s+1;
                }
            }
            int newMonth = beg;
            int newDay = daySum-b[newMonth-1];
            cout<<newDay<<" "<<newMonth<<endl;
        }else{
            int daySum = b[month-1]+day;
            int beg=1, end= n,s;
            while(beg < end){
                s = (beg+end)/2;
                if(daySum <= a[s]){
                    end = s;
                }else{
                    beg = s+1;
                }
            }
            int newMonth = beg;
            int newDay = daySum-a[newMonth-1];
            cout<<newDay<<" "<<newMonth<<endl;
        }
    }
}