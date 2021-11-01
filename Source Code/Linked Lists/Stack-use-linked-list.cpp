#include <stdio.h>

typedef struct Item
{
  int data;
  struct Item* pDown;
}ITEM;

typedef struct Stack
{
  ITEM* Top;
  int numOfNumber;
}STACK;

ITEM* GetItem(int x)
{
  ITEM* t = new ITEM;
  if(t==NULL)
  {
    printf("Khong du bo nho");
    return NULL;
  }
  t->data = x;
  t->pDown = NULL;
  return t;
}

void InitStack(STACK &s)
{
  s.Top = NULL;
  s.numOfNumber = 0;
}

int IsEmty(STACK s)
{
  if (s.Top == NULL && s.numOfNumber == 0)
    return 1;
  return 0;
}

int IsFull()
{
  ITEM* t = new ITEM;
  if(t==NULL)
  {
    printf("Khong du bo nho");
    return 1;
  }
  delete t;
  return 0;
}

void AddTop(STACK &s, ITEM* t)
{
  if(s.Top == NULL)
  {
    s.Top = t;
    return;
  }
  t->pDown = s.Top;
  s.Top = t;
}
int Push(STACK &s, int x)
{
  if(IsFull()==1)
  {
    return 0;
  }
  ITEM* t = GetItem(x);
  AddTop(s,t);
  s.numOfNumber++;
  return 1;
}

void DeleteTop(STACK &s)
{
  if(s.Top == NULL) return;
  ITEM* t = s.Top;
  s.Top = s.Top->pDown;
  delete t;
}
int Pop(STACK &s, int &x)
{
  if(IsEmty(s)==1)
    return 0;
  x = s.Top->data;
  DeleteTop(s);
  s.numOfNumber--;
  return 1;
}

int CheckTop(STACK s, int &x)
{
  if(IsEmty(s) == 1)
    return 0;
  x = s.Top->data;
  return 1;
}

// int Push(STACK &s, int x)
// {
//   if(IsFull()==1)
//   {
//     return 0;
//   }
//   NODE* p = GetNode(x);
//   if(s.Top==NULL)
//   {
//     s.Top = p;
//     return;
//   }
//   p->pDown = s.Top;
//   s.Top = p;
//   s.numOfNumber++;
//   return 1;
// }
//
// int Pop(STACK &s, int &x)
// {
//   if(IsEmty(s))
//   {
//     return 0;
//   }
//   x=s.Top->data;
//   NODE* p = s.Top;
//   s.Top = s.Top->pDown;
//   delete p;
//   return 1;
// }


void Display(STACK s)
{
  if(IsEmty(s) == 1)
  {
    printf("Stack rong");
    return;
  }
  for(ITEM* i = s.Top; i!=NULL; i=i->pDown)
  {
      printf("%4d", i->data);
  }
  printf("\nso luong phan tu cua stack : %d", s.numOfNumber);
}
int main()
{
  STACK s;
  int n, x, check;
  InitStack(s);
  printf("Nhap so luong phan tu :");
  scanf("%d", &n);
  for(int i=0; i<n; i++)
  {
    printf("Nhap x = " );
    scanf("%d", &x);
    Push(s,x);
  }

 Display(s);
 int w;
Pop(s,w);
printf("\n%d\n", w);
  return 1;
}
