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
struct mat{
    int h,w;
};
mat Q[200100];
int main() {
    int n;
    scanf("%d",&n);
    mat m;
    int p = 0,ans = 0;
    for (int i = 1;i <= n; i++) {
        scanf("%d%d",&m.w,&m.h);
        int sumw = 0;
        while (p > 0 && m.h <= Q[p].h) {
            ans = max(ans,Q[p].h*(Q[p].w+sumw));
            sumw += Q[p--].w;
        }
        m.w += sumw;
        Q[++p] = m;
    }
    int sumw = 0;
    while (p > 0) {
        ans = max(ans,Q[p].h*(Q[p].w + sumw));
        sumw += Q[p--].w;
    }
    printf("%d\n",ans);
	return 0;
}
