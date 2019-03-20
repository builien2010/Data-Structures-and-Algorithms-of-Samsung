#include<bits/stdc++.h>
using namespace std;

int n,k,i;
vector<int> x;

main(){
    cin>>n>>k>>i;
    x.resize(n);
    vector<int> f(n+1);
    vector<long long> s(n+1);
    f[0]=s[0]=1;

    // l : độ sâu

    for (int l=1;l<=n;++l){

        int j = max(0,l-i);

        long long fl = s[l-1]-(j?s[j-1]:0);
        if (l<i) ++fl;
        if (fl>k) fl = k+1;
        f[l] = fl;
        s[l] = s[l-1]+f[l];

    while (n>0) {
        int p;
        for (p=min(n,i-1);p>=0;--p){
            if (f[max(0,n-p-1)]>=k) break;
            k -= f[max(0,n-p-1)];
        }
        if (p<0){
            cout<<-1;
            return 0;
        }
        for (int j=0;j<p;++j) cout<<"0 ";if (p<n) cout<<"1 ";
        if (p<n) n -= p+1;
        else n -= p;
    }
    
}