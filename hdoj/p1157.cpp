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
int a[10010];
int main() {
    int n;
    while (scanf("%d",&n) != EOF) {
        for (int i = 1;i <= n; i++) scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        printf("%d\n",a[(n+1)/2]);
    }
	return 0;
}

