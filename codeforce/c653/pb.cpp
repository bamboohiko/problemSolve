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
#define INF 0x3f3f3f3f
#define eps 1e-8
#define pi acos(-1.0)
using namespace std;
typedef long long LL;
int a[10][10],n,m;
string s1,s2;
int dfs(int k,int x) {
    if (k == n) return 1;
    int ans = 0;
    for (int i = 0;i < 6; i++)
        if (a[x][i]) ans += dfs(k+1,i)*a[x][i];
    return ans;
}
int main() {
    scanf("%d%d",&n,&m);
    for (int i = 1;i <= m; i++) {
        cin >> s1 >> s2;
        a[s2[0] - 'a'][s1[0] - 'a']++;
    }
    printf("%d\n",dfs(1,0));
	return 0;
}

