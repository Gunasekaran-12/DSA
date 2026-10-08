#include <bits/stdc++.h>
using namespace std;

struct Node {

    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// Create Binary Tree using Level Order
Node* createTree() {

    int value;
    cin >> value;

    if (value == -1)
        return nullptr;

    Node* root = new Node(value);

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {

        Node* node = q.front();
        q.pop();

        // Left child
        cin >> value;

        if (value != -1) {
            node->left = new Node(value);
            q.push(node->left);
        }

        // Right child
        cin >> value;

        if (value != -1) {
            node->right = new Node(value);
            q.push(node->right);
        }
    }

    return root;
}

// Inorder
void inorder(Node* root) {

    if (root == nullptr)
        return;

    inorder(root->left);

    cout << root->data << " ";

    inorder(root->right);
}

// Preorder
void preorder(Node* root) {

    if (root == nullptr)
        return;

    cout << root->data << " ";

    preorder(root->left);
    preorder(root->right);
}

// Postorder
void postorder(Node* root) {

    if (root == nullptr)
        return;

    postorder(root->left);
    postorder(root->right);

    cout << root->data << " ";
}

// Level Order
void levelOrder(Node* root) {

    if (root == nullptr)
        return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {

        Node* node = q.front();
        q.pop();

        cout << node->data << " ";

        if (node->left)
            q.push(node->left);

        if (node->right)
            q.push(node->right);
    }
}

// Search
bool search(Node* root, int key) {

    if (root == nullptr)
        return false;

    if (root->data == key)
        return true;

    return search(root->left, key) ||
           search(root->right, key);
}

// Count Nodes
int countNodes(Node* root) {

    if (root == nullptr)
        return 0;

    return 1 +
           countNodes(root->left) +
           countNodes(root->right);
}

// Count Leaf Nodes
int countLeaves(Node* root) {

    if (root == nullptr)
        return 0;

    if (root->left == nullptr &&
        root->right == nullptr)
        return 1;

    return countLeaves(root->left) +
           countLeaves(root->right);
}

// Height
int height(Node* root) {

    if (root == nullptr)
        return 0;

    return 1 + max(
        height(root->left),
        height(root->right)
    );
}

int main() {

    Node* root = createTree();

    cout << "Inorder: ";
    inorder(root);
    cout << endl;

    cout << "Preorder: ";
    preorder(root);
    cout << endl;

    cout << "Postorder: ";
    postorder(root);
    cout << endl;

    cout << "Level Order: ";
    levelOrder(root);
    cout << endl;

    // Search
    int key;
    cin >> key;

    cout << "Search: ";

    if (search(root, key))
        cout << "Found";
    else
        cout << "Not Found";

    cout << endl;

    // Count nodes
    cout << "Total Nodes: "
         << countNodes(root) << endl;

    // Count leaves
    cout << "Leaf Nodes: "
         << countLeaves(root) << endl;

    // Height
    cout << "Height: "
         << height(root) << endl;

    return 0;
}