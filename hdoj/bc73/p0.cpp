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
int main() {
    int t;
    int n,m;
    scanf("%d",&t);
    while (t--) {
        scanf("%d%d",&n,&m);
        printf("%d\n",(n>>1) + (m>>1));
    }
	return 0;
}

