#include <iostream>


using namespace std;

int main() {
    int n;
    cin >> n;
    int players[n];
    int max = 0;
    int licznik = 0;
    for(int i; i < n; i ++){
        int num;
        cin >> num;

        if (num > max){
            max = num;
            licznik++;
            players[i] = licznik;
        }
        else if (num == max){
            players[i] = licznik;
        }
    }
    for(int i = 0; i < n; i++){
        if(players[i] == licznik){
            cout << static_cast<char>(i+65);
        }
    }
    return 0;
}
