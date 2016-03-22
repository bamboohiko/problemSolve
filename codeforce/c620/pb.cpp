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
const int v[10] = {6,2,5,5,4,5,6,3,7,6};
int main() {
    int a,b,ans = 0;
    scanf("%d%d",&a,&b);
    for (int i = a;i <= b; i++) {
        int p = i;
        while (p) {
            ans += v[p%10];
            p /= 10;
        }
    }
    printf("%d\n",ans);
	return 0;
}

