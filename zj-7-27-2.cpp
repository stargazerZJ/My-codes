//codevs 1017
#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
using namespace std;
#define rep(i,a,b) for(int i = a; i < b; ++ i)
typedef long long ll;

const ll D = 10;
char s[50];
ll dp[45][45][10];

int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	scanf("%s",s);
	rep(j,0,n) {
		dp[j][j][0] = s[j] - '0';
		for(int i = j - 1; i >= 0; -- i) {
			dp[i][j][0] = dp[i][j - 1][0] * D + dp[j][j][0];
			rep(k,1,m + 1) {
				dp[i][j][k] = 0;
				rep(a,i,j) {
					dp[i][j][k] = max(dp[i][j][k], dp[i][a][k - 1] * dp[a + 1][j][0]);
				}
			}
		}
	}
	printf("%lld\n",dp[0][n - 1][m]);
	return 0;
}
