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
    int a[10];
    for (int i = 0;i < 6; i++)
        scanf("%d",&a[i]);
    sort(a,a+6);
    int x,y,t = 0;
    if (a[0] == a[3]) {x = a[4];y = a[5];t = 1;}
    if (a[1] == a[4]) {x = a[0];y = a[5];t = 1;}
    if (a[2] == a[5]) {x = a[0];y = a[1];t = 1;}
    if (x > y || t == 0) printf("Alien\n");
    else {
        if (x < y) printf("Bear\n");
        if (x == y) printf("Elephant\n");
    }
	return 0;
}
