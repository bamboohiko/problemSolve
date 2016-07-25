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
    int h1,h2,a,b;
    scanf("%d%d%d%d",&h1,&h2,&a,&b);
    int ans = 0;
    if (h2-h1 > 8*a) {
        if (a > b) ans = (h2-h1-8*a-1)/((a-b)*12) + 1;
        else ans = -1;
    }
    printf("%d\n",ans);
	return 0;
}

