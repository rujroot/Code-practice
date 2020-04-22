
#include <bits/stdc++.h>
using namespace std;
int c,l,num,x=1,co=1,m=0;
string s,postfix;
stack<char> st;
struct node{
    char item;
    node *left,*right;
};
void nb(struct node* Node){
    if(Node -> left != NULL and Node -> left -> item == Node -> item){
        co++;
        nb(Node -> left);
    }
    if(Node -> right != NULL and Node -> right -> item == Node -> item){
        co++;
        nb(Node -> right);
    }
}
void P(stack<int> sta){
    int l = sta.size();
    for(int i=0;i<l;++i){
        printf("op(%d,",sta.top());
        sta.pop();
    }
    printf("p");
    for(int i=0;i<l;++i){
        printf(")");
    }
    printf("=");
}

void IOD(struct node* node){
    if(node->item == ')'){
          printf("(");
    }
    if(node -> left != NULL){
        IOD(node->left);
        m++;
    }
     printf("%c",node->item);
    if(node -> right != NULL){
        IOD(node->right);
    }

}
node *createnode(int data){
    node *newnode = new(node);
    newnode->item = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return(newnode);
}
int imp(char opa){
    /*if(opa == 'V')
        return 4;
    else */if(opa == '^')
        return 3;
    else if(opa == '*')
        return 2;
    else if(opa == '+')
        return 1;
    else
        return -1;
}
node* insertNodeAll(){
    stack<node *> st;
    node *t,*t1,*t2;
    for(int i=0;i<postfix.size();++i){
        if(postfix[i] >= 97 and postfix[i] <= 122){
            t = createnode(postfix[i]);
            st.push(t);
        }else if(postfix[i] != '(' and postfix[i] != ')'){
            t = createnode(postfix[i]);
              t1 = st.top();
                st.pop();
              t2 = st.top();
                st.pop();
            //()printf("%c \n",postfix[i]);
                t -> right = t1;
                t -> left = t2;
            st.push(t);
        }else if(postfix[i] == ')'){
            t = createnode(postfix[i]);
            t1 = st.top();
            st.pop();
            t -> left = t1;
            st.push(t);
        }
    }

    t = st.top();
    st.pop();
    return t;
//    if()
}
int main()
{
    //printf("%d %d %d",'a','z','+');
    cin >> s;
    l = s.size();
    for(int i=0;i<l;++i){
        //PS(st);
          //printf("%d ",s.size());
        if(s[i] >= 97 and s[i] <= 122){
            //printf("pass");
            postfix.push_back(s[i]);
           // cout << postfix << "\n";
        }else if(s[i] == '('){
            st.push('(');
        }else if(s[i] == ')'){
            postfix.push_back('(');
            while(st.top() != '('){
                postfix.push_back(st.top());
                st.pop();
            }
            st.pop();
            postfix.push_back(')');
        }
        else{
            if(st.empty()){
                st.push(s[i]);
            }
            else if(imp(s[i]) > imp(st.top())){
                st.push(s[i]);
            }else if(imp(s[i]) <= imp(st.top())){
                while(!st.empty() and imp(s[i]) <= imp(st.top())){
                    postfix.push_back(st.top());
                    st.pop();
                }
                st.push(s[i]);
            }
        }
    }

    while(!st.empty()){
        postfix.push_back(st.top());
        st.pop();
    }
    //printf("Yes");
    //cout << postfix << "\n";
    node *root = insertNodeAll();
    //IOD(root);
    //printf("\n\n\n");
    /*printf("%c\n",root->item);
    printf("%c\n",root->left->left->left->item);
    printf("%c\n",root->left->left->right->item);
    //printf("%c",root->left->left->item);
    //IOD(root);*/
    scanf("%d",&num);
    for(int i=0;i<num;++i){
        stack<int> number;
        bool HA = true;
        node *ask = root;
       // printf("%c",root->right->item);
        while(true){
            co = 1;
            node *gotoask = ask;
            //printf("%c\n",ask->item);
            nb(gotoask);
            //printf("%c",ask->item);
            //printf("%d",co);
            scanf("%d",&x);
            //printf("%d",x);
            //printf("x == %d \n",x);
            /*if(x > 1){
                number.push(x);
                for(int j=1;j<x;++j){
                if(ask -> right != NULL){
                   ask = ask->right;
                }else{
                    HA = false;
                    }
                }
            }else if(x == 1){
                number.push(x);
                 if(ask -> left != NULL){
                   ask = ask->left;
                }else{
                    HA = false;
                }
            }*/if(x == 0){
                    if(HA){
                        P(number);
                        IOD(ask);
                        printf("\n");
                    }else{
                        P(number);
                        printf("null\n");
                    }
                    break;
                }
                else if(x == 1){
                    number.push(x);
                    for(int j=0;j<co-x+1;++j){
                        if(ask -> left != NULL){
                            ask = ask -> left;
                        }
                    }
                }
                else{
                    number.push(x);
                    for(int j=0;j<co-x+1;++j){
                        if(ask -> left == NULL){
                            HA = false;
                        }else{
                            ask = ask -> left;
                        }
                    }
                    if(ask -> right == NULL or co-x+1 < 0){
                        HA = false;
                    }else{
                        ask = ask -> right;
                    }
                }
            }
        }

    //IOD(root);
    /*root->left = createnode('*');
    root->right = createnode('*');
    root->left->left = createnode('a');
    root->left->right = createnode('^');
    root->left->right->left = createnode('b');
    root->left->right->right = createnode('c');
    root->right->left = createnode('d');
    root->right->right = createnode('^');
    root->right->right->left = createnode('e');
     root->right->right->right = createnode('f');*/
    //POD(root);
    return 0;
}
