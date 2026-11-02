#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;
int BFS(vector<string>mapa, int _n, int _m){
        vector<vector<bool>> vistos(_n,vector<bool>(_m,false));
        vector<vector<int>> dist(_n,vector<int>(_m,-1));
        vector<int> df = {-1,1,0,0};
        vector<int> dc = {0,0,-1,1};
        queue<pair<int,int>> cola;
        int si = -1;
        int sj = -1;
        for(int i = 0; i < _n; i ++){
            for(int j = 0; j < _m;j++){
                if(mapa[i][j]=='S'){
                    sj = j;
                    si = i;
                }
            }
        }
        cola.push({si,sj});
        dist[si][sj]=0;
        while(!cola.empty()){
            int i = cola.front().first;
            int j = cola.front().second;
            cola.pop();
            if(mapa[i][j]=='E'){
                return dist[i][j];
            }
            for(int k = 0; k < 4; k++){
                int f =i + df[k];
                int c =j + dc[k];
                if(f>=0 && f < _n && c >= 0 && c < _m && mapa[f][c]!='#' && dist[f][c]==-1){
                dist[f][c]=dist[i][j]+1;
                cola.push({f,c});
                }
            }
        }
        return -1;
    };
int main() {
    int n, m;
    cin >> n >> m;
    vector<string>mapa(n);
    for (int i = 0; i < n; i++) {
        cin>>mapa[i];
    }
    cout << BFS(mapa,n,m);
    return 0;
}
