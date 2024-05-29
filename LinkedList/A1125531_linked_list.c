#include "stdio.h"
#include "stdlib.h"

typedef struct node {
    int value;
    struct node* next;
} node_t;

void printUI(void) {
    printf("A1125531 Linked List使用介面\n");
    printf("1. 列出全部資料\n");
    printf("2. 新增一筆資料到最後面\n");
    printf("3. 新增一筆資料到指定位置\n");
    printf("4. 刪除最後面的資料\n");
    printf("5. 刪除指定位置的資料\n");
    printf("6. 反轉list\n");
    printf("0. 離開\n");
    printf("\n選擇操作:");
}

void printError(void) {
    printf("請輸入有效數值\n\n");
}

int getLen(node_t* node) {
    int cnt = 0;
    while (node != NULL) {
        node = node->next;
        cnt++;
    }

    return cnt;
}

void printList(node_t* node) {
    printf("list內有:");
    while (node != NULL) {
        printf("%d->", node->value);
        node = node->next;
    }
    printf("NULL");
}

void appendList(node_t** node, int value) {
    node_t* newNode = malloc(sizeof(node_t));
    newNode->value = value;
    newNode->next = NULL;
    if (*node == NULL) *node = newNode;
    else {
        node_t* curr;
        curr = *node;
        while (curr->next != NULL) curr = curr->next;
        curr->next = newNode;
    }
}

void insertList(node_t** node, int value, int position) {
    int idx = 1;
    node_t* newNode = malloc(sizeof(node_t));
    node_t* curr;
    node_t* prev;
    curr = *node;

    newNode->value = value;
    newNode->next = NULL;

    while (idx != position) {
        if (curr->next == NULL) {
            idx = -1;
            break;
        }
        prev = curr;
        curr = curr->next;
        idx++;
    }

    switch (idx) {
        case 1:
            newNode->next = curr;
            *node = newNode;
            break;

        case -1:
            curr->next = newNode;
            break;
        
        default:
            prev->next = newNode;
            newNode->next = curr;
            break;
    }
}

void removeListItem(node_t** node, int position) {
    int idx = 1;
    node_t* curr;
    node_t* prev;
    curr = *node;

    while (idx != position) {
        if (curr->next == NULL) {
            idx = -1;
            break;
        }
        prev = curr;
        curr = curr->next;
        idx++;
    }

    switch (idx) {
        case 1:
            *node = (*node)->next;
            break;

        case -1:
            prev->next = NULL;
            break;
        
        default:
            prev->next = curr->next;
            break;
    }
    free(curr);
}

void popList(node_t** node) {
    if ((*node)->next == NULL) {
        free(*node);
        *node = NULL;
    } else {
        node_t* curr;
        node_t* prev;

        curr = *node;
        while (curr->next != NULL) {
            prev = curr;
            curr = curr->next;
        }
        prev->next = NULL;
        free(curr);
    }
}

void reverseList(node_t** node) {
    node_t* prev = NULL;
    node_t* curr;
    node_t* next;

    curr = *node;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *node = prev;
}

void freeList(node_t* node) {
    node_t* curr;
    node_t* prev;
    curr = node;
    while (curr != NULL) {
        prev = curr;
        curr = curr->next;
        free(prev);
    }
}

int main() {
    int x, n, p;
    node_t* linkedList = NULL;
    while (1) {
        printUI();
        scanf("%d", &x);
        if (!x) break;

        switch (x) {
            case 1:
                if (linkedList == NULL) printf("list內現在為空!!!");
                else printList(linkedList);
                printf("\n\n");
                break;

            case 2:
                printf("請輸入要新增的資料\n");
                scanf("%d", &n);
                printf("\n");
                appendList(&linkedList, n);
                break;

            case 3:
                printf("請輸入要插入的位置:\n");
                scanf("%d", &p);
                if ((p > getLen(linkedList) || p < 0) && p != 1) {
                    printError();
                    break;
                }
                printf("請輸入要新增的資料\n");
                scanf("%d", &n);
                insertList(&linkedList, n, p);
                printf("\n");
                break;

            case 4:
                popList(&linkedList);
                printf("\n");
                break;

            case 5:
                printf("請輸入要刪除的位置:\n");
                scanf("%d", &p);
                if (p > getLen(linkedList) || p < 0) {
                    printError();
                    break;
                }
                removeListItem(&linkedList, p);
                printf("\n");
                break;

            case 6:
                reverseList(&linkedList);
                printf("\n");
                break;
        }
    }
    freeList(linkedList);

    return 0;
}