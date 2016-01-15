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
map<char,char> dir;
char st[200100];
int main() {
    int n,m;
    scanf("%d%d%*c",&n,&m);
    gets(st);
    //puts(st);
    for (char i = 'a';i <= 'z'; i++)
        dir[i] = i;
    char c1,c2;
    for (int i = 1;i <= m; i++) {
        scanf("%c%*c%c%*c",&c1,&c2);
        for (char i = 'a';i <= 'z'; i++) {
            if (dir[i] == c1) dir[i] = c2;
            else if (dir[i] == c2) dir[i] = c1;
        }
    }
    for (int i = 0;i < n; i++) {
        //printf("%c %c\n",st[i],dir[st[i]]);
        st[i] = dir[st[i]];
    }
    puts(st);
	return 0;
}

