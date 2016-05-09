#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
const int maxn = 1001000;
char str[maxn];
int p[maxn];
int len;
int cal(int pos, int L){
    int ret = 0;
    int tmp;
    if(pos + L - 1<= len) ret = 1;
    pos = pos + L - 1;
    while(pos <= len && p[pos] >= L){
        tmp = min((p[pos] - 1) / (L - 1), ret);
        ret += tmp;
        pos += tmp * (L - 1);
    }
    return ret;
}
int main(){
    //freopen("data1.out", "w", stdout);
    //freopen("data.in", "r", stdin);
    str[0] = '#';
    int m, pos, L;
    while(scanf("%s", str + 1) != EOF){
            int mxid = 0;
            len = strlen(str + 1);
            str[len+1] = '$';
            int id = 0;
            for(int i = 1; i <= len; ++i){
                if(mxid > i){
                    p[i] = min(p[2*id-i],mxid - i);
                }else {
                    p[i] = 1;
                }
                while(str[i+p[i]] == str[i-p[i]]) p[i]++;
                if(i+p[i] > mxid){
                    mxid = p[i]+i;
                    id = i;
                }
            }
            scanf("%d", &m);
            for(int i = 0; i < m; ++i){
                scanf("%d%d", &pos, &L);
                printf("%d\n", cal(pos, L));
            }
    }
}
