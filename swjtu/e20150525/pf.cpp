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
int cou[30],cmp[30];
int main()
{
    memset(cmp,0,sizeof(cmp));
    string st = "goodmorning";
    for (int i = 0;i < st.size(); i++)
        if (st[i] != ' ') cmp[st[i] - 'a']++;
    cmp['g' - 'a'] = 1;
    int t;
    scanf("%d",&t);
    getline(cin,st);
    for (int turn = 1;turn <= t;turn++) {
        memset(cou,0,sizeof(cou));
        getline(cin,st);
        int spa = 0;
        for (int i = 0;i < st.size(); i++)
            if (st[i] != ' ') cou[st[i] - 'a']++;
            else spa++;
        cou['g' - 'a']--;
        int ans = spa;
        for (int i = 0;i < 26; i++) {
            if (cmp[i] > 0) ans = min(ans,cou[i]/cmp[i]);
        }
        printf("Case #%d: %d\n",turn,ans);
    }
	return 0;
}
