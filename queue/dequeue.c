#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 5

typedef struct 
{
    char* name;
    int product_num;
} Product;

typedef struct 
{
    int rear, front;
    Product stock[MAX_QUEUE_SIZE];
} Dequeue;

void init_queue(Dequeue* p_dq) {
    p_dq ->rear = p_dq ->front = 0;
}

void error(char* message) {
    printf("%s\n", message);
}

int is_empty(Dequeue* p_dq) {
    return p_dq ->front == p_dq ->rear;
}

int is_full(Dequeue* p_dq) {
    return (p_dq ->rear + 1) % MAX_QUEUE_SIZE == p_dq ->front;
}

void add_front(Dequeue* p_dq, Product* p_product) {
    if(is_full(p_dq)) {
        error("stock is currently full now");
        return;
    }
    p_dq ->stock[p_dq ->front] = *p_product;
    p_dq ->front = (p_dq ->front - 1 + MAX_QUEUE_SIZE)% MAX_QUEUE_SIZE;//front 감소
}

Product delete_front(Dequeue* p_dq) {
    if(is_empty(p_dq)) {
        error("stock is empty");
        exit(1);
    }
    
    p_dq ->front = (p_dq ->front + 1) % MAX_QUEUE_SIZE;
    return p_dq ->stock[p_dq ->front];
}

void add_rear(Dequeue* p_dq, Product* p_product) {
    if(is_full(p_dq)) {
        error("stock is currently full now");
        exit(1);
    }
    p_dq ->rear = (p_dq ->rear + 1)% MAX_QUEUE_SIZE;//rear 증가
    p_dq ->stock[p_dq ->rear] = *p_product;
}

Product delete_rear(Dequeue* p_dq) {
    if(is_empty(p_dq)) {
        error("stock is empty");
        exit(1);
    }
    Product p_rear = p_dq ->stock[p_dq ->rear];
    p_dq ->rear = (p_dq ->rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
    return p_rear;
}

Product get_front(Dequeue* p_dq) {
    if(is_empty(p_dq)) {
        error("stock is empty");
        exit(1);
    }
    return p_dq ->stock[p_dq ->front];
}

Product get_rear(Dequeue* p_dq) {
    if(is_empty(p_dq)) {
        error("stock is empty");
        exit(1);
    }
    return p_dq ->stock[p_dq ->rear];
}

void print_dequeue(Dequeue* p_dq) {
    int rear = p_dq ->rear;
    int front = p_dq ->front;

    if(!is_empty(p_dq)){
        int i=p_dq->front;
        do{
             i = (i + 1) % MAX_QUEUE_SIZE;
            Product current_product = p_dq ->stock[i];
            printf("product name: %s, product number: %d\n", current_product.name, current_product.product_num);
            if(i==p_dq->rear)
                break;
        }while(i!=p_dq->front);
    }
    printf("\n");
    
}

int main(void) {
    Dequeue product_queue;
    init_queue(&product_queue);

    Product p1 = {"p1", 1};
    Product p2 = {"p2", 2};
    Product p3 = {"p3", 3};
    Product p4 = {"p4", 4};
    Product p5 = {"p5", 5};
    Product p6 = {"p6", 6};

    add_rear(&product_queue, &p1);
    add_rear(&product_queue, &p2);
    add_rear(&product_queue, &p3);
    add_rear(&product_queue, &p4);
    delete_rear(&product_queue);
    delete_front(&product_queue);
    add_front(&product_queue, &p5);
    add_front(&product_queue, &p6);

    print_dequeue(&product_queue);

    return 0;
}