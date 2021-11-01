#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 100
typedef struct CuonSach
{
	int masach;
	char tensach[40];
	float gia;
}Sach;

void nhap1sach(Sach &x)
{
	printf("\nNhap ma sach : ");
	scanf("%d", &x.masach);
	printf("Nhap ten sach : ");
	fflush(stdin);
	gets(x.tensach);
	printf("Nhap gia : ");
	scanf("%f", &x.gia);
}
void xuat1sach(Sach x)
{
	printf("%d -- %s -- %.2f  \n", x.masach, x.tensach, x.gia );
}
void nhapn(int &n)
{
	do{
	printf("Nhap so phan tu: ");
	scanf("%d", &n);
	}while(n<=0 || n > 100);
}
void nhapDS(Sach a[], int n)
{
	for(int i=0; i<n; i++)
	{
		printf("\nNhap sach thu %d", i+1);
		nhap1sach(a[i]);
	}
}
void xuatDS(Sach a[], int n)
{
	for(int i=0; i<n; i++)
	{
		printf("%d : ", i+1);
		xuat1sach(a[i]);
	}
}
void tim_tt_ma(Sach a[], int n, int x)
{
	int flag = 0;
	printf("\n(Tim tuyen tinh) Nhap ma sach can tim :");
	scanf("%d", &x);
	for(int i=0; i<n; i++)
	{
		if(a[i].masach == x)
		{
			xuat1sach(a[i]);
			flag=1;
			break;
		}
	}
	if(flag == 0) printf("Khong tim thay !!");
}

void swap(Sach &x, Sach &y)
{

	Sach temp = x;
	x = y;
	y = temp;
}

void interchangeSort(Sach a[], int n)
{
	for(int i=0; i<n-1; i++)
		for(int j = i+1; j<n; j++)
			if(a[i].masach > a[j].masach)
				swap(a[i], a[j]);
}

void tim_nhiphan_ma(Sach a[], int n, int x)
{
	int flag = 0, l=0, r=n-1,m;
	printf("\n(Tim nhi phan) Nhap ma sach can tim :");
	scanf("%d", &x);
	while(l<=r)
	{
		m = (l+r)/2;
		if(a[m].masach == x)
		{
			xuat1sach(a[m]);
			flag=1;
			break;
		}

		else if(a[m].masach < x) l=m+1;
		else if(a[m].masach > x) r=m-1;
	}
	if(flag == 0) printf("Khong tim thay !!");
}
void interchangeSort_ten(Sach a[], int n)
{
	int result;
	for(int i=0; i<n-1; i++)
		for(int j = i+1; j<n; j++)
		{
			result = strcmp(a[i].tensach, a[j].tensach);
			if(result > 0)
				swap(a[i], a[j]);
		}

}
void tim_tt_ten(Sach a[], int n, char x[40])
{
	int flag = 0, result;
	printf("\n(Tim tuyen tinh) Nhap ten sach can tim :");
	fflush(stdin);
	gets(x);
	for(int i=0; i<n; i++)
	{
		result = strcmp(a[i].tensach, x);
		if(result == 0)
		{
			xuat1sach(a[i]);
			flag=1;
			break;
		}
	}
	if(flag == 0) printf("Khong tim thay !!");
}

void tim_nhiphan_ten(Sach a[], int n, char x[40])
{
	int flag = 0, l=0, r=n-1, m, result;
	printf("\n(Tim nhi phan) Nhap ten sach can tim :");
	fflush(stdin);
	gets(x);
	while(l<=r)
	{
		m = (l+r)/2;
		result = strcmp(a[m].tensach, x);
		if(result == 0)
		{
			xuat1sach(a[m]);
			flag=1;
			break;
		}

		else if(result < 0) l=m+1;
		else if(result > 0) r=m-1;
	}
	if(flag == 0) printf("Khong tim thay !!");
}

Sach timMax(Sach a[], int n)
{
	Sach max=a[0];
	for(int i=0; i<n; i++)
	{
		if(max.gia < a[i].gia)
		{
			max=a[i];
		}
	}
	return max;
}

void sachgiacaonhat(Sach a[], int n)
{
	Sach max = timMax(a,n);
	for(int i=0; i<n; i++)
	{
		if(max.gia == a[i].gia)
		{
			xuat1sach(a[i]);
		}
	}
}
int main()
{
	Sach a[MAX];
	int n,x;
	char y[40];
	nhapn(n);
	nhapDS(a,n);
	xuatDS(a,n);
	//Tim tuyen tinh theo ma
	tim_tt_ma(a,n,x);
	//Sap xep mang theo ma
	interchangeSort(a,n);
	printf("\nMang sau khi sap xep theo ma\n");
	xuatDS(a,n);
	//Tim nhi phan theo ma
	tim_nhiphan_ma(a,n,x);
	//Tim tuyen tinh theo ten
	tim_tt_ten(a,n,y);
	//Sap xep mang theo ten
	interchangeSort_ten(a,n);
	printf("\n\nMang sau khi sap xep theo ten\n");
	xuatDS(a,n);
	//Tim nhi phan theo ten
	tim_nhiphan_ten(a,n,y);
	//Tim sach gia cao nhat
	printf("\nSach gia cao nhat la :");
	sachgiacaonhat(a,n);
	return 0;
}
