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
vector<int> a[110];
bool cmp(int x,int y) {
    if (a[x].size() != a[y].size()) return false;
    for (int i = 0;i < a[x].size(); i++)
        if (a[x][i] != a[y][i]) return false;
    return true;
}
int main()
{
    int n;char k;
    scanf("%d",&n);
    for (int i = 1;i <= n; i++) {
        scanf("%*c");
        for (int j = 1;j <= n; j++) {
            scanf("%c",&k);
            if (k == '0') a[i].push_back(j);
        }
    }
    int ans = 0;
    for (int i = 1;i <= n; i++) {
        int sum = 0;
        for (int j = 1;j <= n; j++)
            if (cmp(i,j)) sum++;
        ans = max(ans,sum);
    }
    printf("%d\n",ans);
    return 0;
}
