#include <stdio.h>
#include <stdlib.h>
//singly_linked_list 장점(배열에 비해)
//매번 배열 길이를 재할당하지 않아도 된다
//선언 전에 배열 길이를 알 필요가 없다.(필요하면 뒤에 더 붙일 수 있는 방식)
//배열에 비해 중간에 데이터 끼워넣고 빼기가 편하다(배열은 중간에 뭐 넣을라면 다 뒤로 한칸씩 옮겨야 함)
//단, 물리적으로 옆에 저장되는게 아닌 논리적으로 연결된 것이기 때문에 어떤 중간 자료에 바로 접근할 수는 없다. 처음부터 다 훑어야 한다.

typedef int element;

typedef struct ListNode
{
    element data;
    struct ListNode* link;
} ListNode;

ListNode* insert_first(ListNode* head, element value) {
    ListNode* p = (ListNode*)malloc(sizeof(ListNode));
    p ->data = value;
    p ->link = head;
    head = p;
    return head;
}

ListNode* insert(ListNode* head, ListNode* pre, element value) {
    ListNode* p = (ListNode*)malloc(sizeof(ListNode));
    p ->data = value;
    p ->link = pre ->link;
    pre ->link = p;
    return head;
}

ListNode* delete_first(ListNode* head) {
    ListNode* removed;
    if(head == NULL) return NULL;
    removed = head;
    head = removed ->link;
    free(removed);
    return head;
}

ListNode* delete(ListNode* head, ListNode* pre) {
    ListNode* removed;
    removed = pre ->link;
    pre ->link = removed ->link;
    free(removed);
    return head;
}

void print_list(ListNode* head) {
    for(ListNode* p = head; p != NULL; p = p ->link) {
        printf("%d->", p ->data);
    }
    printf("NULL\n");
}

int main(void) {
    ListNode* head = NULL;

    for(int i=0;i<5;i++){
        head=insert_first(head,i);
        print_list(head);
    }
    
    for(int i=0;i<5;i++){
        head=delete_first(head);
        print_list(head);
    }
    return 0;
}