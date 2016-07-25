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
const double win[9][9] = {  0.50,   0.58,  0.59,  0.45,   0.56,    0.58,0.57,0.39,0.38,
0.42,   0.50,  0.65,  0.75,   0.68,    0.52,    0.40,   0.55,   0.60,
0.41,   0.35,  0.50  ,0.46,   0.48 ,   0.47 ,   0.44 ,  0.57 ,  0.54,
0.55,   0.25,  0.54 , 0.50,   0.53 ,   0.51 ,   0.63 ,  0.52 ,  0.42,
0.44,   0.32,  0.52 , 0.47,   0.50 ,   0.47 ,   0.46,   0.55 ,  0.46,
0.42,   0.48,  0.53 , 0.49,   0.53 ,   0.50 ,   0.44 ,  0.40 ,  0.59,
0.43,   0.60 , 0.56 , 0.37 ,  0.54 ,   0.56 ,   0.50 ,  0.68 ,  0.39,
0.61,   0.45 , 0.43 , 0.48 ,  0.45 ,   0.60 ,   0.32 ,  0.50 ,  0.48,
0.62,   0.40 , 0.46 , 0.58 ,  0.54 ,   0.41 ,   0.61 ,  0.52 ,  0.50}; 
map<string,int> dic;
int a[5],b[5];
int main()
{
	dic["Druid"] = 0;dic["Hunter"] = 1;dic["Mage"] = 2;
	dic["Shaman"] = 3;dic["Paladin"] = 4;dic["Warlock"] = 5;
	dic["Warrior"] = 6;dic["Rogue"] = 7;dic["Priest"] = 8;
	int t;
	string st;
	scanf("%d",&t);
	while (t--) {
		for (int i = 1;i <= 3; i++) {
			cin >> st;
			a[i] = dic[st];
		}
		for (int i = 1;i <= 3; i++) {
			cin >> st;
			b[i] = dic[st];
		}
		double ans = 0;
		for (int i = 1;i <= 3; i++)
			ans += win[a[i]][b[i]];
		printf("%.2lf\n",ans);
	}
	return 0;
}
