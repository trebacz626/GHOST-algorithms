#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int biggest_histogram(int hist[], int len){
    //liczymy najwiekszy mozliwy prostakat w otrzymanym histogramie
    stack <int> bars;
    //cout << hist[0];
    int max_area = 0;
    int curr_area;
    int popped;

    int i = 0;
    while (i < len) {
        if (bars.empty()){ // jesli stos jest pusty to wrzucamy na niego index slupka
            bars.push(i++);
        }
        else if (hist[bars.top()] <= hist[i]){ // jesli aktualny slupek jest conajmniej rowny poprzedniemu to nadal wrzucamy
            bars.push(i++);
        }
        else { // jesli aktualny slupek jest mniejszy no to nie mozemy juz dalej zwiekszac pola wiec wyrzucamy slupek i liczymy pole dla wyrzuconego slupka
            popped = bars.top();
            bars.pop();
            curr_area = hist[popped] * (bars.empty() ? i : i - 1 - bars.top()); // pole to wysokosc slupka * szerokosc czyli index po prawo - index po lewo
            if (max_area < curr_area) max_area = curr_area;
        }

    }
    //jestli zostalo cos na stosie to zrzucamy z niego
    while (!bars.empty()) {
        popped = bars.top();
        bars.pop();
        curr_area = hist[popped] * (bars.empty() ? i : i - 1 - bars.top());
        if (max_area < curr_area) max_area = curr_area;
    }

    return max_area;
}
int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    //int dzialka[n][n];
    int heights[n];
    int curr;
    fill(heights, heights + n, 0 );


    int biggest_area = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> curr;
            if (curr == 1) heights[j] =0;
            else heights[j] ++;
            //cout << heights[j] << " ";
        }
        //cout << endl ;
        int temp = biggest_histogram(heights,n);
        if (temp > biggest_area) biggest_area = temp;

    }

    cout << biggest_area;
    return 0;
}