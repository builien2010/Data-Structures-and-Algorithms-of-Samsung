#include <iostream>

using namespace std;

int a[1000];

int n = 3 , k = 2, y = 3, x = 0, m = 2;
int sum = 0;
void printSolution(){

    for ( int i = 1; i <= k; i++)
        cout << a[i] << " ";
}
void TRY( int i)
{
    cout << "TRY : "  << i << endl;
    for ( int v = x; v <= y; v++){
        a[i] = v;
        sum += v;
        if( sum < n){
        if ( i > k)
            break;
        if( i == k && sum == n){
            printSolution();
        }
        else{
            TRY(i+1);
        }
        sum -= v;
        }



    }
}



int main(){

/*
    cin >> n;
    cin >> k;
    cin >> y;
    cin >> x;
    cin >> m;
  */
    TRY(1);

    return 0;


}
