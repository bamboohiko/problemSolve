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
    int t;
    scanf("%d",&t);
    while (t--){
        int n,m,p,q;
        scanf("%d%d%d%d",&n,&m,&p,&q);
        int i = 1,ans = p*n;
        while (i*m < n) {
            ans = min(ans,q*i+ p*(n - i*m));
            i++;
        }
        ans = min(ans,q*i);
        printf("%d\n",ans);
    }
	return 0;
}
