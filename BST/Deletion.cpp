#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode* Create(TreeNode* root, int data) {
    if (root == NULL) {
        root = new TreeNode(data); 
        return root;
    }
    else if (root->val < data) {
        root->right = Create(root->right, data);
    }
    else {
        root->left = Create(root->left, data);
    }
    return root;
}


int main (){
int n;
    cout << "Enter the number of nodes: ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter the " << i << "th node: ";
        cin >> arr[i];
    }

    TreeNode* root = NULL;
    for (int i = 0; i < n; i++) {
        root = Create(root, arr[i]);
    }
    

}