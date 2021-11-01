#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
  int data;
  struct Node* pNext;
}NODE;

typedef struct List
{
  NODE* pHead;
  NODE* pTail;
}LIST;

void InitList(LIST &l)
{
  l.pHead = l.pTail = NULL;
}

int IsEmpty(LIST l)
{
	if(l.pHead==NULL)
		return 1;
	return 0;
}
NODE* GetNode(int &x)
{
    NODE* p = new NODE;
    if (p == NULL)
    {
      printf("Not enough memory for allocate\n");
      return NULL;
    }
    p->data = x;
    p->pNext = NULL;
}

void AddFirst(LIST &l, NODE* p)
{
  if (l.pHead == NULL)
  {
    l.pHead = l.pTail = p;
  }
  else
  {
    p->pNext = l.pHead;
    l.pHead = p;
  }
}

void AddTail(LIST &l, NODE* p)
{
  if (l.pHead == NULL)
  {
    l.pHead = l.pTail = p;
  }
  else
  {
    l.pTail->pNext = p;
    l.pTail = p;
  }
}

void InsertAfter(LIST &l, NODE* q, int x)
{
  if(l.pHead == NULL)
  {
    printf("DS dang rong khong the insert after");
    return ;
  }
  if (x == l.pHead->data && l.pHead->data == NULL)
  {
    AddTail(l, q);
  }
  else
  {
    for(NODE* i = l.pHead; i!=NULL; i=i->pNext)
    {
      if(i->data == x)
      {
        NODE* g = GetNode(q->data); // truong hop trong list co nhiều giá trị giống nhau
        g->pNext = i->pNext;
        i->pNext = g;
      }
    }
  }
}

void InsertBefore(LIST &l, NODE* q, int x)
{
  if(l.pHead == NULL)
  {
    printf("DS dang rong khong the insert before");
    return ;
  }

  if (l.pHead == l.pTail)
  {
    AddFirst(l, q);
  }
  else
  {
    NODE *g = new NODE;
    for(NODE* i = l.pHead; i!=NULL; i=i->pNext)
    {
      if(x==l.pHead->data)
      {
        AddFirst(l,q);
      }
      else if(i->data==x && x!=l.pHead->data)
      {
        NODE* h = GetNode(q->data);
        h->pNext = i;
  			g->pNext = h;
      }
      g = i;
    }
  }
}

void InputList(LIST &l)
{
  int n, x;
  printf("\nNhap so luong Node : ");
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
  {
      printf("\nNhap gia tri x :");
      scanf("%d", &x);
      NODE* p = GetNode(x);
      AddFirst(l,p);
  }
}
void DeleteHead(LIST &l)
{
	NODE* p;
	p = l.pHead;
	l.pHead = l.pHead->pNext;
	delete p;
	if(l.pHead==NULL)
			l.pTail = NULL;

	printf("\n%d\n%d\n", l.pHead, l.pTail);
}
void DeleteTail(LIST &l)
{
	NODE* p, *i;
	if(l.pHead==l.pTail)
	{
		delete l.pHead;
		l.pHead = l.pTail = NULL;
		return;
	}
	for(i=l.pHead;i->pNext!=l.pTail;i=i->pNext);
	p=l.pTail;
	l.pTail = i;
	l.pTail->pNext = NULL;
	delete p;
		printf("\n%d\n%d\n", l.pHead, l.pTail);
}

void Display(LIST l)
{
  if(IsEmpty(l))
	{
		printf("DS rong.");
		return;
	}
  for(NODE* i = l.pHead; i != NULL; i = i->pNext)
  {
    printf("%d -> ", i->data);
  }
  printf("NULL");
}

int main()
{
  LIST l;
  InitList(l);
  InputList(l);
  Display(l);

    int x, data_q;
    printf("\nNhap gia tri can tim : ");
    scanf("%d", &x);
    printf("Nhap node can them : ");
    scanf("%d", &data_q);
    NODE* q = GetNode(data_q);
    InsertBefore(l,q,x);
    Display(l);


  return 0;
}
