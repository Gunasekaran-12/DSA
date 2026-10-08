// You are using GCC
#include <iostream>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

// Create Binary Tree using Level Order input
Node* create() {

    int value;
    cin >> value;

    if(value == -1)
        return NULL;

    Node* root = new Node(value);

    queue<Node*> q;
    q.push(root);

    while(!q.empty()) {

        Node* node = q.front();
        q.pop();

        // Left child
        cin >> value;

        if(value != -1) {
            node->left = new Node(value);
            q.push(node->left);
        }

        // Right child
        cin >> value;

        if(value != -1) {
            node->right = new Node(value);
            q.push(node->right);
        }
    }

    return root;
}


// Level Order Traversal
void levelOrder(Node* root) {

    if(root == NULL)
        return;

    queue<Node*> q;
    q.push(root);

    while(!q.empty()) {

        Node* node = q.front();
        q.pop();

        cout << node->data << " ";

        if(node->left)
            q.push(node->left);

        if(node->right)
            q.push(node->right);
    }
}


// Search
bool search(Node* root, int key) {

    if(root == NULL)
        return false;

    if(root->data == key)
        return true;

    return search(root->left, key) ||
           search(root->right, key);
}


// Count Total Nodes
int countNodes(Node* root) {

    if(root == NULL)
        return 0;

    return 1 + countNodes(root->left)
             + countNodes(root->right);
}


// Count Leaf Nodes
int countLeafNodes(Node* root) {

    if(root == NULL)
        return 0;

    if(root->left == NULL && root->right == NULL)
        return 1;

    return countLeafNodes(root->left)
         + countLeafNodes(root->right);
}


// Height
int height(Node* root) {

    if(root == NULL)
        return 0;

    return 1 + max(height(root->left),
                   height(root->right));
}


// Minimum Element
int findMin(Node* root) {

    if(root == NULL)
        return INT_MAX;

    int leftMin = findMin(root->left);
    int rightMin = findMin(root->right);

    return min(root->data, min(leftMin, rightMin));
}


// Maximum Element
int findMax(Node* root) {

    if(root == NULL)
        return INT_MIN;

    int leftMax = findMax(root->left);
    int rightMax = findMax(root->right);

    return max(root->data, max(leftMax, rightMax));
}


// Delete a Node from Binary Tree
void deleteNode(Node* root, int key) {

    if(root == NULL)
        return;

    // Find node to delete
    Node* target = NULL;

    queue<Node*> q;
    q.push(root);

    while(!q.empty()) {

        Node* node = q.front();
        q.pop();

        if(node->data == key) {
            target = node;
            break;
        }

        if(node->left)
            q.push(node->left);

        if(node->right)
            q.push(node->right);
    }

    if(target == NULL) {
        cout << "Node Not Found" << endl;
        return;
    }

    // Find deepest node and its parent
    Node* deepest = NULL;
    Node* parent = NULL;

    q.push(root);

    while(!q.empty()) {

        Node* node = q.front();
        q.pop();

        deepest = node;

        if(node->left) {
            parent = node;
            q.push(node->left);
        }

        if(node->right) {
            parent = node;
            q.push(node->right);
        }
    }

    // Replace target value with deepest node value
    target->data = deepest->data;

    // Remove deepest node
    if(deepest == root) {
        delete root;
        return;
    }

    if(parent->right == deepest) {
        parent->right = NULL;
    }
    else {
        parent->left = NULL;
    }

    delete deepest;
}


// Main
int main() {

    Node* root = create();

    // Level Order
    cout << "Level Order: ";
    levelOrder(root);
    cout << endl;


    // Search
    int key;
    cin >> key;

    cout << "Search: ";

    if(search(root, key))
        cout << "Found";
    else
        cout << "Not Found";

    cout << endl;


    // Count Nodes
    cout << "Total Nodes: "
         << countNodes(root) << endl;


    // Count Leaves
    cout << "Leaf Nodes: "
         << countLeafNodes(root) << endl;


    // Height
    cout << "Height: "
         << height(root) << endl;


    // Minimum
    cout << "Minimum: "
         << findMin(root) << endl;


    // Maximum
    cout << "Maximum: "
         << findMax(root) << endl;


    // Delete
    int deleteKey;
    cin >> deleteKey;

    deleteNode(root, deleteKey);

    cout << "After Delete: ";
    levelOrder(root);
    cout << endl;


    return 0;
}

// input :

// 1 2 3 4 5 -1 7 -1 -1 -1 -1 -1 -1
// 5
// 2

// output :

// Level Order: 1 2 3 4 5 7
// Search: Found
// Total Nodes: 6
// Leaf Nodes: 3
// Height: 3
// Minimum: 1
// Maximum: 7
// After Delete: 1 7 3 4 5