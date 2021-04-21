#include <iostream>
#include <climits>
using namespace std;

int main() {
    int n;
    cin >> n;
    int zapalki[n+1];


//    bool meet_10 = false;
    int answer = INT_MAX;
    //Trzeba zauwazyc ze do pewnego momentu wszystkie zapalki beda musialy byc przekrecone w prawo a od pewnego momentu tylko w lewo
    for (int i = 1; i <= n; ++i) {
        cin >> zapalki[i];
    }
    int lewo[n+1]; // tablica do przechowywanie ile zapalek jest przekreconych w lewo
    lewo[0] = 0; // na poczatku zadna zapałka nie jest przekrecona w lewo
    for (int i = 1; i <= n; ++i) {
        lewo[i] = lewo[i-1] + 1 - zapalki[i]; // zapamietujemy ile zapalek od poczatku jest przekrecone w lewo
    }
    for (int i = 1; i <= n; ++i) {
        cout << lewo[i] << " ";
    }
    cout << endl;
    int prawo[n+2]; // tablica do przechowywanie ile zapalek jest przekreconych w prawo
    prawo[n+1] = 0; // za ciagiem zadna zapalka nie jest przekrecona w prawo
    for (int i = n; i >= 1 ; --i) {
        prawo[i] = prawo[i+1] + zapalki[i];
    }
    for (int i = 1; i <= n; ++i) {
        cout << prawo[i] << " ";
    }
    cout << endl;
    for (int i = 0; i <= n; ++i) {
        answer = min(answer, prawo[i+1] + lewo[i]); //kazdy punkty i uznajemy za nasz punkt zwrotny gdzie przed tym punktem kazda zapalka jest w prawo a za tym
        //punktem kazda jest w lewo
    }
    cout << answer;

//    int n2;
//    cin >> n2;
//    int zapalki2[n2];
//
//    for (int i = 0; i < n2; ++i) {
//        cin >> zapalki2[i];
//    }
////    for (int i = 0; i < n2; ++i) {
////        cout << zapalki2[i]  << " ";
////    }
//    answer = 0;
//    int last_checked = 0;
//    if (zapalki2[0] == 0 and zapalki2[1] == 1) {
//        answer++;
//        zapalki2[0] = 1;
//    }
//    last_checked = zapalki2[0];
//    for (int i = 1; i < n2-1; ++i) {
//        if (zapalki2[i] == 0 and zapalki2[i+1] == 1){
//            if (last_checked == 0) zapalki2[i + 1] = 0;
//            else zapalki2[i] = 1;
//            answer++;
//        }
//        last_checked = zapalki2[i];
//    }
//
//////    cout << endl;
////    cout << answer << endl;
    return 0;
}
