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
const int inf = 1e9 + 7;
int a[10010],s[10010],n;
bool f[10010];
bool dp(int sum) {
    //cout << sum << endl;
    for (int i = 0;i < n; ) {
        int j = upper_bound(s+1,s+n+1,s[i] + sum) - s-1;
        if (s[j] != s[i] + sum) return false;
        else i = j;
    }
    return true;
}
int main() {
    int t,ca;
    scanf("%d",&t);
    while (t--) {
        scanf("%d%d",&ca,&n);
        for (int i = 1;i <= n; i++) {
            scanf("%d",&a[i]);
            s[i] = s[i-1] + a[i];
        }
        int ans = 0;
        for (int i = n;i >= 1; i--)
            if (s[n]%i == 0 && dp(s[n]/i)) {
                ans = s[n]/i;
                break;
            }
        printf("%d %d\n",ca,ans);
    }
	return 0;
}

