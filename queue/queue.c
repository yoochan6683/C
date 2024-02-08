#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 5

typedef struct
{
    char* name;
    int school_num;
} student_info;

typedef struct
{
    int rear;
    int front;
    student_info students[MAX_QUEUE_SIZE];
} student_queue;

void init_student_queue(student_queue* sq) {
    sq -> rear = -1;
    sq -> front = -1;
}

void error(char* message) {
    printf("%s\n", message);
}

int is_full(student_queue* sq) {
    return sq -> rear == MAX_QUEUE_SIZE - 1;
}

void enqueue(student_queue* sq, student_info object) {
    if (is_full(sq)) {
        error("queue is currently full. please remove items first.");
        return;
    }
    sq ->students[++sq->rear] = object;
}

int is_empty(student_queue* sq) {
    return sq -> rear == sq -> front;
}

student_info dequeue(student_queue* sq) {
    if (is_empty(sq)) {
        error("queue is empty. please add student.");
        exit(1);
    }
    return sq -> students[++sq -> front];
}

int main(void)
{
    student_queue sq;
    student_queue* p_sq = &sq;
    student_info st1 = {"yoochan", 202143318};
    student_info st2 = {"yoochan2", 202143319};
    student_info st3 = {"yoochan3", 202143320};
    student_info st4 = {"yoochan4", 202143321};
    student_info st5 = {"yoochan5", 202143322};
    student_info st6 = {"yoochan6", 202143323};

    init_student_queue(p_sq);

    enqueue(p_sq, st1);
    enqueue(p_sq, st2);
    enqueue(p_sq, st3);
    enqueue(p_sq, st4);
    enqueue(p_sq, st5);
    enqueue(p_sq, st6);
    student_info queue_st = dequeue(p_sq);

    printf("%d\n", p_sq -> rear);
    printf("%s\n", queue_st.name);

    return 0;
}
