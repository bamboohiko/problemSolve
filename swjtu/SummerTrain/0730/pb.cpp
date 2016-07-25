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
typedef long long LL;
LL pri[6] = {6,28,496,8128,33550336,134216704};
const int n = 6;
int main() {
    pri[5] *= 64;
    int t;
    scanf("%d",&t);
    for (int ca = 1;ca <= t;ca++) {
        long long l,r;
        scanf("%lld%lld",&l,&r);
        int cou = 0;
        for (int i = 0;i < n; i++) {
            if (l <= pri[i] && r >= pri[i]) cou++;
        }
        printf("Case #%d: %d\n",ca,cou);
    }
	return 0;
}


