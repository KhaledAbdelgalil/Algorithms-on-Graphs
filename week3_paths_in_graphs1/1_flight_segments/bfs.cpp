#include <iostream>
#include <vector>
#include <queue>
#define INF 10000000
using std::vector;
using std::queue;
vector<int>dist;
vector<vector<int> > adj;
 
int distance(vector<vector<int> > &adj, int s, int t) {
  //write your code here
  queue<int>q;
  
  dist[s] = 0;
  q.push(s);
  
  while(!q.empty()){
      int u = q.front();
      q.pop();
      for(int i = 0; i < adj[u].size(); i++){
          int v = adj[u][i];
          if(dist[v] == INF){
              dist[v] = dist[u] + 1;
              if(v == t)return dist[v];
              q.push(v);
          }
      }
  }
  return -1;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  adj=vector<vector<int>>(n, vector<int>());
  dist = vector<int>(adj.size(),INF);
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, s, t);
}
