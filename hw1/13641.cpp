#include <iostream>
using namespace std;

struct listNode
{
    int value;
    listNode* next;
    listNode(int x)
    {
        value = x;
        next = NULL;
    }
};

void print(listNode* head)
{
    //TODO
    while(head!=NULL){
        printf("%d ",head->value);
        head = head->next;
    }
    printf("\n");
}

listNode* removeElements(listNode* head, int val) {
    //TODO
    Node* pt = head;
    while(head!=NULL){
        if(head->next->value == val){
            head->next = head->next->next;
        }
        head = head->next;
    }
    return pt;
}

int main() {
    int val;
    cin >> val;

    listNode* head = new listNode(1);
    head->next = new listNode(2);
    head->next->next = new listNode(2);
    head->next->next->next = new listNode(3);
    head->next->next->next->next = new listNode(4);
    head->next->next->next->next->next = new listNode(5);
    head->next->next->next->next->next->next = new listNode(5);
    head->next->next->next->next->next->next->next = new listNode(10);

    print(removeElements(head, val));
    return 0;
}