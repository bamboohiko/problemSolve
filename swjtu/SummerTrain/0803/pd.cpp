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
const double pi = acos(-1.0);
const double k = (8.0-2.0*sqrt(2))*pi/3;
int main() {
    double r;
    while (scanf("%lf",&r) != EOF) {
        printf("%.2lf\n",k*r*r*r);
    }
	return 0;
}
