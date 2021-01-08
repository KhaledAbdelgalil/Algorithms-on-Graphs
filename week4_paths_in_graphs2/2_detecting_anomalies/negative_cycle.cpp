#include <bits/stdc++.h>
using namespace std;
#define INF INT_MAX

vector < pair<long long, long long> > adj[1005];

int main()
{
    
    int n, m;
    cin >>  n >> m;
    for (int i = 0; i < m; i++) {
		long long u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back(make_pair(v, w));
	}
	vector <long long> dist(n + 1, INF);
	dist[1] = 0;
    for (int i = 1; i <= n - 1; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 0; k < adj[j].size(); k++) {
				long long v = adj[j][k].first;
				long long w = adj[j][k].second;
				if (dist[v] > w + dist[j]) {
					dist[v] = w + dist[j];
				}
			}
		}
	}
	
	for (int j = 1; j <= n; j++) {
		for (int k = 0; k < adj[j].size(); k++) {
			long long v = adj[j][k].first;
			long long w = adj[j][k].second;
			if (dist[v] > w + dist[j] ) {
				cout << "1" << endl;
				return 0;
			}
		}
	}
    cout << "0" << endl;
    //cout << endl;
    //cout << dist[1] <<" "<<dist[2] << " "<<dist[3] << " " << dist[4];
    return 0;
}

