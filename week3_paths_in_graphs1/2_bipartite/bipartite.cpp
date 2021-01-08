#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;
vector < int > colors;
bool dfs(int src, vector<vector<int> > &adj){
    
    for(int i = 0; i < adj[src].size(); i++){
        int v = adj[src][i];
        if(colors[v] == colors[src]){
            return 0;
        }
        else if(colors[v] == 3){
            colors[v] = 1 - colors[src];
            return dfs(v, adj);
        }
    }
    return 1;
}
int bipartite(vector<vector<int> > &adj) {
  //write your code here
  colors.clear();
  colors.resize(adj.size(), 3);
  bool ans = true;
  for(int i = 0; i < adj.size() && ans; i++){
      if(colors[i] == 3){
          colors[i] = 0;
          ans &= dfs(i, adj);
      }
  }
  return ans;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  std::cout << bipartite(adj);
}
