#include <bits/stdc++.h>

using namespace std;

string x, y;
int LCS[1000][1000];
char path[1000][1000];
void read(){
    cin >> x >> y;
}

void longest_common_subsequence(){
    for(int i=0; i<=x.length(); i++){
        LCS[i][0] = 0;
        path[i][0] = '.';
    }
    for(int j=0; j<=y.length(); j++){
        LCS[0][j] = 0;
        path[0][j] = '.';
    }

    for(int i=1; i<=x.length(); i++){
        for(int j=1; j<=y.length(); j++){
            if(x[i-1] == y[j-1]){
                LCS[i][j] = LCS[i-1][j-1] + 1;
                path[i][j] = '\\';
            }
            else{
                LCS[i][j] = max(LCS[i][j-1], LCS[i-1][j]);
                if(LCS[i][j-1] > LCS[i-1][j] && LCS[i][j-1] != LCS[i-1][j])
                    path[i][j] = '-';
                else if(LCS[i][j-1] < LCS[i-1][j] && LCS[i][j-1] != LCS[i-1][j])
                    path[i][j] = '|';
                else
                    path[i][j] = '+';
            }
        }
    }
}

void print(){
    cout << "\nTable:" << endl;
    cout << setw(8) << "- ";
    for(int j=0; j<y.length(); j++)
        cout << setw(3) << y[j] << " ";
    cout << endl;

    for(int i=0; i<=x.length(); i++){
        if(i != 0){
            cout << setw(3) << x[i-1] << " ";
        }
        else{
            cout << setw(4) << "- ";
        }
        for(int j=0; j<=y.length(); j++){
            cout << setw(3) << LCS[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    cout << "\nPath:" << endl;
    cout << setw(8) << "- ";
    for(int j=0; j<y.length(); j++)
        cout << setw(3) << y[j] << " ";
    cout << endl;

    for(int i=0; i<=x.length(); i++){
        if(i != 0){
            cout << setw(3) << x[i-1] << " ";
        }
        else{
            cout << setw(4) << "- ";
        }
        for(int j=0; j<=y.length(); j++){
            cout << setw(3) << path[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    return;
}
int main(){
    read();
    longest_common_subsequence();
    print();
}

/*
atgc
tga

atgc
gctg
*/
