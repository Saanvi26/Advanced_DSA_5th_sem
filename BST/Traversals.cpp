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

void inorderTraversal(vector<int>& inorder, TreeNode* root) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(inorder, root->left);
    inorder.push_back(root->val);
    inorderTraversal(inorder, root->right);  
}
void postorderTraversal(vector<int>& postorder, TreeNode* root)
{
    if(root==NULL){
        return ;
    }
    postorderTraversal(postorder,root->left);
    postorderTraversal(postorder,root->right);
    postorder.push_back(root->val);
}
void preorderTraversal(vector<int>& preorder, TreeNode* root)
{
    if(root==NULL){
        return ;
    }
    preorder.push_back(root->val);
    preorderTraversal(preorder,root->left);
    preorderTraversal(preorder,root->right);
}

int main() {
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter the " << i << "th node: ";
        cin >> arr[i];
    }

    TreeNode* root = NULL;
    vector<int> inorder;
    vector<int> postorder;
    vector<int> preorder;
    for (int i = 0; i < n; i++) {
        root = Create(root, arr[i]);
    }
    
    cout << endl;
    inorderTraversal(inorder, root);
    postorderTraversal(postorder,root);
    preorderTraversal(preorder,root);
    cout<<"Inorder"<<endl;
    for (int i = 0; i < inorder.size(); i++) {
        cout << inorder[i] << " ";
    }
    cout<<endl;
     cout<<"Preorder"<<endl;
     for (int i = 0; i < preorder.size(); i++) {
        cout << preorder[i] << " ";
    }
     cout<<endl;
      cout<<"Postorder"<<endl;
    for (int i = 0; i < postorder.size(); i++) {
        cout << postorder[i] << " ";
    }
    return 0;
}
