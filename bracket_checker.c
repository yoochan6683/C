#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    char* brackets;
    int capacity;
    int top;
} bracket_stack;

void init_bracket_stack(bracket_stack *bs) {
    bs -> top = -1;
    bs -> capacity = 1;
    bs -> brackets = (char *)malloc(sizeof(char)*bs -> capacity);
}

int is_full(bracket_stack *bs) {
    return bs -> top == (bs -> capacity - 1);
}

int is_empty(bracket_stack *bs) {
    return bs -> top == -1;
}

void push(bracket_stack *bs, char bracket) {
    if(is_full(bs)) {
        bs -> capacity *= 2;
        bs -> brackets = (char *)realloc(bs, sizeof(char)*bs -> capacity);
    }
    bs -> brackets[++bs -> top] = bracket;
}

char pop(bracket_stack *bs) {
    if(is_empty) {
        printf("UnderFlow");
        exit(1);
    }
    else return bs -> brackets[bs -> top--];
}



int main() {
    bracket_stack s;
    init_bracket_stack(&s);



    printf("hello world!");
    return 0;
}