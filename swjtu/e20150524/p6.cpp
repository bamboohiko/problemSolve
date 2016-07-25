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
    int n;
    scanf("%d",&n);
    if (n%2) printf("%d %d\n",9,n-9);
    else printf("%d %d\n",4,n-4);
	return 0;
}
