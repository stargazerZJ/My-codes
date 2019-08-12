//codevs 1026
#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
using namespace std;
#define rep(i,a,b) for(int i = a; i < b; ++ i)
typedef long long ll;
#define out(i,j) ((i < 0) || (j < 0) || (i >= n) || (j >= m))

const int N = 55;
char mp[N][N],tmp[10];
int dc[1005],di[4] = {0,0,1,-1},dj[4] = {1,-1,0,0};

int main() {
	int n,m,q;
	scanf("%d%d",&n,&m);
	rep(i,0,n) {
		scanf("%s",&mp[i]);
	}
	rep(i,0,n) {
		rep(j,0,m) {
			if(mp[i][j] == '*') mp[i][j] = 0;
		}
	}
	scanf("%d",&q);
	rep(i,0,q) {
		scanf("%s",tmp);
		if(tmp[0] == 'N') {
			dc[i] = 3;
		}
		if(tmp[0] == 'S') {
			dc[i] = 2;
		}
		if(tmp[0] == 'E') {
			dc[i] = 0;
		}
		if(tmp[0] == 'W') {
			dc[i] = 1;
		}
	}
	rep(k,0,q) {
		rep(i,0,n) {
			rep(j,0,m) {
				if(mp[i][j] == k) {
					mp[i][j] = '.';
					for(int ni = i + di[dc[k]],nj = j + dj[dc[k]];
					(!out(ni,nj)) && mp[ni][nj] != 'X';
					ni += di[dc[k]], nj += dj[dc[k]]) {
						mp[ni][nj] = k + 1;
					}
				}
			}
		}
	}
	rep(i,0,n) {
		rep(j,0,m) {
			if(mp[i][j] == q) {
				mp[i][j] = '*';
			}
		}
	}
	rep(i,0,n) {
		puts(mp[i]);
	}
	return 0;
} 
