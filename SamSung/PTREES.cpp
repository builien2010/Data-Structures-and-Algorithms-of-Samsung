#include <iostream>

using namespace std;

int N;
int t[100001];

int main(){

    cin >> N;

    for ( int i = 1; i <= N; i++){
        cin >> t[i];
    }

    for ( int i = 1; i < N; i++){
        for ( int j = i + 1; j <= N; j++){
            if( t[i] < t[j]){
                int temp = t[i];
                t[i] = t[j];
                t[j] = temp;
            }
        }
    } 
    int max = 0;
    for (int i = 1; i <= N; i++){
        if ( max < t[i] + i)
            max = t[i] + i;
    }

    cout << max + 1<< endl;


    return 0;

}