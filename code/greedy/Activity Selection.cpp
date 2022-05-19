#include<bits/stdc++.h>

using namespace std;

int n;
int s[1000], e[1000]; // start point and end point
int start_time = 0x3f3f3f3f, end_time = 0;
vector<int> ans;

void read(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> s[i] >> e[i];
        start_time = min(start_time, s[i]);
        end_time = max(end_time, e[i]);
    }
}
void activity_selection(){ // with iterate way
    for(int i=0; i<n; i++){
        if(s[i] >= start_time && e[i] <= end_time){
            start_time = e[i];
            ans.push_back(i);
        }
    }
}
void print(){
    for(int i=0; i<ans.size(); i++)
        cout << ans[i] << " ";
    cout << endl;
}

int main(){
    read();
    activity_selection();
    print();
    return 0;
}

/*
11
1 4
3 5
0 6
5 7
3 8
5 9
6 10
8 11
8 12
2 13
12 14
*/
