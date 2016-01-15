#include<iostream>
#include<cstdio>
#include<map>
#include<set>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
    int k,n,w;
    scanf("%d%d%d",&k,&n,&w);
    printf("%d\n",max((w+1)*w/2*k-n,0));
	return 0;
}
