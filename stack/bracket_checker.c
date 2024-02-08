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
            if(latest_bracket != '(' || latest_bracket == 'e') {
                //error message 작성을 위해서 다시 스택에 넣어둠
                push(bs, latest_bracket);
                return 0;
            }
            break;
        case '}':
            latest_bracket = pop(bs);
            if(latest_bracket != '{' || latest_bracket == 'e') {
                //error message 작성을 위해서 다시 스택에 넣어둠
                push(bs, latest_bracket);
                return 0;
            }
            break;
        case ']':
            latest_bracket = pop(bs);
            if(latest_bracket != '[' || latest_bracket == 'e') {
                //error message 작성을 위해서 다시 스택에 넣어둠
                push(bs, latest_bracket);
                return 0;
            }
            break;
        }
        code++;
    }
    if(!is_empty(bs)) return 0;
    return 1;
}

void error_message(int is_valid, bracket_stack *bs) {
    if(!is_valid) {
        char latest_bracket = pop(bs);
        char expected_bracket;

        switch (latest_bracket)
        {
        case '(':
            expected_bracket = ')';
            break;
        case '{':
            expected_bracket = '}';
            break;
        case '[':
            expected_bracket = ']';
            break;
        }
        
        printf("error: your code is not valid. Expected: %c\n", expected_bracket);
        
    } else {
        printf("Your code is fine");
    }
}

int main() {
    //스택 초기 설정
    bracket_stack s;
    init_bracket_stack(&s);

    //입력된 코드 저장
    char code[100];
    char* p_code = code;
    scanf("%s", code);

    //괄호 유효성 검사, 0 = 부적함, 1 = 적합
    int is_valid = check_braket(code, &s);

    //검사 내용 출력 함수
    error_message(is_valid, &s);

    return 0;
}