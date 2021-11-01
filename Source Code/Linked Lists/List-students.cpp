#include<stdio.h>
#include<string.h>

typedef struct Student
{
  char masv[10];
  char hoten[30];
  int tuoi;
  float dtb;
}SV;

typedef struct Node
{
  SV info;
  struct Node* pNext;
}NODE;

typedef struct List
{
  NODE* pHead;
  NODE* pTail;
}LIST;

void Nhap1Sv(SV &x)
{
  printf("\nNhap MSSV : ");
  fflush(stdin);
  gets(x.masv);
  printf("\nNhap ho ten : ");
  gets(x.hoten);
  printf("\nNhap tuoi : ");
  scanf("%d", &x.tuoi);
  printf("\nNhap diem tb : ");
  scanf("%f", &x.dtb);
}

void Xuat1Sv(SV x)
{
  printf("\n%-15s %-15s %-15d %-15f", x.masv, x.hoten, x.tuoi, x.dtb);
}
void InitList(LIST &l)
{
  l.pHead = l.pTail = NULL;
}

int IsEmty(LIST l)
{
  return (l.pHead == NULL);
}
NODE* GetNode(SV &x)
{
  NODE* p = new NODE;
  if(p == NULL)
  {
    printf("Not enough memory for allocate");
    return NULL;
  }
  else
  {
    p->info = x;
    p->pNext = NULL;
  }
}

void AddFirst(LIST &l, NODE* p)
{
  if(l.pHead == NULL)
  {
    l.pHead = l.pTail = p;
  }
  else
  {
    p->pNext = l.pHead;
    l.pHead = p;
  }
}

void InputList(LIST &l)
{
  int n;
  SV x;
  printf("Nhap so luong sinh vien :");
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
  {
    Nhap1Sv(x);
    NODE* p = GetNode(x);
    AddFirst(l, p);
  }
}

void Update(LIST &l, char x[10])
{
  SV k;
  printf("Nhap mssv muon sua");
  fflush(stdin);
  gets(x);
  for(NODE* i = l.pHead; i!=NULL; i=i->pNext)
  {
    if(strcmp(i->info.masv,x) == 0)
    {
      Nhap1Sv(k);
      NODE* p = GetNode(k);
      i->info = p->info;
    }
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
}

void Delete(LIST &l, char x[30])
{
  printf("Nhap ten muon xoa");
  fflush(stdin);
  gets(x);
  NODE *g = new NODE;
  if(strcmp(l.pHead->info.hoten,x) == 0)
  {
  DeleteHead(l);
  }
  for(NODE* i = l.pHead; i!=NULL; i=i->pNext)
  {

    if(strcmp(i->info.hoten,x) == 0)
    {
      NODE *tam = g->pNext;
  			g->pNext = g->pNext->pNext;
  			delete tam;
    }
    g=i;
  }
}

void Find(LIST l, int x)
{
  printf("Nhap tuoi sinh vien can tim");
  scanf("%d", &x);
  for(NODE* i = l.pHead; i!=NULL; i=i->pNext)
  {
    if(i->info.tuoi == x)
    {
      Xuat1Sv(i->info);
    }
  }
}
void swap(SV &x, SV &y)
{
  SV temp = x;
  x = y;
  y = temp;
}
void InterchangeSort(LIST &l){
  for(NODE* i = l.pHead; i!=l.pTail; i=i->pNext)
    for(NODE* j = i->pNext; j!=NULL; j = j->pNext)
      if(i->info.dtb > j->info.dtb)
        swap(i->info, j->info);
}
void Display(LIST l)
{
  if(IsEmty(l))
  {
    return;
  }
  for(NODE* i = l.pHead; i!=NULL; i=i->pNext)
  {
    Xuat1Sv(i->info);
  }
}

void RemoveList(LIST &l)
{
  NODE* i;
  while(l.pHead != NULL)
  {
    i=l.pHead;
    l.pHead = i->pNext;
    delete i;
  }
  l.pTail = NULL;
}

int main()
{
  LIST l;
  char x[10];
  int y;
  InitList(l);
  InputList(l);
  Display(l);
  //InterchangeSort(l);
  //Update(l, x);
  //Find(l,y);
  Delete(l,x);
  //RemoveList(l);
  Display(l);
  return 0;
}
