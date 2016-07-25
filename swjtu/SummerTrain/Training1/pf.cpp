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
const int N = 10;
char ch[] = {'p','q','r','u','v','w','x','y','z'};
int main()
{
    int t;
    scanf("%d",&t);
    while (t--) {
        int k;
        bool fr = true;
        for (int i = 0;i < N-1; i++) {
            scanf("%d",&k);
            if (k) {
                if (k == 1) {
                    if (fr) {printf("%c",ch[i]);fr = false;}
                    else printf("+%c",ch[i]);
                } else if (k == -1) {
                    if (fr) {printf("-%c",ch[i]);fr = false;}
                    else printf("-%c",ch[i]);
                } else {
                    if (fr) {printf("%d%c",k,ch[i]);fr = false;}
                    else printf("%+d%c",k,ch[i]);
                }
            }
        }
        scanf("%d",&k);
            if (k) {
                if (fr) {printf("%d",k);fr = false;}
                else printf("%+d",k);
            }
        printf("\n");
    }
	return 0;
}
