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
int main() {
    int d1,d2,d3;
    scanf("%d%d%d",&d1,&d2,&d3);
    int ans = d1+d2+d3;
    ans = min(ans,(d1+d2)<<1);
    ans = min(ans,(d1+d3)<<1);
    ans = min(ans,(d2+d3)<<1);
    printf("%d\n",ans);
	return 0;
}
