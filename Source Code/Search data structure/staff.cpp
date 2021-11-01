#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 100
typedef struct Nhanvien
{
	int manv;
	char hoten[40];
	float luong;
}NV;
void nhap1nv(NV &x)
{
	printf("\nNhap ma nv : ");
	scanf("%d", &x.manv);
	printf("Nhap ho ten : ");
	fflush(stdin);
	gets(x.hoten);
	printf("Nhap luong : ");
	scanf("%f", &x.luong);
}
void xuat1nv(NV x)
{
	printf("%d -- %s -- %.2f  \n", x.manv, x.hoten, x.luong );
}
void nhapn(int &n)
{
	do{
	printf("Nhap so phan tu: ");
	scanf("%d", &n);
	}while(n<=0 || n > 100);
}
void nhapDS(NV a[], int n)
{
	for(int i=0; i<n; i++)
	{
		printf("\nNhap nhan vien thu %d", i+1);
		nhap1nv(a[i]);
	}
}
void xuatDS(NV a[], int n)
{
	for(int i=0; i<n; i++)
	{
		printf("%d : ", i+1);
		xuat1nv(a[i]);
	}
}

void swap(NV &x, NV &y)
{

	NV temp = x;
	x = y;
	y = temp;
}

void selectionSort_luong(NV a[], int n)
{
	for(int i=0; i<n-1; i++)
	{
		int vtmin = i;
		for(int j = i+1; j<n; j++)
			if(a[j].luong < a[vtmin].luong) vtmin = j;
		swap(a[i], a[vtmin]);
	}
}

void insertionSort_luong(NV a[], int n)
{
	int pos;
	NV x;
	for(int i=1; i<n; i++)
	{
		x=a[i];
		pos = i-1;
		while(pos >=0 && a[pos].luong > x.luong)
		{
			a[pos+1] = a[pos];
			pos--;
		}
		a[pos+1] = x;
	}
}
int main()
{
	NV a[MAX];
	int n,x;
	char y[40];
	nhapn(n);
	nhapDS(a,n);
	xuatDS(a,n);
	selectionSort_luong(a,n);
	xuatDS(a,n);
	insertionSort_luong(a,n);
	xuatDS(a,n);
	return 0;
}
