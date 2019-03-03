#include<iostream>
#include<math.h>
#include<stdio.h>

using namespace std;

void swap( float &x, float &y)
{
    float temp = x;
    x = y;
    y = temp;

}

void combSort( float a [] , int n ){
    int gap = n; // Initialize gap size: khởi tạo kích thước khoảng cách

    float shrink = 1.3; // Set the gap shrink factor : đặt lại khoảng cách co lại
    bool sorted = false;

    while (( gap > 1) || ( sorted == false )) {
        // Update the gap value for a next comb
        gap = floor( gap / shrink);

        if ( gap < 1)
            gap = 1;

        int i = 0;
        if ( gap == 1)
            sorted = true ;

        // A single " comb " over the input list
        while ( i + gap < n) {

            // See Shell sort for a similar idea
            if (a [i] > a[i+gap]) {
                swap (a[i], a[i+gap]);
                if ( gap == 1)
                    sorted = false ;
            // If this assignment never happens within the loop ,
            // then there have been no swaps and the list is sorted .
            }
            i = i + 1;
        }
    }
}

int main(){

    int n;
    float a[1000000];

    cin >> n;

    for ( int i = 0; i < n; i++){
        cin >> a[i];
    }

    combSort(a,n);

    for ( int i = 0; i < n; i++){
        printf("%.2f ",a[i]);
    }






    return 0;
}

