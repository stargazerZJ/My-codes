//codevs 1295
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

const int N = 20;
ll ans[N] = {1, 1, 0, 0, 2, 10, 4, 40, 92, 352, 724, 2680, 14200, 73712, 365596, 2279184, 14772512, 95815104, 666090624, 4968057848};
//N QUEEN
int main() {
	int n;
	while(scanf("%d",&n) != EOF)
		printf("%lld\n",ans[n]);
	return 0;
}
