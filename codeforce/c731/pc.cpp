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
struct node{
    int col,k;
    bool operator <(const node &rhs) const {
        if (k != rhs.k) return k < rhs.k;
        else return col < rhs.col;
    }
};
int f[200100],c[200100];
stack<int> S;
vector<node> V;
int _find(int k) {
    while (f[k] != k) {
        S.push(k);
        k = f[k];
    }
    while (!S.empty()) {
        int p = S.top();S.pop();
        f[p] = k;
    }
    return k;
}
int main() {
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for (int i = 1;i <= n; i++) {
        scanf("%d",&c[i]);
        f[i] = i;
    }
    int a,b;
    for (int i = 1;i <= m; i++) {
        scanf("%d%d",&a,&b);
        int fa = _find(a),fb = _find(b);
        f[fa] = fb;
    }
    for (int i = 1;i <= n; i++) {
        int fi = _find(i);
        V.push_back((node){c[i],fi});
    }
    V.push_back((node){0,n+1});
    sort(V.begin(),V.end());
    int cnt = 0,maxc = 0,ans = 0;
    for (int i = 0;i+1 < V.size(); i++) {
        cnt++;
        if (V[i].col != V[i+1].col || V[i].k != V[i+1].k) {maxc = max(maxc,cnt);cnt = 0;}
        if (V[i].k != V[i+1].k) {ans += maxc;maxc = 0;}
    }
    printf("%d\n",n-ans);
	return 0;
}
