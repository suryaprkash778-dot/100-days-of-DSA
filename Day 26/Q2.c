// Definition for singly-linked list node
struct Node {
    int val;
    struct Node* next;
};

typedef struct {
    struct Node* head;
    int size;
} MyLinkedList;

// Initialize the linked list
MyLinkedList* myLinkedListCreate() {
    MyLinkedList* obj = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    obj->head = NULL;
    obj->size = 0;
    return obj;
}

// Get the value of the index-th node
int myLinkedListGet(MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->size) return -1;
    struct Node* curr = obj->head;
    for (int i = 0; i < index; i++) {
        curr = curr->next;
    }
    return curr->val;
}

// Add a node at the head
void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->val = val;
    newNode->next = obj->head;
    obj->head = newNode;
    obj->size++;
}

// Add a node at the tail
void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->val = val;
    newNode->next = NULL;
    if (obj->head == NULL) {
        obj->head = newNode;
    } else {
        struct Node* curr = obj->head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = newNode;
    }
    obj->size++;
}

// Add a node before the index-th node
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if (index < 0 || index > obj->size) return;
    if (index == 0) {
        myLinkedListAddAtHead(obj, val);
        return;
    }
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->val = val;
    struct Node* curr = obj->head;
    for (int i = 0; i < index - 1; i++) {
        curr = curr->next;
    }
    newNode->next = curr->next;
    curr->next = newNode;
    obj->size++;
}

// Delete the index-th node
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->size) return;
    struct Node* temp;
    if (index == 0) {
        temp = obj->head;
        obj->head = obj->head->next;
        free(temp);
    } else {
        struct Node* curr = obj->head;
        for (int i = 0; i < index - 1; i++) {
            curr = curr->next;
        }
        temp = curr->next;
        curr->next = temp->next;
        free(temp);
    }
    obj->size--;
}

// Free the linked list
void myLinkedListFree(MyLinkedList* obj) {
    struct Node* curr = obj->head;
    while (curr != NULL) {
        struct Node* temp = curr;
        curr = curr->next;
        free(temp);
    }
    free(obj);
}

