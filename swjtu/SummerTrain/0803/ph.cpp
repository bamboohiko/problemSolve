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
const double dx = 0.0001;
double f(double x) {
    return x/sqrt(x*x*x+1);
}
int main() {
    double x;
    while (scanf("%lf",&x) != EOF) {
        double ans = 0;
        while (x > 0) {
            ans += f(x)*dx;
            x -= dx;
        }
        printf("%.4lf\n",ans);
    }
	return 0;
}
