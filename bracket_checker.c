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
    return (bs -> top) == -1;
}

void push(bracket_stack *bs, char bracket) {
    if(is_full(bs)) {
        bs -> capacity *= 2;
        bs -> brackets = (char *)realloc(bs -> brackets, sizeof(char)*bs -> capacity);
    }
    bs -> brackets[++(bs -> top)] = bracket;
}

char pop(bracket_stack *bs) {
    if(is_empty(bs)) {
        return 'e';
    }
    else return bs -> brackets[bs -> top--];
}

int check_braket(char * code, bracket_stack *bs) {
    char latest_bracket;
    while(*code != '\0') {
        switch (*code)
        {
        case '(': case '{': case '[':
            push(bs, *code);
            break;
        case ')':
            latest_bracket = pop(bs);
            if(latest_bracket != '(' || latest_bracket == 'e') return 0;
            break;
        case '}':
            latest_bracket = pop(bs);
            if(latest_bracket != '{' || latest_bracket == 'e') return 0;
            break;
        case ']':
            latest_bracket = pop(bs);
            if(latest_bracket != '[' || latest_bracket == 'e') return 0;
            break;
        }
        code++;
    }
    if(!is_empty(bs)) return 0;
    return 1;
}



int main() {
    //스택 초기 설정
    bracket_stack s;
    init_bracket_stack(&s);

    //입력된 코드 저장
    char code[100];
    char* p_code = code;
    scanf("%s", code);

    //괄호 검사 함수
    int is_valid = check_braket(code, &s);
    printf("%d", is_valid);


    return 0;
}