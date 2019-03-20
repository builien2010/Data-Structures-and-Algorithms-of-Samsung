#include <bits/stdc++.h>

using namespace std;

int T;
string a;
string b;

int s[5000][5000];

int LCS(string a, string b){

    int n = a.length();

    int m = b.length();


    for ( int j = 0; j <= m; ++j){
        s[0][j] = 0;
    }

    for ( int i = 0; i <= n; ++i){
        s[i][0] = 0;
    }

    for ( int i = 1; i <= n; ++i){
        for ( int j = 1; j <= m; j++){
            if( a[i-1] == b[j-1])
                s[i][j] = s[i-1][j-1] + 1;
            else 
                s[i][j] = max(s[i-1][j] , s[i][j-1]);
        }
    }

    return s[n][m];


}

int main(){

    cin >> T;
    
    for ( int i = 1; i <= T; ++i){

        cin >> a[i];
        cin >> b[i];
        cout << LCS(a, b) << endl;
    }

    return 0;
}