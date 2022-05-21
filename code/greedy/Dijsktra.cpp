#include <bits/stdc++.h>

using namespace std;

int n;
int d[1000];
int w[1000][1000];
const int inf = 0x3f3f3f3f;

void read(){
    cin >> n;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> w[i][j];
}
void dijkstra(int source){
    bool visit[n];
    for (int i=0; i<n; i++){
        visit[i] = false;
        d[i] = inf;
    }

    d[source] = 0;

    for (int k=0; k<n; k++){
        int a = -1, b = -1, min_ = inf;
        for (int i=0; i<n; i++){
            if (!visit[i] && d[i] < min_){
                a = i;
                min_ = d[i];
            }
        }

        if (a == -1 || min_ == inf) break;
        visit[a] = true;

        for (b=0; b<n; b++)
            if (!visit[b] && d[a] + w[a][b] < d[b])
                d[b] = d[a] + w[a][b];
    }
}

void print(){
    cout << "d:" << endl;
    for(int i=0; i<n; i++)
        cout << d[i] << " ";
    cout << endl;
}

int main(){
    read();
    dijkstra(0);
    print();
    return 0;
}

/*

5
9 3 5 9 9
9 9 2 9 6
9 1 9 4 6
9 9 9 9 2
3 9 9 7 9

*/
