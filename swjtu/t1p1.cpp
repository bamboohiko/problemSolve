/*#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{int t,ans;
	while (cin >> t)
		while (t--)
			{string s;ans = 0;
			cin >> s;
			for (int i = 0;i < s.length(); i++)
				{int j = 1;
				while ((i-j >= 0) && (i+j < s.length()) && (s[i-j] == s[i+j])) j++;
				ans = max(ans,j*2-1);
				if (s[i] == s[i+1])
					{j = 1;
					while ((i-j >= 0) && (i+j+1 < s.length()) && (s[i-j] == s[i+j+1])) j++;
					ans = max(ans,j*2);
					}
				}
			cout << ans << endl;
			}
	return 0;
}*/
int max(int a,int b)
{
	return (a>b)?a:b;
}
#include<stdio.h>
#include<string.h>
int main()
{int t;
	scanf("%d",&t);
	while (t--)
		{char s[255];
		scanf("%s",s);
		int ans = 0,len = strlen(s);
		for (int i = 0;i < len; i++)
			{int j = 1;
			while ((i-j >= 0) && (i+j < len) && (s[i-j] == s[i+j])) j++;
			ans = max(ans,j*2-1);
			if (s[i] == s[i+1])
				{j = 1;
				while ((i-j >= 0) && (i+j+1 < len) && (s[i-j] == s[i+j+1])) j++;
				ans = max(ans,j*2);
				}
			}
		printf("%d\n",ans);
		}
	return 0;
}
