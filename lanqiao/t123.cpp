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
const int maxn = 1e5 + 100;
int a[maxn],p[maxn],t[maxn];
int n;
int sum(int k) {
    int ans = 0;
    for (int i = k;i > 0;i -= i&(-i)) ans += t[i];
    return ans;
}
void ins(int k) {
    for (int i = k;i <= n;i += i&(-i)) t[i]++;
}
bool cmp(int x,int y) {
    return a[x] < a[y];
}
int main() {
    scanf("%d",&n);
    for (int i = 1;i <= n; i++) {
        scanf("%d",&a[i]);p[i] = i;
    }
    sort(p+1,p+n+1,cmp);
    for (int i = 1;i <= n; i++) cout << p[i] << " ";cout << endl;
    int ans = 0;
    for (int i = 1;i <= n; i++) {
        int k = sum(n) - sum(p[i]);
        ans += k*(k+1);
        ins(p[i]);
    }
    printf("%d\n",ans);
	return 0;
}

