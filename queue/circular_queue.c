#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 5

typedef struct
{
    char* name;
    int student_num;
} student;

typedef struct
{
    int rear, front;
    student students[MAX_QUEUE_SIZE];
} circular_queue;

void init_circular_queue(circular_queue* p_cq) {
    p_cq -> rear = -1;
    p_cq -> front = 0;
}

int is_full(circular_queue* p_cq) {
    return p_cq ->rear - p_cq ->front == MAX_QUEUE_SIZE;
}

int is_empty(circular_queue* p_cq) {
    return p_cq ->rear + 1 == p_cq ->front;
}

void error(char* message) {
    printf("%s\n", message);
}

void enqueue(circular_queue* p_cq, student* p_student) {
    if(is_full(p_cq)) {
        error("queue is full now. please remove items first.");
        exit(1);
    }
    p_cq -> students[++p_cq ->rear % MAX_QUEUE_SIZE] = *p_student;
}

student dequeue(circular_queue* p_cq) {
    if(is_empty(p_cq)) {
        error("queue is currently empty now. please add items first.");
        exit(1);
    }
    return p_cq -> students[p_cq ->front++ % MAX_QUEUE_SIZE];
}

int main(void) {
    circular_queue cq;
    circular_queue* p_cq = &cq;

    init_circular_queue(p_cq);

    student st1 = {"yoochan", 202143318};
    student st2 = {"yoochan2", 202143319};
    student st3 = {"yoochan3", 202143320};
    student st4 = {"yoochan4", 202143321};
    student st5 = {"yoochan5", 202143322};
    student st6 = {"yoochan6", 202143323};

    enqueue(p_cq, &st1);
    printf("%d %d\n", p_cq ->rear, p_cq ->front);
    enqueue(p_cq, &st2);
    printf("%d %d\n", p_cq ->rear, p_cq ->front);
    enqueue(p_cq, &st3);
    printf("%d %d\n", p_cq ->rear, p_cq ->front);
    enqueue(p_cq, &st4);
    printf("%d %d\n", p_cq ->rear, p_cq ->front);
    enqueue(p_cq, &st5);
    printf("%d %d\n", p_cq ->rear, p_cq ->front);

    dequeue(p_cq);
    printf("%d %d\n", p_cq ->rear, p_cq ->front);
    enqueue(p_cq, &st6);
    printf("%d %d\n", p_cq ->rear, p_cq ->front);

    while (!is_empty(p_cq))
    {
        student st = dequeue(p_cq);
        printf("%s\n", st.name);
    }
    
    return 0;
}