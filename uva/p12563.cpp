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
const int inf = 1e9 + 7;
int f[11000],a[110];
int main() {
    int t,ca = 1;
    scanf("%d",&t);
    while (t--) {
        int n,v,sum = 1;
        scanf("%d%d",&n,&v);
        for (int i = 1;i <= n; i++) {
            scanf("%d",&a[i]);
            sum += a[i];
        }
        if (sum < v) v = sum;
        for (int i = 1;i < v; i++) f[i] = -inf;f[0] = 0;
        for (int i = 1;i <= n; i++) {
            for (int j = v-1;j >= a[i];j--)
                f[j] = max(f[j],f[j-a[i]]+1);
        }
        int p = 0;
        for (int i = v-1;i > 0; i--) {
            if (f[i] > f[p]) p = i;
        }
        printf("Case %d: %d %d\n",ca++,f[p]+1,p+678);
    }
	return 0;
}
