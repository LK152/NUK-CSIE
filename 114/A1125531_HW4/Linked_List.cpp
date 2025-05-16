#include "Linked_List.h"
#include "Album.h"
#include "iostream"

using namespace std;

template <typename T>
LinkedList<T>::~LinkedList() {
    while (head) {
        Node* tmp = head;
        head = head->next;
        delete tmp;
    }
}

template <typename T>
bool LinkedList<T>::isEmpty() {
    if (head == nullptr) return 1;
    return 0;
}

template <>
void LinkedList<Track>::play() {
    cout << head->data.name << "\n";
}

template <>
void LinkedList<Album>::play() {
    head->data.tracks.play();
}

template <>
void LinkedList<Album>::next() {
    if (!(head->data.tracks.isEmpty())) head->data.tracks.pop();
    if (head->data.tracks.isEmpty()) {
        head = head->next;
        return;
    }
}

template <typename T>
void LinkedList<T>::printList() {
    Node* curr = head;
    while (curr) {
        cout << curr->data.name;
        if (curr->next) cout << " ";
        curr = curr->next;
    }
    cout << "\n";
}

template <typename T>
void LinkedList<T>::pushback(T data) {
    Node* newNode = new Node(data);

    if (!head) head = newNode;
    else {
        Node* curr = head;
        while (curr->next) curr = curr->next;
        curr->next = newNode;
    }
}

template <typename T>
void LinkedList<T>::pushfront(T data) {
    Node* newNode = new Node(data);

    newNode->next = head;
    head = newNode;
}

template <typename T>
void LinkedList<T>::insert(T data, int pos) {
    if (pos <= 0) return;

    if (pos == 1) {
        pushfront(data);
        return;
    }

    Node* prev = head;
    for (int i = 0;i<pos-2;i++) {
        if (prev->next == nullptr) break;
        prev = prev->next;
    }
    if (prev == nullptr) return;
    Node* newNode = new Node(data);
    newNode->next = prev->next;
    prev->next = newNode;
}

template <typename T>
void LinkedList<T>::pop() {
    Node* toDel = head;
    if (head == nullptr) return;
    head = head->next;
    delete toDel;
}

template <typename T>
void LinkedList<T>::removelast() {
    Node* prev = head;
    if (prev->next == nullptr) {
        prev = nullptr;
        return;
    }
    Node* curr = prev->next;
    while (curr->next) {
        prev = curr;
        curr = curr->next;
    }
    prev->next = nullptr;
    delete curr;
}

template <typename T>
void LinkedList<T>::reverse() {
    Node* prev = nullptr;
    Node* curr = head;
    while (curr) {
        Node* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    head = prev;
}

template <typename T>
void LinkedList<T>::removeat(int pos) {
    if (pos <= 0) return;

    if (pos == 1) {
        pop();
        return;
    }

    Node* prev = head;
    if (prev == nullptr) return;
    for (int i = 0;i<pos-2;i++) prev = prev->next;
    Node* toDel = prev->next;
    prev->next = toDel->next;
    delete toDel;
}

template <>
void LinkedList<Album>::find(string name, string type, int pos, string trackName, int count) {
    Node* curr = head;
    while (curr->data.name != name) curr = curr->next;
    if (type == "TrackPB") {
        curr->data.tracks.pushback({trackName, count});
    }

    if (type == "TrackPF") {
        curr->data.tracks.pushfront({trackName, count});
    }

    if (type == "TrackIns") {
        curr->data.tracks.insert({trackName, count}, pos);
    }

    if (type == "print") {
        curr->data.tracks.printList();
    }
    
    if (type == "rev") {
        curr->data.tracks.reverse();
    }

    if (type == "pt") {
        curr->data.tracks.pop();
    }

    if (type == "rlt") {
        curr->data.tracks.removelast();
    }

    if (type == "rat") {
        curr->data.tracks.removeat(pos);
    }
}

template <typename T>
void LinkedList<T>::mergeSort(bool (*cmp)(T, T)) {
    head = mergeSortRec(head, cmp);
}

template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::mergeSortRec(Node* node, bool (*cmp)(T, T)) {
    if (!node || !node->next)
        return node;

    Node* mid = getMiddle(node);
    Node* right = mid->next;
    mid->next = nullptr;

    Node* leftSorted = mergeSortRec(node, cmp);
    Node* rightSorted = mergeSortRec(right, cmp);

    return merge(leftSorted, rightSorted, cmp);
}

template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::getMiddle(Node* node) {
    if (!node) return node;

    Node* slow = node;
    Node* fast = node->next;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::merge(Node* a, Node* b, bool (*cmp)(T, T)) {
    if (!a) return b;
    if (!b) return a;

    if (cmp(a->data, b->data)) {
        a->next = merge(a->next, b, cmp);
        return a;
    } else {
        b->next = merge(a, b->next, cmp);
        return b;
    }
}

template <>
string LinkedList<Track>::getTrack() {
    return head->data.name;
}

template <>
string LinkedList<Album>::getTrack() {
    while (head->data.tracks.isEmpty()) head = head->next;
    return head->data.tracks.getTrack();
}

template <>
int LinkedList<Track>::getCnt() {
    return head->data.count;
}

template <>
int LinkedList<Album>::getCnt() {
    return head->data.tracks.getCnt();
}

template <>
void LinkedList<Track>::printAll() {
    Node* curr = head;
    while (curr) {
        cout << curr->data.name << " " << curr->data.count;
        if (curr->next != nullptr) cout << "\n";
        curr = curr->next;
    }
}

template class LinkedList<Track>;
template class LinkedList<Album>;