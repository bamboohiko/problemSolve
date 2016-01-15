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
    scanf("%d",&n);
    if (n&1) printf("0\n");
    else printf("%d\n",(n/2-1)/2);
	return 0;
}
