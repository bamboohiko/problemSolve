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
bool vis[1010];
int main()
{
    int n,m,k;
    scanf("%d",&n);
    scanf("%d",&m);
    for (int i = 0;i < m; i++) {
        scanf("%d",&k);
        vis[k] = true;
    }
    scanf("%d",&m);
    for (int i = 0;i < m; i++) {
        scanf("%d",&k);
        vis[k] = true;
    }
    bool ans = true;
    for (int i = 1;i <= n; i++)
        if (!vis[i]) {
            ans = false;
            break;
        }
    if (ans) printf("I become the guy.\n");
    else printf("Oh, my keyboard!\n");
	return 0;
}
