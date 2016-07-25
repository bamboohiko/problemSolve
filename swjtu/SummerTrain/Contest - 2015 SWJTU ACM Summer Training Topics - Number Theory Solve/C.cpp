#include<iostream>
#include <stdio.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <functional>
#include <string>
#include <fstream>
using namespace std;
int main()
{	 int i,j,p;
	int a[37]={2,3,5,7,13,17,19,31,61,89,107,127,521,607,1279,2203,2281,3217,4253,4423,9689,9941,11213,\
		19937,21701,23209,44497,86243,110503,132049,216091,756839,859433,1257787,1398269,2976221,3021377};
	while(cin>>p)
	{	j=0;
		for(i=0;i<37;i++)
			if(a[i]==p)
			{	j=1;
				break;
			}
		if(j)	cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
  return 0;
}