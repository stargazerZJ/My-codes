//codevs 1004
#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;
#define rep(i,a,b) for(int i = a; i < b; i ++)
typedef long long ll;

const int d[2][4] = {0,0,1,-1,1,-1,0,0};
char tmp[4];
int vis[2][50000000];

struct node {
	int mp[4][4];
	char f;
	int dis;
	inline int* operator [] (const int & a) {
		return mp[a];
	}
};

void print(node mp) {
	rep(i,0,4) {
		rep(j,0,4) {
			printf("%d",mp[i][j]);
		}
		puts("");
	}
	//puts("");
}

int h_c(node mp) {
	rep(i,0,4) {
		if(mp[i][0] == mp[i][1] && mp[i][2] == mp[i][1] && mp[i][0] == mp[i][3])
			return -1;
		if(mp[0][i] == mp[1][i] && mp[2][i] == mp[1][i] && mp[0][i] == mp[3][i])
			return -1;
	}
	if(mp[0][0] == mp[1][1] && mp[1][1] == mp[2][2] && mp[2][2] == mp[3][3]) 
		return -1;
	if(mp[0][3] == mp[1][2] && mp[1][2] == mp[2][1] && mp[2][1] == mp[3][0]) 
		return -1;
	int ret = 0,dig = 1;
	rep(i,0,4) {
		rep(j,0,4) {
			ret += mp[i][j] * dig;
			dig *= 3;
		}
	}
	return ret;
}

int bfs(node ini) {
	node a,b;
	a = b = ini;
	a.f = 0;
	b.f = 1;
	a.dis = b.dis = 0;
	queue <node> q;
	q.push(a);
	q.push(b);
	while(!q.empty()) {
		node now = q.front();
		q.pop();
		int hs = h_c(now);
		if(hs == -1) {
			return now.dis;
		}
		if(vis[now.f][hs]) {
			continue;
		}
		vis[now.f][hs] = 1;
		rep(i,0,4) {
			rep(j,0,4) {
				if(now[i][j] == now.f)
					rep(k,0,4) {
						if(((i + d[0][k] + 1) % 5) && ((j + d[1][k] + 1) % 5)
							&& now[i + d[0][k]][j + d[1][k]] == 2) {
							node nxt = now;
							nxt[i + d[0][k]][j + d[1][k]] = now.f;
							nxt[i][j] = 2;
						/*	if(hs == 30360241 && f == 1) {
								printf("%d %d %d %d\n",i,j,i + d[0][k],j + d[1][k]);
								print();
							}*/
							nxt.f = 1 ^ now.f;
							nxt.dis = now.dis + 1;
							q.push(nxt);
						}
					}
			}
		}
	}
}

int main() {
	node my_map;
	rep(i,0,4) {
		scanf("%s",tmp);
		rep(j,0,4) {
			my_map[i][j] = (tmp[j] == 'O') ? 2 : ((tmp[j] == 'B') ? 1 : 0);
		}
	}
	int ans = bfs(my_map);
	printf("%d\n",ans);
	return 0;
}

