                            
#include <iostream>
#include <vector>
#include <climits> 
using namespace std;


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
   
    int findCeil(TreeNode* root, int key){

        int ceil = -1; 
        while(root){
            if(root->val == key){
                ceil = root->val;
                return ceil;
            } 
            
            if(key > root->val){
                root = root->right;
            }
            else{ 
                ceil = root->val;
                root = root->left;
            }
        }
        return ceil;
    }
};



void printInOrder(TreeNode* root) {
   
    if (root == nullptr) {  
        return;
    }
    printInOrder(root->left);
    cout << root->val << " ";
    printInOrder(root->right);
}

TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return root;
        TreeNode* cur = root;
        TreeNode* prev = NULL;
        while(cur) {
            if(key == cur->val){
                if(cur->left){
                    TreeNode* rightMost = cur->left;
                    while(rightMost->right) rightMost = rightMost->right;
                    rightMost->right = cur->right;
                    if(!prev) root = cur->left;
                    else {
                        if(prev->left == cur) prev->left = cur->left;
                        else prev->right = cur->left;
                    }
                } else if(cur->right){
                    TreeNode* leftMost = cur->right;
                    while(leftMost->left) leftMost = leftMost->left;
                    leftMost->left = cur->left;
                    if(!prev) root = cur->right;
                    else {
                        if(prev->left == cur) prev->left = cur->right;
                        else prev->right = cur->right;
                    }
                } else {
                    if(!prev) root = NULL;
                    else {
                        if(prev->left == cur) prev->left = NULL;
                        else prev->right = NULL;
                    }
                };
                delete cur;
                break; 
            }
            prev = cur;
            if(key < cur->val) cur = cur->left;
            else cur = cur->right;
        }
        return root;
    }

int main() {
    // Creating a BST
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(13);
    root->left->left = new TreeNode(3);
    root->left->left->left = new TreeNode(2);
    root->left->left->right = new TreeNode(4);
    root->left->right = new TreeNode(6);
    root->left->right->right = new TreeNode(9);
    root->right->left = new TreeNode(11);
    root->right->right = new TreeNode(14);
    
    cout << "Binary Search Tree: "<< endl;
    printInOrder(root);
    cout << endl;

    Solution solution;
    
    // Searching for a value in the BST
    int target = 8;
    int ciel = solution.findCeil(root, target);
    
    if(ciel != -1){
        cout << "Ceiling of " << target << " is: " << ciel << endl;
    }
    else{
        cout << "No ceiling found!";
    }
    
    return 0;
}
                            
                        