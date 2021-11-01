// •	mach int
// •	tench char[40]
// •	diachi char[50]
// •	dienthoai char[12]
// •	doanhso float
// 1.	nhập/ xuất cửa hàng
// 2.	nhập/ xuất 1 danh sách các cửa hàng
// 3.	thêm/ xóa 1 cửa hàng vào đầu/cuối danh sách
// 4.	thêm/ xóa 1 cửa hàng trước/sau cửa hàng có tên/mã tìm được thấy
// 5.	in ra danh sách các cửa hàng có doanh số > doanh số k nhập vào (truyền tham số k vào)
// 6.	sắp xếp các cửa hàng theo thứ tự tăng dần theo doanh số/mã (sử dụng interchange sort hoặc insertion sort)
// 7.	In thông tin các cửa hàng có doanh số lớn/ nhỏ nhất
// 8.	In thông tin các cửa hàng có doanh số lớn/ nhỏ hơn doanh số trung bình của các cửa hàng
#include<stdio.h>
#include<string.h>

typedef struct Cuahang
{
  int mach;
  char tench[40];
  char dienthoai[12];
  float doanhso;
}CH;

typedef struct Node
{
  CH info;
  struct Node* pNext;
}NODE;

typedef struct List
{
  NODE* pHead;
  NODE* pTail;
}LIST;

void NhapCH(CH &x)
{
  printf("\nNhap mach : ");
  scanf("%d", &x.mach);
  printf("Nhap ten ch : ");
  fflush(stdin);
  gets(x.tench);
  printf("Nhap sdt : ");
  gets(x.dienthoai);
  printf("Nhap doanh so : ");
  scanf("%f", &x.doanhso);
}

void XuatCH(CH x)
{
  printf("%-15d %-15s %-15s %-15f\n",x.mach, x.tench, x.dienthoai, x.doanhso);
}

void InitList(LIST &l)
{
  l.pHead = l.pTail = NULL;
}

int IsEmty(LIST l)
{
  return (l.pHead == NULL);
}

NODE* GetNode(CH x)
{
  NODE* p = new NODE;
  if(p==NULL)
  {
    printf("Khong du bo nho" );
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

void AddTail(LIST &l, NODE* p)
{
  if(l.pHead == NULL)
  {
    l.pHead = l.pTail = p;
  }
  else
  {
    l.pTail->pNext = p;
    l.pTail = p;
  }
}

void DeleteHead(LIST &l)
{
  if(l.pHead == NULL)
    return;
  NODE* q = l.pHead;
  l.pHead = l.pHead->pNext;
  delete q;
}

void DeleteTail(LIST &l)
{
  if(l.pHead == NULL)
    return;
  if(l.pHead == l.pTail)
  {
    DeleteHead(l);
    return;
  }
  for(NODE* i = l.pHead; i!=NULL; i=i->pNext)
  {
      if(i->pNext == l.pTail)
      {
        delete l.pTail;
        i->pNext = NULL;
        l.pTail = i;
        return;
      }
  }
}

void DeleteAfter(LIST &l, char x[40])
{
  printf("Nhap ten cua hang muon xoa(xoa sau)");
  fflush(stdin);
  gets(x);
  if(l.pHead == NULL)
   return;
   for(NODE* i = l.pHead; i!=NULL; i=i->pNext)
   {
       if(strcmp(i->info.tench, x) == 0)
       {
         NODE* q = i->pNext;
         i->pNext =  i->pNext->pNext;
         delete q;
         return;
       }
   }
}

void DeleteBefore(LIST &l, char x[40])
{
  printf("Nhap ten cua hang muon xoa(xoa truoc)");
  fflush(stdin);
  gets(x);
  if(l.pHead == NULL)
   return;
   for(NODE* i = l.pHead; i!=NULL; i=i->pNext)
   {
      if(strcmp(l.pHead->pNext->info.tench, x) == 0)
      {
        DeleteHead(l);
        return;
      }
       if(strcmp(i->pNext->pNext->info.tench, x) == 0)
       {
         NODE* q = i->pNext;
         i->pNext = i->pNext->pNext;
         delete q;
         return;
       }
   }
}

void InputList(LIST &l)
{
  int n;
  CH x;
  printf("Nhap so luong cua hang : ");
  scanf("%d", &n);
  for(int i = 0; i<n; i++)
  {
    NhapCH(x);
    NODE* p = GetNode(x);
    AddFirst(l, p);
  }
}

void BiggerThanX(LIST l, float x)
{
  printf("Nhap doanh so : " );
  scanf("%f", &x);
  for(NODE* i = l.pHead; i!=NULL; i=i->pNext)
  {
      if(i->info.doanhso > x)
      {
        XuatCH(i->info);
      }
  }
}

void Swap(CH &x, CH &y)
{
  CH temp = x;
  x = y;
  y = temp;
}

void InterchangeSortLIST(LIST l)
{
  for(NODE* i=l.pHead; i!=l.pTail; i=i->pNext)
    for(NODE* j= i->pNext; j!=NULL; j=j->pNext)
      if(i->info.doanhso > j->info.doanhso)
        Swap(i->info, j->info);
}

NODE* FindMax(LIST l)
{
  NODE* max = l.pHead;
  for(NODE* i = l.pHead; i!=NULL; i=i->pNext)
  {
      if(max->info.doanhso < i->info.doanhso)
      {
        max->info = i->info;
      }
  }
  return max;
}

void Max(LIST l)
{
  NODE* max = FindMax(l);
  for(NODE* i = l.pHead; i!=NULL; i=i->pNext)
  {
      if(max->info.doanhso == i->info.doanhso)
      {
        XuatCH(i->info);
      }
  }
}

float AverageDS(LIST l)
{
  float x = 0;
  float n = 0;
  for(NODE* i = l.pHead; i!=NULL; i=i->pNext)
  {
    x = x + i->info.doanhso;
    n++;
  }
  return x/n;
}

void BiggerThanAverageDS(LIST l)
{
  float x = AverageDS(l);
  for(NODE* i = l.pHead; i!=NULL; i=i->pNext)
  {
      if(i->info.doanhso > x)
      {
        XuatCH(i->info);
      }
  }
}

void Display(LIST l)
{
  if(IsEmty(l))
  {
    return;
  }
  for(NODE* i = l.pHead; i!=NULL; i=i->pNext)
  {
    XuatCH(i->info);
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
    for(NODE* i = l.pHead; i!=NULL; i=i->pNext)
    {
      if(x==l.pHead->info.mach)
      {
        AddFirst(l,q);
      }
      else if(i->pNext->info.mach==x)
      {
        q->pNext = i->pNext;
  			i->pNext = q;
        return;
      }
    }
  }
}
int main()
{
  LIST l;
  char x[40];
  float k;
  InitList(l);
  InputList(l);
  Display(l);
  int z;
  CH data_q;
  printf("\nNhap gia tri can tim : ");
  scanf("%d", &z);
  NhapCH(data_q);
  NODE* q = GetNode(data_q);
  InsertBefore(l,q,z);
Display(l);
//  DeleteAfter(l,x);
  // Display(l);
  // printf("\nCac cua hang co doanh thu nhieu nhat : \n");
  // Max(l);
  // BiggerThanX(l,k);
  //InterchangeSortLIST(l);
  //DeleteBefore(l, x);
//  Display(l);
  return 0;
}
