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
string op = "*------------*";
string ed = "*------------*";
int main()
{
    int t;
    scanf("%d",&t);
    for (int turn = 1;turn <= t; turn++) {
        int k;
        scanf("%d",&k);k /= 10;
        printf("Case #%d:\n",turn);
        cout << op << endl;
        for (int i = 1;i <= 10 - k; i++)
            printf("|............|\n");
        for (int i = 1;i <= k; i++)
            printf("|------------|\n");
        cout << ed << endl;
    }
	return 0;
}
