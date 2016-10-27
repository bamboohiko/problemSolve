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
    int m = 0,c = 0;
    int a,b;
    while (n--) {
        scanf("%d%d",&a,&b);
        if (a > b) m++;
        if (a < b) c++;
    }
    if (m > c) puts("Mishka");
    else if (m < c) puts("Chris");
    else puts("Friendship is magic!^^");
	return 0;
}
