#include<bits/stdc++.h>

using namespace std;

const int maxn = 1000, inf = 0x3f3f3f3f;
int n;
float A[maxn][maxn], R[maxn][maxn];
float p[maxn];

void read(){
    cin >> n;
    for(int i=1; i<=n; i++)
        cin >> p[i];
}
void printA(){
    cout << "A: " << endl;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cout << setw(5) << A[i][j] << " ";
        }
        cout << endl;
    }
}
void printR(){
    cout << "R: " << endl;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cout << setw(5) << R[i][j] << " ";
        }
        cout << endl;
    }
}
float sigma(int a, int b){
    float sum = 0;
    for(int i=a; i<=b; i++)
        sum += p[i];
    return sum;
}
void opt_search_tree(){
    int i, j, k, diagonal;
    for(i=1; i<=n; i++){
        A[i][i-1] = R[i][i-1] = 0;
        A[i][i] = p[i];
        R[i][i] = i;
    }

    A[n+1][n] = R[n+1][n] = 0;

    for(diagonal=1; diagonal<= n-1; diagonal++){
        for(i=1; i<=n-diagonal; i++){
            j = i + diagonal;
            float best = inf;
            for(k=i; k<=j; k++){
                if(best > (A[i][k-1] + A[k+1][j])){
                    best = A[i][k-1] + A[k+1][j];
                    A[i][j] = best + sigma(i,j);
                    R[i][j] = k;
                }
            }
        }
    }

    float minavg = A[1][n];
    cout << "minavg = " << minavg << endl;
    printA();
    printR();
}

int main(){
    read();
    opt_search_tree();

    return 0;
}
