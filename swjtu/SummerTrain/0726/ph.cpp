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
int main() {
    char a,b,c;
    while (scanf("%c%c%c%*c",&a,&b,&c) != EOF) {
        if (b < a) swap(a,b);
        if (c < a) swap(a,c);
        if (c < b) swap(b,c);
        printf("%c %c %c\n",a,b,c);
    }
	return 0;
}
