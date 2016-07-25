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
int a[1100];
int main()
{
    int t,turn = 0;
    scanf("%d",&t);
    while (turn++ < t) {
        int n;
        scanf("%d",&n);
        for (int i = 1;i <= n; i++) scanf("%d",&a[i]);
        bool maxheap = true,minheap = true,incbst = true,decbst = true;
        for (int i = 1;i <= n; i++) {
            if (2*i <= n) {
                if (a[2*i] > a[i]) {maxheap = false;incbst = false;}
                if (a[2*i] < a[i]) {minheap = false;decbst = false;}
            }
            if (2*i+1 <= n) {
                if (a[2*i+1] > a[i]) {maxheap = false;decbst = false;}
                if (a[2*i+1] < a[i]) {minheap = false;incbst = false;}
            }
            if (!(maxheap || minheap || incbst || decbst)) break;
        }
        printf("Case #%d: ",turn);
        if (maxheap || minheap)
            if (incbst || decbst) printf("Both\n");
            else printf("Heap\n");
        else
            if (incbst || decbst) printf("BST\n");
            else printf("Neither\n");
    }
	return 0;
}
