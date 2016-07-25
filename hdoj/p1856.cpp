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
const int maxn = 1e7 + 10;
int f[maxn],num[maxn];
stack<int> S;
int find(int k) {
    while (f[k] != -1) {
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
    int n,a,b;
    while (scanf("%d",&n) != EOF) {
        memset(f,-1,sizeof(f));
        memset(num,0,sizeof(num));
        int ans = 0;
        for (int i = 1;i <= n; i++) {
            scanf("%d %d",&a,&b);
            a = find(a);b = find(b);
            //cout << a << ":" << b << endl;
            if (a != b) {f[a] = b;num[b] += num[a]+1;ans = max(ans,num[b]);}
        }
        printf("%d\n",ans+1);
    }
	return 0;
}
