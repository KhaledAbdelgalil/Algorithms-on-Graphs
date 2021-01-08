#include <iostream>
#include <limits>
#include <vector>
#include <queue>
using std::vector;
using std::queue;
using std::pair;
using std::priority_queue;

void shortest_paths(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, vector<long long> &distance, vector<int> &reachable, vector<int> &shortest) {
  //write your code here
  distance[s] = 0;
  reachable[s] = 1;
  queue<int>notShortest;
  vector<bool>visited(adj.size(), 0);
  for(int i = 0; i < adj.size(); i++){
      for(int j = 0; j < adj.size(); j++){
          for(int k = 0; k < adj[j].size(); k++){
             int v = adj[j][k];
             int w = cost[j][k];
             if(distance[j] != std::numeric_limits<long long>::max() && distance[v] > distance[j] + w){
                 distance[v] = distance[j] + w;
                 reachable[v] = 1;
                 if(i == adj.size() -1){//the last loop
                     //you can make better negative cycle
                     notShortest.push(v);
                     visited[v] = 1;
                     shortest[v] = 0;
                 }
             }
          }
      }
  }
  
  while(!notShortest.empty()){
      int u = notShortest.front();
      notShortest.pop();
      //if you can reach any node form negative cycle so it doesn't have a shortest path, as you can enter negative 
      // cycle, then loop in it many times , then go to the node
      for(int i = 0; i < adj[u].size(); i++){
          int v = adj[u][i];
         if(!visited[v]){
             visited[v] = 1;
             notShortest.push(v);
             shortest[v] = 0;
         }
      }
  }
}

int main() {
    
  int n, m, s;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  std::cin >> s;
  s--;
  vector<long long> distance(n, std::numeric_limits<long long>::max());
  vector<int> reachable(n, 0);
  vector<int> shortest(n, 1);
  shortest_paths(adj, cost, s, distance, reachable, shortest);
  for (int i = 0; i < n; i++) {
    if (!reachable[i]) {
      std::cout << "*\n";
    } else if (!shortest[i]) {
      std::cout << "-\n";
    } else {
      std::cout << distance[i] << "\n";
    }
  }
}
