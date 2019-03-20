#include <bits/stdc++.h>

using namespace std;

int n, k, i;

// vector lưu kết quả
vector<int> x;

int f[10000][10000];

// độ sâu depth

// pre : đếm bao nhiêu số 0 liên tiếp hiện tại

// đếm số nghiệm ở độ sâu thứ depth
int dem(int depth, int pre0){

    if ( depth == n)
        return 1;
    int &r = f[depth][pre0];
    if( r != -1)
        return r;
    r = 0;
    if( pre0 < i){
        r += dem(depth+1, pre0+1);

    }

    r += dem(i+1, 0);
    
    return r;

}

int main(){

    cin >> n >> k >> i;
    duyet(0, 0);

    vector<int, int> f(n+1);
    vector<long long> s(n+1);
    f[0] = 1;
    s[0] = 1;

    for ( int depth = 1; depth <= n; depth++){
        int j = max(0, depth - i);
        long long fl = s[depth-1] - ( j ? s[j-1] : 0);
        if ( depth < i)
            ++fl;
        if( fl > k)
            fl = k + 1;
        
        f[depth] = fl;
        s[depth] = s[depth - 1] + f[depth];
            
    }

    int &sum = f[depth] = 0;
        for (int p=0;p<=depth&&p<i;++p){
            sum += f[max(0,depth-p-1)];//00001 (p so 0)
            if (sum > k){
                sum = k+1;
                break;
            }
        }

        */
    
    return 0;
}

/*

int main(){

    cin >> n >> k >> i;
    vector<int> f(n+1);
    vector<long long> s(n+1);
    f[0] = 1;
    s[0] = 1;

    for ( int depth = 1; depth <= n; depth++){
        int j = max(0, depth - i);
        long long fl = s[depth-1] - ( j ? s[j-1] : 0);
        if ( depth < i)
            ++fl;
        if( fl > k)
            fl = k + 1;
        
        f[depth] = fl;
        s[depth] = s[depth - 1] + f[depth];
            
    }


    while( n > 0){

        int p;

        for ( p = min(n, i- 1); p >= 0; --p){
            if( f[max(0, n-1-p)] >= k)
                break;
            k = k - f[max(0, n-p-1)];
        }

        if ( p < 0){
            cout << -1;
            return 0;
        }

        for ( int j = 0; j < p; ++j ){
            cout << "0 ";
        }

        if ( p < n)
            cout << "1 ";
        
        if ( p < n)
            n = n - p - 1;
        else 
            n = n-p;
    


    }


}

// đếm số nghiệm ở độ sâu thứ i
int dem(int depth, int pre){

    if ( i == n)
        return 1;
    int &r = f[i][pre0];
    if( r != -1)
        return r;
    r = 0;
    if( pre0 < L){
        r += dem(i+1, pre0+1);

    }

    r += dem(i+1, 0);
    
    return r;

}

void f(int depth, int pre){
    if( depth == n){
        
        // in ra kết quả thứ k
    }

    if ( pre < L){
        s[depth] = 0;
        f(depth + 1, pre + 1);

    }else{
        s[depth] = 1;
        f(depth + 1, 0);
    }

}

int main(){


    cin >> n;
    cin >> k;
    cin >> L;




    
    //cout << count;
    if( flag == -1)
        cout << -1;
    return 0;
}
*/