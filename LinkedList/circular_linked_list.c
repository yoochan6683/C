#include <stdio.h>
#include <stdlib.h>
//제일 마지막 노드가 head임
//원형이기 때문에 시작과 끝이 애매모호함
//따라서 insert_first() : head(마지막 노드) -> 새로운 노드 -> 첫 노드
//새로운 노드가 첫 노드가 되는 것

//insert_last() : head(마지막 노드) -> 새로운 노드(새로운 head로 변경) -> 첫 노드
//insert_first()와 같은 로직으로 head와 첫 노드 사이에 끼워넣는다는 개념. 차이점은 새로운 노드를 새로운 head로 만들어준다는 것(새로운 마지막 노드로 임명).

typedef int element;
typedef struct ListNode
{
    element data;
    struct ListNode* link;
} ListNode;

ListNode* insert_first(ListNode* head, element value) {
    ListNode* p = (ListNode*)malloc(sizeof(ListNode));
    p ->data = value;
    if(head == NULL) {
        head = p;
        p ->link = head;
    } else {
        p ->link = head ->link;
        head ->link = p;
    }
    return head;
}

ListNode* insert_last(ListNode* head, element value) {
    ListNode* p = (ListNode*)malloc(sizeof(ListNode));
    p ->data = value;
    if(head == NULL) {
        head = p;
        p ->link = head;
    } else {
        p ->link = head ->link;
        head ->link = p;
        head = p;
    }
    return head;
}

void print_list(ListNode* head)
{

    ListNode*p;

    if(head==NULL) return;
    p=head->link;
    do{
      printf("%d->",p->data);
      p=p->link;
    } while (p!=head);
    
    printf("%d",p->data);
    
}

int main(void) {
    ListNode* head = NULL;

    head=insert_last(head,20);
    head=insert_last(head,30);
    head=insert_last(head,40);
    head=insert_first(head,10);

    //출력: 10->20->30->40
    print_list(head);
    return 0;
}