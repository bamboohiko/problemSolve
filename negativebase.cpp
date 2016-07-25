#include<iostream>
using namespace std;
const char ch[]="0123456789ABCDEF";
int num[1010];
int main()
{int n,base,len,t;
	while (cin >> n >> base)
		{len=0;
		while (n)
			{if (n%base < 0) 
				{num[++len]=n%base-base;
				n=n/base+1;
				}
			else 
				{num[++len]=n%base;
				n/=base;
				}
			}
			for (int i = len;i >= 1; i--) cout << ch[num[i]];
			cout << endl;
		}
	return 0;
}
