#include <iostream>
#include <cstdio>

using namespace std;
const int MAXN = 110000;
char in[MAXN];
int  nxt[MAXN];
bool flag[MAXN];

void GetNext()
{
    nxt[0] = -1;
    flag[0] = false;
    for ( int i =1, j =-1; in[i]; i++)
    {
        flag[i] = false;
        while (j!=-1 && in[j+1]!=in[i]) j =nxt[j];
        nxt[i] = in[j+1]==in[i] ? ++j : j;
        if (in[i+1] && nxt[i]!=-1) flag[nxt[i]] = true;
    }
}

int main()
{
    int T, ncase =0;
    for ( scanf("%d", &T); T--; )
    {
        scanf("%s", in);
        int l = strlen(in), ans;
        GetNext();

        for ( ans =nxt[l-1]; ans!=-1 && !flag[ans]; ans =nxt[ans]);
        
        if (ans != -1) in[ans+1] = '\0';
        printf("Case #%d: %s\n", ++ncase, ans==-1 ? "-1" : in);
    }
    return 0;
}