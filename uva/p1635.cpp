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
const int maxn = 1e5;
int prime[10010],num[10010],cou = 0,neg = 0;
bool vis[maxn + 10];
int V[maxn + 10];
void init() {
    for (int i = 2;i <= maxn; i++)
        if (!vis[i]) {
            prime[cou++] = i;
            for (int j = i+i;j <= maxn; j += i) vis[j] = true;
        }
    //cout << cou << endl;
}
void add(int k,int d) {
    for (int i = 0;i < cou; i++) {
        while (k%prime[i] == 0) {
            k /= prime[i];
            if (num[i] >= 0 && num[i]+d < 0) neg++;
            if (num[i] < 0 && num[i]+d >= 0) neg--;
            num[i] += d;
        }
        if (k == 1) break;
    }
}
int main() {
    init();
    int n,m;
    while (scanf("%d%d",&n,&m) != EOF) {
        n--;
        int ans = 0;
        memset(num,0,sizeof(num));neg = 0;
        add(m,-1);
        for (int i = 1;i < n; i++) {
            add(n-i+1,1);
            add(i,-1);
            if (neg == 0) V[ans++] = i+1;
        }
        printf("%d\n",ans);
        if (ans > 0) printf("%d",V[0]);
        for (int i = 1;i < ans; i++) printf(" %d",V[i]);
        printf("\n");
    }
	return 0;
}
