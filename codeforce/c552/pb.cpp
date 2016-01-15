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
    long long  n,ans = 0,w = 1;
    scanf("%I64d",&n);
    while (n >= w) {
        ans += n - w + 1;
        w *= 10;
    }
    printf("%I64d\n",ans);
	return 0;
}
