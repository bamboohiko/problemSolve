//树状数组：单点修改与线段查找
#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int f[50100];
int lowbit(int x) {
    return x&(-x);
}
void add(int pos,int x,int n) {
    while (pos <= n) {
        f[pos]+=x;
        pos+=lowbit(pos);
    }
}
int sum(int pos) {
    int s = 0;
    while (pos > 0) {
        s+=f[pos];
        pos-=lowbit(pos);
    }
    return s;
}
int main() {
    int t,nt = 0;
    scanf("%d",&t);
    while (nt++ < t) {
        printf("Case %d:\n",nt);
        int n,x;
        memset(f,0,sizeof(f));
        scanf("%d",&n);
        for (int i = 1; i <= n; i++) {
            scanf("%d",&x);
            add(i,x,n);
        }
        char st[10];
        int l,r;
        while ((scanf("%s",st) != EOF) && (st[0] != 'E')) {
            scanf("%d%d",&l,&r);
            if (st[0] == 'A') add(l,r,n);
            if (st[0] == 'S') add(l,-r,n);
            if (st[0] == 'Q') printf("%d\n",sum(r)-sum(l-1));
        }
    }
    return 0;
}
