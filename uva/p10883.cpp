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
    int t,n;
    scanf("%d",&t);
    for (int ca = 1;ca <= t;ca++) {
        double c = 1,k,ans = 0;
        scanf("%d",&n);
        for (int i = 0;i < n; i++) {
            scanf("%lf",&k);
            ans += c*k;
            c = c*(n-1-i)/(i+1);
        }
        //printf("%.3lf",ans);
        ans /= pow(2,n-1);
        printf("Case #%d: %.3lf\n",ca, ans);
    }
	return 0;
}
