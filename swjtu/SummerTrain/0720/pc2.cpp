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
using namespace std;
const double eps = 1e-9;
int main() {
    int t;
    scanf("%d",&t);
    for (int ca = 1;ca <= t; ca++) {
        printf("Case #%d: ",ca);
        double a,b,c;
        scanf("%lf%lf%lf",&a&b,&c);
        if (a == 0) {
            if (b == 0) printf("INF\n");
            else if (c == 0) printf("1\n%.2lf\n",0);
            else printf("1\n%.2lf\n",-c/b);
        } else {

        }
    }
	return 0;
}
