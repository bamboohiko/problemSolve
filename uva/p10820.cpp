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
const int maxn = 5e4;
int phi[maxn + 10],sum[maxn + 10];
void phi_table(int n) {
    phi[1] = 1;
    for (int i = 2;i <= n; i++)
        if (!phi[i]) {
            for (int j = i;j <= n;j += i) {
                if (!phi[j]) phi[j] = j;
                phi[j] = phi[j]/i*(i-1);
            }
        }
    for (int i = 2;i <= n; i++) sum[i] = sum[i-1] + phi[i];
}
int main() {
    phi_table(maxn);
    int n;
    while (scanf("%d",&n) != EOF && n) {
        printf("%d\n",sum[n]+sum[n]+1);
    }
	return 0;
}
