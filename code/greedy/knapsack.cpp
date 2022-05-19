#include <bits/stdc++.h>

using namespace std;

int n, w;
int val[1000], wei[1000];
int greedy[1000];

void read(){
    cin >> n >> w;
    for(int i=0; i<n; i++)
        cin >> val[i] >> wei[i];
}
void knapsack(){
    for(int i=0; i<=w; i++)
        greedy[i] = 0;

    for(int j=0; j<=w; j++){
        for(int i=0; i<n; i++){
            int vi = val[i], wi = wei[i];
            if(wi <= j){
                int temp = vi + greedy[j-wi];
                greedy[j] = max(greedy[j],temp);
            }
        }
    }
}
void print(){
    for(int i=0; i<=w ;i++)
        cout << greedy[i] << " ";
    cout << endl;
}

int main(){
    read();
    knapsack();
    print();
    return 0;
}

/*
3 5
4 1
9 2
20 4
*/
