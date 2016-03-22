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
    LL x1,y1,x2,y2;
    scanf("%I64d%I64d",&x1,&y1);
    scanf("%I64d%I64d",&x2,&y2);
    printf("%I64d\n",max(abs(x1-x2),abs(y1-y2)));
	return 0;
}

