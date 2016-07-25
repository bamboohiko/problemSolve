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
int v[200];
int main() {
    int n,ca = 1;
    while (scanf("%d%*c",&n) != EOF && n) {
        memset(v,0,sizeof(v));
        printf("Program #%d\n",ca++);
        v['a'] = 1;
        char a,b;
        for (int i = 1;i <= n; i++) {
            scanf("%c = %c%*c",&a,&b);
            v[a] = v[b];
        }
        int cou = 0,fr = 1;
        for (int i = 'a';i <= 'z'; i++)
            if (v[i]) {
                printf("%c ",i);
                fr = 0;
            }
        if (fr) printf("none");
        printf("\n\n");
    }
	return 0;
}


