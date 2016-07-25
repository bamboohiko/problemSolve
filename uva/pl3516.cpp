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
typedef long long LL;
const LL mod = 1000000000;
int n;
LL f[310][310];
bool vis[310][310];
string st;
LL dfs(int l,int r) {
    if (l > r) return 0;
    if (st[l] != st[r]) return 0;
    if (vis[l][r]) return f[l][r];
    f[l][r] = 0;
    for (int k = l+1;k <= r; k++) {
        if (st[k] == st[l]) f[l][r] = (f[l][r] + dfs(l+1,k-1)*dfs(k,r))%mod;
    }
    vis[l][r] = true;
    //printf("%d %d %lld\n",l,r,f[l][r]);
    return f[l][r];
}
int main() {
    while (cin >> st) {
        memset(vis,false,sizeof(vis));
        n = st.size();
        for (int i = 0;i < n; i++) {vis[i][i] = true;f[i][i] = 1;}
        printf("%lld\n",dfs(0,n-1));
    }
	return 0;
}
