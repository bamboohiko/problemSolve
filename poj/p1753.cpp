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
const int maxn = 1e5;
struct node{
    int step,k;
};
queue<node> Q;
bool vis[maxn];
int main() {
    node s;char ch;
    s.k = s.step = 0;
    for (int i = 0;i < 4;i++) {
        for (int j = 0;j < 4;j++) {
            ch = getchar();
            if (ch == 'w')  s.k += 1 << (i*4+j);
        }
        getchar();
    }
    vis[s.k] = true;
    Q.push(s);
    int ans = -1;
    while (!Q.empty()) {
        node s = Q.front();Q.pop();
        if (s.k == 0 || s.k == (1 << 16)-1) {ans = s.step;break;}
        for (int i = 0;i < 4;i++)
            for (int j = 0;j < 4;j++) {
                node t = s;
                t.k ^= 1 << (i*4+j);
                if (i > 0) t.k ^= 1 << ((i-1)*4+j);
                if (i < 3) t.k ^= 1 << ((i+1)*4+j);
                if (j > 0) t.k ^= 1 << (i*4+j-1);
                if (j < 3) t.k ^= 1 << (i*4+j+1);
                if (!vis[t.k]) {
                    vis[t.k] = true;
                    t.step = s.step + 1;
                    Q.push(t);
                }
            }
    }
    if (ans == -1) puts("Impossible");
    else printf("%d\n",ans);
	return 0;
}
