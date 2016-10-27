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
const int ans[1001] = {0,0,1,3,2,3,3,3,3,4,4,4,4,5,4,5,4,5,5,5,5,5,5,6,5,6,6,6,5,6,6,6,5,6,6,6,6,6,6,7,6,
7,6,7,6,7,7,7,6,7,7,7,7,7,7,7,6,7,7,8,7,8,7,7,6,8,7,8,7,8,7,7,7,8,7,8,7,8,8,8,7,
8,8,8,7,8,8,8,7,9,8,8,8,9,8,8,7,9,8,8,8,9,8,8,8,8,8,9,8,9,8,8,7,9,8,9,8,9,9,8,8,
9,9,9,8,9,8,8,7,9,8,9,8,9,9,8,8,9,9,9,8,9,8,9,8,9,9,9,8,9,9,9,8,9,9,9,9,9,9,9,8,
9,9,10,9,9,9,9,8,9,9,9,9,10,9,9,8,9,9,10,9,10,9,9,9,9,9,9,9,9,9,9,8,10,9,10,9,10
,9,9,9,9,10,10,9,10,9,10,9,10,9,10,9,9,10,10,9,9,10,10,9,10,9,9,8,10,9,10,9,10,10,
9,9,9,10,10,10,10,9,10,9,10,10,10,10,10,10,10,9,10,10,10,9,10,9,9,8,10,9,10,9,
10,10,10,9,9,10,10,10,10,9,10,9,10,10,10,10,10,10,10,9,10,10,10,9,10,10,10,9,10,
10,11,10,10,10,10,9,10,10,10,10,10,10,10,9,10,10,11,10,10,10,10,10,10,10,10,10,10,
10,10,9,11,10,10,10,10,10,10,10,10,10,11,10,10,10,10,9,11,10,11,10,10,10,10,10
,10,10,11,10,11,10,10,9,11,10,10,10,10,11,10,10,10,10,10,10,11,10,11,10,11,10,11
,10,11,10,11,10,11,10,11,10,11,10,10,9,11,10,11,10,11,10,11,10,10,10,11,10,11,10
,11,10,11,10,11,11,10,11,11,10,11,11,11,10,11,11,11,10,11,11,11,10,11,11,11,10,11,
10,11,11,11,11,11,10,11,10,11,11,11,11,11,10,10,11,11,10,11,10,10,9,11,10,11,10,
11,11,10,10,10,10,11,11,11,10,11,10,11,10,11,11,11,11,11,11,11,11,11,10,11,11,
11,10,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,10,11,11,11,11,11,11,11,10,11
,11,11,10,11,10,10,9,11,10,11,10,11,11,11,10,10,10,11,11,11,11,11,10,11,10,11,11
,11,11,11,11,11,11,11,10,11,11,11,10,12,11,11,11,11,11,11,11,11,11,11,11,12,11,11,
10,11,11,12,11,11,11,11,10,11,11,11,11,12,11,11,10,12,11,11,11,11,11,11,11,11,
11,11,11,11,11,11,10,12,11,11,11,11,11,12,11,11,11,11,11,12,11,11,10,12,11,11,11
,11,12,11,11,12,11,11,11,12,11,12,11,12,11,11,11,11,11,12,11,12,11,11,11,12,11,11
,10,12,11,12,11,11,11,12,11,11,11,11,11,12,11,12,11,12,11,12,11,12,12,12,11,11,
11,12,11,12,11,11,10,12,11,11,11,12,11,11,11,11,11,11,11,12,11,12,11,12,11,12,11
,11,12,12,11,11,12,11,11,12,11,11,10,12,11,12,11,12,11,11,11,12,11,11,12,12,11,12
,11,12,11,12,11,12,11,12,11,12,12,12,11,12,12,12,11,12,12,12,11,12,12,12,11,12,
12,12,11,12,12,12,11,12,12,12,11,12,12,12,11,12,11,12,11,12,11,11,10,12,11,12,11
,12,11,12,11,11,11,11,11,12,12,12,11,12,11,12,11,12,12,12,11,12,12,11,11,12,12,12
,11,12,12,12,11,12,12,12,12,12,11,12,12,12,12,12,11,12,12,12,12,12,12,12,11,12,
12,12,12,12,12,12,11,12,12,12,12,12,12,12,11,12,12,12,12,12,12,12,11,12,12,12,11
,12,12,12,12,12,12,12,12,12,12,12,11,12,12,12,11,12,12,12,12,12,12,12,12,12,12,12
,11,12,11,12,12,12,12,12,11,11,12,12,11,12,11,11,10,12,11,12,11,12,12,11,11,12,
11,11,12,12,11,12,11,12,11,12,11,12,12,12,12,12,12,12,11,12,12,12,11,13,12,12,11
,12,12,12,12,13,12,12,12,12,12,12,12,12,12,13,12,12,12,12,11,12,12,12,12,12,12,12
,11,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,13,12,13,12,12,12,12,12,12,
12,12,12,13,12,12,11,13,12,12,12,13,12,12,12};
int main() {
    int n;
    while (scanf("%d",&n) != EOF) {
        printf("%d\n",ans[n]);
    }
	return 0;
}