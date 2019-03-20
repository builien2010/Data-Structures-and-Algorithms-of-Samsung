#include <bits/stdc++.h>

using namespace std;

int T;
string a;
string b;

int d[5001][5001];

int ED(string a, string b){

    int n = a.length();

    int m = b.length();


    for ( int j = 0; j <= m; ++j){
        d[0][j] = j;
    }

    for ( int i = 0; i <= n; ++i){
        d[i][0] = i;
    }

    d[0][0] = 0;

    for ( int i = 1; i <= n; ++i){
        for ( int j = 1; j <= m; j++){

            int k = 1;
            if ( a[i-1] == b[j-1])
                k = 0;

            d[i][j] = min(min(d[i-1][j-1] + k, d[i-1][j] + 1), d[i][j-1] + 1);
            
        }
    }

    return d[n][m];


}

int main(){

    cin >> T;
    
    for ( int i = 1; i <= T; ++i){
        
        cin >> a;
        cin >> b;
        cout << ED(a, b) << endl;
    }
    

    return 0;
}