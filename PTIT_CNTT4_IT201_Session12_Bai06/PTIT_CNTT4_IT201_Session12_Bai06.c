#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
}Node;
Node* createNode(int date) {
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->data=date;
    newNode->next=NULL;
    return newNode;
}
int length(Node* head) {
    int count=0;
    while (head!=NULL) {
        count++;
        head=head->next;
    }
    return count;
}
void printList(Node* head) {
    while (head!=NULL) {
        printf("%d->",head->data);
        head=head->next;
    }
    printf("NULL\n");
}
void search(Node* head,int lenght) {
    int mid=lenght/2;
    int count=1;
    for (int i=0;i<mid;i++) {
        head=head->next;
        count++;
    }
    printf("Node %d: %d",count,head->data);
}
int main(void) {
    Node* head=createNode(5);
    Node* Node1=createNode(4);
    Node* Node2=createNode(3);
    Node* Node3=createNode(2);
    Node* Node4=createNode(1);
    // Node* Node5=createNode(6);
    head->next=Node1;
    Node1->next=Node2;
    Node2->next=Node3;
    Node3->next=Node4;
    // Node4->next=Node5;
    int lenght=length(head);
    search(head,lenght);
    return 0;
}