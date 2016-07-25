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
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    int ans = a+b+c;
    ans = max(ans,a*b*c);
    ans = max(ans,a*b+c);
    ans = max(ans,a+b*c);
    ans = max(ans,(a+b)*c);
    ans = max(ans,a*(b+c));
    printf("%d\n",ans);
	return 0;
}
