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
    int t,n,ans;
    scanf("%d",&t);
    while (t--) {
        scanf("%d",&n);
        for (int i = 1; ; i++) {
            if (n <= i) ans = (n-1)%9 + 1;
            n -= i;
            if (n <= 0) break;
        }
        printf("%d\n",ans);
    }
	return 0;
}
