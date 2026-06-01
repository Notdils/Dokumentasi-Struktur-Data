#include <bits/stdc++.h>
using namespace std;

struct BstNode {
    int nodeValue;
    BstNode* leftChild;
    BstNode* rightChild;
};

BstNode* initNode(int val) {
    BstNode* node = new BstNode();
    node->nodeValue = val;
    node->leftChild = NULL;
    node->rightChild = NULL;

    return node;
}

BstNode* insertData(BstNode* root, int val) {
    if (root == NULL) {
        return initNode(val);
    }

    if (val < root->nodeValue) {
        root->leftChild = insertData(root->leftChild, val);
    }
    else if (val > root->nodeValue) {
        root->rightChild = insertData(root->rightChild, val);
    }

    return root;
}

void printInorderAsc(BstNode* root) {
    if (root != NULL) {
        printInorderAsc(root->leftChild);
        cout << root->nodeValue << " ";
        printInorderAsc(root->rightChild);
    }
}

bool searchData(BstNode* root, int targetKey) {
    if (root == NULL)
        return false;

    if (root->nodeValue == targetKey)
        return true;

    if (targetKey < root->nodeValue)
        return searchData(root->leftChild, targetKey);
    else
        return searchData(root->rightChild, targetKey);
}

int main() {
    BstNode* root = NULL;
    root = insertData(root, 50);
    insertData(root, 30);
    insertData(root, 70);
    insertData(root, 20);
    insertData(root, 40);
    insertData(root, 60);
    insertData(root, 80);

    cout << "Hasil Inorder Traversal: ";
    printInorderAsc(root);
    cout << endl;

    int targetKey = 60;
    if (searchData(root, targetKey)) 
        cout << "Informasi ditemukan" << " (" << targetKey << ")" << endl;
    else 
        cout << "Informasi tidak ditemukan" << endl;

    return 0;
}
