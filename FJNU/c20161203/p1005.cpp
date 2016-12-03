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
    int t;
    scanf("%d",&t);
    while (t--) {
        int ti,v1,v2;
        scanf("%d%d%d",&ti,&v1,&v2);
        int s = ti*(v1-v2)%400;
        printf("%.2lf\n",(double)s/v2);
    }
	return 0;
}
