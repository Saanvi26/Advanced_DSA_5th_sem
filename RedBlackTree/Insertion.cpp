#include <iostream>
using namespace std;

class RedBlackTree
{
private:
    // Node creating subclass
    struct Node
    {
        int data;
        Node *left;
        Node *right;
        char colour;
        Node *parent;

        Node(int data) : data(data), left(nullptr), right(nullptr), colour('R'), parent(nullptr) {}
    };

    Node *root;
    bool ll; // Left-Left Rotation flag
    bool rr; // Right-Right Rotation flag
    bool lr; // Left-Right Rotation flag
    bool rl; // Right-Left Rotation flag

    Node *rotateLeft(Node *node)
    {
        Node *x = node->right;
        Node *y = x->left;
        x->left = node;
        node->right = y;
        node->parent = x;
        if (y != nullptr)
            y->parent = node;
        return x;
    }

    // Function to perform Right Rotation
    Node *rotateRight(Node *node)
    {
        Node *x = node->left;
        Node *y = x->right;
        x->right = node;
        node->left = y;
        node->parent = x;
        if (y != nullptr)
            y->parent = node;
        return x;
    }
    Node *insertHelp(Node *root, int data)
    {
        bool f = false; 

        if (root == nullptr)
            return new Node(data);
        else if (data < root->data)
        {
            root->left = insertHelp(root->left, data);
            root->left->parent = root;
            if (root != this->root)
            {
                if (root->colour == 'R' && root->left->colour == 'R')
                    f = true;
            }
        }
        else
        {
            root->right = insertHelp(root->right, data);
            root->right->parent = root;
            if (root != this->root)
            {
                if (root->colour == 'R' && root->right->colour == 'R')
                    f = true;
            }
        }

        if (ll)
        {
            root = rotateLeft(root);
            root->colour = 'B';
            root->left->colour = 'R';
            ll = false;
        }
        else if (rr)
        {
            root = rotateRight(root);
            root->colour = 'B';
            root->right->colour = 'R';
            rr = false;
        }
        else if (rl)
        {
            root->right = rotateRight(root->right);
            root->right->parent = root;
            root = rotateLeft(root);
            root->colour = 'B';
            root->left->colour = 'R';
            rl = false;
        }
        else if (lr)
        {
            root->left = rotateLeft(root->left);
            root->left->parent = root;
            root = rotateRight(root);
            root->colour = 'B';
            root->right->colour = 'R';
            lr = false;
        }

        if (f)
        {
            if (root->parent->right == root)
            {
                if (root->parent->left == nullptr || root->parent->left->colour == 'B')
                {
                    if (root->left != nullptr && root->left->colour == 'R')
                        rl = true;
                    else if (root->right != nullptr && root->right->colour == 'R')
                        ll = true;
                }
                else
                {
                    root->parent->left->colour = 'B';
                    root->colour = 'B';
                    if (root->parent != this->root)
                        root->parent->colour = 'R';
                }
            }
            else
            {
                if (root->parent->right == nullptr || root->parent->right->colour == 'B')
                {
                    if (root->left != nullptr && root->left->colour == 'R')
                        rr = true;
                    else if (root->right != nullptr && root->right->colour == 'R')
                        lr = true;
                }
                else
                {
                    root->parent->right->colour = 'B';
                    root->colour = 'B';
                    if (root->parent != this->root)
                        root->parent->colour = 'R';
                }
            }
            f = false;
        }
        return root;
    }

    void inorderTraversalHelper(Node *node)
    {
        if (node != nullptr)
        {
            inorderTraversalHelper(node->left);
            cout << node->data << " ";
            inorderTraversalHelper(node->right);
        }
    }

    void printTreeHelper(Node *root, int space)
    {
        if (root != nullptr)
        {
            space += 10;
            printTreeHelper(root->right, space);
            cout << endl;
            for (int i = 10; i < space; i++)
               cout << " ";
            cout << root->data << endl;
            printTreeHelper(root->left, space);
        }
    }

public:
    RedBlackTree() : root(nullptr), ll(false), rr(false), lr(false), rl(false) {}

    void insert(int data)
    {
        if (root == nullptr)
        {
            root = new Node(data);
            root->colour = 'B';
        }
        else
            root = insertHelp(root, data);
    }

    void inorderTraversal()
    {
        inorderTraversalHelper(root);
    }

    void printTree()
    {
        printTreeHelper(root, 0);
    }
};

int main()
{

    RedBlackTree t;
    int arr[] = {1, 4, 6, 3, 5, 7, 8, 2, 9};
    for (int i = 0; i < 9; i++)
    {
        t.insert(arr[i]);
        cout << endl;
        t.inorderTraversal();
    }
    t.printTree();
    return 0;
}
// mid sem 1:
// avl
// red black
// b tree