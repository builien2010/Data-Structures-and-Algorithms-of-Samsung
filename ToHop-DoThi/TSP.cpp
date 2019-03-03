#include <iostream>

using namespace std;

int n, m;
long c[21][21];
bool visited[21];
long fmax;
long f;
long cmin;
int x[21];

void TRY(int k){

    for ( int v = 1; v <= n; v++){
        if( visited[v] == false){
            x[k] = v;
            visited[v] = true;
            f = f + c[x[k-1]][x[k]];

            if( k == n){
                if( f + c[x[n]][1] < fmax){
                    fmax = f + c[x[n]][1];
                }
            }else{
                long z = f + ( n - k + 1)* cmin;
                if( z < fmax )
                    TRY(k+1);

            }
            f = f - c[x[k-1]][x[k]];
            visited[v] = false;
        }

    }

}

int main(){

     cin >> n;
     cin >> m;

     int i, j;
     long c1;

     for(int i = 1; i <= n; i++){
        for ( int j = 1; j <= n; j++)
            c[i][j] = 1000000;
     }


     for ( int k = 1; k <= m; k++){
        cin >> i;
        cin >> j;
        cin >> c1;
        c[i][j] = c1;
     }

     int cmin = c[1][1];
     for(int i = 1; i <= n; i++){
        for ( int j = 1; j <= n; j++){
            if(cmin > c[i][j])
                cmin = c[i][j];
        }

     }

     fmax = 20000000;
     f = 0;
     x[1] = 1;
     visited[1] = true;
     TRY(2);

     cout << fmax << endl;


    return 0;

}
