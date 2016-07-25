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
const int inf = 1e5 + 7;
bool can[1010][1010];
int f[1010];
int main() {
    int t;
    scanf("%d",&t);
    string st;
    while (t--) {
        memset(can,false,sizeof(can));
        cin >> st;
        int n = st.size();
        for (int i = 0;i < n; i++) {
            int l = i,r = i;
            while (l >= 0 && r < n && st[l] == st[r]) {
                can[l][r] = true;
                l--;r++;
            }
            if (i < n-1 && st[i] == st[i+1]) {
                int l = i,r = i+1;
                while (l >= 0 && r < n && st[l] == st[r]) {
                    can[l][r] = true;
                    l--;r++;
                }
            }
        }
        f[0] = 0;
        for (int i = 1;i <= n; i++) {
            f[i] = i;
            for (int j = 0;j < i; j++)
                if (can[j][i-1]) f[i] = min(f[i],f[j]+1);
        }
        printf("%d\n",f[n]);
    }
	return 0;
}
