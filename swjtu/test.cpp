#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
using namespace std;
const int act[4][2] = {0,1,1,0,0,-1,-1,0};
int main()
{
	for (int i = 0;i < 4; i++)
		for (int j = 0;j < 2; j++)
			printf("%d %d %d\n",i,j,act[i][j]);
	return 0;
}
