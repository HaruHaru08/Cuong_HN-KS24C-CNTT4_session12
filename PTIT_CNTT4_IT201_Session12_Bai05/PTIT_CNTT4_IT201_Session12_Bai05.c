#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
}Node;
Node* createNode(int data) {
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->data=data;
    newNode->next=NULL;
    newNode->prev=NULL;
    return newNode;
}
void printList(Node* head) {
    while(head!=NULL) {
        if (head->next==NULL) {
            printf("%d -> ",head->data);
            break;
        }
        printf("%d <-> ",head->data);
        head=head->next;
    }
    printf("NULL");
}
Node* deleteAt(Node* head,int num) {
    if (head==NULL) {
        return NULL;
    }
    if (head->next==NULL && head->data==num) {
        free(head);
        return NULL;
    }
    if (head->data==num) {
        Node* temp=head;
        head=head->next;
        head->prev=NULL;
        free(temp);
    }
    Node* current=head;
    while (current->next!=NULL) {
        if (current->next->data==num) {
            Node* temp=current->next;
            Node* next=current->next->next;
            current->next=next;
            if (next !=NULL) next->prev=current;
            free(temp);
        }else {
            current=current->next;
        }
    }
    return head;
}
int main() {
    Node* head = createNode(5);
    Node* Node1 = createNode(4);
    Node* Node2 = createNode(3);
    Node* Node3 = createNode(5);
    Node* Node4 = createNode(2);
    Node* Node5 = createNode(1);
    Node* Node6 = createNode(5);
    head->next=Node1;
    Node1->prev=head;
    Node1->next=Node2;
    Node2->prev=Node1;
    Node2->next=Node3;
    Node3->prev=Node2;
    Node3->next=Node4;
    Node4->prev=Node3;
    Node4->next=Node5;
    Node5->prev=Node4;
    Node5->next=Node6;
    Node6->prev=Node5;
    head=deleteAt(head,5);
    printList(head);
    return 0;
}