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
const int maxn = 1e5 + 10;
int prime[10010],n = 0;
bool vis[maxn + 10];
void init() {
    memset(vis,0,sizeof(vis));
    for (int i = 2;i <= maxn; i++)
        if (!vis[i]) {
            prime[n++] = i;
            for (int j = i+i;j <= maxn;j += i) vis[j] = true;
        }
}
int bsearch(int k) {
    int l = 0,r = n-1;
    while (l < r) {
        int mid = ((l+r) >> 1) + 1;
        if (prime[mid] > k) r = mid -1;
        else l = mid;
    }
    return l;
}
int main() {
    init();
    int m;double a,b;
    while (scanf("%d%lf%lf",&m,&a,&b) != EOF && m) {
        int l = 1,h = 1;
        for (int i = 0;i < n; i++) {
            if (prime[i]*prime[i] > m)  break;
            int k1 = bsearch(floor(prime[i]*b/a));
            int k2 = bsearch(floor(m/prime[i]));
            k1 = min(k1,k2);
            if (prime[i]*prime[k1] > l*h) {
                l = prime[i];h = prime[k1];
            }
        }
        printf("%d %d\n",l,h);
    }
	return 0;
}

