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
int main() {
    int t;
    scanf("%d",&t);
    for (int ca = 1;ca <= t; ca++) {
        double a,b,c;
        scanf("%lf%lf%lf",&a,&b,&c);
        printf("Case #%d: ",ca);
        if (a == 0) {
            if (b == 0) {
                if (c == 0) printf("INF\n");
                else printf("0\n");
            } else if (c == 0) printf("1\n%.2lf\n",0);
            else printf("1\n%.2lf\n",-c/b);
        } else {
            double drt = b*b - 4*a*c;
            if (drt < 0) printf("0\n");
            else if (drt == 0) {
                if (b == 0) printf("1\n%.2lf\n",0);
                else printf("1\n%.2lf\n",-b/(2*a));
            }
            else {
                printf("2\n%.2lf %.2lf\n",(-b - sqrt(drt))/(2*a),(-b + sqrt(drt))/(2*a));
            }
        }
    }
	return 0;
}
