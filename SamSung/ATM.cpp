#include <iostream>

using namespace std;
unsigned long long  W[1001];
int c[1001];
int T;
unsigned long long N = 0, S = 0;

void SL(int z)
{

    switch (z)
    {
    case 0:
        N += 0;
        S *= 1;
        break;

    case 1:
    case 2:
    case 3:
    case 5:
        N += 1;
        S *= 1;
        break;

    case 4: 
    case 6:
        N += 2;
        S *= 2;
        break;

    case 7:
    case 8:
        N += 2;
        S *= 1;
        break;

    case 9:
        N += 3;
        S *= 3;
        break;
    }
}

void ATM(unsigned long long W, int c)
{

    
    if (W % 1000 != 0){
        N = 0;
        S = 0;
        cout << 0 << endl;
        return;
    }

    W = W / 1000;

    int i = 1;
    long temp = 1;
    while ( i <= c){
        temp *= 10;
        i++;
    }

    //cout << "temp " << temp << endl;

    unsigned long long  x = W / (100*temp);

    //cout << "x " << x << endl;
    
    
    N = 20*x;

    //cout << N << endl;
    S = 1;

    //int y = (W % (100*temp))/10;

    //cout << N  << " " << S<< endl;

    //cout << "du" << du << endl;

    //cout << " W: " << W << endl;
    int y = ((unsigned long long )( W / temp) )% 100;

    //cout  << "y " << y << endl;

    if ((y == 1 && x != 0)|| y == 11 || y == 21 || y == 31 || y == 41|| y == 51|| y == 61 || y == 71 || y == 81 || y == 91){
        N = N + (y-11)/5 +3;
        S *= 2;
    }
    else if ( (y == 4 && x != 0)|| y == 14 || y == 24 || y == 34 || y == 44 || y == 54 || y == 64 || y == 74 || y == 84 || y == 94 ){
        N = N +  ( y-14)/5 + 4;
        S *= 3;
    }
    else{
        
        int du = y % 10;
        N += (int)((y - du)/5);
        SL(y%10);
    }

    //cout << N << " " << S << endl;

    //cout << N  << S<< endl;



    int z = W % (temp);

    //cout << " z " << z << endl;

    while( z > 0){

        //cout << "z" << z << endl;

        int du = z % 10;
        SL(du) ;
        //cout << N << S << endl;

        z = z / 10;
        
    }

}

int main()
{

    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        cin >> W[i];
        cin >> c[i];
    }

    for (int i = 1; i <= T; i++)
    {

        N = 0, S = 1;
        ATM(W[i], c[i]);
        if ( N != 0 && S != 0) 
            cout << N << " " << S << endl;
    }

    return 0;
}