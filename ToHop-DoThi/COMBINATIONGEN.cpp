/*
    Phương pháp sinh chuỗi tổ hợp  - COMBINATIONGEN
*/

#include <iostream>

using namespace std;

#define MAX 10000

void nextComination(int a[], int n, int m){

    int i = m ;

    while ( a[i] == n - m + i)
        i--;

    if ( i == 0)
        cout << -1;
    else{
        a[i] = a[i] + 1;

        for (int j = i + 1; j <= m; j++)
            a[j] = a[i] + j - i;

        for( int i = 1; i <= m; i++)
            cout << a[i] << " ";
    }

}



int main(){

    int m, n;
    int a[MAX];

    cin >> n;
    cin >> m;

    for ( int i = 1; i <= m; i++){
        cin >> a[i];
    }

    nextComination(a, n, m);


    return 0;
}
