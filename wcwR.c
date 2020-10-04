#include <stdio.h>
#include <conio.h>
#include <string.h>

void push(char s[], int n, int *top, char x)
{
  if(*top>=(n-1))
  {
    printf("Stack Overflow");
    return;
  }
  *top=*top+1;
  s[*top]=x;
}

char pop(char s[], int *top)
{
  if(*top == -1)
    return '~';
  *top=*top-1;
  return(s[*top+1]);
}

int chk_lang(char a[])
{
  int i, top=-1, n;
  char s[100], c;

  n=strlen(a);
  for( i=0; a[i]!='C' && a[i]!='c'; i++)
  {
    if((a[i]>='a' && a[i]<='z') || (a[i]>='A' && a[i]<='Z'))
        push(s,n,&top,a[i]);
    else
        return 0;
  }
  i++;
  while(a[i]!='\0')
  {
    c=pop(s,&top);
    if(c==a[i])
      i++;
    else
      return 0;
  }
  if(top==-1)
    return 1;
  else
    return 0;
}

void main()
{
  char a[100];
  printf("19012011002 MANTHAN BHAVSAR\n");
  printf("Enter Expression: \n");
  gets(a);
  if(chk_lang(a))
    printf("It belongs to ");
  else
    printf("It does not belong to ");

  printf("the lang of xcy \n\twhere x is a string and y is reverse of x.");
}
