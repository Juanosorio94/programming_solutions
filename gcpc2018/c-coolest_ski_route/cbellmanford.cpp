#include <bits/stdc++.h>

//with adj list representation

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;

int main() {
  int m, n;
  scanf("%d %d", &n, &m);
  vector<vii> adjList;
  adjList.resize(n+1);

  vector<int> dist;
  dist.assign(n+1, 100*1001);
  dist[0] = 0;
  int s, t, c;

  for(int i = 0; i < m; ++i) {
    scanf("%d %d %d", &s, &t, &c);
    adjList[s].push_back({t, -c});
  }

  for(int i = 1; i < n + 1 ; ++i)
    adjList[0].push_back({i, 0});
 
  

  //bellman ford:
  for(int k = 0; k < adjList.size(); ++k){
   for(int i = 0; i < adjList.size(); ++i){
    for(int j = 0; j < adjList[i].size(); ++j) {
      //relax (source u, target v, weight w);
      int u = i;
      int v = adjList[i][j].first;
      //printf("traversing Node: %d, with Edge: %d, and weight: %d\n", u, v, adjList[i][j].second);
      if(dist[v] > dist[u] + adjList[i][j].second){
	dist[v] = dist[u] + adjList[i][j].second;
	//printf("weight updated: %d\n", dist[v]);
      }
    }
   }
  }

    auto ret = min_element(dist.begin(), dist.end());
    printf("%d\n", -*ret);

  return 0;
}
