#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const long long INF = 1e8;

int dijkstra(vector<vector<pair<int, int>>> adj, int s, int l){ 
    int n = adj.size();
    vector<int> dist(n, INF);
    vector<int> parent(n, -1);
    priority_queue<pair<int, int>, vector<pair<int, int>>> Q;
    dist[s] = 0;
    Q.push({0, s});
    int v, w, d, u;

    while(!Q.empty()){
        pair<int, int> e =  Q.top();
        d = e.first;
        u = e.second;
        Q.pop();
        if(d > dist[u]) continue;
        for(int i = 0; i < adj[u].size(); i++){
            v =  adj[u][i].first;
            w =  adj[u][i].second;
            if(d + w < dist[v]){
                 dist[v] = d + w;
                 parent[v] = u;
                 Q.push({d + w, v});
            }
        }
    }
    return dist[l];
}


int main() 
{
    vector<vector<pair<int, int>>> adj; //completar 
    int s = 0;
    int d = 4;
    cout<<"La distancia minima desde nodo "<<s<< " a al "<<d<<" es "<<dijkstra(adj, s, d);
    return 0;
}