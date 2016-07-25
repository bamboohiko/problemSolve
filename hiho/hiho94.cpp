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
int dfs(int n,int k) {
    int ans;
    if (n >= k) {
        int rec = dfs(n-n/k,k);
        if (rec < n%k) ans = rec - n%k + n;
        else ans = rec - n%k + (rec - n%k)/(k-1);
    } else {
        ans = 0;
        for (int i = 2;i <= n; i++) ans = (ans + k)%i;
    }
    return ans;
}
int main() {
    int t,n,k;
    scanf("%d",&t);
    while (t--) {
        scanf("%d%d",&n,&k);
        printf("%d\n",dfs(n,k));
    }
	return 0;
}

