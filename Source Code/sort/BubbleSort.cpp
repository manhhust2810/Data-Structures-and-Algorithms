



void BubbleSort(int a[], int n){
  for(int i=0; i<n-1; i++)
    for(int j=n-1; j<i;i--)
      if(a[j-1]>a[j])
        swap(a[j-1],a[j]);
}

void InterchangeSort(int a[], int n){
  for(int i = 0; i<n-1; i++)
    for(int j = i+1; j < n;j++)
      a[i]>a[j];
}

void selectionSort(int a[], int n){
  for(int i=0; i<n-1; i++)
   int vtmin = i;
    for(int j=i+1; j<n; j++)
      if(a[j] < a[vtmin]) vtmin = j;
    swap(a[vtmin], a[i])
}

void insertionSort(int a[], int n) {
  int x,pos;
  for(int i=1; i<n; i++){
    x=a[i], pos=i-1;
    while(pos>=0 && a[pos]>x)
    {
      a[pos+1] = a[pos];
      pos--;
    }
    a[pos+1] = x;
  }
}
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element

    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        { 
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

/* The main function that implements QuickSort
 arr[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index */
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
