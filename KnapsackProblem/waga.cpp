#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, l, p; //n to liczba cegielek na kazdej wiezy
    cin >> n >> l >> p;
    //l to liczba wiez na lewej szalce
    //p to liczba wiez na prawej szalce

    int max_ = 25 * 50 * 50 * 2 ; //maksymalnie wieza moze skladac z 50 cegielek
    //int max = 50;
    //i maksymalnie moze byc 25 wiez i hipotetycznie moze miec maksymalnie wartosc 50 wiec razem z ujemnymi * 2
    int maksymalna_liczba_cegielek = 50*25 + 1;
    //int maksymalna_liczba_cegielek = 50;

    int DP[max_];
    int DPR[max_];

    //int DPR[n+1][max];


    for (int i = 0; i < max_; ++i) {
        DP[i] = maksymalna_liczba_cegielek;
        DPR[i] = maksymalna_liczba_cegielek;
    }

    int zero = max_/2; // waga 0
    //int zero = 0;
    //cout << zero << endl;


    int lewa[n][l] ; //lewa szalka
    int sumaLewa = 0;
    int prawa[n][p] ; // prawa szalka
    int sumaPrawa = 0;

    for (int i = 0; i < l; ++i) {
        for (int j = n-1 ; j > -1; --j) {
            cin >> lewa[j][i] ;
            sumaLewa += lewa[j][i];
        }
    }
    for (int i = 0; i < p; ++i) {
        for (int j = n-1; j > -1; --j) {
            cin >> prawa[j][i] ;
            sumaPrawa += prawa[j][i];
        }
    }

    DP[zero + sumaLewa] = 0; // aby otrzymac taka sume na lewej szalce potrzebuje 0 ruchow
    DPR[zero + sumaPrawa] = 0; // aby otrzymac taka sume na prawej szalce potrzebuje 0 ruchow

