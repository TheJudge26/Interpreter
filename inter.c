#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define input_len 1000

#define INT 0
#define OP 1
#define err -1
#define INT_STR "INT"
#define OPERATOR_STRING "OPERATOR"


typedef struct 
{
    int type;//num or op 2+2
    char operator_value;
    int number_value;

}Token;

int current_pos=0;

Token current_token;

bool is_digit(char c)
{
   return c>='0'&&c<='9';
    
}

bool is_operator(char c)
{
   return c=='+'||c=='-';
    
}

bool is_wight_space(char c)
{
   return c==' ';
    
}

void get_next_token(char *text){

    char c = text[current_pos];

    while (is_wight_space(c))
    {
        current_pos ++;
        c = text[current_pos];
    }
    

    if (is_digit(c))
    {
        int current_number=c-'0';

        current_pos ++;

        while (is_digit(text[current_pos]))
        {
            current_number *= 10;
            current_number+=(text[current_pos] - '0');  
            current_pos ++;
        }
        
        current_token.type=INT;

        current_token.number_value=current_number;
        
        current_token.operator_value=' ';
    }
    
    else if(is_operator(c)) 
    {
        current_token.type=OP;

        current_token.operator_value=c; 

        current_token.number_value=0;

        current_pos ++ ;
    }
    else
    {
        // current_token.type = err;
        // current_token.number_value=0;
        printf("invalid token at pos %d : %c\n",current_pos,c);
        exit(-1);
    }
    
}

void token_str(Token token, char *s) // token as string in string s
{
    // char *type = OPERATOR_STRING;
    // if (token.type==INT)
    // {
    //     type = INT_STR;
    // }
    // char *value = token.number_value;
    // if (token.type==OP)
    // {
    //     value = &token.operator_value;
    // }
    
    sprintf(s,"Token (type=%s, numper_value=%d,operator_vlaue=%c)", token.type==INT? INT_STR:OPERATOR_STRING,token.number_value,token.operator_value);
}

void parse(int type){

    if (current_token.type!=type)
    {
        char s[100];
        token_str(current_token, s);
        printf("syntax error at pos %d: Expected token of type %s,but received tosken%s", current_pos,type==INT ? INT_STR : OPERATOR_STRING,s);
        exit(-1);
    }
    
}

int interpret(char *text)//from the text to tokens 
{
    get_next_token(text);
    parse(INT);
    int left = current_token.number_value;

    get_next_token(text);
    parse(OP);
    int operator = current_token.operator_value;

    get_next_token(text);
    parse(INT);
    int right = current_token.number_value;

    current_pos=0;

    int result;

    if (operator=='+')
    {
        result = left + right;
    }
    else{
        result=left-right;
    }
    return result;
}
int main() {

char s[input_len];
printf("Interpreter is running......");

int result;
while (true)
{
    printf(">>>");

    fgets(s,input_len,stdin);

    result =interpret(s);

    printf("%d\n",result);
}

    
}

