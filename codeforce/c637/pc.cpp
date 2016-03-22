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
string st[1010];
int main() {
    int n,ans = 6;
    scanf("%d",&n);
    for (int i = 1;i <= n; i++) cin >> st[i];
    for (int i = 1;i <= n; i++)
        for (int j = i+1;j <= n; j++) {
            int dis = 0;
            for (int k = 0;k < 6; k++)
                if (st[i][k] != st[j][k]) dis++;
            if (dis > 0 ) dis = (dis-1)/2;
            ans = min(ans,dis);
        }
    printf("%d\n",ans);
	return 0;
}