//    cout << "Suma lewej: " << sumaLewa  <<endl << "Suma prawej: " << sumaPrawa << endl;
//
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < l; ++j) {
//            cout << lewa[i][j] << " " ;
//
//        }
//        cout << endl;
//    }
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < p; ++j) {
//            cout << prawa[i][j] << " ";
//        }
//        cout << endl;
//    }

    //iterujemy sie po wszystkich wieżach
    for (int j = 0; j < l; ++j) {
        queue <int> do_dodania;
        int DP_kolumny[max_] ;

        for (int i = 0; i < max_; ++i) {
            DP_kolumny[i] = maksymalna_liczba_cegielek;
        }
        //DP_kolumny[zero + sumaLewa] = 0;
        //int temp_sum = 0 ;
        //iterujemy sie po poziomie kazdej wieży
        for (int i = 0; i < n; ++i) {
            int key = lewa[i][j];
            //cout << "Aktualnie rozwazany klocek! " <<key << endl;
            //jesli zdejmujemy pierwsza cegielke to mozemy zaaktualizować wszystko co do tej pory w DP
            if( i == 0){
//                if (j == 2) {
//                    for (int z = 0; z < max_; ++z) {
//                        if(DP[z] < maksymalna_liczba_cegielek) {
//                            cout << "Moge stworzyc " << z - zero << " Uzywajac " << DP[z] << " klockow\n";
//                        }
//                    }
//                    cout <<endl;
//                }
                //cout << "Zciagam pierwszy element!\n";
                if (key < 0) {
                    for (int k = max_ - 1; k >= 0; --k) {
                        if (DP[k] < maksymalna_liczba_cegielek) {
                            //cout << "moge stworzyc " << k - zero - key << endl;
                            DP[k - key] = min(DP[k - key], DP[k] + 1); //za pierwszym obrotem aktualizuje ogolnego DP
                            DP_kolumny[k-key] = DP[k] + 1; // Zdejmujac kolejne elementy nie bede mogl wykorzystac minimalnego DP a tego ktory dostane z zabrania tej szufladki
                            do_dodania.push(k - key); //w kolejnej iteracji bede mogl otrzymac DP tylko poprzed zdjecie kolejnej cegielki z danej kolumny
                        }
                    }

                }
                else {
                    for (int k = 0; k < max_; ++k){
                        //if(DPL[k] < maksymalna_liczba_cegielek) cout << k - zero << " ";
                        if (DP[k] < maksymalna_liczba_cegielek) {
                            //cout << "moge stworzyc " << k - zero -key << endl;
                            DP[k - key] = min(DP[k - key], DP[k] + 1);
                            DP_kolumny[k-key] =  DP[k] + 1; //dodaje nie wartosc ogolna tylko taka wartosc jaka dostane po zdjeciu tego klocka
                            do_dodania.push(k - key);
                        }
                    }
//                    if (j == 2)
//                    for (int z = 0; z < max_; ++z) {
//                        if(DP[z] < maksymalna_liczba_cegielek) {
//                            cout << "Moge stworzyc " << z - zero << " Uzywajac " << DP[z] << " klockow\n";
//                        }
//                    }
//                    cout <<endl;
                }
            }
            else{
                //kiedy zdejmuje ktoras cegielke
                int rozmiar_kolejki = do_dodania.size(); // po kolei bede zdejmowal wszystkie cegielki z kolejki

                for (int k = 0; k < rozmiar_kolejki; ++k) {
                    int possible = do_dodania.front(); // biore dowolna cegielke tutaj kolejnosc nie ma znaczenia
                    //if (j == 2) cout << "moge stworzyc " << possible - zero  << " Uzywajac " << DP_kolumny[possible] << " klockow" <<endl;
                    //cout << "moge stworzyc " << possible - zero - key << endl;
                    //jesli jakims cudem dostalem ponownie taka sama wage to probuje zaaktualizowac ogolnego DP
                    if (DP_kolumny[possible - key] < DP_kolumny[possible] +1)
                        DP[possible - key] = min(DP_kolumny[possible - key], DP[possible - key]);

                    //aktualizuje kolumnowego DP b
                    DP_kolumny[possible - key] = DP_kolumny[possible] +1;
                    do_dodania.pop();
                    //wrzucam do kolejki kolejne elementy ktore moge dostac tylko usuwajac k pierwszych wierszy z danej kolumny
                    do_dodania.push(possible - key);
                }
            }


            // cout << endl;
            //temp_sum += key;
        }
        for (int i = 0; i < max_; ++i) {
            //moze sie okazac ze niektore elementy moglem uzyskac tylko w jakis unikatowy sposob i dlatego bedzie to mniejsze od aktualnej wartosci DP
            DP[i] = min(DP_kolumny[i], DP[i]);
        }
//        if (j == 2) {
//            for (int z = 0; z < max_; ++z) {
//                if(DP[z] < maksymalna_liczba_cegielek) {
//                    cout <<"Moge stworzyc " << z - zero << " Uzywajac " << DP[z] << " klockow\n";
//                }
//            }cout <<endl;
//        }
    }

//Identyczna procedurę powtarzamy dla prawej wieży
    for (int j = 0; j < p; ++j) {
        queue <int> do_dodania;
        int DP_kolumny[max_] ;

        for (int i = 0; i < max_; ++i) {
            DP_kolumny[i] = maksymalna_liczba_cegielek;
        }
        //DP_kolumny[zero + sumaPrawa] = 0;
        //int temp_sum = 0 ;
        //iterujemy sie po poziomie kazdej wieży
        for (int i = 0; i < n; ++i) {
            //jesli zdejmujemy pierwsza cegielke to mozemy zaaktualizować wszystko co do tej pory w DP
            int key = prawa[i][j];
            //cout << "Aktualnie rozwazany klocek! " <<key << endl;
            if( i == 0){
                //cout << "Zciagam pierwszy element!\n";
                if (key < 0) {

                    for (int k = max_ - 1; k >= 0; --k) {
                        if (DPR[k] < maksymalna_liczba_cegielek) {
                            //cout << "moge stworzyc " << k - zero - key << endl;
                            DPR[k - key] = min(DPR[k - key], DPR[k] + 1);
                            DP_kolumny[k-key] = DPR[k] + 1;
                            do_dodania.push(k - key);
                        }
                    }

                }
                else {
                    for (int k = 0; k < max_; ++k){
                        //if(DPL[k] < maksymalna_liczba_cegielek) cout << k - zero << " ";
                        if (DPR[k] < maksymalna_liczba_cegielek) {
                            //cout << "moge stworzyc " << k - zero -key << endl;
                            DPR[k - key] = min(DPR[k - key], DPR[k] + 1);
                            DP_kolumny[k-key] =  DPR[k] + 1;
                            do_dodania.push(k - key);
                        }
                    }
                }
            }
            else{
                int rozmiar_kolejki = do_dodania.size();
                for (int k = 0; k < rozmiar_kolejki; ++k) {
                    int possible = do_dodania.front();
                    //cout << "moge stworzyc " << possible - zero - key << endl;
                    //jesli juz ktorys raz dostaje ta sama wartosc w jednej kolumnie no to probuje zaaktualizowac calkowicie DP
                    if (DP_kolumny[possible - key] < DP_kolumny[possible] +1)
                        DPR[possible - key] = min(DP_kolumny[possible - key], DPR[possible - key]);

                    DP_kolumny[possible - key] = DP_kolumny[possible] +1;
                    do_dodania.pop();
                    do_dodania.push(possible - key);
                }
            }


            // cout << endl;
            //temp_sum += key;
        }
        for (int i = 0; i < max_; ++i) {
            DPR[i] = min(DP_kolumny[i], DPR[i]);
        }
    }

//    cout << "Podsumowanie \n";
//    for (int i = 0; i < max_; ++i) {
//            if(DP[i] < maksymalna_liczba_cegielek) {
//                cout << "Moge stworzyc " << i - zero << " Uzywajac " << DP[i] << " klockow\n";
//            }
//    }
//    cout << endl;
//    cout << "Dla prawej wiezy!\n";
//    for (int i = 0; i < max_; ++i) {
//        if(DPR[i] < maksymalna_liczba_cegielek) {
//            cout << "Moge stworzyc " << i - zero << " Uzywajac " << DPR[i] << " klockow\n";
//        }
//    }
//    cout << endl;
    int ans = max_;
    for (int i = 0; i < max_; ++i) {
        if(DP[i] < maksymalna_liczba_cegielek && DPR[i] < maksymalna_liczba_cegielek){
            ans = min(ans, DP[i]+ DPR[i]);
        }
    }
    cout << ans;
    return 0;
}