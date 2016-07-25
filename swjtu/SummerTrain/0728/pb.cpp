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
string a,b,c;
bool f[210][210],vis[210][210];
bool dfs(int i,int j) {
    if (vis[i][j]) return f[i][j];
    if (i == a.size() && j == b.size()) return true;
    bool t1 = false,t2 = false;
    if (i < a.size() && c[i+j] == a[i]) t1 = dfs(i+1,j);
    if (j < b.size() && c[i+j] == b[j]) t2 = dfs(i,j+1);
    f[i][j] = t1 || t2;
    vis[i][j] = true;
    return f[i][j];
}
int main() {
    int t;
    scanf("%d",&t);
    while (t--) {
        memset(f,false,sizeof(f));
        memset(vis,false,sizeof(vis));
        cin >> a >> b >> c;
        if (dfs(0,0)) printf("Yes\n");
        else printf("No\n");
    }
	return 0;
}
