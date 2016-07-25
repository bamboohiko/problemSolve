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
const int inf = -(1e9 + 7);
int a[2010],s[2010],q[2010];
int main() {
    int n,m;
    while (scanf("%d%d",&n,&m) != EOF) {
        for (int i = 1;i <= n; i++) {
            scanf("%d",&a[i]);
            a[n+i] = a[i];
        }
        for (int i = 1;i <= (n << 1); i++) s[i] = s[i-1] +a[i];
        int ans = inf;
        for (int i = 1;i + m <= (n << 1); i++) {
            //cout << (s[i+m-1] - s[i-1]) << endl;
            ans = max(ans,s[i+m-1] - s[i-1]);
        }
        printf("%d\n",ans);
    }
	return 0;
}

