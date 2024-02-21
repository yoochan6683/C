#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 100

//트리 노드, 큐 정의
typedef struct TreeNode
{
    int data;
    struct TreeNode *left, *right;
} TreeNode;

typedef TreeNode *element;

typedef struct
{
    element data[MAX_QUEUE_SIZE];
    int front, rear;
} LevelQueue;

//트리 생성
//     1    
//  2     3
// 4  5  6  7
TreeNode n7 = {7, NULL, NULL};
TreeNode n6 = {6, NULL, NULL};
TreeNode n5 = {5, NULL, NULL};
TreeNode n4 = {4, NULL, NULL};
TreeNode n3 = {3, &n6, &n7};
TreeNode n2 = {2, &n4, &n5};
TreeNode n1 = {1, &n2, &n3};

//함수 정의
void queue_level_order(TreeNode* root);
void init_queue(LevelQueue* p_lq);
int is_full(LevelQueue* p_lq);
int is_empty(LevelQueue* p_lq);
void enqueue(LevelQueue* p_lq, TreeNode* element);
TreeNode* dequeue(LevelQueue* p_lq);
void error(char* message);

//implement
void queue_level_order(TreeNode* root) {
    LevelQueue lq;
    init_queue(&lq);

    if(root == NULL) return;

    enqueue(&lq, root);
    while (!is_empty(&lq))
    {
        root = dequeue(&lq);
        printf("%d\n", root ->data);
        if(root ->left) enqueue(&lq, root ->left);
        if(root ->right) enqueue(&lq, root ->right);
    }
}

void error(char* message) {
    printf("%s", message);
    exit(1);
}

void init_queue(LevelQueue* p_lq) {
    p_lq ->front = p_lq ->rear = 0;
}

int is_empty(LevelQueue* p_lq) {
    return p_lq ->front == p_lq ->rear;
}

int is_full(LevelQueue* p_lq) {
    return (p_lq ->rear + 1)%MAX_QUEUE_SIZE == p_lq ->front;
}

void enqueue(LevelQueue* p_lq, TreeNode* element) {
    if(is_full(p_lq)) {
        error("queue is full now.");
        return;
    }

    p_lq ->rear = (p_lq ->rear + 1)%MAX_QUEUE_SIZE;
    p_lq ->data[p_lq ->rear] = element;
}

TreeNode* dequeue(LevelQueue* p_lq) {
    if(is_empty(p_lq)) {
        error("queue is empty now");
    }

    p_lq ->front = (p_lq ->front + 1)%MAX_QUEUE_SIZE;
    return p_lq ->data[p_lq ->front];
}

int main(void) {
    //트리 구조의 root를 넣으면 레벨 순회해서 프린트
    queue_level_order(&n1);
    return 0;
}