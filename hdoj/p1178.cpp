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
    double n;
    while (scanf("%lf",&n) != EOF && n != 0) {
        double ans = ((n+1)*(n+2)*(n+n+3)/6 - (n+2)*(n+1)/2)/2;
        double m = log10(ans);
        double k = pow(10.,m - (long long)m);
        printf("%.2lfE%lld\n",k,(long long)m);
    }
	return 0;
}

