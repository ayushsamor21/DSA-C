#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* createNode(int value){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = value;
    node->next = NULL;
    return node;
}

struct Node* append(struct Node* head, int value) {
    struct Node* newNode = createNode(value);
    if (head == NULL) {
        return newNode;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

void printLinkedList(struct Node* head){
    while (head != NULL){
        printf("%d", head->data);
        if(head->next != NULL){
            printf("->");
        }
        head = head->next;
    }
}

void freeList(struct Node* head){
    struct Node* temp;
    while (head != NULL){
        temp = head;
        head = head->next;
        free(temp);
    }
}

void insertAfterIndex(struct Node* head){
    int targetIndex, newValue, index = 0;
    printf("Please enter the target index: ");
    scanf("%d", &targetIndex);

    printf("Please enter the new value: ");
    scanf("%d", &newValue);

    struct Node* temp = head;

    struct Node* newNode = createNode(newValue);
    if(head == NULL){
        printf("Error in the operation!!");
        return head;
    }

    while (temp != NULL){
        if (index == targetIndex){
            newNode->next = temp->next;
            temp->next = newNode;
            return;
        }
        index++;
        temp = temp->next;
    }
    printf("The target index %d does not exist.\n", targetIndex);

}

int main(){
    int times, num;

    printf("Please enter the number of elements : ");
    scanf("%d", &times);

    struct Node* head = NULL;
    for(int i = 0; i < times; i++){
        printf("Please enter the elements : ");
        scanf("%d", &num);
        head = append(head, num);
    }

    printf("Original Linked List: ");
    printLinkedList(head);
    printf("\n");

    insertAfterIndex(head);

    printf("Linked List after insertion: ");
    printLinkedList(head);
    printf("\n");
    
    freeList(head);
}
