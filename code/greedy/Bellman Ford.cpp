#include <bits/stdc++.h>

using namespace std;

int n;
int d[1000];
int w[1000][1000];
const int inf = 0x3f3f3f3f;

void print();
void read(){
    cin >> n;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> w[i][j];
}
void bellman_ford(int source){
    for (int i=0; i<n; i++)
        d[i] = inf;

    d[source] = 0;
    print();
    for (int i=0; i<n-1; i++){
        for (int a=0; a<n; ++a){
            for (int b=0; b<n; ++b){
                if (d[a] != inf && w[a][b] != inf){
                    if (d[a] + w[a][b] < d[b]){
                        d[b] = d[a] + w[a][b];
                    }
                }
            }
        }
        print();
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
    bellman_ford(0);
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

5
99 -1  4 99 99
99 99  3  2  2
99 99 99 99 99
99  1  5 99 99
99 99 99 -3 99



*/
