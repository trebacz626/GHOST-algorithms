#include <iostream>
#include <string>

using namespace std;

int chain[1000001];
int desiredColorCounts[1000001];
int colorCounts[1000001];

int main(){
    //READING DATA
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int m,n;
    cin>>n>>m;
    int tempColors[n][2];//[color_id,count]
    for (int i = 0; i < m; i++)
    {
        cin>>tempColors[i][1];
    }
    for (int i = 0; i < m; i++)
    {
        cin>>tempColors[i][0];
    }
    long long length = 0;
    for (int i = 0; i < m; i++){
        desiredColorCounts[tempColors[i][0]] = tempColors[i][1];
        length+=tempColors[i][1];
    }
    if( length > n){
        cout<<0;
        return 0;
    }
    for (int i = 0; i < n; i++){
        cin>>chain[i];
    }
    //SOLUTION
    int badColors = m;
    for (int i = 0; i < length; i++){
        int currentColor = chain[i];
        if(colorCounts[currentColor] == desiredColorCounts[currentColor]){
            badColors++;
        }
        colorCounts[currentColor]++;
        if(colorCounts[currentColor] == desiredColorCounts[currentColor]){
            badColors--;
        }
    }
    int beautifullFragments = 0;
    if(badColors ==0){
        beautifullFragments++;
    }
    for(int i=length;i<n;i++){
        int tailColor = chain[i-length];
        if(colorCounts[tailColor] == desiredColorCounts[tailColor]){
            badColors++;
        }
        colorCounts[tailColor]--;
        if(colorCounts[tailColor] == desiredColorCounts[tailColor]){
            badColors--;
        }
        int noseColor = chain[i];
        if(colorCounts[noseColor] == desiredColorCounts[noseColor]){
            badColors++;
        }
        colorCounts[noseColor]++;
        if(colorCounts[noseColor] == desiredColorCounts[noseColor]){
            badColors--;
        }
        if(badColors == 0) beautifullFragments++;
    }
    cout<<beautifullFragments<<endl;

}