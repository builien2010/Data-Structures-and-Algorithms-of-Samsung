#include<iostream>+
#include<math.h>
#include<stdio.h>

using namespace std;

void swap( float &x, float &y)
{
    float temp = x;
    x = y;
    y = temp;

}

int partition (float a[], int L, int R, int indexPivot){

    float pivot = a[indexPivot];

    swap(a[indexPivot], a[R]);

    int storeIndex = L;


    for (int i = L; i < R; i++){
        if(a[i] < pivot){
            swap(a[storeIndex], a[i]);
            storeIndex++;
        }
    }
    swap(a[storeIndex], a[R]);

    return storeIndex;

}
void quickSort(float a[], int L, int R){

    if( L < R){

        int index = ( L + R)/2;
        index = partition(a, L, R, index);
        if( L < index)
            quickSort(a, L, index - 1);
        if( R > index)
            quickSort(a, index + 1, R);
    }

}

int main(){

    int n;
    float a[100000];

    cin >> n;

    for ( int i = 0; i < n; i++){
        cin >> a[i];
    }

    quickSort(a, 0, n - 1);

    for ( int i = 0; i < n; i++){
        printf("%.2f ",a[i]);
    }

    return 0;
}

