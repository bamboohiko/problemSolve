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
const int inf = 1e8 + 7;
char s[2010];
map<char,int> p;
bool vis[2010][2010];
int f[2010][2010],n,m;
int dfs(int l,int r) {
    if (l == 0 && r == m-1) return 0;
    if (vis[l][r]) return f[l][r];
    f[l][r] = inf;
    if (l > 0 && r < m-1 && s[l-1] == s[r+1]) f[l][r] = dfs(l-1,r+1);
    if (l > 0) f[l][r] = min(f[l][r],dfs(l-1,r) + p[s[l-1]]);
    if (r < m-1) f[l][r] = min(f[l][r],dfs(l,r+1) + p[s[r+1]]);
    vis[l][r] = true;
    //printf("%d %d %d\n",l,r,f[l][r]);
    return f[l][r];
}
int main() {
    int k;
    char ch;int p1,p2;
    scanf("%d%d%*c",&n,&m);
    gets(s);
    for (int i = 1;i <= n; i++) {
        scanf("%c%d%d%*c",&ch,&p1,&p2);
        p[ch] = min(p1,p2);
    }
    int ans = 0;
    for (int i = 0;i < m; i++) {
        ans += p[s[i]];
    }
    for (int i = 0;i < m; i++) {
        ans = min(ans,dfs(i,i));
        if (i < m-1 && s[i] == s[i+1]) ans = min(ans,dfs(i,i+1));
    }
    printf("%d\n",ans);
	return 0;
}
