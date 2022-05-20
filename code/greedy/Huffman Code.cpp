#include<bits/stdc++.h>

using namespace std;

struct Node{
    int freq;
    char data;
    Node *left, *right;

    Node(char c, int f){
        data = c;
        freq = f;
        left = right = NULL;
    }
};

int num;
int f[1000];
char c[1000];
Node *root;


void read(){
    cin >> num;
    for(int i=0; i<num; i++)
        cin >> c[i] >> f[i];
}

bool comp(Node *a, Node *b){
    return a->freq > b->freq;
}
void huffman_code(){
    vector<Node*> vec;
    for(int i=0; i<num; i++){
        Node *n = new Node(c[i],f[i]);
        vec.push_back(n);
    }

    while(vec.size() > 1){
        sort(vec.begin(), vec.end(), comp);
        Node *n1 = vec.back();
        vec.pop_back();
        Node *n2 = vec.back();
        vec.pop_back();
        int temp = n1->freq + n2->freq;
        Node *n = new Node('#',temp);
        n->left = n1;
        n->right = n2;
        vec.push_back(n);
    }
    root = vec.back();
}
void print_tree(Node *node, int n){
    if(node == NULL)
        return;
    print_tree(node->right, n + 1);
    for(int j = 0; j < n; j ++)
        cout << "            ";
    cout << "(" << node->data << ", " << node->freq << ")" << endl;
    print_tree(node->left, n + 1);
}

void print_code(Node *node, string str){
    if (node == NULL)
        return;

    if (node->data != '#')
        cout << node->data << ": " << str << "\n";

    print_code(node->left, str + "0");
    print_code(node->right, str + "1");
}
int main(){
    read();
    huffman_code();
    print_tree(root,0);
    print_code(root,"");
    return 0;
}

/*

6
F 2
O 3
R 4
G 4
E 5
T 7

6
F 5
E 9
C 12
B 13
D 16
A 45
*/
