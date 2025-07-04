#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

bool searchElement(struct Node* head, int target){
    struct Node* temp;
    temp = head;
    while (temp != NULL){
        if(temp->data == target){
            return true;
        }
        temp = temp->next;
    }
    return false;
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
    int times, num, target;

    printf("Please enter the number of elements : ");
    scanf("%d", &times);

    struct Node* head = NULL;
    for(int i = 0; i < times; i++){
        printf("Please enter the elements %d: ", i + 1);
        scanf("%d", &num);
        head = append(head, num);
    }

    printf("Please enter the element you want to search : ");
    scanf("%d", &target);

    bool isPresent = searchElement(head, target);
    if(isPresent){
        printf("The element %d is present in Linked List.\n", target);
    } else {
        printf("The element %d is not present in Linked List.\n", target);
    }
    freeList(head);
}
