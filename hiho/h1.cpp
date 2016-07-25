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
#define INF 0x3f3f3f3f
#define eps 1e-8
#define pi acos(-1.0)
using namespace std;
const int maxlen = 3e6 + 10;
char st[maxlen];
int f[maxlen];
int main() {
    int t;
    scanf("%d%*c",&t);
    st[0] = '@';st[1] = '#';
    while (t--) {
        int i = 2;
        while (true) {
            st[i++] = getchar();
            if (st[i-1] == '\n') break;
            st[i++] = '#';
        }
        st[i-1] = '$';
        //puts(st);
        int r = 1,ans = 0,len = i-1;
        for (int i = 1;i < len; i++) {
            int j = min(f[(r<<1)-i],f[r]-((i-r)<<1)) >> 1;
            //cout << j <<endl;
            for (;st[i-j-1] == st[i+j+1];j++) ;
            f[i] = 1+(j << 1);
            if (i+(f[i]>>1) > r+(f[r]>>1)) r = i;
            ans = max(ans,j);
        }
        printf("%d\n",ans);
    }
	return 0;
}
