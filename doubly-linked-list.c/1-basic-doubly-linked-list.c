#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* createNode(int value){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = value;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

// Append Function
struct Node* append(struct Node* head, int value){
    struct Node* newNode = createNode(value);
    if(head == NULL){
        head = newNode;
        return head;
    }
    struct Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

void forwardTraversal(struct Node* head){
    struct Node* temp = head;

    // Handle empty list
    if (temp == NULL) {
        return;
    }

    //Traverse from head to tail
    while (temp != NULL){
        printf("%d", temp->data);
        if (temp->next != NULL){
            printf("->");
        }
        temp = temp->next;
    }
    printf("\n");
}

void backwardTraversal(struct Node* head) {
    struct Node* temp = head;

    // Handle empty list
    if (temp == NULL) {
        return;
    }

    // Move temp to the last node (tail)
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Traverse backward from tail to head
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->prev != NULL) {
            printf("<-");
        }
        temp = temp->prev;
    }
    printf("\n");
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main(){
    int num, value;

    printf("Please enter number of elements: ");
    scanf("%d", &num);

    struct Node* head = NULL;
    for(int i = 0; i < num; i++){
        printf("Enter the element at %d: ", i + 1);
        scanf("%d", &value);
        head = append(head, value);
    }
    printf("Forward Traversal: ");
    forwardTraversal(head);

    printf("Reverse Traversal: ");
    backwardTraversal(head);

    freeList(head);
    return 0;
}