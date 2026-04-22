#include <iostream>
using namespace std;

#define CAPACITY 5

class ArrayQueue {
private:
    int elements[CAPACITY];
    int frontIndex, rearIndex;

public:
    ArrayQueue() {
        frontIndex = -1;
        rearIndex = -1;
    }

    bool empty() {
        return (frontIndex == -1);
    }

    bool full() {
        return (rearIndex == CAPACITY - 1);
    }

    void enqueue(int value) {
        if (full()) {
            cout << "[ERROR] Kapasitas Queue Penuh!\n";
            return;
        }
        if (empty()) {
            frontIndex = 0;
        }
        elements[++rearIndex] = value;
        cout << "Ditambahkan: " << value << "\n";
    }

    void dequeue() {
        if (empty()) {
            cout << "[ERROR] Queue Kosong!\n";
            return;
        }
        cout << "Dikeluarkan: " << elements[frontIndex] << "\n";
        if (frontIndex == rearIndex) {
            frontIndex = rearIndex = -1; // Reset queue
        } else {
            frontIndex++;
        }
    }

    void printQueue() {
        if (empty()) {
            cout << "Status: Queue Kosong\n";
            return;
        }
        cout << "Isi Queue (Front -> Rear): ";
        for (int i = frontIndex; i <= rearIndex; i++) {
            cout << elements[i] << " ";
        }
        cout << "\n";
    }
};

int main() {
    ArrayQueue q;
    q.enqueue(11);
    q.enqueue(22);
    q.enqueue(33);
    q.printQueue();
    q.dequeue();
    q.printQueue();
    return 0;
}
