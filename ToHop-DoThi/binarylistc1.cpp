/* duyệt đến xâu thứ  k thỏa mãn */


#include <bits/stdc++.h>

using namespace std;

int n, k, i;
int flag = -1;

// vector lưu kết quả
vector<int> x;

int f[10000][10000];

// độ sâu depth

// pre : đếm bao nhiêu số 0 liên tiếp hiện tại
void duyet( int depth, int pre){

    // Nếu độ sâu bằng n  và thứ k thì in ra kết quả
    if( depth == n){
        if( --k == 0){
            for ( int j = 0; j < n ; j++){
                cout << x[j] << " ";
            }
            flag = 1;
            exit(0);
        }
        return ;

    }

    
    if( pre + 1 < i){
        x[depth] = 0;
        duyet(depth + 1, pre + 1);
    }

    x[depth] = 1;
    duyet(depth + 1, 0);
} 


int main(){

    cin >> n >>  k >> i;

    // resize(): thay đổi kích thước của vector
    x.resize(n);

    duyet(0,0);

    if ( flag == -1)
        cout << -1;

    return 0;
}