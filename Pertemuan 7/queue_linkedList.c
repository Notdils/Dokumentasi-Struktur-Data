#include <iostream>
using namespace std;

struct QueueNode {
    int value;
    QueueNode* nextPtr;
};

class LinkedListQueue {
private:
    QueueNode *frontNode, *rearNode;

public:
    LinkedListQueue() {
        frontNode = rearNode = NULL;
    }

    bool empty() {
        return (frontNode == NULL);
    }

    void enqueue(int val) {
        QueueNode* tempNode = new QueueNode();
        tempNode->value = val;
        tempNode->nextPtr = NULL;

        if (rearNode == NULL) {
            frontNode = rearNode = tempNode;
        } else {
            rearNode->nextPtr = tempNode;
            rearNode = tempNode;
        }
        cout << "Push elemen: " << val << "\n";
    }

    void dequeue() {
        if (empty()) {
            cout << "Antrian sudah kosong.\n";
            return;
        }

        QueueNode* targetDelete = frontNode;
        cout << "Pop elemen: " << targetDelete->value << "\n";

        frontNode = frontNode->nextPtr;

        if (frontNode == NULL) {
            rearNode = NULL;
        }

        delete targetDelete;
    }

    void showElements() {
        if (empty()) {
            cout << "Antrian kosong.\n";
            return;
        }

        QueueNode* tracker = frontNode;
        cout << "Data Antrian: ";
        while (tracker != NULL) {
            cout << tracker->value << " ";
            tracker = tracker->nextPtr;
        }
        cout << "\n";
    }
};

int main() {
    LinkedListQueue listQueue;
    listQueue.enqueue(50);
    listQueue.enqueue(60);
    listQueue.enqueue(70);
    listQueue.showElements();
    listQueue.dequeue();
    listQueue.showElements();
    return 0;
}
