#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node(int val) {
        this->val = val;
        left = nullptr;
        right = nullptr;
    }
};

class BinaryTree {
public:
    // Insert function
    Node* insert(int val, Node* root) {
        if (root == nullptr) {
            return new Node(val);
        } else if (val < root->val) {
            root->left = insert(val, root->left);
        } else {
            root->right = insert(val, root->right);
        }
        return root;
    }
//helper function 
Node* min(Node *root)
{
    while(root->left!=NULL)
    {
    root=root->left;
    }
    return root;
}
// deletenode
Node* deletenode(int val,Node*root)
{
    if(root==NULL) 
    {
        cout<<"empty";
        return root;
    }
        //traversing 
        if(val<root->val) root->left=deletenode(val,root->left);
        else if(val>root->val) root->right= deletenode(val,root->right);
else 
{
    // no child
    if(root->left==nullptr && root->right==nullptr)
{
    delete root;
    return nullptr;
}
// one child
 else if (root->left == nullptr) {
                Node* temp = root->right;
                delete root;
                return temp;
            } 
            else if (root->right == nullptr) {
                Node* temp = root->left;
                delete root;
                return temp;
            }
// two child
else
{
    Node *temp= min(root->right);
    root->val= temp->val;
    root->right= deletenode(temp->val,root->right);
}
}
return root;
}
// mirror image 
void* mirror(Node *root)
{

if(!root) return nullptr;
 mirror(root->left);
 mirror(root->right);
 Node *temp= root->left;
 root->left=root->right;
 root->right=temp;
}
    // Inorder traversal (Left, Root, Right)
    void inorderTraversal(Node* root) {
        if (root != nullptr) {
            inorderTraversal(root->left);
            cout << root->val << " ";
            inorderTraversal(root->right);
        }
    }

    // Preorder traversal (Root, Left, Right)
    void preorder(Node* root) {
        if (root != nullptr) {
            cout << root->val << " ";
            preorder(root->left);
            preorder(root->right);
        }
    }

    // Postorder traversal (Left, Right, Root)
    void postorder(Node* root) {
        if (root != nullptr) {
            postorder(root->left);
            postorder(root->right);
            cout << root->val << " ";
        }
    }

    // Search function
    bool search(int val, Node* root) {
        if (root == nullptr) {
            return false;
        }
        if (root->val == val) {
            return true;
        } else if (val < root->val) {
            return search(val, root->left);
        } else {
            return search(val, root->right);
        }
    }
};

int main() {
    BinaryTree b;
    Node* root = nullptr; // Initial tree root

    // Insert nodes into the binary tree
    root = b.insert(34, root);
    root = b.insert(45, root);
    root = b.insert(23, root);
    root = b.insert(2, root);
    root = b.insert(3, root);
    root = b.insert(-3, root);

    // Traversals
    cout << "Inorder traversal: ";
    b.inorderTraversal(root);
    cout << "\nPreorder traversal: ";
    b.preorder(root);
    cout << "\nPostorder traversal: ";
    b.postorder(root);

    // Search for a value
    cout << "\nSearching for 45: ";
    if (b.search(45, root)) {
        cout << "Found";
    } else {
        cout << "Not Found";
    }
    int key = 45;
    root = b.deletenode(key,root);
     cout << "Inorder traversal: ";
    b.inorderTraversal(root);
    b.mirror(root);
      cout << "Inorder traversal: ";
    b.inorderTraversal(root);
    
    return 0;
}