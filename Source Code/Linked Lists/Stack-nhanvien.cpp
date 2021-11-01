// 	1. Tạo cấu trúc nhân viên gồm tên, tuổi, lương.
// 	2. Tạo cấu trúc node để lưu trữ mỗi node là một nhân viên tương ứng.
// 	3. Tạo cấu trúc Queue.
// 	4. Khởi tạo Queue rỗng (hàm InitQueue).
// 	5. Viết hàm kiểm tra Queue có rỗng hay không? (IsEmpty).
// 	6. Viết hàm nhập các thông tin nhân viên.
// 	7. Viết hàm thêm một node nhân viên vào cuối Queue (EnQueue).
// 	8. Viết hàm lấy một node nhân viên ở đầu Queue ra (DeQueue).
// 	9. Viết hàm lấy một node nhân viên ở đỉnh Queue ra mà không xóa node đó khỏi Queue (QueueFront).
// 	10. Viết nhập một danh sách thông tin nhân viên vào trong Queue.
// 	11. Viết hàm hiển thị thông tin nhân viên trong Queue ra.
// 	12. Viết hàm in thông tin nhân viên có lương lớn nhất trong Queue
// 	13. Viết hàm in lương trung bình của  các nhân viên
#include <stdio.h>
#include <string.h>
typedef struct Nhanvien
{
  char ten[30];
  int tuoi;
  float luong;
}NV;

typedef struct Item
{
  NV info;
  struct Item* pDown;
}ITEM;

typedef struct Stack
{
  ITEM* Top;
}STACK;

void NhapNV(NV &x)
{
  printf("Nhap ten : ");
  fflush(stdin);
  gets(x.ten);
  printf("Nhap tuoi : ");
  scanf("%d", &x.tuoi);
  printf("Nhap luong : ");
  scanf("%f", &x.luong);
}
void XuatNV(NV x)
{
  printf("%-15s %-15d %-15f\n",x.ten, x.tuoi, x.luong);
}

void InitStack(STACK &s)
{
  s.Top = NULL;
}

ITEM* GetItem(NV x)
{
  ITEM* t = new ITEM;
  if(t==NULL)
  {
    return NULL;
  }
  else
  {
    t->info = x;
    t->pDown = NULL;
  }
}
int IsEmty(STACK s)
{
  return(s.Top == NULL);
}
int IsFull()
{
  ITEM* t = new ITEM;
  if(t == NULL)
    return 1;
  else
  {
    delete t;
    return 0;
  }
}
int Push(STACK &s, ITEM* t)
{
  if(IsFull())
  {
    return 0;
  }
  if(s.Top == NULL)
  {
    s.Top = t;
    return NULL;
  }
  else
  {
    t->pDown = s.Top;
    s.Top = t;
  }
  return 1;
}
int Pop(STACK &s, NV &x)
{
  if(IsEmty(s))
    return 0;
  else
  {
    ITEM* t = s.Top;
    x = t->info;
    s.Top = s.Top->pDown;
    delete t;
  }
  return 1;
}
int CheckTop(STACK &s, NV &x)
{
  if(IsEmty(s))
    return 0;
  else
  {
    x = s.Top->info;
  }
  return 1;
}
void InputSTACK(STACK &s)
{
  int n;
  NV x;
  printf("Nhap so luong phan tu" );
  scanf("%d", &n);
  for(int i=0; i<n; i++)
  {
    NhapNV(x);
    ITEM* t = GetItem(x);
    Push(s,t);
  }
}

void Display(STACK s)
{
  while(IsEmty(s)==0)
  {
    NV x;
    Pop(s,x);
    XuatNV(x);
  }
}

int main()
{
  STACK s;
  NV x, k;
  int check;
  InitStack(s);
  InputSTACK(s);
  //Display(s);
  CheckTop(s, k);
  XuatNV(k);
  return 0;
}
