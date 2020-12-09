#include<bits/stdc++.h>
using namespace std;
struct node
{
    int key;
    struct node *left, *right;
    
};

void perorder(struct node* Node){
    //cout<<"in";
    if(Node != NULL){
        perorder(Node -> left);
        perorder(Node -> right);
        printf("%d ",Node -> key);
    }
}

struct node* newnode( int item){
    struct node* temp = new node;
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

struct node* insert(struct node* Node, int item){
    if(Node == NULL)
     return newnode(item);
    if(Node->key > item)
        Node -> left = insert(Node->left,item);
    if(Node->key <= item) 
        Node -> right = insert(Node->right,item);
    return Node;
}


int main(){
    struct node* root = NULL;
    int n,x;
    scanf("%d%d",&n,&x);
    root = insert(root, x);
    for(int i = 1; i < n; ++i){
        scanf("%d",&x);
        insert(root, x);
    }
    perorder(root);
}