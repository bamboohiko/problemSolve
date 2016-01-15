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
    int n;
    scanf("%d",&n);
    int la = 0,len = 0,ans = 0,k;
    for (int i = 1;i <= n; i++) {
        scanf("%d",&k);
        if (k >= la) len++;
        else {
            ans = max(ans,len);
            len = 1;
        }
        la = k;
    }
    ans = max(ans,len);
    printf("%d\n",ans);
	return 0;
}

