#include<iostream>
#include<cstdio>
#include<map>
#include<set>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
string r;
char st[2000100];
int f[2000100];
int main()
{
    int n;
    scanf("%d",&n);
    st[0] = '#';
    for (int ca = 1;ca <= n; ca++)
    {
        int m = 1;
        cin >> r;
        for (int i = 0;i < r.size(); i++)
            st[m++] = r[i],st[m++] = '$';
        st[--m] = '\0';
        int r = 1,loc = 1,ans = 1;
        for (int i = 1;st[i]; i++)
        {
            f[i] = min(f[2*loc-i],f[loc] - 2*(i-loc)) >> 1;
            int j = max(f[i],0);
            for ( ;st[i+j+1] == st[i-j-1]; j++) ;
            f[i] = 1+j*2;
            if (i + (f[i] >> 1) > r)
            {
                r = i + (f[i] >> 1);
                loc = i;
            }
            if (st[i-f[i]/2-1] == '#' || st[i+f[i]/2+1] == '\0') ans = max((f[i] >> 1)+1,ans);
            else ans = max(f[i] >> 1,ans);
        }
        printf("%d\n",ans);
    }
	return 0;
}

