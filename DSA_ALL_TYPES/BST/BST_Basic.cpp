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

// Insert value into BST
Node* insert(Node* root, int value) {

    if (root == nullptr) {
        return new Node(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    }
    else {
        root->right = insert(root->right, value);
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

    if (key < root->data)
        return search(root->left, key);

    return search(root->right, key);
}

// Minimum
Node* findMin(Node* root) {

    while (root->left != nullptr)
        root = root->left;

    return root;
}

// Maximum
Node* findMax(Node* root) {

    while (root->right != nullptr)
        root = root->right;

    return root;
}

// Delete
Node* deleteNode(Node* root, int key) {

    if (root == nullptr)
        return nullptr;

    if (key < root->data) {

        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data) {

        root->right = deleteNode(root->right, key);
    }
    else {

        // No child
        if (root->left == nullptr &&
            root->right == nullptr) {

            delete root;
            return nullptr;
        }

        // Only right child
        if (root->left == nullptr) {

            Node* temp = root->right;

            delete root;

            return temp;
        }

        // Only left child
        if (root->right == nullptr) {

            Node* temp = root->left;

            delete root;

            return temp;
        }

        // Two children
        Node* temp = findMin(root->right);

        root->data = temp->data;

        root->right =
            deleteNode(root->right, temp->data);
    }

    return root;
}

int main() {

    int n;
    cin >> n;

    Node* root = nullptr;

    // Create BST using input
    for (int i = 0; i < n; i++) {

        int value;
        cin >> value;

        root = insert(root, value);
    }

    // Traversals
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

    // Minimum
    cout << "Minimum: "
         << findMin(root)->data << endl;

    // Maximum
    cout << "Maximum: "
         << findMax(root)->data << endl;

    // Delete
    int del;
    cin >> del;

    root = deleteNode(root, del);

    cout << "After Deletion: ";
    inorder(root);
    cout << endl;

    return 0;
}