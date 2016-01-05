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
const int maxn = 1e5 + 100;
int f[maxn],dis[maxn];
stack<int> S;
int find(int k) {
    while (f[k] != k) {
        S.push(k);
        k = f[k];
    }
    int sum = 0;
    while (!S.empty()) {
        int p = S.top();S.pop();
        sum += dis[p];dis[p] = sum;
        f[p] = k;
    }
    return k;
}
int main() {
    int n,x,y,fy;char ch;
    scanf("%d",&n);
    for (int i = 1;i <= n; i++) {f[i] = i;dis[i] = 0;}
    while (scanf(" %c",&ch) != EOF && ch != 'O') {
        if (ch == 'E') {
            scanf("%d",&x);
            find(x);
            printf("%d\n",dis[x]);
        }
        if (ch == 'I') {
            scanf("%d%d",&x,&y);
            x = find(x);fy = find(y);
            if (x != fy) {f[x] = y;dis[x] = abs(x-y)%1000;}
        }
    }
    //for (int i = 1;i <= n; i++) printf("%d %d\n",f[i],dis[i]);
	return 0;
}
