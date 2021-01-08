#include <iostream>
#include <vector>

using std::vector;
using std::pair;

void dfs(vector<vector<int> > &adj, vector< bool > &vis, int src){
    vis[src] = 1;
    for(int i = 0; i < adj[src].size(); i++){
        int v = adj[src][i];
        if(vis[ v ] == false)dfs(adj, vis, v);
    }
}
int reach(vector<vector<int> > &adj, int x, int y) {
  //write your code here
  vector< bool > vis(adj.size(), false);
  dfs(adj, vis, x);
  return vis[y];
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  int x, y;
  std::cin >> x >> y;
  std::cout << reach(adj, x - 1, y - 1);
}
