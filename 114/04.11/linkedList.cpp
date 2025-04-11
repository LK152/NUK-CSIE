#include "iostream"

using namespace std;

class linkedList;

class listNode {
    private:    
        string value;
        listNode* next;
    public:
        listNode():value(0), next(0){};
        listNode(string x):value(x), next(0){};

    friend linkedList;
};

class linkedList {
    private: 
        listNode* first;
    public:
        linkedList():first(NULL){};
        void printList();
        void appendList(string x);
};

void linkedList::printList() {
    if (first == NULL) return;

    listNode* curr = first;
    while (curr != NULL) {
        cout << curr->value << " ";
        curr = curr->next;
    }
}

void linkedList::appendList(string value) {
    listNode* newNode = new listNode(value);

    if (first == NULL) {
        first = newNode;
        return;
    }

    listNode* curr = first;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = newNode;
}

int main() {
    linkedList list;

    list.appendList("a");
    list.appendList("b");
    list.appendList("c");
    list.appendList("d");
    list.appendList("e");

    list.printList();

    return 0;
}