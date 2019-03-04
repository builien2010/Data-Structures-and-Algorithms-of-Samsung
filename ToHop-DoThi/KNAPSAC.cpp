#include <bits/stdc++.h>
using namespace std;
#define m first
#define v second

main()
{
    int n, M;
    cin >> n >> M;
    vector<int> m(n), v(n);
    for (int i = 0; i < n; ++i)
        cin >> m[i] >> v[i];

    vector<pair<int, int> > S1, S2;

    int l = n / 2;


    for (int k = 0; k < (1 << l); ++k)
    {
        int sumM = 0, sumV = 0;
        for (int i = 0; i < l; ++i)
            if (k >> i & 1)
            {
                sumM += m[i];
                sumV += v[i];
            }
        S1.push_back({sumM, sumV});
    }


    int ll = n - l;
    for (int i = 0; i < ll; ++i)
    {
        m[i] = m[i + l];
        v[i] = v[i + l];
    }
    l = ll;
    for (int k = 0; k < (1 << l); ++k)
    {
        int sumM = 0, sumV = 0;
        for (int i = 0; i < l; ++i)
            if (k >> i & 1)
            {
                sumM += m[i];
                sumV += v[i];
            }
        S2.push_back({sumM, sumV});
    }
    sort(S2.begin(), S2.end());

    vector<int> maxV(S2.size());
    maxV[0] = S2[0].v;
    for (int i = 1; i < S2.size(); ++i)
        maxV[i] = max(maxV[i - 1], S2[i].v);

    int ans = -1e9;
    for (int i = 0; i < S1.size(); ++i)
    {
        int L = 0, H = S2.size() - 1, j = -1;
        while (L <= H)
        {
            int m = (L + H) / 2;
            if (S1[i].m + S2[m].m <= M)
            {
                j = m;
                L = m + 1;
            }
            else
                H = m - 1;
        }
        if (j != -1)
        {
            ans = max(ans, S1[i].v + maxV[j]);
        }
    }
    cout << ans;
}
/*
4 8
2 1
3 4
4 5
2 6
*/
