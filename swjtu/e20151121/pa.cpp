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
string st;
int main() {
    int t;
    scanf("%d",&t);
    while (t--) {
        cin >> st;
        int ans = 0;
        for (int i = 0;i < st.size()-1; ) {
            if (st[i+1] == '~') {
                if (st[i+2] == '~' || (st[i] == '_' && st[i+2] == '-')) {
                    ans = -1;
                    break;
                } else ans++,i+=2;
            } else if (st[i] == '_' && st[i+1] == '-') {
                ans++;
                i++;
            } else i++;
        }
        if (ans == -1) puts("Gua will give it up!");
        else if (ans <= 1) printf("Gua will click %d time.\n",ans);
        else printf("Gua will click %d times.\n",ans);
    }
	return 0;
}
