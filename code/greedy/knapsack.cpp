#include <iostream>
#define L "LEFT"
/*
3 5
1 4
2 9
4 20
*/


using namespace std;

struct Item{
    int val, wei;
};

Item item[1000];
int table[1000][5000];
int N, W;

void show();
void read(){
    cin >> N >> W;
    for(int i=1; i<=N; i++)
        cin >> item[i].wei >> item[i].val;
}
void solve(){
    for(int w=0; w<=W; w++){
        table[0][w] = 0;
    }

    for(int i=1; i<=N; i++){
        int wi = item[i].wei, vi = item[i].val;
        for(int w=0; w<=W; w++){
            if(wi>W || w-wi<0){
                table[i][w] = table[i-1][w];
            }
            else{
                table[i][w] = max(vi + table[i-1][w-wi], table[i-1][w]);
            }
        }
    }
}
void show(){
    for(int i=0; i<=N; i++){
        for(int j=0; j<=W; j++){
            cout << table[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    read();
    solve();
    show();
    cout << L;
    return 0;
}
