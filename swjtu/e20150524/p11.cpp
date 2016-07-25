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
    int n,ans = 1;
    scanf("%d",&n);
    string st;
    cin >> st;
    for (int i = 0; i < n; i++) {
        if (st[i] == '1') ans++;
        else break;
    }
    printf("%d\n",min(ans,n));
	return 0;
}
