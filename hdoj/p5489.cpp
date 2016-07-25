#include<iostream>
#include<cstdio>
#include<map>
#include<set>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<cstring>
#include<sstream>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxn = 1e5 + 10;
int a[maxn],b[maxn];
int f[maxn],s[maxn];
int n,m,l;
int lowbit(int k)
{
    return k&(-k);
}
int queryf(int k)
{
    int ans = 0;
    while (k > 0)
    {
        ans = max(f[k],ans);
        k -= lowbit(k);
    }
    return ans;
}
void updataf(int val,int k)
{
    while (k <= m)
    {
        f[k] = max(f[k],val);
        k += lowbit(k);
    }
}
int querys(int k)
{
    int ans = 0;
    while (k > 0)
    {
        ans = max(s[k],ans);
        k -= lowbit(k);
    }
    return ans;
}
void updatas(int val,int k)
{
    while (k <= m)
    {
        s[k] = max(s[k],val);
        k += lowbit(k);
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    for (int ca = 1; ca <= t; ca++) {
        memset(f,0,sizeof(f));
        memset(s,0,sizeof(s));
        scanf("%d%d",&n,&l);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d",&a[i]);
            b[i] = a[i];
        }
        sort(b,b+n);
        m = unique(b,b+n) - b;
        for (int i = 0; i < n; i++) {
            int k1 = lower_bound(b,b+m,a[i]) - b + 1;
            int tmp1 = queryf(k1-1) + 1;
            if (i + l < n) {
                ans = max(ans,tmp1);
                int k2 = lower_bound(b,b+m,a[i+l]) - b + 1;
                int tmp2 = max(queryf(k2-1),querys(k2-1)) + 1;
                ans = max(ans,tmp2);
                updatas(tmp2,k2);
            }
            updataf(tmp1,k1);
            //cout << queryf(k1) << " " << querys(k1) << endl;
        }
        printf("Case #%d: %d\n",ca,ans);
    }
    return 0;
}

