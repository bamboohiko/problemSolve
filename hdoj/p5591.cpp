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
    int t,x;
    scanf("%d",&t);
    while (t--) {
        scanf("%d",&x);
        if (x%2 == 1) puts("1");
        else puts("0");
    }
	return 0;
}
