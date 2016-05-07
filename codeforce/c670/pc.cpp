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
map<int,int> cnt;
int a[200100],b[200100];
int main() {
    int n,m,k;
    scanf("%d",&n);
    for (int i = 1;i <= n; i++) {
        scanf("%d",&k);
        if (!cnt.count(k)) cnt[k] = 1;
        else cnt[k]++;
    }
    scanf("%d",&m);
    for (int i = 1;i <= m; i++) {
        scanf("%d",&a[i]);
        a[i] = cnt[a[i]];
    }
    for (int i = 1;i <= m; i++) {
        scanf("%d",&b[i]);
        b[i] = cnt[b[i]];
    }
    int loc = 1;
    for (int i = 2;i <= m; i++) {
        if (a[i] > a[loc] || (a[i] == a[loc] && b[i] > b[loc])) loc = i;
    }
    printf("%d\n",loc);
	return 0;
}
