#include <iostream>
#include <string.h>

using namespace std;

int n;
string p;
string f[100000];

void solve(int n){
    f[0] = "0";
    f[1] = "1";

    for ( int i = 2; i <= n; i++){
        f[i] = strcat(f[i-1],f[i-2]);
    }

    cout << f << endl;
}

int main(){


    cin >> n;
    cin >> p;

    solve(6);

    return 0;
}