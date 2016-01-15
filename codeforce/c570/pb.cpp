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
    scanf("%d%d",&n,&m);
    if (n == 1) printf("%d",1);
    else {
        if (n - m > m - 1) printf("%d",m+1);
        else printf("%d",m-1);
    }
    printf("\n");
	return 0;
}
