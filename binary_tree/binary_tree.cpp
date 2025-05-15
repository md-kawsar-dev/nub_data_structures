#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val)
    {
        data = val;
        left = nullptr;
        right= nullptr;
    }
};

Node* insert(Node* root,int val)
{
    if(root ==nullptr)
    {
        return new Node(val);
    }
    if(val<root->data)
    {
        root->left = insert(root->left,val);
    }else{
        root->right = insert(root->right,val);
    }
    return root;
}
// Pre-order: Root -> Left -> Right
void preorder(Node* root)
{
    if(root != nullptr)cout<<root->data<<" ";
    if(root->left !=nullptr)preorder(root->left);
    if(root->right !=nullptr)preorder(root->right);
}
// In-order: Left -> Root -> Right
void inorder(Node* root) {
    if (root->left != nullptr) inorder(root->left);
    if (root != nullptr) cout << root->data << " ";
    if (root->right != nullptr) inorder(root->right);
}

// Post-order: Left -> Right -> Root
void postorder(Node* root) {
    if (root->left != nullptr) postorder(root->left);
    if (root->right != nullptr) postorder(root->right);
    if (root != nullptr) cout << root->data << " ";
}

int main() {
    Node* root = nullptr;
    int n, value;

    cout << "How many nodes do you want to insert? ";
    cin >> n;

    cout << "Enter " << n << " node values:\n";
    for (int i = 0; i < n; ++i) {
        cin >> value;
        root = insert(root, value);
    }

    cout << "\nPre-order Traversal: ";
    preorder(root);
     cout << "\nIn-order Traversal: ";
    inorder(root);

    cout << "\nPost-order Traversal: ";
    postorder(root);

    cout << endl;
    return 0;
}
