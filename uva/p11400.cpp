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
struct lamp {
    int v,k,c,l;
};
lamp a[1010];
int f[1010];
bool cmp(lamp a,lamp b) {
    return a.v < b.v;
}
int main() {
    int n;
    while (scanf("%d",&n) != EOF && n) {
        for (int i = 1;i <= n; i++) {
            scanf("%d%d%d%d",&a[i].v,&a[i].k,&a[i].c,&a[i].l);
        }
        sort(a+1,a+n+1,cmp);
        for (int i = 2;i <= n; i++)
            a[i].l += a[i-1].l;
        for (int i = 1;i <= n; i++) {
            f[i] = a[i].l*a[i].c + a[i].k;
            for (int j = 1;j < i; j++)
                f[i] = min(f[i],f[j] + (a[i].l - a[j].l)*a[i].c + a[i].k);
        }
        printf("%d\n",f[n]);
    }
	return 0;
}
