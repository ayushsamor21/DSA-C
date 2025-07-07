#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int value){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = value;
    node->next = NULL;
    return node;
}

struct Node* append(struct Node* head, int value){
    struct Node* newNode = createNode(value);
    if (head == NULL){                        
        head = newNode;
        return head;
    }
    struct Node* temp;                       
    temp = head;
    while (temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode; 
    return head;
}

void printLinkedList(struct Node* head){
    struct Node* temp = head;
    while (temp != NULL){
        printf("%d", temp->data);
        if (temp->next != NULL){
            printf("->");
        }
        temp = temp->next;
    }
    printf("\n");
}

void elementOccurrence(struct Node* head){
    if(head == NULL){
        return;
    }
    
    int count = 0, keyValue;
    printf("Please enter the value: ");
    scanf("%d", &keyValue);

    struct Node* temp = head;
    while (temp != NULL){
        if (keyValue == temp->data){
            count++;
        }
        temp = temp->next;
    }
    printf("The occurrence of value: %d\n", count);
}

void freeList(struct Node* head){
    struct Node* temp;
    while (head != NULL){
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main(){
    int num, value;

    printf("Please enter the number of elements : ");
    scanf("%d", &num);

    struct Node* head = NULL;
    for(int i = 0; i < num; i++){
        printf("Enter element %d: ", i + 1);
        scanf("%d", &value);
        head = append(head, value);
    }
    printf("Original Linked list: ");
    printLinkedList(head);
    printf("\n");

    elementOccurrence(head);
    freeList(head);
}
