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
    int n,d1,d2;
    while (scanf("%d%d%d",&n,&d1,&d2) != EOF) {
        int len = 1,t = 0,la,now;
        long long ans = 1;
        scanf("%d",&la);
        for (int i = 2;i <= n; i++) {
            scanf("%d",&now);
            if (!t)
                if (now - la == d1) len++;
                else t = 1;
            if (t)
                if (now - la == d2) len++;
                else {
                    len = 1;t = 0;
                    if (now - la == d1) len++;
                }
            ans += len;
            la = now;
        }
        printf("%lld\n",ans);
    }
	return 0;
}

