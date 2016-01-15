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
const int maxn = 2e5 + 100;
char a[maxn],b[maxn];
bool dfs(int l1,int l2,int len) {
    bool ans = true;
    for (int i = 0;i < len; i++)
        if (a[l1 + i] != b[l2 + i]) {
            ans = false;
            break;
        }
    if (ans || len%2) return ans;
    else {
        int nlen = len >> 1;
        return dfs(l1,l2 + nlen,nlen) && dfs(l1 + nlen,l2,nlen);
    }
}
int main() {
    a[0] = b[0] = ' ';
    scanf("%s%s",a+1,b+1);
    if (dfs(1,1,strlen(a)-1)) printf("YES\n");
    else printf("NO\n");
	return 0;
}
