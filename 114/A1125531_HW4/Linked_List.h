#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "string"

using namespace std;

template <typename T>
class LinkedList {
    private:
        struct Node {
            T data;
            Node* next;
            Node(T data): data(data), next(nullptr) {};
        };
        Node* head;

    public:
        LinkedList(): head(nullptr) {}
        ~LinkedList();

        bool isEmpty();
        void play();
        string getTrack();
        int getCnt();
        void printAll();
        void next();
        void printList();
        void pushback(T data);
        void pushfront(T data);
        void insert(T data, int pos);
        void pop();
        void removelast();
        void reverse();
        void removeat(int pos);
        void find(string name, string type, int pos, string trackName, int count);

        void mergeSort(bool (*cmp)(T, T));
        typename LinkedList<T>::Node * mergeSortRec(Node * node, bool(* cmp)(T,T));
        typename LinkedList<T>::Node * getMiddle(Node * node);
        typename LinkedList<T>::Node * merge(Node * a, Node * b, bool(* cmp)(T,T));
    };

#endif