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
const int maxn = 5e3 + 10;
string st;
int l[maxn],r[maxn],k[maxn];
int f[2*maxn],dis[2*maxn];
set<int> S;
map<int,int> dir;
stack<int> St;
int find(int k) {
    while (f[k] != k) {
        St.push(k);
        k = f[k];
    }
    while (!St.empty()) {
        int p = St.top();St.pop();
        dis[p] = (dis[p] + dis[f[p]])%2;
        f[p] = k;
    }
    return k;
}
int main() {
    int n,m;
    int x,y,a,b,c;
    scanf("%d%d",&n,&m);
        for (int i = 1;i <= m; i++) {
            scanf("%d%d",&l[i],&r[i]);
            cin >> st;
            k[i] = (st[0] == 'o')?1:0;
            S.insert(l[i]);S.insert(r[i]);
        }
        n = 0;
        for (set<int>::iterator i = S.begin();i != S.end(); i++)
            dir[(*i)] = ++n;
        for (int i = 1;i <= n; i++) {f[i] = i;dis[i] = 0;}
        int ans = m;
        for (int i = 1;i <= m; i++) {
            a = dir[l[i]],b = dir[r[i]],c = k[i];
            x = find(a-1),y = find(b);
            if (x == y && (dis[a-1] + c)%2 != dis[b]) {ans = i-1;break;}
            if (x < y) {f[y] = x;dis[y] = (dis[a-1] + c - dis[b] + 2)%2;}
            if (x > y) {f[x] = y;dis[x] = (dis[b] - c - dis[a-1] + 2)%2;}
        }
        printf("%d\n",ans);
	return 0;
}
