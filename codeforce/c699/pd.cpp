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
int f[200100],a[200100];
stack<int> S;
int find(int k) {
    while (f[k] != k) {
        S.push(k);
        k = f[k];
    }
    while (!S.empty()) {
        int p = S.top();S.pop();
        f[p] = k;
    }
    return k;
}
int main() {
    int n,k,root = 0;
    scanf("%d",&n);
    for (int i = 1;i <= n; i++) f[i] = i;
    for (int i = 1;i <= n; i++) {
        scanf("%d",&a[i]);
        if (root == 0 && i == a[i]) root = a[i];
        int x = find(i),y = find(a[i]);
        if (x != y) f[x] = y;
    }
    int ans = 0;
    for (int i = 1;i <= n; i++)
        if (f[i] == i && f[i] != root) {
            ans++;
            if (root) a[i] = root;
            else a[i] = root = i;
        }
    //cout << root <<endl;
    printf("%d\n",ans);
    for (int i = 1;i < n; i++) printf("%d ",a[i]);
    printf("%d\n",a[n]);
	return 0;
}
