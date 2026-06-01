#include <iostream>
using namespace std;

// Struktur penyusun tree
struct TreeNode {
    int value;
    TreeNode* leftNode;
    TreeNode* rightNode;
};

// Instansiasi node baru
TreeNode* makeNode(int val) {
    TreeNode* node = new TreeNode();
    node->value = val;
    node->leftNode = NULL;
    node->rightNode = NULL;
    return node;
}

// Logika penyisipan data
TreeNode* insertNode(TreeNode* root, int val) {
    if (root == NULL) {
        return makeNode(val);
    }
    if (val < root->value) {
        root->leftNode = insertNode(root->leftNode, val);
    } else if (val > root->value) {
        root->rightNode = insertNode(root->rightNode, val);
    }
    return root;
}

// Traversal berurutan (kiri - akar - kanan)
void printInorder(TreeNode* root) {
    if (root != NULL) {
        printInorder(root->leftNode);
        cout << root->value << " ";
        printInorder(root->rightNode);
    }
}

// Validasi keberadaan data
bool findValue(TreeNode* root, int target) {
    if (root == NULL) return false;
    if (root->value == target) return true;
    
    if (target < root->value) {
        return findValue(root->leftNode, target);
    } else {
        return findValue(root->rightNode, target);
    }
}

int main() {
    TreeNode* root = NULL;
    
    // Membangun struktur BST
    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 70);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 60);
    insertNode(root, 80);
    
    cout << "Hasil Print Inorder: ";
    printInorder(root);
    cout << endl;
    
    int target = 60;
    if (findValue(root, target)) {
        cout << target << " ada di dalam BST" << endl;
    } else {
        cout << target << " tidak ditemukan" << endl;
    }
    
    return 0;
}
