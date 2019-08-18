//codevs 1018
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<set>
using namespace std;
#define rep(i,a,b) for(int i = a; i < b; ++ i)
typedef long long ll;

const int N = 25;
int n;
int mat[N][N];
string words[N];
char beg;
int vis[N];

int dfs(int now) {
	int ret = 0;
//	cout << words[now] << '\n';
	vis[now] ++;
	rep(i,0,n) {
	//	printf("%d %d\n",i,mat[now][i]);
		if(mat[now][i] > 0 && vis[i] < 2) {
		//	printf(" %d\n",i);
			ret = max(ret, dfs(i) + mat[now][i]);
		}
	}
	vis[now] --;
	return ret;
}

int main() {
	int ans;
	scanf("%d",&n);
	rep(i,0,n) {
		cin >> words[i];
	}
	rep(i,0,n) {
		rep(j,0,n) {
			mat[i][j] = 0;
			rep(k,1,words[i].length()) {
			//	cout << words[i].substr(k) << ' ' << words[j].substr(0,words[i].length() - k) << '\n';
				if(words[i].substr(k) == words[j].substr(0,words[i].length() - k)) {
					mat[i][j] = words[j].length() - words[i].length() + k;
				//	printf("%d %d %d %d\n",i,j,mat[i][j],k);
				}
			}
		}
	}
	scanf("%s",&beg);
	ans = 0;
	rep(i,0,n) {
		if(words[i][0] == beg) {
			ans = max(ans, dfs(i) + (int)words[i].length());
		//	cout << words[i] << ' ' << ans << '\n';
		}
	}
	printf("%d\n",ans);
	return 0;
}
