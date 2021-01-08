#include <bits/stdc++.h>
#define oo LLONG_MAX
using namespace std;

long long distance(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, int t) {
  //write your code here
  vector <long long > dist(adj.size(), oo);
  priority_queue< pair<long long, int> , vector < pair<long long, int > >, greater < pair<long long, int> > > pq;
  dist[s] = 0;
  pq.push({dist[s], s});
  while(!pq.empty()){
      pair < long long, int > top = pq.top();
      pq.pop();
      long long d = top.first;
      int u = top.second;
      if(u == t)return dist[u];
      if(d > dist[u])continue;//you already found a shortest path
      for(int i = 0; i < adj[u].size(); i++){
          int v = adj[u][i];
          int newD = d + cost[u][i];
          if(newD < dist[v]){
              dist[v] = newD;
              pq.push({dist[v], v});
          }
      }
  }
  return -1;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, cost, s, t);
}
