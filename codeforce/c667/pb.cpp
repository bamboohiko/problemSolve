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
    int n,k,m = 0,sum = 0;
    scanf("%d",&n);
    for (int i = 1;i <= n; i++) {
        scanf("%d",&k);
        m = max(m,k);
        sum += k;
    }
    printf("%d\n",2*m+1-sum);
	return 0;
}

