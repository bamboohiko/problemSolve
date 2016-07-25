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
struct Edge{
    int from,to,dis;
};
Edge edge[20100];
int d[1010],cou;
int build(int from,int to,int dis) {
    edge[++cou].from = from;edge[cou].to = to;edge[cou].dis = dis;
}
int main() {
    int n,ml,md;cou = 0;
    int from,to,dis;
    scanf("%d%d%d",&n,&ml,&md);
    for (int i = 1;i < n; i++) {
        build(i+1,i,0);
    }
    for (int i = 1;i <= ml; i++) {
        scanf("%d%d%d",&from,&to,&dis);
        build(from,to,dis);
    }
    for (int i = 1;i <= md; i++) {
        scanf("%d%d%d",&from,&to,&dis);
        build(to,from,-dis);
    }
    for (int i = 2;i <= n; i++) d[i] = INF;d[1] = 0;
    for (int i = 1;i <= n; i++)
        for (int j = 1;j <= cou; j++) {
            if (d[edge[j].to] > d[edge[j].from] + edge[j].dis) {
                d[edge[j].to] = d[edge[j].from] + edge[j].dis;
            }
        }
    //for (int i = 1;i <= n; i++) cout << d[i] << " ";cout << endl;
    int ans = d[n];
    if (d[1] < 0) ans = -1;
    else if (d[n] == INF) ans = -2;
    printf("%d\n",ans);
	return 0;
}

