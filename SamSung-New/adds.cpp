#include<bits/stdc++.h>
using namespace std;

int main(int argc, char **argv){
    if (argc>2){
        freopen(argv[1],"r",stdin);
        freopen(argv[2],"w",stdout);
    }
    long long A,B,M;
    cin>>A>>B>>M;

    long long x=B*(B+1)/2, y=2*B+1;
    if (x%3==0) x/=3;
    else y/=3;
    int sb = x%M*y%M;

    --A;
    x=A*(A+1)/2, y=2*A+1;
    if (x%3==0) x/=3;
    else y/=3;
    int sa = x%M*y%M;

    cout<<(sb-sa+M)%M;
    
    return 0;
}

