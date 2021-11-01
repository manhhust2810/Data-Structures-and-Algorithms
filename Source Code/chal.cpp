// A C++ program to check if two given line segments intersect
#include <iostream>
using namespace std;

struct Point
{
    int x;
    int y;
};
struct node
{
    Point info;
    node *pNext;
};
struct Path
{
    node *pHead;
    node *pTail;
};

void CreateList(Path &l)
{
    l.pHead = NULL;
    l.pTail = NULL;
}
node *CreateNode(Point x)
{
    node *pNew = new node;

    pNew->pNext = NULL;
    pNew->info = x;
    return pNew;
}
void AddTail(Path &l, node *p)
{
    if (l.pHead == NULL)
    {
        l.pHead = p;
        l.pTail = l.pHead;
    }
    else
    {
        l.pTail->pNext = p;
        l.pTail = p;
    }
}
void nhap(Path &L)
{
    while (1)
    {
        cout << "Moi nhap diem cua list";
        Point x;
        cin >> x.x;
        cin >> x.y;
        if (x.x == 69)
        {
            cout << "Ket thuc nhap list";
            break;
        }
        node *P = CreateNode(x);
        AddTail(L, P);
    }
}
void xuat(Path L)
{
    node *P = L.pHead;
    while (P != NULL)
    {

        cout << endl
             << "{" << P->info.x << ";" << P->info.y << "}";
        P = P->pNext;
    }
}
bool onSegment(Point p, Point q, Point r)
{
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
        return true;

    return false;
}

int orientation(Point p, Point q, Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);

    if (val == 0)
        return 0;

    return (val > 0) ? 1 : 2;
}
// ham kiếm giao điểm copy trên mạng để test cho nhanh :v
Point giaoDiem(Point A, Point B, Point C, Point D)
{
    // Line AB represented as a1x + b1y = c1
    double a1 = B.y - A.y;
    double b1 = A.x - B.x;
    double c1 = a1 * (A.x) + b1 * (A.y);

    // Line CD represented as a2x + b2y = c2
    double a2 = D.y - C.y;
    double b2 = C.x - D.x;
    double c2 = a2 * (C.x) + b2 * (C.y);

    double determinant = a1 * b2 - a2 * b1;

    double x = (b2 * c1 - b1 * c2) / determinant;
    double y = (a1 * c2 - a2 * c1) / determinant;
    cout << endl
         << "Giao diem la "
         << "{" << x << ";" << y << "}";
}
bool giaoDiem(Path l1, Path l2)
{
    node *p1 = l1.pHead;
    node *p2 = l2.pHead;
    while (l1.pHead != NULL)
    {
        while (l2.pHead != NULL)
        {
            int o1 = orientation(p1->info, p1->pNext->info, p2->info);
            int o2 = orientation(p1->info, p1->pNext->info, p2->pNext->info);
            int o3 = orientation(p2->info, p2->pNext->info, p1->info);
            int o4 = orientation(p2->info, p2->pNext->info, p1->pNext->info);

            //  case bình thường
            if (o1 != o2 && o3 != o4)
            {
                giaoDiem(p1->info, p1->pNext->info, p2->info, p2->pNext->info);
                return true;
            }

            //  cases bất thường (điểm path này thuộc pa)
            if (o1 == 0 && onSegment(p1->info, p2->info, p1->pNext->info))
            {
                giaoDiem(p1->info, p1->pNext->info, p2->info, p2->pNext->info);
                return true;
            }

            if (o2 == 0 && onSegment(p1->info, p2->pNext->info, p1->pNext->info))
            {
                giaoDiem(p1->info, p1->pNext->info, p2->info, p2->pNext->info);
                return true;
            }

            if (o3 == 0 && onSegment(p2->info, p1->info, p2->pNext->info))
            {
                giaoDiem(p1->info, p1->pNext->info, p2->info, p2->pNext->info);
                return true;
            }
            if (o4 == 0 && onSegment(p2->info, p1->pNext->info, p2->pNext->info))
            {
                giaoDiem(p1->info, p1->pNext->info, p2->info, p2->pNext->info);
                return true;
            }
            if (p2->pNext->pNext == NULL)
                break;
            p2 = p2->pNext;
        }
        if (p1->pNext->pNext == NULL)
            break;
        p1 = p1->pNext;
    }
    return false;
}

int main()
{

    Path l1, l2;
    int count = 0;
    CreateList(l1);
    CreateList(l2);
    nhap(l1);
    nhap(l2);
    xuat(l1);
    xuat(l2);
    cout << endl;
    giaoDiem(l1, l2) ? cout << endl
                            << "Yes" << endl
                     : cout << endl
                            << "No" << endl;
    return 0;
}