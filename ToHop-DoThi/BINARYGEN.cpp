/*
    Phương pháp sinh xâu nhị phân _BINARYGEN

*/

#include <iostream>
#include <string>

using namespace std;

void nextGeneration(string s, int n){

    int flag = -1;

    for ( int i = n - 1; i >= 0; i--){
       if( s[i] == '0'){

            s[i] = '1';
            flag = 1;

            for ( int j = n - 1; j > i; j--)
                s[j] = '0';
            break;
       }
    }

    if( flag == 1)
        cout << s;
    else
        cout << -1;

}
int main(){

    int n;

    cin >> n;

    string s;

    cin.ignore(); //xoa bo nho dem

    getline(std::cin, s);

    nextGeneration(s, n);

    return 0;








}
