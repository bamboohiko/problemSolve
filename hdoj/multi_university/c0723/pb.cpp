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
    int n,m,x,y;
    while (scanf("%d%d%d%d",&n,&m,&x,&y) != EOF) {
        if (n < m) {
            swap(n,m);
            swap(x,y);
        }
        int d1,d2;
        if (n == m && n%2 && x == n/2 && y == m/2) d1 = m/2;
        else d1 = (m+1)/2;
        d2 = min((n+1)/2,max(y-1,m-y));
        printf("%d\n",max(d1,d2));
    }
	return 0;
}
