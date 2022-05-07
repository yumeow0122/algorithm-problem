#include <bits/stdc++.h>

using namespace std;

string x, y;
string xx, yy;
int SA[1000][1000];
int wei, ins, del;
void read(){
    cin >> wei >> ins >> del;
    cin >> x >> y;
}

void sequence_alignment(){
    for(int i=0; i<=x.length(); i++)
        SA[i][0] = i *del;
    for(int j=0; j <=y.length(); j++)
        SA[0][j] = j*ins;

    for(int i=0; i<x.length(); i++){
        for(int j=0; j<y.length(); j++){
            if(x[i] != y[j])
                SA[i+1][j+1] = min(SA[i][j]+wei, min(SA[i+1][j]+ins, SA[i][j+1]+del));
            else
                SA[i+1][j+1] = min(SA[i][j],   min(SA[i+1][j]+ins, SA[i][j+1]+del));
        }
    }
}

void print(){
    for(int i=0; i<=x.length(); i++){
        for(int j=0; j<=y.length(); j++){
            cout << setw(3) << SA[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
int main(){
    read();
    sequence_alignment();
    print();
}

/*
7 4 4
banana
aeniqadikjaz

*/
