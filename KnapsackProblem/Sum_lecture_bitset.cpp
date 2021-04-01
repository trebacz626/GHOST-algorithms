#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main() {

//Kiedy nasza tablica składa się tylko z 0 i 1 i ma stałą wielkość to aby zwiekszyc
//wydajnosc pamieciowa do (n/32) oraz predkosc wykonywania operacji bitowych do O(n/32) mozemy uzyc bitseta
int szukana, rozmiar_zbioru;
cin >> szukana >> rozmiar_zbioru;
bitset<11> DP ;
DP.set(0,1);
//bitset <szukana> DP; Tak nie wolno !
int zbior[rozmiar_zbioru];
    for (int i = 0; i < rozmiar_zbioru; ++i) {
        cin >> zbior[i];
    }
    //kiedy analizujemy kolejna liczbe ze zbioru k, to wszystkie dotychczasowe jedynki przesuwają się o k w lewo no i oczywiscie nie zamieniaja sie w zera
    for (int i = 0; i < rozmiar_zbioru; ++i) {
        for (int j = 0; j < szukana+1; ++j) {
            cout << DP[j] << " ";
        }
        cout << endl;
        int k = zbior[i];
        DP |= (DP << k) ; // DP = DP | (DP << k)
    }
    for (int j = 0; j < szukana+1; ++j) {
        cout << DP[j] << " ";
    }
    cout << endl;
    cout << DP.test(rozmiar_zbioru);


}
