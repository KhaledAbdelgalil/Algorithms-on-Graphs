#include <bits/stdc++.h>
using namespace std;
class DSU{
private:
    std::vector<int>p,rank;
    int sets;
public:
    DSU(int n){
        sets=n;
        p.assign(n+1,0),rank.assign(n+1,0);
        for(int i=0;i<n+1;i++)p[i]=i;
    }
    
    int findSet(int i){
        return (i==p[i])?i:(p[i]=findSet(p[i]));
    }
    
    int isSameSet(int i,int j){
        return findSet(i)==findSet(j);
    }
    
    void unionSet(int i,int j){
        int x=findSet(i);
        int y=findSet(j);
        if(rank[x]>rank[y]){
            if(x!=y)sets--;
            p[y]=x;
        }
        else{
            
            if(x!=y)sets--;
            p[x]=y;
            if(rank[x]==rank[y])rank[y]++;
        }
    }
    
    int Size(){
        return sets;
    }
  
};

double calculate(int x1, int x2, int y1 , int y2){
    return sqrt( (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) );
}
double clustering(vector<int> x, vector<int> y, int k) {
  double result = 0.;
  //write your code here
  int n = x.size();//number of vertices

  //1) build graph
  vector < pair < double, pair < int, int > > > edgeList;
  for(int i = 0; i < n ; i++){
        for(int j = i + 1; j < n; j++){
            double edgeWeight = calculate(x[i], x[j], y[i], y[j]);
            edgeList.push_back( { edgeWeight, { i, j } } );
            result += edgeWeight * 2;
        }
  }
  //2) sort edges
  sort(edgeList.begin(), edgeList.end());
  
  //3) apply algorithm
  DSU trees(x.size());
  for(int i = 0; i < edgeList.size(); i++){
        if(trees.Size() == k){
        break;        //you finished building your clusters
        }
        double w = edgeList[i].first;
        int u = edgeList[i].second.first;
        int v = edgeList[i].second.second;
        if(!trees.isSameSet(u, v)){
                trees.unionSet(u, v);
        }
   }
   for(int i = 0; i < n; i++){
       for(int j = i + 1; j < n; j++){
           if(!trees.isSameSet(i,j))//they are in different clusters, find distance and take minimum
            result = min(result, calculate(x[i], x[j], y[i], y[j]));
       }
   }
  return result;
} 

int main() {
    //std::ifstream in ("input");
    //std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
   // std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
  size_t n;
  int k;
  std::cin >> n;
  vector<int> x(n), y(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }
  std::cin >> k;
  std::cout << std::setprecision(10) << clustering(x, y, k) << std::endl;
}
