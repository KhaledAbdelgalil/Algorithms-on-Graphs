#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;
using std::pair;
vector< int >dfsNum, dfsLow, dfsStack;
vector< bool > InStack; 
vector<vector<int> > adj;
size_t n, m;
int timeVisited;
int result = 0;
void dfs(int u){
    dfsLow[u] = dfsNum[u] = timeVisited++;
    InStack[u] = true;
    dfsStack.push_back(u);
    for(int i = 0; i < adj[u].size(); i++){
        int v = adj[u][i];
        if(dfsNum[v] == 0)
            dfs(v);
        if(InStack[v]){
            dfsLow[u] = std:: min(dfsLow[u],  dfsLow[v]);
        }
    }
    if(dfsLow[u] == dfsNum[u]){
        result++;
        while(!dfsStack.empty()){
            int top = dfsStack.back();
            dfsStack.pop_back();
            InStack[top] = false;
            if(top == u)break;
        }
    }
}
int number_of_strongly_connected_components() {
  //write your code here
  result = 0;
  InStack.clear();
  InStack.resize(n, 0);
  dfsStack.clear();
  dfsLow.clear();
  dfsNum.clear();
  dfsNum.resize(n, 0);
  dfsLow.resize(n, 0);
  timeVisited = 1;
  for(int i = 0; i < n; i++){
      if(dfsNum[i] == 0){
          dfs(i);
      }
  }
  return result;
}

int main() {
  std::cin >> n >> m;
  adj.resize(n);
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  std::cout << number_of_strongly_connected_components();
}
