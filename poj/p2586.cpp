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
int main() {
    int s,d;
    while (scanf("%d%d",&s,&d) != EOF) {
        int ans = 0;
        if (d >= 4*s) ans = 10*s - 2*d;
        else if (2*d >= 3*s) ans = 8*s-4*d;
        else if (3*d >= 2*s) ans = 6*s-6*d;
        else if (4*d >= s) ans = 3*s - 9*d;
        else ans = -1;
        if (ans < 0) puts("Deficit");
        else printf("%d\n",ans);
    }
	return 0;
}

