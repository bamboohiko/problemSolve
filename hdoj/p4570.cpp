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
typedef long long LL;
const LL inf = 1e9 + 7;
LL e2[100],f[100],a[100];
void init() {
    e2[0] = 1;
    for (int i = 1;i <= 25; i++)
        e2[i] = e2[i-1] << 1;
}
int main() {
    init();
    int t;
    scanf("%d",&t);
    while (t--) {
        int n;
        scanf("%d",&n);
        for (int i = 1;i <= n; i++) {
            scanf("%lld",&a[i]);
            f[i] = inf;
        }
        for (int i = 1;i <= n; i++) {
            for (int j = max(0,i-20);j < i; j++)
                f[i] = min(f[i],f[j] + a[j+1]*e2[i-j]);
            //cout << f[i] << endl;
        }
        printf("%lld\n",f[n]);
    }
	return 0;
}

