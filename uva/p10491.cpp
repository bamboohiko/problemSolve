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
    int a,b,c;
    while (scanf("%d%d%d",&a,&b,&c) != EOF) {
        double ans = (double)b*(a+b-1)/(a+b)/(a+b-c-1);
        printf("%.5lf\n",ans);
    }
	return 0;
}
