#include<iostream>
#include<cstdio>
#include<map>
#include<set>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
map<int,int> dir;
queue<int> a[100100];
int main()
{
    int n,m;
    while (scanf("%d%d",&n,&m) != EOF) {
        int k;
        for (int i = 1;i <= n; i++) {
            scanf("%d",&k);
            if (!dir.count(k)) dir[k] = dir.size();
            a[dir[k]].push(i);
        }
        for (int i = 1;i <= m; i++) {
            scanf("%d",&k);
            if (dir.count(k) && !a[dir[k]].empty()) {
                int ans = a[dir[k]].front();a[dir[k]].pop();
                printf("%d\n",ans);
            } else {
                printf("%d\n",-1);
            }
        }
        for (int i = 0;i < dir.size(); i++) {
            while (!a[i].empty()) a[i].pop();
        }
        dir.clear();
    }
	return 0;
}
