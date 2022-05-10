#include <bits/stdc++.h>

using namespace std;

string x, y;
string xx, yy;
int SA[1000][1000];
int x_ans[2000], y_ans[2000];
int wei, gap;
void read(){
    cin >> wei >> gap;
    cin >> x >> y;
}

void sequence_alignment(){

    // get table
    for(int i=0; i<=x.length(); i++)
        SA[i][0] = i *gap;
    for(int j=0; j <=y.length(); j++)
        SA[0][j] = j*gap;

    for(int i=0; i<x.length(); i++){
        for(int j=0; j<y.length(); j++){
            if(x[i] != y[j])
                SA[i+1][j+1] = min(SA[i][j]+wei, min(SA[i+1][j]+gap, SA[i][j+1]+gap));
            else
                SA[i+1][j+1] = min(SA[i][j],   min(SA[i+1][j]+gap, SA[i][j+1]+gap));
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
            cout << setw(3) << SA[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    return;
}
int main(){
    read();
    sequence_alignment();
    print();
}

/*
2 1
atgc
tga

2 1
atgc
gctg
*/
