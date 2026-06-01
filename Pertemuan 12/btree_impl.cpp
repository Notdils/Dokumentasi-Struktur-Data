#include <bits/stdc++.h>
using namespace std;

class BTreeNode {
    int *nodeKeys, minDegree, keyCount;
    bool isLeaf;
    BTreeNode **children;
public:
    BTreeNode(int degree, bool leafStatus);

    void addNonFull(int val);
    void splitNode(int index, BTreeNode *childNode);
    void printTree();

    BTreeNode *findKey(int val);

    friend class BTreeIndex;
};

class BTreeIndex {
    BTreeNode *rootNode;
    int minDegree;
public:
    BTreeIndex(int degree) {
        rootNode = NULL;
        minDegree = degree;
    }

    void printTree() {
        if (rootNode != NULL)
            rootNode->printTree();
    }

    BTreeNode *findKey(int val) {
        return (rootNode == NULL) ? NULL : rootNode->findKey(val);
    }

    void insertData(int val);
};

BTreeNode::BTreeNode(int degree, bool leafStatus) {
    minDegree = degree;
    isLeaf = leafStatus;

    nodeKeys = new int[2 * minDegree - 1];
    children = new BTreeNode *[2 * minDegree];

    keyCount = 0;
}

void BTreeNode::printTree() {
    int i;
    for(i = 0; i < keyCount; i++) {
        if (!isLeaf) children[i]->printTree();
        cout << " " << nodeKeys[i];
    }

    if(!isLeaf) children[i]->printTree();
}

BTreeNode *BTreeNode::findKey(int val) {
    int i = 0;
    while (i < keyCount && val > nodeKeys[i]) i++;

    if(nodeKeys[i] == val)
        return this;

    if (isLeaf)
        return NULL;

    return children[i]->findKey(val);
}

void BTreeIndex::insertData(int val) {
    if (rootNode == NULL) {
        rootNode = new BTreeNode(minDegree, true);
        rootNode->nodeKeys[0] = val;
        rootNode->keyCount = 1;
    }
    else {
        if (rootNode->keyCount == 2 * minDegree - 1) {
            BTreeNode *newRoot = new BTreeNode(minDegree, false);

            newRoot->children[0] = rootNode;
            newRoot->splitNode(0, rootNode);

            int i = 0;
            if (newRoot->nodeKeys[0] < val) i++;

            newRoot->children[i]->addNonFull(val);
            rootNode = newRoot;
        }
        else rootNode->addNonFull(val);
  }
}

void BTreeNode::addNonFull(int val) {
    int i = keyCount - 1;

    if (isLeaf) {
        while (i >= 0 && nodeKeys[i] > val) {
            nodeKeys[i + 1] = nodeKeys[i];
            i--;
        }

        nodeKeys[i + 1] = val;
        keyCount = keyCount + 1;
    }
    else {
        while (i >= 0 && nodeKeys[i] > val) i--;

        if (children[i + 1]->keyCount == 2 * minDegree - 1) {
            splitNode(i + 1, children[i + 1]);

            if (nodeKeys[i + 1] < val) i++;
        }

        children[i + 1]->addNonFull(val);
    }
}

void BTreeNode::splitNode(int index, BTreeNode *childNode) {
    BTreeNode *newNode = new BTreeNode(childNode->minDegree, childNode->isLeaf);
    newNode->keyCount = minDegree - 1;

    for (int j = 0; j < minDegree - 1; j++) 
        newNode->nodeKeys[j] = childNode->nodeKeys[j + minDegree];

    if (!childNode->isLeaf) {
        for (int j = 0; j < minDegree; j++) 
            newNode->children[j] = childNode->children[j + minDegree];
    }

    childNode->keyCount = minDegree - 1;
    for (int j = keyCount; j >= index + 1; j--) 
        children[j + 1] = children[j];

    children[index + 1] = newNode;

    for (int j = keyCount - 1; j >= index; j--) 
        nodeKeys[j + 1] = nodeKeys[j];

    nodeKeys[index] = childNode->nodeKeys[minDegree - 1];
    keyCount = keyCount + 1;
}

int main() {
    BTreeIndex tree(3);
    tree.insertData(8);
    tree.insertData(9);
    tree.insertData(10);
    tree.insertData(11);
    tree.insertData(15);
    tree.insertData(16);
    tree.insertData(17);
    tree.insertData(18);
    tree.insertData(20);
    tree.insertData(23);

    cout << "Representasi B-tree: ";
    tree.printTree();

    int target = 10;
    if (tree.findKey(target) != NULL) cout << endl << target << " ditemukan";
    else cout << endl << target << " tidak ditemukan";

    target = 2;
    if (tree.findKey(target) != NULL) cout << endl << target << " ditemukan";
    else cout << endl << target << " tidak ditemukan\n";

    return 0;
}
