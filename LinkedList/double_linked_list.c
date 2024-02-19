#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct ListNode
{
    element data;
    struct ListNode* lead_link;
    struct ListNode* rear_link;
} ListNode;

void init(ListNode* head) {
    head ->lead_link = head;
    head ->rear_link = head;
}

void print_list(ListNode* head) {
    ListNode* p;
    for (p = head ->rear_link; p != head; p = p ->rear_link) {
        printf("<-||%d||->", p ->data);
    }
    printf("\n");
}

void insert_node(ListNode* prev, element value) {
    ListNode* new_node = (ListNode*)malloc(sizeof(ListNode));
    //새로운 노드 데이터, 링크 설정
    new_node ->data = value;
    new_node ->lead_link = prev;
    new_node ->rear_link = prev ->rear_link;

    //이전 노드 설정 변경
    prev ->rear_link ->lead_link = new_node;
    prev ->rear_link = new_node;
}


void delete_node(ListNode* head, ListNode* removed) {
    if (head == removed) return;

    removed->lead_link->rear_link = removed->rear_link;
    removed->rear_link->lead_link = removed->lead_link;

    free(removed); // 메모리 해제
}

int main(void) {
    ListNode* head=(ListNode *)malloc(sizeof(ListNode));
    init(head);
    printf("추가 단계\n");
    for(int i=0;i<5;i++){
       insert_node(head,i);
       print_list(head);
    }
    printf("삭제 단계\n");    
    for(int i=0;i<5;i++){
       print_list(head);
       delete_node(head, head ->rear_link);
    }
    free(head); 
    return 0;
}