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
#define INF 0x3f3f3f3f
#define eps 1e-8
#define pi acos(-1.0)
using namespace std;
struct matrix{
    int x1,x2,y1,y2;
};
matrix M[100100];
set<int> savx,savy;
map<int,int> dirx,diry;
int add(int x,int y,int val) {
    for (int i = x;; )
}
int main() {
    int n;
    scanf("%d",&n);
    for (int i = 1;i <= n; i++) {
        scanf("%d%d%d%d",&M[i].x1,&M[i].y1,&M[i].x2,&M[i].y2);
        savx.insert(M[i].x1);savx.insert(M[i].x2);
        savy.insert(M[i].y1);savy.insert(M[i].y2);
    }
    for (set<int>::iterator i = savx.begin();i != savx.end(); i++)
        dirx[*i] = dirx.size();
    for (set<int>::iterator i = savy.begin();i != savy.end(); i++)
        diry[*i] = diry.size();
    for (int i = 1;i <= n; i++) {
        add(dirx[x2],diry[y2],1);
        add(dirx[x2],diry[y1],-1);
        add(dirx[x1],diry[y2],-1);
        add(dirx[x1],diry[y1],1);
    }
    printf("%d\n",query(dirx.size(),diry.size()));
	return 0;
}
