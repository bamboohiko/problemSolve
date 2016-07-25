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
#include<ctime>
using namespace std;
int a[10][10];
int main() {
    srand(time(NULL));
    int n = rand()%6 + 3,m = 0;
    for (int i = 1;i < n; i++)
        for (int j = i+1;j <= n; j++) {
            if (rand()%2) {
                printf("%d %d\n",i,j);
                m++;
            }
        }
    printf("%d %d\n",n,m);
	return 0;
}
