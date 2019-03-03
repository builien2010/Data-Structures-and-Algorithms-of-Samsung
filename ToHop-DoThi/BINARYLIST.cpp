
#include <iostream>
#include <string>

using namespace std;

int n, k, i;

int count = 0;
int s[100];
int x1 = 0;
int flag = -1;

void TRY( int x){

    for (int v = 0; v <= 1; v++){
        s[x] = v;
        if ( v == 0)
            x1++;
        else
            x1 = 0;
        if( x ==  n - 1 && x1 != i){
            count = count + 1;
            if( count == k){
                for ( int j = 0; j < n; j++)
                    cout << s[j] << " ";
                flag = 1;
                break;
            }

        }else{
            if( x1 != i){
                TRY(x+1);
                if( x1 != 0)
                    x1--;
            }

        }


    }

}


int main(){

    cin >> n;
    cin >> k;
    cin >> i;


    TRY(0);
    //cout << count;
    if( flag == -1)
        cout << -1;


    return 0;
}
