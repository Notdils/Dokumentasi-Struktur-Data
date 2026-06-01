#include <iostream>
using namespace std;

// Struktur data pemain
struct PlayerNode {
    int point;
    PlayerNode* leftBranch;
    PlayerNode* rightBranch;
};

// Fabrikasi data poin baru
PlayerNode* generateNode(int pt) {
    PlayerNode* node = new PlayerNode();
    node->point = pt;
    node->leftBranch = NULL;
    node->rightBranch = NULL;
    return node;
}

// Penambahan rekam jejak poin
PlayerNode* addScore(PlayerNode* root, int pt) {
    if (root == NULL) {
        return generateNode(pt);
    }
    
    if (pt < root->point) {
        root->leftBranch = addScore(root->leftBranch, pt);
    } else if (pt > root->point) {
        root->rightBranch = addScore(root->rightBranch, pt);
    }
    
    return root;
}

// Traversal terbalik (kanan - akar - kiri)
void showRanking(PlayerNode* root) {
    if (root != NULL) {
        showRanking(root->rightBranch);
        cout << root->point << endl;
        showRanking(root->leftBranch);
    }
}

// Pengecekan riwayat skor
bool checkScore(PlayerNode* root, int pt) {
    if (root == NULL) return false;
    if (root->point == pt) return true;
        
    if (pt < root->point) {
        return checkScore(root->leftBranch, pt);
    } else {
        return checkScore(root->rightBranch, pt);
    }
}

int main() {
    PlayerNode* root = NULL;
    
    root = addScore(root, 500); 
    addScore(root, 300);
    addScore(root, 700);
    addScore(root, 200);
    addScore(root, 400);
    addScore(root, 600);
    addScore(root, 800);
    
    cout << "Klasemen Peringkat Pemain:" << endl;
    showRanking(root);
    
    cout << "-----------------------" << endl;
    
    int searchTarget = 600;
    if (checkScore(root, searchTarget)) {
        cout << "Poin " << searchTarget << " tercatat dalam sistem" << endl;
    } else {
        cout << "Poin " << searchTarget << " tidak terdaftar" << endl;
    }
    
    return 0;
}
