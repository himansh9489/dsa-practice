#include<bits/stdc++.h>
using namespace std;

struct Node {
 public:
   int val;
   Node *left;
   Node *right;

 public:
   Node(int value) : val(value), left(NULL), right(NULL) {}
};
void printList(vector<int> arr){
    for(int el : arr){
        cout<<el<<" ";
    }
    cout << endl;
}
void printLists(vector<vector<int>> mat){
    for(auto arr : mat){
        for(int el : arr){
            cout<<el<<" ";
        }
        cout<<endl;
    }
    cout << endl;
}
void preOrder(Node* root, vector<int> &ans){
    if(root == NULL) return;
    ans.push_back(root->val);
    preOrder(root->left, ans);
    preOrder(root->right, ans);
}

void inOrder(Node* root,  vector<int> &ans){
    if(root == NULL) return;
    inOrder(root->left, ans);
    ans.push_back(root->val);
    inOrder(root->right, ans);
}

void postOrder(Node* root, vector<int> &ans){
    if(root == NULL) return;
    postOrder(root->left, ans);
    postOrder(root->right, ans);
    ans.push_back(root->val);
}

vector<vector<int>> levelOrder(Node* root) {
    vector<vector<int>> leverOrder;
    if(root == NULL) return leverOrder;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();
        vector<int> arr;
        while(size--){
            Node* node = q.front(); q.pop();
            arr.push_back(node->val);
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        leverOrder.push_back(arr);
    }
    return leverOrder;
}

vector<int> iterativePreOrder(Node* root){
    vector<int> preOrder;
    if(root == NULL) return preOrder;
    stack<Node*> st;
    st.push(root);
    while (!st.empty()){
        root = st.top(); 
        st.pop();
        preOrder.push_back(root->val);
        if(root->right) st.push(root->right) ;
        if(root->left) st.push(root->left);
    }
    return preOrder;
}

vector<int> iterativeInOrder(Node* root){
    vector<int> inOrder;
    if(root == NULL) return inOrder;
    stack<Node *> st;
    while (true) {
       if (root) {
          st.push(root);
          root = root->left;
       } else {
          if (st.empty()) break;
          root = st.top();
          st.pop();
          inOrder.push_back(root->val);
          root = root->right;
       }
    }
    return inOrder;
}

vector<int> iterativePostOrderWithTwoStack(Node* root){
    vector<int> postOrder;
    if(root == NULL) return postOrder;
    stack<Node*> st1, st2;
    st1.push(root);
    while (!st1.empty()){
        root = st1.top(); st1.pop();
        st2.push(root);
        if(root->left) st1.push(root->left);
        if(root->right) st1.push(root->right);
    }
    while (!st2.empty()){
        postOrder.push_back(st2.top()->val);
        st2.pop();
    }
    return postOrder;
}
vector<int> iterativePostOrderWithOneStack(Node* curr){
    vector<int> postOrder;
    if(curr == NULL) return postOrder;
    stack<Node*> st;
    while (curr != NULL || !st.empty()) {
        if(curr != NULL){
            st.push(curr);
            curr = curr->left;
        } else {
            Node* temp = st.top()->right;
            if(temp == NULL){
                temp = st.top(); st.pop();
                postOrder.push_back(temp->val);
                while (!st.empty() && temp == st.top()->right) {
                    temp = st.top(); st.pop();
                    postOrder.push_back(temp->val);
                }
            } else curr = temp;
        }
    }
    
    return postOrder;
}
vector<vector<int>> allDFSTraversal(Node* root){
    if(root  == NULL) return {};
    vector<int> preOrder,inOrder,postOrder;
    stack<pair<Node*, int>> st;
    st.push({root,1});
    while (!st.empty()) {
       auto it = st.top();
       st.pop();
       if (it.second == 1) {
          preOrder.push_back(it.first->val);
          it.second++;
          st.push(it);
          if (it.first->left) st.push({it.first->left, 1});
       } else if (it.second == 2) {
          inOrder.push_back(it.first->val);
          it.second++;
          st.push(it);
          if (it.first->right) st.push({it.first->right, 1});
       } else {
          postOrder.push_back(it.first->val);
       }
    }
    return {preOrder,inOrder,postOrder};
}
int  main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);
    root->left->right->right = new Node(7);
    vector<int> pre, in, post;
    // preOrder(root, pre);
    // printList(pre);
    // printList(iterativePreOrder(root));
    // inOrder(root, in);
    // printList(in);
    // printList(iterativeInOrder(root));
    // postOrder(root, post);
    // printList(post);
    // printList(iterativePostOrderWithTwoStack(root));
    // printList(iterativePostOrderWithOneStack(root));
    // auto level = levelOrder(root);
    // printLists(level);
    printLists(allDFSTraversal(root));


}
