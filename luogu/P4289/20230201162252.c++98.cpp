#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>

const int N = 20 + 5, M = 1000 + 5;
const int INF = 0x3f3f3f3f;
int n, m, tot = 1, lnk[N], cur[N], ter[M], nxt[M], cap[M], cost[M], dis[N], ret;
bool vis[N];

void add(int u, int v, int w, int c) {
  ter[++tot] = v, nxt[tot] = lnk[u], lnk[u] = tot, cap[tot] = w, cost[tot] = c;
}

void addedge(int u, int v, int w, int c) { 
//printf("conn %d %d\n",u,v); 
add(u, v, w, c), add(v, u, 0, -c); }

bool spfa(int s, int t) {
  memset(dis, 0x3f, sizeof(dis));
  memcpy(cur, lnk, sizeof(lnk));
  std::queue<int> q;
  q.push(s), dis[s] = 0, vis[s] = 1;
  while (!q.empty()) {
    int u = q.front();
    q.pop(), vis[u] = 0;
    for (int i = lnk[u]; i; i = nxt[i]) {
      int v = ter[i];
      if (cap[i] && dis[v] > dis[u] + cost[i]) {
        dis[v] = dis[u] + cost[i];
        if (!vis[v]) q.push(v), vis[v] = 1;
      }
    }
  }
  return dis[t] != INF;
}

int dfs(int u, int t, int flow) {
  if (u == t) return flow;
  vis[u] = 1;
  int ans = 0;
  for (int &i = cur[u]; i && ans < flow; i = nxt[i]) {
    int v = ter[i];
    if (!vis[v] && cap[i] && dis[v] == dis[u] + cost[i]) {
      int x = dfs(v, t, std::min(cap[i], flow - ans));
      if (x) ret += x * cost[i], cap[i] -= x, cap[i ^ 1] += x, ans += x;
    }
  }
  vis[u] = 0;
  return ans;
}

int mcmf(int s, int t) {
  int ans = 0;
  while (spfa(s, t)) {
    int x;
    while ((x = dfs(s, t, INF))) ans += x;
  }
  return ans;
}

int main() {
	int s = 17,t = 18;
	char tt;
	
	for(int i=1;i<=12;i++)
		addedge(i,i+4,INF,1);
	for(int i=5;i<=16;i++)
		addedge(i,i-4,INF,1);
	for(int i=1;i<=15;i++)
		if(i%4!=0)addedge(i,i+1,INF,1);
	for(int i=2;i<=16;i++)
		if(i%4!=1)addedge(i,i-1,INF,1);
		
	for(int i=1;i<=16;i++){
		tt = getchar();
		while(tt!='0'&&tt!='1')tt = getchar();
		if(tt=='1')
			addedge(s,i,1,0);
	}
	
	for(int i=1;i<=16;i++){
		tt = getchar();
		while(tt!='0'&&tt!='1')tt = getchar();
		if(tt=='1')
			addedge(i,t,1,0);
	}

    int ans = mcmf(s, t);
    printf("%d\n", ret);
	return 0;
}