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
const int pownum = 1e9 + 5;
const LL mod = 1e9 + 7;
int gcd(int a,int b) {
    while (b) {
        int t = a;a = b;b = a%b;
    }
    return a;
}
matrix matpow(matrix m,int p) {
    while (p) {
        m = m*m;

    }
}
struct frac {
    int s,m;
    frac(int _s = 0,int _m = 0) {s = _s;m = _m;}
    frac operator *(frac rhs) {
        if (s == 0 || rhs.s == 0) return frac(0,0);
        int a = s*rhs.s,b = m*rhs.m;
        int c = gcd(a,b);
        return frac(a/c,b/c);
    }
};
struct matrix {
    int n,m;
    frac v[52][52];
    matrix(int _n,int _m) {
        n = _n;m = _m;
    }
};
int main() {
    int n,m,q;
    int x,y,u,k;
    while (scanf("%d%d",&n,&m) != EOF) {
        memset(sum,0,sizeof(sum));
        matrix edge(n,n);
        for (int i = 1;i <= m; i++) {
            scanf("%d%d",&x,&y);
            edge.v[y][x].s = 1;sum[x]++;
        }
        for (int i = 1;i <= n; i++)
            for (int j = 1;j <= n; j++)
                if (edge.v[i][j]) edge.v[i][j].m = sum[j];
        scanf("%d",&q);
        for (int i = 1;i <= q; i++) {
            scanf("%d%d",&u,&k);
            edge = matpow(edge,k);
            matrix fx = (1,n);fx.a[u][1] = 1;
            fx = matmul(fx,edge);
            for (int i = 1;i <= n; i++) printf("%d ",fx[i][1].s*modpow(f[i][1].m,pownum)%mod);
            printf("\n");
        }
    }
	return 0;
}
