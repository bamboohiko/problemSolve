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
int main() {
    int n,m;
    int from,to;
    for (int i = 1;i <= m; i++) {
        scanf("%d%d",&from,&to);
        build(from,to,i);
        build(to,from,i);
    }

	return 0;
}
