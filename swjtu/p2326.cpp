#include <stdio.h>
#include <cstring>
#define clr(x) memset(x, 0, sizeof(x))
const int INF = 0x1f1f1f1f;

bool G[100010][15];
int limit[15];
bool vis[15];
int v1, v2;
int v[15];
int vv[15][100010];

bool find(int u)
{
    int i, j, k;
    for(i = 0; i < v2; ++i) {
        if(G[u][i] && !vis[i]) {
            vis[i] = true;
            if(v[i] < limit[i]) {
                vv[i][v[i]++] = u;
                return true;
            }

            for(j = 0; j < v[i]; ++j) {
                if(find(vv[i][j])) {
                    vv[i][j] = u;
                    return true;
                }
            }
        }
    }
    return false;
}

bool solve()
{
    clr(v), clr(vv);
    for(int i = 0; i < v1; ++i) {
        clr(vis);
        if(!find(i)) {
            return false;
        }
    }
    return true;
}

int main()
{
    int i, j, k;
    //freopen("data3.in", "r" ,  stdin);
    //freopen("data.out", "w", stdout);
    while(scanf("%d %d", &v1, &v2) != EOF)
    {
        clr(G);

        for(i = 0; i < v1; ++i)
        for(j = 0; j < v2; ++j) {
            scanf("%d", &G[i][j]);
        }
        for(i = 0; i < v2; ++i)
            scanf("%d", &limit[i]);

        if(solve()) puts("YES");
        else puts("NO");
    }

    return 0;
}
