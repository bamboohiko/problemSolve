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
const int w[8] = {0,52,52,52,52,53,53,52};
const int m[32] = {0,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,11,7};
int main() {
    string st;int n;
    scanf("%d",&n);
    getline(cin,st);
    if (st[4] == 'w') printf("%d\n",w[n]);
    else printf("%d\n",m[n]);
	return 0;
}
