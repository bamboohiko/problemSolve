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
int k,f[15][105][105];
int dfs(int d,int m1,int m2) {
    if (f[d][m1][m2] != -1) return f[d][m1][m2];
    if (d == 0)
        if (m1 == 0 && m2 == 0) return 1;
        else return 0;
    f[d][m1][m2] = 0;
    int p = 1;
    for (int i = 1;i < d; i++) p = p*10%k;
    for (int i = 0;i < 10; i++)
        f[d][m1][m2] += dfs(d-1,(m1+i)%k,(m2+i*p)%k);
    return f[d][m1][m2];
}
int fig(int n) {
    int ans = 0;
    int d = 0,p = 1,sum = 0;
    for (int i = n; i; i/=10) sum += i%10;
    if (sum%k == 0 && n%k == 0) ans++;
    while (n) {
        int m = n%10;
        sum -= m;n /= 10;
        for (int i = 0;i < m; i++) {
            ans += dfs(d,(sum+i)%k,(n*10+i)*p%k);
        }
        d++;p *= 10;
    }
    return ans;
}
int main() {
    int t,l,r;
    scanf("%d",&t);
    while (t--) {
        memset(f,-1,sizeof(f));
        scanf("%d%d%d",&l,&r,&k);
        if (k < 100) printf("%d\n",fig(r)-fig(l-1));
        else printf("%d\n",0);
    }
	return 0;
}
