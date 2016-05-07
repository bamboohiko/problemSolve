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
    int n;
    scanf("%d",&n);
    int a = n/7*2,b = n%7;
    printf("%d %d\n",a+(b == 6),a+min(b,2));
	return 0;
}

