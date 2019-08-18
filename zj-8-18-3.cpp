//codevs 1116
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

const int N = 8;
int mat[N][N];

const inline int get4(const int &i, const int &x) {
	return 3 & (i >> (x << 1));
}

int main() {
	int n;
	int ans = 0;
	scanf("%d",&n);
	rep(i,0,n) {
		rep(j,0,n) {
			scanf("%d",&mat[i][j]);
		}
	}
	int l = 1 << (n << 1);// l = 2 ** (n * 2);
	rep(k,0,l) {
		char flag = 0;
		rep(i,1,n) {
			rep(j,0,i) {
				if(mat[i][j] && ((get4(k,i) == get4(k,j)))) {
					flag = 1;
					break;
				}
			}
			if(flag) break;
		}
		ans += flag ^ 1;
	}
	printf("%d\n",ans);
	return 0;
}
