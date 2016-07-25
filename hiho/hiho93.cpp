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
const int maxn = 1e6;
int vis[maxn + 10],sum[maxn + 10];
int prime[maxn],cou = 0;
void Eular() {
    for (int i = 2;i <= maxn; i++) {
        if (!vis[i]) prime[cou++] = i;
        sum[i] = sum[i-1] + (vis[i]?0:1);
        for (int j = 0;j < cou; j++) {
            if (prime[j]*i > maxn) break;
            vis[i*prime[j]] = true;
            if (i%prime[j] == 0) break;
        }
    }
}
int main() {
    Eular();
    int n;
    scanf("%d",&n);
    printf("%d\n",sum[n]);
	return 0;
}

