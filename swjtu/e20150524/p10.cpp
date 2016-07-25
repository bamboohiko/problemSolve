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
    int n,m,a,b;
    scanf("%d%d%d%d",&n,&m,&a,&b);
    int ans = (n/m+1)*b;
    for (int i = 0;i*m <= n; i++) {
        ans = min(ans,i*b + (n-i*m)*a);
    }
    printf("%d\n",ans);
	return 0;
}
