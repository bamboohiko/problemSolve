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
    int n,c;
    while (scanf("%d%d",&n,&c) != EOF) {
        if (n == 0) {
            printf("0\n");
            continue;
        }
        double ans = (double)c/2/n;
        if (ans - floor(ans) > 0.5) ans = ceil(ans);
        else ans = floor(ans);
        printf("%.0lf\n",ans);
    }
	return 0;
}
