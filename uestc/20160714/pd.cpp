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
typedef long long LL;
char st[200100];
int ans[200100];
set<char>  S;
int main() {
    int k;
    scanf("%d%s",&k,st);
    int n = strlen(st),l = 0;
    for (int i = 0;i < n; i++) {
        S.insert(st[i]);
        if (S.size() < k) ans[i] = -1;
        else  {
            if (ans[i-1] != -1) ans[i] = ans[i-1];
            else ans[i] = 1;
            if (sum > k) {
                ans[i] = ans[i-1] + 1;
                l = i;
            }
        }
    }
    printf("%d",ans[0]);
    for (int i = 1;i < n; i++) printf(" %d",ans[i]);
    printf("\n");
	return 0;
}
