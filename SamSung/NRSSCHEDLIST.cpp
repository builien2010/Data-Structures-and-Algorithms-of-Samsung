#include <iostream>

using namespace std;

int N, K1, K2;
int a[200];
int length = 0;

void printSolution(){

    for ( int i = 0; i <= N-1; i++)
        cout << a[i];
    cout << endl;
}

bool check( int v, int k){
    cout << v << k << endl;
    if( v == 0){
        if( a[k-1] == 0)
            return false;
        if(a[k-1] == 1){
            if(length >= K1){
                length = 0;
                return true;
            }else
                return false;
        }else
            return true;
    }else{
        // v = 1
        length++;
    }

    if(length >  K2)
        return false;

    return true;

}

bool check1( int v, int k){

    int len = 0;
    int i = k - 1;
    while (a[i] != 0){
        len = len + 1;
        i--;
    }

    if( v == 0){
        if( k == 0)
            return true;
        if( a[k-1] == 0)
            return false;
        else if(a[k-1] == 1){
            if(len >= K1){
                len = 0;
                return true;
            }else
                return false;
        }else{
            //cout << a[k]  << "a[k] "<< endl;
            return true;
        }
    }else{
        // v = 1
        //cout << "1" << endl;
        len = len + 1;
    }

    if(len >  K2)
        return false;

    if ( k == N - 1){
        if( len >= K1)
            return true;
        else
            return false;
    }

    return true;

}

void Try(int k){

    for ( int v = 0; v <= 1; v++){

        if( check1(v, k)){
            a[k] = v;
            if((k == N - 1)){
                printSolution();

            }
            else
                Try(k+1);

        }

    }
}





int main(){

    cin >> N;
    cin >> K1;
    cin >> K2;

    Try(0);


    return 0;

}
