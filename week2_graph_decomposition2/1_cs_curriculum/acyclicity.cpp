#include <iostream>
#include <vector>

using std::vector;
using std::pair;

bool acyclic_util(int u, vector<vector<int> > &adj, vector<bool> &vis, vector<bool> &inStack){
    if(vis[u] == 0){
        vis[u] = 1;
        inStack[u] = 1;
        for(int i = 0; i < adj[u].size(); i++){
            int v = adj[u][i];
            if(!vis[v] && acyclic_util(v, adj, vis, inStack))
                return true;
            else if(inStack[v])//cycle
                return true;
        }
    }
    inStack[ u ] = 0;
    return false;
}
int acyclic(vector<vector<int> > &adj) {
  //write your code here
  vector<bool>vis(adj.size(), false),inStack(adj.size(), false);
  bool ans = false;
  for(int i = 0; i < adj.size() && !ans; i++){
      if(vis[i] == 0){
          ans |= acyclic_util(i, adj, vis, inStack);
      }
  }
  if(ans)return 1;
  return 0;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  std::cout << acyclic(adj);
}
