#include<iostream>

using namespace std;

int main(){

    int a[1000000];
    int s[1000000];
    int n;

    cin >> n;

    for ( int i = 0; i < n; i++){
        cin >> a[i];
    }

    // Array s : tong tu phan tu dau tien den phan tu thu i
    s[0] = a[0];
    for ( int i = 1; i < n; i++){
        s[i] = s[i-1] + a[i];

    }

    int min = 0, result = 0;

    for ( int i = 0; i < n; i++){
        if(s[i] - min > result)
            result = s[i] - min;
        if( min > s[i])
            min = s[i];
    }

    cout << result << endl;

    return 0;

}
