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
string st[6];
int dir[3] = {1,2,4};
int main()
{
    st[0] = "+------------------------+";
    st[1] = "|#.#.#.#.#.#.#.#.#.#.#.|D|)";
    st[2] = "|#.#.#.#.#.#.#.#.#.#.#.|.|";
    st[3] = "|#.......................|";
    st[4] = "|#.#.#.#.#.#.#.#.#.#.#.|.|)";
    st[5] = "+------------------------+";
    int n;
    scanf("%d",&n);
    for (int i = 1;i <= min(n,4); i++)
        st[i][1] = 'O';
    for (int i = 5;i <= n; i++) {
        int x = (i-5)/3 + 1,y = (i-5)%3;
        st[dir[y]][2*x+1] = 'O';
    }
    for (int i = 0;i < 6; i++)
        cout << st[i] << endl;
	return 0;
}
