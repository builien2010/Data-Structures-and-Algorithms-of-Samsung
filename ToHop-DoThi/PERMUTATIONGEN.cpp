/*
    Phương pháp sinh hoán vị - PERMUTATION
*/

#include <iostream>

using namespace std;

void swap ( int &x, int &y){

    int temp = x;
    x = y;
    y = temp;
}


void nextPermutation(int a[], int n){

    int j = n - 1;
    // Tìm j là chỉ số lớn nhất thỏa mãn a[j] > a[j+1]

    while ( a[j] > a[j+1])
        j--;
    // Tìm a[k] là số nhỏ nhất còn lớn hơn a[j] ở bên phải a[j]
    if( j == 0){
        cout << -1;
        return ;
    }


    int k = n;
    while ( a[j] > a[k])
        k--;

    swap(a[j], a[k]);

    // Lật ngược đoạn a[j+1] đến a[n]

    int r = n, s = j + 1;

    while( r > s){
        swap(a[r], a[s]);
        r--;
        s++;
    }

    for ( int i = 1; i <= n; i++)
        cout << a[i] << " ";

}

int main(){

    int n;
    int a[10000];

    cin >> n;

    for ( int i = 1; i <= n; i++)
        cin >> a[i];

    nextPermutation(a, n);

    return 0;
}
