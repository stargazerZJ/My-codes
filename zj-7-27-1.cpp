//codevs 1220
#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
using namespace std;
#define rep(i,a,b) for(int i = a; i < b; ++ i)
typedef long long ll;

const int N = 105;
ll dp[N][N],ans = 0xefffffffffffffff;

int main() {
	int n;
	scanf("%d",&n);
	if(!n) {
		puts("0");
		return 0;
	}
	rep(i,1,n + 1) {
		rep(j,1,i + 1) {
			scanf("%lld",&dp[i][j]);
			dp[i][j] += max(dp[i - 1][j], dp[i - 1][j - 1]);
			if(i == n)	ans = max(ans,dp[i][j]); 
		//	printf("%lld ",dp[i][j]);
		}
	//	puts("");
	}
	printf("%lld\n",ans);
	return 0;
}
