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
int cou[200];
int main() {
    int n;
    while (scanf("%d",&n) != EOF) {
        memset(cou,0,sizeof(cou));
        string a,b;
        cin >> a >> b;
        for (int i = 0;i < a.size(); i++)
            cou[a[i]]++;
        for (int i = 0;i < b.size(); i++)
            cou[b[i]]--;
        bool ans = true;
        for (int i = 'A';i <= 'Z'; i++)
            if (cou[i] < 0) {
                ans = false;
                break;
            }
        if (ans) printf("Yes\n");
        else printf("No\n");
    }
	return 0;
}
