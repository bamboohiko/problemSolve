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
    double n,p,q;
    scanf("%lf%lf%lf",&n,&p,&q);
    double m1 = n/(p+q)*p;
    double m2 = 2*n/(p+q)*p-m1;
    printf("%lf\n",m2);
	return 0;
}

