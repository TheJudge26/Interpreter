#include <stdio.h>
#include <stdbool.h>

#define input_len 1000

void interpret(char *text)
{
char c;

while ((c=*text)!='\0')
{
    printf("%c\n",c);
    text++;
}


}
int main() {

char s[input_len];
printf("Interpreter is running......");
while (true)
{
    printf(">>>");

    fgets(s,input_len,stdin);

    interpret(s);


}

    
}

