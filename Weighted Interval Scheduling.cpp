#include <iostream>
#include <iomanip>

using namespace std;

const int maxn = 1000;
int n;
int W[maxn][maxn], D[maxn][maxn], P[maxn][maxn];

void read(){
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> W[i][j];
}
void printW(){
    cout << "W:" << endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << setw(3) << W[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void printD(){
    cout << "D:" << endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << setw(3) << D[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void printP(){
    cout << "P:" << endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << setw(3) << P[i][j]+1 << " ";
        }
        cout << endl;
    }
    cout << endl;
}


void D_equal_W(){
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            D[i][j] = W[i][j];
}
void floyd(){
    int i, j, k;
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            P[i][j] = -1;

    D_equal_W();

    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            for(k=0; k<n; k++){
                if(D[j][i] + D[i][k] < D[j][k]){
                    P[j][k] = i;
                    D[j][k] = D[j][i] + D[i][k];
                }
            }
        }
    }

    printW();
    printD();
    printP();
}

int main(){
    cin >> n;
    read();
    floyd();

    return 0;
}
