//codevs 1040
#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
#define rep(i,a,b) for(int i = a; i < b; ++ i)
typedef long long ll;

const int N = 205;
char str[N],words[10][N];
int dp[N][N][45],lwords[10];

bool cmp(char* a, char* b, int l) {
	rep(i,0,l) {
		if(a[i] != b[i]) {
			return 0;
		}
	}
	return 1;
}

int main() {
	int T,p,n,m,s;
	scanf("%d",&T);
	while(T--) {
		scanf("%d%d",&p,&m);
		n = p * 20;
		rep(i,0,p) {
			scanf("%s",str + i * 20);
		}
	//	puts(str);
		scanf("%d",&s);
		rep(i,0,s) {
			scanf("%s",words[i]);
			lwords[i] = strlen(words[i]);
		}
		for(int i = n - 1; i >= 0; -- i) {
			dp[i][0][1] = 0;
			rep(j,1,n - i + 1) {
				dp[i][j][1] = dp[i + 1][j - 1][1];
				rep(k,0,s) {
					if(j >= lwords[k] && cmp(str + i, words[k], lwords[k])) {
						dp[i][j][1] ++;
						break;
					}
				}
			//	printf("%d %d %d\n",i,i + j - 1,dp[i][j][1]);
				rep(k,2,m + 1) {
					dp[i][j][k] = 0;
					rep(a,1,j - k + 2) {
						dp[i][j][k] = max(dp[i][j][k], dp[i][j - a][k - 1] + dp[i + j - a][a][1]);
					//	if(i == 15 && j == 5) printf("%d %d %d %d %d %d\n",a,k,i, i + j - a - 1, i + j - a, i + j - 1);
					}
				}
			//	printf("		%d %d %d\n",dp[i][j][2],dp[i][j][3],dp[i][j][4]);
			}
		}
		printf("%d\n",dp[0][n][m]);
	}
	return 0;
}
