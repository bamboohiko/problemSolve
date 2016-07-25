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
const int maxm = 1e6;
int f[maxm + 100][5];
int dfs(int r,int k) {
    if (k == 3) {
        int x = floor(sqrt(r) + 0.5);
        if (r == x*x) return 1;
        else return 0;
    }
    if (f[r][k]) return f[r][k];
    for (int i = 0;i*i <= r; i++)
        f[r][k] += dfs(r-i*i,k+1);
    return f[r][k];
}
int main() {
    int t;
    scanf("%d",&t);g
    for (int ca = 1;ca <= t; ca++) {
        int r;
        scanf("%d",&r);
        printf("%d\n",dfs(r,0));
    }
	return 0;
}
