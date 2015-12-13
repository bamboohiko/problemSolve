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
const int maxn = 10000;
int prime[maxn + 10],m = 0;
int cou[maxn + 10];
bool vis[maxn + 10];
int init() {
    for (int i = 2;i <= maxn; i++)
        if (!vis[i]) {
            prime[++m] = i + prime[m-1];
            for (int j = i+i;j <= maxn; j += i) vis[j] = true;
        }
    for (int i = 1;i <= m; i++)
        for (int j = i-1;j >= 0; j--)
            if (prime[i]-prime[j] <= maxn) cou[prime[i]-prime[j]]++;
            else break;
}
int main() {
    init();
    int n;
    while (scanf("%d",&n) != EOF) {
        if (!n) break;
        printf("%d\n",cou[n]);
    }
	return 0;
}
