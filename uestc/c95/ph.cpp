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
const int maxn = 1e6 + 100;
const int mov[4][2] = {0,1,0,-1,1,0,-1,0};
int a[maxn],b[maxn],loc[maxn],f[maxn];
int r[1010],c[1010],kr[1010],kc[1010];
//map<int,int> D;
bool cmp(int x,int y) {
    return a[x] < a[y];
}
void uni(int x,int y) {
    int a = find(x),b = find(y);
    if (a != b) f[a] = b;
}
int main() {
    int n,m,cou = 0;
    scanf("%d%d",&n,&m);
    for (int i = 0;i < n*m; i++) {
            scanf("%d",&a[i]);
            loc[i] = i;f[i] = i;
    }
    sort(loc,loc+n*m,cmp);
    for (int i = 0;i < n*m; i++) {
        int x = loc[i]/m,y = loc[i]%m;
        b[loc[i]] = max(r[x],c[y]) + 1;
        if (a[loc[i]] == a[kr[x]]) uni(loc[i],kr[x]);
        if (a[loc[i]] == a[kc[y]]) uni(loc[i],kc[y]);
        //printf("%d %d %d\n",loc[i],a[loc[i]],b[loc[i]]);
        r[x] = c[y] = b[loc[i]];
        kr[x] = kc[y] = loc[i];
    }
    for (int i = 0;i < n; i++) {
        for (int j = 0;j < m; j++) printf("%d ",b[i*m+j]);
        printf("\n");
    }
	return 0;
}

