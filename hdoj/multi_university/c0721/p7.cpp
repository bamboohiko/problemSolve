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
struct Edge {
    int to,dist,next;
};
Edge edge
int main() {
    int n,m;
    while (scanf("%d%d",&n,&m) != EOF) {
        for (int i = 1;i <= m; i++) {
            scanf("%d%d%d",&from,&to,&dist);
            build (from,to,dist);
        }
        spfa();
        dfs(1);

    }
	return 0;
}
