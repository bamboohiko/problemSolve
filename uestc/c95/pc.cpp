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
stack<int> S;
const int maxn = 2e5 + 100;
int f[maxn];
int find(int x) {
    while (f[x] != x) {
        S.push(x);
        x = f[x];
    }
    int k;
    while (!S.empty()) {
        k = S.top();S.pop();
        f[k] = x;
    }
    return x;
}
void uni(int x,int y) {
    int a = find(x),b = find(y);
    if (a != b) f[a] = b;
}
bool cut(int x,int y) {
    int a = find(x),b = find(y);
    return a == b;
}
int main() {
    int n;
    scanf("%d",&n);
    for (int i = 1;i <= n; i++) {f[i] = i;f[n+i] = n+i;}
    bool ans = true;
    int x,t;
    for (int i = 1;i <= n; i++) {
        scanf("%d%d",&x,&t);
        if (t == 1) {uni(i,x);uni(n+i,n+x);}
        else {uni(i,n+x);uni(n+i,x);}
        if (cut(i,n+i) || cut(x,n+x)) {
            ans = false;
            break;
        }
    }
    if (ans) puts("Time to show my power");
    else puts("One face meng bi");
	return 0;
}

