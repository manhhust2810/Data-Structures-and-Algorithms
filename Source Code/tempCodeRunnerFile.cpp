struct node
{
    int info;
    node *pNext;
};
struct List
{
    node *pHead;
    node *pTail;
};
void CreateList(List &l)
{
    l.pHead = NULL;
    l.pTail = NULL;
}
void SortIncrease(List &l);

//Your code
node *CreateNode(int x)
{
    node *pNew = new node;

    pNew->pNext = NULL;
    pNew->info = x;
    return pNew;
}

void AddTail(List &l, node *p)
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
void nhap(List &L)
{
    while (1)
    {
        int x;
        cin >> x;
        if (x == 0)
            break;
        node *P = CreateNode(x);
        AddTail(L, P);
    }
}
void xuat(List L)
{
    node *P = L.pHead;
    while (P != NULL)
    {
        cout << P->info << " ";
        P = P->pNext;
    }
}
node *Merge(node *h1, node *h2)
{
    node *t1 = new node;
    node *t2 = new node;
    node *temp = new node;

    if (h1 == NULL)
        return h2;

    if (h2 == NULL)
        return h1;

    t1 = h1;

    while (h2 != NULL)
    {
        t2 = h2;

        h2 = h2->pNext;
        t2->pNext = NULL;

        if (h1->info > t2->info)
        {
            t2->pNext = h1;
            h1 = t2;
            t1 = h1;
            continue;
        }

    flag:
        if (t1->pNext == NULL)
        {
            t1->pNext = t2;
            t1 = t1->pNext;
        }
        else if ((t1->pNext)->info <= t2->info)
        {
            t1 = t1->pNext;
            goto flag;
        }
        else
        {
            temp = t1->pNext;
            t1->pNext = t2;
            t2->pNext = temp;
        }
    }

    return h1;
}
bool tang(List l)
{

    for (node *t = l.pHead; t->pNext != NULL; t = t->pNext)
    {
        if (t->info > t->pNext->info)

            return false;
    }
    return true;
}
void MergeSort(node **head)
{
    node *first = new node;
    node *second = new node;
    node *temp = new node;
    first = *head;
    temp = *head;

    if (first == NULL || first->pNext == NULL)
    {
        return;
    }
    else
    {
        while (first->pNext != NULL)
        {
            first = first->pNext;
            if (first->pNext != NULL)
            {
                temp = temp->pNext;
                first = first->pNext;
            }
        }
        second = temp->pNext;
        temp->pNext = NULL;
        first = *head;
    }

    MergeSort(&first);
    MergeSort(&second);

    *head = Merge(first, second);
}
void SortIncrease(List &l)
{
    MergeSort(&l.pHead);
}
int main()
{
    List l;
    CreateList(l);
    nhap(l);
    if (l.pHead == NULL)
        cout << "Danh sach rong.";
    else
    {
        int check = tang(l);
        int x = 0;
        if (check == true)
            cin >> x;
        cout << "Danh sach vua nhap la: ";
        xuat(l);
        if (l.pHead->pNext == NULL)
        {
            check = false;
            cout << endl
                 << "Danh sach khong tang.";
        }
        if (check == true)
        {
            node *t = CreateNode(x);
            AddTail(l, t);
            cout << endl
                 << "Danh sach sau khi chen so " << x << " la: ";
            SortIncrease(l);
            xuat(l);
        }
        if (tang(l) == false)
        {
            cout << endl
                 << "Danh sach khong tang.";
        }
    }
    return 0;
}