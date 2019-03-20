#include<bits/stdc++.h>
using namespace std;

main(){
    int n,m,k;
    cin>>n>>m>>k;
    //vector<vector<int> > c(n+1,vector<int>(m+1));
    int c[10000][10000];

    
    for (int i=0;i<=n;++i){
        c[i][0]=1;
        for (int j=1;j<=i && j<=m;++j){
            if ((c[i][j]=c[i-1][j]+c[i-1][j-1]) > k){
                c[i][j]=k+1;
            }
        }
    }


    vector<int> x(m+1);
    
    for (int i=1;i<=m;++i){
        int j;
        for (j=x[i-1]+1;j<=n;++j){
            int f = c[n-j][m-i];
            if (f>=k) break;
            k -= f;
        }
        if (j>n){
            cout<<-1;
            return 0;
        }
        x[i]=j;
    }
    for (int i=1;i<=m;++i) cout<<x[i]<<" ";
}
