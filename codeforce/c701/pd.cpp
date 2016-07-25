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
#define eps 1e-6
#define pi acos(-1.0)
using namespace std;
typedef long long LL;
int n,k;
double l,v1,v2;
bool check(double t) {
    int m = (n-1)/k + 1;
    double nt = 0,b = 0;
    for (int i = 1;i < m; i++) {
        double dt = (b-nt*v1)/(v1+v2);nt += dt;
        dt = (l-nt*v1-(t-nt)*v1)/(v2-v1);
        b = nt*v1 + dt*v2;nt += dt;
        //cout << nt*v1 << " " << b << endl;
        if (nt > t) break;
    }
    double dt = (b-nt*v1)/(v1+v2);nt += dt;
    nt += (l-nt*v1)/v2;
    if (nt <= t) return true;
    else return false;
}
int main() {
    scanf("%d%lf%lf%lf%d",&n,&l,&v1,&v2,&k);
    double x = l/v2,y = l/v1;
    while (y-x > eps) {
        double mid = (x+y)/2;
        if (check(mid)) y = mid;
        else x = mid;
        cout <<x << " " << y << endl;
    }
    printf("%.10lf\n",y);
	return 0;
}
