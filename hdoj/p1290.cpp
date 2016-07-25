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
int main() {
    int n;
    while (scanf("%d",&n) != EOF) {
        printf("%lld\n",((long long)n*n*n+5*n)/6 + 1);
    }
	return 0;
}
