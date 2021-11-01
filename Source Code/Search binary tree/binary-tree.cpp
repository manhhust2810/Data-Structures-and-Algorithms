#include <stdio.h>
typedef struct Node
{
  int key;
  struct Node* pLeft;
  struct Node* pRight;
}NODE;

typedef NODE * TREE;

int ThemNut(TREE &t, int x){

  if(t==NULL)
  {
    NODE* p = new NODE;
    if(p==NULL) return -1;
    p->key=x;
    p->pLeft=p->pRight=NULL;
    t=p;
    return 1;
  }

  if(x==t->key)
    return 0;
  if(x>t->key)
    ThemNut(t->pRight, x);
  else
    ThemNut(t->pLeft, x);
}
void NhapCay(TREE &t)
{
	int x,kt;
	do
	{
		printf("Nhap gia tri cho mot nut:");
		scanf("%d", &x);
		kt=ThemNut(t,x);
		if(kt==0||kt==-1)
			return;
	}while(true);
}

void DuyetNLR(TREE t)
{
	//if(t==NULL);
	if(t!=NULL)
	{
		printf("%4d",t->key );
		DuyetNLR(t->pLeft);//Left
		DuyetNLR(t->pRight);//Right
	}
}
int DemNutLa(TREE t)
{
  if(t==NULL) return 0;
	if(t->pLeft==NULL && t->pRight==NULL)
		return 1;
	return DemNutLa(t->pLeft)+DemNutLa(t->pRight);
}

int DoCaoCay(TREE t) // khi su*? du.ng ha`m na`y, nho*' tru*` d-i 1
{
	if(t==NULL) return 0;
	int d1=DoCaoCay(t->pLeft);
	int d2=DoCaoCay(t->pRight);
	if(d1>d2) return d1+1;
	else return d2+1;
}

void XoaNut(TREE &t, int x)
{
	if(t!=NULL)
	{
		if(x>t->key) XoaNut(t->pRight,x);
		else
			if(x<t->key) XoaNut(t->pLeft,x);
			else //x==t->key
			{
				NODE *p=t;//truoc khi t di chuyen thi luu t vao p
				if(t->pLeft==NULL) t=t->pRight;//TH2 (bao gom TH1)
				else
					if(t->pRight==NULL) t=t->pLeft;//TH2 (bao gom TH1)
					else //TH3, tim nut the mang la nut trai nhat cua cay con ben phai
					{
						NODE *truocQ=t;
						NODE *q=t->pRight; //q la cay con ben phai
						//Doan code na`y tuong duong ha`m SearchStandFor(p,q)
						while(q->pLeft!=NULL)
						{
							truocQ=q;
							q=q->pLeft;
						}
						if(truocQ!=t) truocQ->pLeft=q->pRight;
						else t->pRight=q->pRight;
						t->key=q->key; // chep noi dung nut the mang vao nut t
						p=q;
					}
					delete p;
			}
	}
}
int main()
{
	int x;
	TREE t;
	t=NULL;
	NhapCay(t);
	DuyetNLR(t);
  printf("\nSo luong nut la': %d", DemNutLa(t));
  printf("\nDo cao cua cay: %d",DoCaoCay(t)-1);
	printf("\nNhap gia tri key cua nut muon xoa: ");
	scanf("%d", &x);
	XoaNut(t,x);
	printf("Duyet cay sau khi xoa:");
	DuyetNLR(t);
  return 0;
}
