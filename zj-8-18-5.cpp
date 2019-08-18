//codevs 1294
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<set>
using namespace std;
#define rep(i,a,b) for(register int i = a; i < b; ++ i)
typedef long long ll;

const int N = 11;
int a[N] = {1,2,3,4,5,6,7,8,9,10};

int main() {
	int n;
	scanf("%d",&n);
	do {
		rep(i,0,n) {
			printf("%d ",a[i]);
		}
		puts("");
	} while(next_permutation(a, a + n));
	return 0;
}
