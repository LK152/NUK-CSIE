#include "iostream"
#include "cmath"

using namespace std;

template <class T>
class Stack {
    private:
        int top = 0;
        T list[1000];

    public:
        T getTop() {
            return list[top];
        }

        int isEmpty() {
            if (list[top]>0) return 0;

            return 1;
        }

        void reverseStack() {
            int temp[top+1], idx = 0;
            for (int i = 0;i<=top;i++) {
                temp[idx++] = list[i];
                list[i] = 0;
            }
            idx = 0;
            for (int i = top;i>=0;i--) {
                list[i] = temp[idx++];
            }
        }

        void pushStack(T e) {
            if (isEmpty()) {
                list[top] = e;
                
                return;
            }
            list[++top] = e;
        }

        int popStack() {
            if (isEmpty()) return 0;

            int v = list[top];
            list[top--] = 0;
            if (top < 0) top = 0;

            return v;
        }

        void printStack() {
            for (int i = top; i>=0; i--) {
                cout << list[i];
            }
            cout << "\n";
        }
};

template <class T>
class Queue {
    private:
        int front = 0, rear = 0;
        T list[1000];

    public:
        int isEmpty() {
            if (rear == front) return 1;

            return 0;
        }

        int getLength() {
            return rear - front;
        }

        void pushQueue(T e) {
            list[rear++] = e;
        }

        int popQueue() {
            if (isEmpty()) return 0;

            int v = list[rear-1];
            list[rear--] = 0;

            return v;
        }

        void printQueue() {
            for (int i = front;i<rear;i++) {
                cout << list[i];
            }
            cout << "\n";
        }
};

int main() {
    Stack<int> s1, s2;
    Queue<int> q;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (s1.isEmpty() || x < s1.getTop()) {
            s1.pushStack(x);
            s1.printStack();
            if (!s2.isEmpty()) s2.printStack();
        }
        else if (s2.isEmpty() || x > s2.getTop()) {
            s2.pushStack(x);
            if (!s1.isEmpty()) s1.printStack();
            s2.printStack();
        }
        else {
            if (abs(x-s1.getTop()) < abs(x-s2.getTop())) {
                while (x > s1.getTop() && !s1.isEmpty()) {
                    q.pushQueue(s1.popStack());
                }
                q.printQueue();
                s1.pushStack(x);
                s1.printStack();
                if (!s2.isEmpty()) s2.printStack();
                while (!q.isEmpty()) {
                    s1.pushStack(q.popQueue());
                }
            } else {
                while (x < s2.getTop() && !s2.isEmpty()) {
                    q.pushQueue(s2.popStack());
                }
                q.printQueue();
                s2.pushStack(x);
                if (!s1.isEmpty()) s1.printStack();
                s2.printStack();
                while (!q.isEmpty()) {
                    s2.pushStack(q.popQueue());
                }
            }
        }
    }
    s2.reverseStack();
    while (!(s1.isEmpty() && s2.isEmpty())) {
        if ((s1.getTop() < s2.getTop()) || s2.isEmpty()) q.pushQueue(s1.popStack());
        else q.pushQueue(s2.popStack());
        q.printQueue();
        if (!s1.isEmpty()) s1.printStack();
        if (!s2.isEmpty()) s2.printStack();
    }

    return 0;
}