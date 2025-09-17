#include<iostream>
using namespace std;

class circularqueue {
    int* arr;
    int currentsize;
    int capacity;
    int r;
    int f;

public:
    circularqueue(int size) {
        capacity = size;
        arr = new int[capacity];
        currentsize = 0;
        f = 0;
        r = -1;
    }

    void push(int data) {
        if (currentsize == capacity) {
            cout << "queue is full" << endl;
            return;
        }
        r = (r + 1) % capacity;
        arr[r] = data;
        currentsize++;
    }

    void pop() {
        if (currentsize == 0) {
            cout << "queue is empty" << endl;
            return;
        }
        f = (f + 1) % capacity;
        currentsize--;
    }

    int front() {
        if (currentsize == 0) {
            cout << "queue is empty" << endl;
            return -1;
        }
        return arr[f];
    }

    bool isempty() {
        return currentsize == 0;
    }

    ~circularqueue() {
        delete[] arr;
    }
};

int main() {
    circularqueue q(5);
    q.push(1);
    q.push(2);
    q.push(3);

    cout << q.front() << endl;  // should print 1
    q.pop();
    cout << q.front() << endl;  // should print 2

    return 0;
}
