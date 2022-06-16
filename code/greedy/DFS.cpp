#include <bits/stdc++.h>

using namespace std;

int v, e;
int adj[1000][1000];
bool visited[1000];

void read(){
    for(int i=0; i<1000; i++){
        visited[i] = false;
        for(int j=0; j<1000; j++){
            adj[i][j] = 0;
        }
    }

    cin >> v >> e;
    for(int i=0; i<e; i++){
        int a, b;
        cin >> a >> b;
        adj[a][b] = 1;
    }
}

void dfs(){
    vector<int> que;
    vector<int> path;
    que.push_back(0);
    while(!que.empty()){
        int cur = que.front();
        path.push_back(cur);
        que.erase(que.begin());

        for(int i=0; i<v; i++){
            if(adj[cur][i] && !visited[i]){
                que.push_back(i);
                adj[cur][i] = 0;
                visited[i] = true;
            }
        }

        cout << "current path:\n";
        for(int i=0; i<path.size(); i++)
            cout << path[i] << " ";
        cout << endl;

        cout << "current queue:\n";
        for(int i=0; i<que.size(); i++)
            cout << que[i] << " ";
        cout << "\n" << endl;
    }
}

int main(){
    read();
    dfs();
    return 0;
}

/*

6 8
0 1
0 3
1 4
2 5
2 4
3 1
4 3
5 5

*/
