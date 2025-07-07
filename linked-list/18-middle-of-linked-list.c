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

void middleTerm(struct Node* head, int num){
    int position = num / 2;
    int count = 0;
    struct Node* temp = head;
    while(temp != NULL){
        if(position == count){
            printf("the middle node : %d\n", temp->data);
        }
        temp = temp->next;
        count++;
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

    middleTerm(head, value);
    freeList(head);
}
