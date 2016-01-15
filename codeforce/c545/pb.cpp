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
int main()
{
	string s1,s2;
	cin >> s1 >> s2;
	int cou = 0;
	for (int i = 0; i < s1.size(); i++) {
		if (s1[i] != s2[i]) cou++;
	}
	if (cou%2) printf("impossible\n");
	else {
		cou /= 2;
		int j = 0;
		for (int i = 0;i < s1.size(); i++) {
			if (s1[i] == s2[i]) cout << s1[i];
			else {
				if (j < cou) {
				cout << ('1' - s1[i]);
				j++;
				} else {
					cout << s1[i];
				} 
			}
		}
		cout << endl;
	}
	return 0;
}
