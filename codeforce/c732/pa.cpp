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
    int x,y;
    scanf("%d%d",&x,&y);
    int ans = 10;
    for (int i = 1;i <= 10; i++)
        if (i*x%10 == y || i*x%10 == 0) {
            ans = i;
            break;
        }
    printf("%d\n",ans);
	return 0;
}
