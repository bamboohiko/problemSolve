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
    int t,x,s;
    scanf("%d%d%d",&t,&s,&x);
    int d = (x-t)%s;
    if (x >= t && (x != t + 1) && (d == 0 || d == 1)) puts("YES");
    else puts("NO");
	return 0;
}
