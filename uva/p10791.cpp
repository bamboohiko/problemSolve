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
const int maxn = (1 << 16);
int prime[7000],num[7000],cou = 0;
bool vis[maxn];
void init() {
    for (int i = 2;i <= maxn; i++)
        if (!vis[i]) {
            prime[cou++] = i;
            for (int j = i;j <= maxn; j += i) vis[j] = true;
        }
}
int main() {
    init();
    int k,T = 1;
    while (scanf("%d",&k) != EOF && k != 0) {
        LL ans = 0;int sav = k,num = 0;
        for (int i = 0;i < cou; i++) {
            int sum = 0;
            while (k%prime[i] == 0) {
                k /= prime[i];
                sum++;
            }
            if (sum > 0) {
                ans += pow(prime[i],sum);
                num++;
            }
            if (k == 1) break;
        }
        if (k > 1) {
            ans += k;
            num++;
        }
        if (num == 0) ans += 2;
        if (num == 1) ans++;
        printf("Case %d: %lld\n",T++,ans);
    }
	return 0;
}
