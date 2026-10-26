#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CAP 512
#define LINE 1024
typedef struct { double a[CAP]; int top; } DStack;
typedef struct { char a[CAP]; int top; } CStack;
static int prec(char c){switch(c){case '~':case '#':return 3;case '^':return 4;case '*':case '/':return 2;case '+':case '-':return 1;default:return 0;}}
static int right_assoc(char c){return c=='^'||c=='~'||c=='#';}
static int op(char c){return strchr("+-*/^~#",c)!=NULL;}
static int pushc(CStack*s,char c){if(s->top>=CAP-1)return 0;s->a[++s->top]=c;return 1;}
static int pushd(DStack*s,double d){if(s->top>=CAP-1)return 0;s->a[++s->top]=d;return 1;}
/* Shunting-yard conversion from infix text to space-separated postfix tokens. */
static int postfix(const char*in,char*out,size_t cap){CStack s={.top=-1};size_t i=0,n=0;int want=1;out[0]='\0';while(in[i]){if(isspace((unsigned char)in[i])){i++;continue;}if(isdigit((unsigned char)in[i])||in[i]=='.'){char*end;(void)strtod(in+i,&end);if(end==in+i||!want)return 0;size_t len=(size_t)(end-(in+i));if(n+len+2>=cap)return 0;memcpy(out+n,in+i,len);n+=len;out[n++]=' ';out[n]='\0';i+=len;want=0;continue;}char c=in[i++];if(c=='('){if(!want||!pushc(&s,c))return 0;want=1;}else if(c==')'){if(want)return 0;while(s.top>=0&&s.a[s.top]!='('){if(n+3>=cap)return 0;out[n++]=s.a[s.top--];out[n++]=' ';out[n]='\0';}if(s.top<0)return 0;s.top--;want=0;}else if(strchr("+-*/^",c)){if(want){if(c!='+'&&c!='-')return 0;c=c=='-'?'~':'#';}else want=1;while(s.top>=0&&op(s.a[s.top])&&(prec(s.a[s.top])>prec(c)||(prec(s.a[s.top])==prec(c)&&!right_assoc(c)))){if(n+3>=cap)return 0;out[n++]=s.a[s.top--];out[n++]=' ';out[n]='\0';}if(!pushc(&s,c))return 0;}else return 0;}if(want)return 0;while(s.top>=0){if(s.a[s.top]=='('||n+3>=cap)return 0;out[n++]=s.a[s.top--];out[n++]=' ';out[n]='\0';}if(n)out[n-1]='\0';return 1;}
static int calculate(const char*p,double*ans){DStack s={.top=-1};char buf[LINE];if(strlen(p)>=sizeof buf)return 0;strcpy(buf,p);for(char*t=strtok(buf," ");t;t=strtok(NULL," ")){if(strlen(t)==1&&op(t[0])){char c=t[0];if(c=='~'||c=='#'){if(s.top<0)return 0;if(c=='~')s.a[s.top]=-s.a[s.top];}else{if(s.top<1)return 0;double b=s.a[s.top--],a=s.a[s.top],r;switch(c){case '+':r=a+b;break;case '-':r=a-b;break;case '*':r=a*b;break;case '/':if(b==0)return -1;r=a/b;break;case '^':r=pow(a,b);break;default:return 0;}s.a[s.top]=r;}}else{char*end;double v=strtod(t,&end);if(!*t||*end||!pushd(&s,v))return 0;}}if(s.top!=0||!isfinite(s.a[0]))return 0;*ans=s.a[0];return 1;}
int main(void){char in[LINE],out[LINE];puts("Expression Evaluation Using Stack\nOperators: + - * / ^ | Type q to quit");for(;;){printf("\nEnter expression: ");if(!fgets(in,sizeof in,stdin))break;if(in[0]=='q'||in[0]=='Q')break;if(!postfix(in,out,sizeof out)){puts("Error: invalid expression or mismatched parentheses.");continue;}double result;int status=calculate(out,&result);if(status==-1)puts("Error: division by zero.");else if(!status)puts("Error: expression could not be evaluated.");else printf("Postfix: %s\nResult: %.10g\n",out,result);}puts("Calculator closed.");return 0;}
