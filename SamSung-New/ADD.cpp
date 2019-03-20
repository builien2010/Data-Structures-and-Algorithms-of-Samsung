#include <iostream>
#include <math.h>

using namespace std;

int main(){

    unsigned long long a, b;

    cin >> a;
    cin >> b;

    unsigned long long temp = a % 100000000000 + b % 100000000000;
    cout << temp <<endl;
    cout << temp % 100000000000 << endl;

    int n = (int)log10(temp) + 1;
    cout << n << endl;

    unsigned long long pre = a/100000000000 + b/100000000000;

    cout << pre << endl;

    if ( n > 11)
        cout << pre + 1 << temp % 100000000000 << endl;
    else
        cout << a + b << endl;

    //cout << a + b;

    return 0;

}
