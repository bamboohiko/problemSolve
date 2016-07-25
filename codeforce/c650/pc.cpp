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
vector<int> r[1000100];
vector<int> c[1000100];
int main() {
    int n,m,x;
    for (int i = 1;i <= n; i++)
        for (int j = 1;j <= m; j++) {
            scanf("%d",&x);
            r[i].push_back(x);
            c[j].push_back(x);
        }
	return 0;
}

