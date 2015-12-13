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
    double n,p;
    while (scanf("%lf%lf",&n,&p) != EOF) {
        double k = log2(p)/n;
        int ans = pow(2,k) + eps;
        //像这样也可以过OTZ
        // int ans = (double)pow(p,1/n) + eps;
        printf("%d\n",ans);
    }
	return 0;
}
