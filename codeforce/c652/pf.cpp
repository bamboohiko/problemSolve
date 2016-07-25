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
const int maxn = 3e5 + 100;
int a[maxn],b[maxn];
int main() {
    int n,m,t;
    int loc;char dir;
    for (int i = 1;i <= n; i++) {
        scanf("%d%*c%c",&b[i],&dir);
        if (dir == 'L') a[i] = (b[i]-t%m+t)%m;
    }
	return 0;
}

