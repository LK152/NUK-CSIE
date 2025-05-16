#include "iostream"
#include "vector"
#include "algorithm"
#include "random"
#include "chrono"

using namespace std;
using namespace std::chrono;

template <typename T>
class LinkedList {
    struct Node {
        T data;
        Node* next;
        Node(T d) : data(d), next(nullptr) {}
    };
    Node* head = nullptr;

    Node* getMiddle(Node* node) {
        if (!node) return node;
        Node* slow = node;
        Node* fast = node->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    Node* merge(Node* a, Node* b) {
        if (!a) return b;
        if (!b) return a;
        if (a->data < b->data) {
            a->next = merge(a->next, b);
            return a;
        } else {
            b->next = merge(a, b->next);
            return b;
        }
    }

    Node* mergeSortRec(Node* node) {
        if (!node || !node->next) return node;
        Node* mid = getMiddle(node);
        Node* right = mid->next;
        mid->next = nullptr;
        return merge(mergeSortRec(node), mergeSortRec(right));
    }

public:
    void push_back(T val) {
        Node* newNode = new Node(val);
        if (!head) head = newNode;
        else {
            Node* cur = head;
            while (cur->next) cur = cur->next;
            cur->next = newNode;
        }
    }

    void mergeSort() {
        head = mergeSortRec(head);
    }

    void print() {
        Node* cur = head;
        while (cur) {
            cout << cur->data << " ";
            cur = cur->next;
        }
        cout << endl;
    }
};

bool isSorted(const vector<int>& v) {
    for (size_t i = 1; i < v.size(); ++i)
        if (v[i - 1] > v[i]) return false;
    return true;
}

void bogoSort(vector<int>& v) {
    random_device rd;
    mt19937 g(rd());
    while (!isSorted(v)) {
        shuffle(v.begin(), v.end(), g);
    }
}

int main() {
    const int SIZE = 10;
    vector<int> data;
    for (int i = SIZE; i > 0; --i)
        data.push_back(i);

    LinkedList<int> list;
    for (int x : data) list.push_back(x);

    auto start1 = high_resolution_clock::now();
    list.mergeSort();
    auto end1 = high_resolution_clock::now();
    auto duration1 = duration_cast<milliseconds>(end1 - start1);
    cout << "Linked List Merge Sort Time: " << duration1.count() << " ms\n";

    // Bogo Sort
    vector<int> data2 = data;
    auto start2 = high_resolution_clock::now();
    bogoSort(data2);
    auto end2 = high_resolution_clock::now();
    auto duration2 = duration_cast<milliseconds>(end2 - start2);
    cout << "Bogo Sort Time: " << duration2.count() << " ms\n";

    return 0;
}
