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
int prime[10100],num[10100],cou = 0;
bool vis[10100];
void init() {
    for (int i = 2;i <= 1e4; i++)
        if (!vis[i]) {
            prime[cou++] = i;
            for (int j = i+i;j <= 1e4; j += i) vis[j] = true;
        }
}
void add(int k,int inc) {
    for (int i = 0;i < cou; i++) {
        while (k%prime[i] == 0) {
            k /= prime[i];
            num[i] += inc;
        }
        if (k < prime[i]) break;
    }
}
int main() {
    init();
    int p,q,r,s;
    while (scanf("%d%d%d%d",&p,&q,&r,&s) != EOF) {
        memset(num,0,sizeof(num));
        for (int i = p-q+1;i <= p; i++) add(i,1);
        for (int i = 1;i <= q; i++) add(i,-1);
        for (int j = r-s+1;j <= r; j++) add(j,-1);
        for (int j = 1;j <= s; j++) add(j,1);
        double ans = 1;
        for (int i = 0;i < cou; i++)
            if (num[i] != 0) {
                ans *= pow(prime[i],num[i]);
                //cout << prime[i] << " " << num[i] <<endl;
            }
        printf("%.5lf\n",ans);
    }
	return 0;
}
