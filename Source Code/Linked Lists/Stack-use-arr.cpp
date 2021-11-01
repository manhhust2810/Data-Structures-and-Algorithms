#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Stack
{
  int *a; //array
  int n;
  int top;
}STACK;

void InitStack(STACK &s, int spt)
{
  s.a = new int[spt];
  if(s.a == NULL)
  {
    printf("Khong cap phat duoc");
    return;
  }
  s.n = spt;
  s.top = -1;
}

int IsEmty(STACK s)
{
  return (s.top == -1);
}

int IsFull(STACK s)
{
  return (s.top == s.n-1);
}

int Push(STACK &s, int x)
{
  if(IsFull(s))
    return 0;
  s.a[++s.top] = x;
  return 1;
}

int Pop(STACK &s, int &x)
{
  if(IsEmty(s))
    return 0;
  x = s.a[s.top--];
}

int CheckTop(STACK s, int &x)
{
  if(IsEmty(s))
   return 0;
   x = s.a[s.top];
}

void Display(STACK s)
{
  if(IsEmty(s))
    return ;
  for(int i=0; i<=s.top; i++)
  {
    printf("%4d", s.a[i]);
  }
  printf("\nVi tri dinh cua stack la %d",s.top);
}

int main()
{
  int over, emty;
  STACK s;
  int n, x;
  printf("Nhap so phan tu : ");
  scanf("%d", &n);
  InitStack(s, n);
  printf("Thi nghiem ham push\n");
    for(int i=0; i<s.n; i++)
    {
      printf("Nhap gia tri de dua vao stack: ");
      scanf("%d", &x);
      over = Push(s,x);
      if(over == 0)
      {
        printf("Stack bi tran !!!");
      }
    }
    Display(s);
    return 0;
}
