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
    int to,next;
};
struct point{
    int p,h;
};
Edge edge[1010];
int head[1010],heg[1010],cou;
queue<point> Q;
void build(int from,int to) {
    edge[++cou].to = to;edge[cou].next = head[from];head[from] = cou;
}
int main() {
    int n;
    while (scanf("%d",&n) != EOF) {
        memset(head,-1,sizeof(head));
        memset(heg,0,sizeof(heg));
        int from,to;cou = 0;
        for (int i = 1;i < n; i++) {
            scanf("%d%d",&from,&to);
            build(from,to);
        }
        int m = 1;
        Q.push((point){1,1});
        while (!Q.empty()) {
            point now = Q.front();Q.pop();
            heg[now.h]++;m = max(m,now.h);
            for (int i = head[now.p];i != -1; i = edge[i].next)
                Q.push((point){edge[i].to,now.h+1});
        }
        int ok = 1;
        for (int i = 2;i <= m; i++)
            if (heg[i] && heg[i-1] > 1) {
                ok = 0;
                break;
            }
        if (ok) printf("YES\n");
        else printf("NO\n");
    }
	return 0;
}

