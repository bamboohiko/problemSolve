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
using namespace std;
int main()
{
    int t,a,b;
    int ans = 0;
    scanf("%d",&t);
    while (t--) {
        scanf("%d%d",&a,&b);
        if (b-a >= 2) ans++;
    }
    printf("%d\n",ans);
	return 0;
}
