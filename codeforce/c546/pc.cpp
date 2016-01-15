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
int a[200],b[200];
set<string> dir;
string fig(int &op1,int &ed1,int& op2,int& ed2) {
    string ans = "";
    for (int i = op1;i <= ed1; i++) {
        ans += a[i] + '0';
    }
    ans += " ";
    for (int i = op2;i <= ed2; i++) {
        ans += b[i] + '0';
    }
    //cout << op <<":" <<ed <<" " << ans << "!" <<endl;
    return ans;
}
void cmp(int &op1,int &ed1,int& op2,int& ed2){
    if (a[op1] > b[op2]) {
        a[++ed1] = b[op2++];
        a[++ed1] = a[op1++];
    } else {
        b[++ed2] = a[op1++];
        b[++ed2] = b[op2++];
    }
    //for (int i = op1;i <= ed1; i++) cout << a[i] << " ";cout <<endl;
    //for (int i = op2;i <= ed2; i++) cout << b[i] << " ";cout <<endl;
}
int main()
{
    int n;
    int op1 = 1,ed1;
    int op2 = 1,ed2;
    scanf("%d",&n);
    scanf("%d",&ed1);
    for (int i = 1; i <= ed1; i++) {
        scanf("%d",&a[i]);
        a[i]--;
    }
    scanf("%d",&ed2);
    for (int i = 1; i <= ed2; i++) {
        scanf("%d",&b[i]);
        b[i]--;
    }
    dir.insert(fig(op1,ed1,op2,ed2));
    int turn = 0;
    string sav;
    while (true) {
        if ((ed1 - op1+1 == 0) || (ed2 - op2+1 == 0)) break;
        //cout << (ed1 - op1 + 1) << " " << (ed2 - op2 + 1) << endl;
        cmp(op1,ed1,op2,ed2);
        sav = fig(op1,ed1,op2,ed2);
        if (dir.count(sav)){
            turn = -1;
            break;
        } else {
            dir.insert(sav);
        }
        turn++;
    }
    if (turn < 0) printf("-1\n");
    else printf("%d %d\n",turn,(ed1 - op1 + 1)?1:2);
	return 0;
}
