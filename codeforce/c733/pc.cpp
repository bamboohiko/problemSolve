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
bool f[510][510];
int a[510],b[510],sum[510],loc[510],cnt[510];
int print(int i,int j) {
    if (i == j) return i;
    if (f[i][j-1] && (sum[j-1]-sum[i-1] > a[j])) {
        int k = print(i,j-1);
        printf("%d R\n",k);

        return k;
    } else {
        int k = print(i+1,j);
        printf("%d L\n",k);
        return k;
    }
}
int main() {
    int n,m;
    scanf("%d",&n);
    for (int i = 1;i <= n; i++) {
        scanf("%d",&a[i]);
        sum[i] = sum[i-1] + a[i];
    }
    for (int i = 1;i <= n; i++) f[i][i] = true;
    for (int len = 1;len < n; len++)
        for (int i = 1;i + len <= n; i++) {
            int j = i + len;
            f[i][j] = ((f[i][j-1] && (sum[j-1]-sum[i-1] > a[j])) || (f[i+1][j] && (sum[j]-sum[i] > a[i])));
        }
    scanf("%d",&m);
    int k = 1;
    bool pass = true;
    for (int i = 1;i <= m; i++) {
        scanf("%d",&b[i]);
        while (k < n && sum[k] - sum[loc[i-1]] < b[i]) k++;
        if (sum[k] - sum[loc[i-1]] > b[i] || !f[loc[i-1]+1][k]) {
            pass = false;
            break;
        }
        loc[i] = k;
    }
    if (!pass) puts("NO");
    else {
        puts("YES");
        for (int i = 1;i <= n; i++) cnt[i] = i;
        for (int i = 1;i <= m; i++) print(loc[i-1]+1,loc[i]);
    }
	return 0;
}
