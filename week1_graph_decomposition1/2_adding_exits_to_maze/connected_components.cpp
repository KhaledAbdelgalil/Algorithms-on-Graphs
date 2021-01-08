#include <iostream>
#include <vector>

using std::vector;
using std::pair;
void dfs(vector<vector<int> > &adj, vector < bool > &vis, int src){
    vis[ src ] = true;
    for(int i = 0; i < adj[src].size(); i++){
        int v = adj[src][i];
        if(vis[v] == false){
            dfs(adj, vis, v);
        }
    }
}
int number_of_components(vector<vector<int> > &adj) {
  int res = 0;
  //write your code here
  vector < bool > vis(adj.size(), 0);
  int n = adj.size();
  for(int i = 0; i < n; i++){
      if(vis[i] == 0){
          res++;
          dfs(adj, vis, i);
      }
  }
  return res;
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
  std::cout << number_of_components(adj);
}
