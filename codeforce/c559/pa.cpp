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
    int up,down,l1,l2,r1,r2;
    scanf("%d%d%d%d%d%d",&up,&r1,&r2,&down,&l2,&l1);
    up = up*2 + 1;down = down*2 + 1;
    int ans = 0;
    if (l1 == r1) {
        ans += up*l1 + l1*(l1-1);
        ans += down *l2 + l2*(l2-1);
    } else {
        int d1 = min(l1,r1);
        int d2 = max(l1,r1) - d1;
        int d3 = min(l2,r2);
        ans += up*d1 + d1*(d1-1);
        ans += down*d3 + d3*(d3-1);
        ans += (up + 2*(d1-1) + 1)*d2;
    }
    printf("%d\n",ans);
	return 0;
}
