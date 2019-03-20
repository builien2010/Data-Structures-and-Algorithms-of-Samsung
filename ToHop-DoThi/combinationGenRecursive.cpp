
#include <bits/stdc++.h>

using namespace std;

int n, m ;
long k;
long dem = 0;
int flag = -1;

int a[10000];

void printSolution(){

    for ( int i = 1; i <= m; i++){
        cout << a[i] << " ";
    }

    cout << endl;
}

void Try( int i){

    int j;

    for ( j = a[i-1] + 1; j <= n-m+i; ++j){
        a[i] = j;
        if ( i == m){
            dem = dem + 1;
            if ( dem == k){
                flag = 1;
                printSolution();
                return;
            }
        }

        else 
            Try(i+1);
    }
}

int main(){

    cin >> n >> m  >> k;
    a[0]  = 0;
    Try(1);
    if ( flag == -1)
        cout << -1;
    return 0;
}