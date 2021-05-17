#include<bits/stdc++.h>
using namespace std;
struct Node{
    char item;
    struct Node *left, *right;
};
typedef Node node;
stack<node*> st;
int level(char c){
    if(c == '^') return 5;
    if(c == '*') return 4;
    if(c == '+') return 3;
    if(c == '(' or c == ')') return -1;
}
node* Makenode(char c){
    node *newnode = new node;
    newnode -> item = c;
    newnode -> left = NULL;
    newnode -> right = NULL;
    return newnode;
}
void MakeTree(string postfix){
    for(int i = 0; i < postfix.size(); ++i){
        node *newnode = new node;
        newnode = Makenode(postfix[i]);
        if((postfix[i] >= 'a' and postfix[i] <= 'z') or postfix[i] == '(')
            st.push(newnode);
        else if(postfix[i] == ')'){
            node *nodeprev = st.top(), *nodes = st.top();
            st.pop();
            while(nodeprev -> right != NULL)
                nodeprev = nodeprev -> right;
            nodeprev -> right = newnode;
            node *nodeprevprev = st.top();
            st.pop();
            nodeprevprev -> left = nodes;
            st.push(nodeprevprev);
        }
        else{
            node *n1 = st.top(); st.pop();
            node *n2 = st.top(); st.pop();
            newnode -> left = n2;
            newnode -> right = n1;
            st.push(newnode);
        }
    }
}
string MakePostfix(string s){
    string post;
    stack<char> stpost;
    for(int i = 0; i < s.size(); ++i){
        if(s[i] >= 'a' and s[i] <= 'z'){
            post.push_back(s[i]);
        }
        else if(s[i] == '(' or s[i] == ')'){
            if(s[i] == '(') {
                stpost.push('(');
                post.push_back(stpost.top());
               }
            else{
                while(!stpost.empty() and stpost.top() != '('){
                    post.push_back(stpost.top());
                    stpost.pop();
                }
                 post.push_back(')');
                stpost.pop();
            }
        }
        else{
            if(stpost.empty() or level(s[i]) > level(stpost.top())) stpost.push(s[i]);
            else{
                while(!stpost.empty() and level(s[i]) <= level(stpost.top())){
                    post.push_back(stpost.top());
                    stpost.pop();
                }
                stpost.push(s[i]);
            }
        }
    }
    while(!stpost.empty()){
        post.push_back(stpost.top());
        stpost.pop();
    }
    return post;
}
void printInfix(node *curr){
    if(curr -> item == '(') printf("(");
    if(curr -> left != NULL)
        printInfix(curr -> left);
    if(curr -> item != '(' and curr -> item != ')')
     printf("%c", curr -> item);
    if(curr -> right != NULL)
        printInfix(curr -> right);
    if(curr -> item == '(') printf(")");
}

int FindLast(node* curr, char c, int Cout){
    if(curr -> left != NULL and curr -> left -> item == c)
        return FindLast(curr -> left, c, Cout + 1);
    return Cout;
}

int main(){
    string s;
    cin >> s;
    string post = MakePostfix(s);
    MakeTree(post);
    int n; scanf("%d", &n);
    while(n--){
        vector<int> v;
        int x;
        node *root = st.top();
        while(true){
            scanf("%d", &x);
            if(x == 0){
                reverse(v.begin(), v.end());
                for(int i = 0; i < v.size(); ++i){
                    printf("op(%d,", v[i]);
                }
                printf("p");
                for(int i = 0; i < v.size(); ++i){
                    printf(")");
                }
                printf("=");
                if(root == NULL){
                    printf("null\n");
                    break;
                }
                printInfix(root);
                printf("\n");
                break;
            }else{
                v.push_back(x);
                if(root == NULL) continue;
                if(root -> item >= 'a' and root -> item <= 'z' and x != 1){
                    root = NULL;
                    continue;
                }
                vector<node*> no;
                int Last = FindLast(root, root -> item , 1);
                for(int i = 0; i <= Last and root != NULL; ++i){
                    no.push_back(root);
                    root = root -> left;
                }
                reverse(no.begin(), no.end());
                if(x == 1) root = no[x - 1];
                else if(x > Last + 1) root = NULL;
                else if(x == Last + 1) root = no[Last] -> right;
                else root = no[x - 1] -> right;
            }
        }
    }
}
