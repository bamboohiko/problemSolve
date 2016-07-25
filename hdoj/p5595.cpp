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
int a,b,c,l,r;
int f(int x) {
    return a*x*x + b*x + c;
}
int main() {
    int t;
    scanf("%d",&t);
    while (t--) {
        scanf("%d%d%d%d%d",&a,&b,&c,&l,&r);
        int maxf = f(l),minf = maxf;
        for (int i = l+1;i <= r; i++) {
            int ans = f(i);
            maxf = max(ans,maxf);
            minf = min(ans,minf);
        }
        printf("%d %d\n",maxf,minf);
    }
	return 0;
}
