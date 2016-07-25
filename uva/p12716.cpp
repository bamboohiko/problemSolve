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
const int maxn = 3e7;
int ans[maxn + 10];
int gcd(int a,int b) {
    while (b) {
        int t = a;a = b;b = t%b;
    }
    return a;
}
int main() {
    int t,T = 1;
    scanf("%d",&t);
    for (int i = 1;i <= maxn; i++) {
            for (int j = i+i;j <= maxn;j += i) {
                if (j-(j^i) == i) ans[j]++;
            }
        }
    for (int i = 2;i <= maxn; i++) ans[i] += ans[i-1];
    while (t--) {
        int n;
        scanf("%d",&n);
        printf("Case %d: %d\n",T++,ans[n]);
    }
	return 0;
}
