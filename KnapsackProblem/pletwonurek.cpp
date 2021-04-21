#include <iostream>

using namespace std;
int main() {
    int t, a;
    cin >> t >> a;
    int  butle ;
    cin >> butle;
    int sumaTlen = 0;
    int sumaAzot = 0;
    //int sumaWag = 0;
    int waga[butle], tlen[butle], azot[butle];
    for (int i = 0; i < butle; ++i) {
        cin >> tlen[i] >> azot[i] >> waga[i];
        sumaTlen += tlen[i];
        sumaAzot += azot[i];
        //sumaWag += waga[i];
    }
//
//    //PODEJSCIE 1
//    int DP[sumaTlen+1][sumaAzot+1]; //najmniejsza waga butli aby zdobyć tyle tlenu i tyle azotu
//    //int DP2[sumaWag+1]; //Najwieksza liczba tlenu i azotu jaka moge wziasc dla danej masy
//    for (int i = 0; i <= sumaTlen; ++i) {
//        for (int j = 0; j <= sumaAzot; ++j) {
//            DP[i][j] = 1000* 801;
//        }
//    }
//    DP[0][0] = 0; // nie potrzebujemy zadnej butli
//    int ans = 1001;
//    for (int i = 0; i < butle ; ++i) {
//        for (int j = sumaTlen-tlen[i]; j >=0 ; --j) {
//            for (int k = sumaAzot - azot[i]; k >=0; --k) {
//                if (DP[j][k] < 1000){
//                    //cout << ans << endl;
//
//                    DP[j+tlen[i]][k+azot[i]] = min(DP[j+tlen[i]][k+azot[i]], DP[j][k] + waga[i]);
//                    //cout <<  DP[j+tlen[i]][k+azot[i]] << endl;
//                    if (j+tlen[i] >= t && k+azot[i] >= a) ans = min(ans,DP[j+tlen[i]][k+azot[i]] );
//                }
//            }
//        }
//    }
//    cout << ans;
//
//OPTYMALIZACJA 1

    int DP[t+1][a+1]; // nie mamy teraz wszystkich mozliwych mas ale mozemy uznaz ze DP[t][a] oznacza ze jest minimum tyle ile potrzebujemy

    for (int i = 0; i <= t; ++i) {
        for (int j = 0; j <= a; ++j) {
            DP[i][j] = 1000 * 801;
        }
    }
//    DP[0][0] = 0;
//        for (int i = 0; i < butle ; ++i) {
//        for (int j = t; j >=0 ; --j) {
//            for (int k = a; k >=0; --k) {
//                if(j+tlen[i] >= t && k+azot[i] >= a) DP[t][a] = min(DP[t][a], DP[j][k] + waga[i]);
//                else if(j+tlen[i] >= t) DP[t][k+azot[i]] = min(DP[t][k+azot[i]], DP[j][k] + waga[i]);
//                else if( k+azot[i] >= a) DP[j+tlen[i]][a] = min(DP[j+tlen[i]][a], DP[j][k] + waga[i]);
//                else    DP[j+tlen[i]][k+azot[i]] = min(DP[j+tlen[i]][k+azot[i]], DP[j][k] + waga[i]);
//                }
//            }
//        }
//
//    cout << DP[t][a];


// OPTYMALIZACJA 2

    DP[0][0] = 0;
    for (int i = 0; i < butle ; ++i) {
        for (int j = t; j >=0 ; --j) {
            for (int k = a; k >=0; --k) {
                int mozliwyTlen = min(t, j+tlen[i]); // jesli moja aktualnie rozpatrywana zawartosc tlenu przekroczy potrzebna
                //to uznam ze aktualnie rozpatrywana zawartosc tlenu to ta potrzebna
                int mozliwyAzot = min(a, k +azot[i]);
                DP[mozliwyTlen][mozliwyAzot] = min(DP[mozliwyTlen][mozliwyAzot], DP[j][k] + waga[i]);
            }
        }
    }

    cout << DP[t][a];
    return 0;
}
