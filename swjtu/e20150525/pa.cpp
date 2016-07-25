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
int main()
{
    int t,turn = 0;
    scanf("%d",&t);
    while (turn++ < t) {
        double k;
        scanf("%lf",&k);
        printf("Case #%d: ",turn);
        if (k >= 1.0) printf("Too Bright\n");
        if (k >= 0.400 && k < 1.000) printf("1\n");
        if (k >= 0.160 && k < 0.400) printf("2\n");
        if (k >= 0.063 && k < 0.160) printf("3\n");
        if (k >= 0.025 && k < 0.063) printf("4\n");
        if (k >= 0.010 && k < 0.025) printf("5\n");
        if (k >= 0.004 && k < 0.010) printf("6\n");
        if (k < 0.004) printf("Invisible\n");

    }
	return 0;
}
