#include<stdio.h>
#include<math.h>
void merge(long int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(long int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

int binarySearch(long int arr[], int l, int r, int x)
{
  if (r < l)
        return -1;
    int mid = l + (r - l) / 2;
    if (arr[mid] == x)
        return mid;
    if (arr[mid] > x)
        return binarySearch(arr, l, mid - 1, x);
    return binarySearch(arr, mid + 1, r, x);
}

int countOccurrences(long int arr[], int n, int x)
{
    int ind = binarySearch(arr, 0, n - 1, x);

    int count = 1;
    int left = ind - 1;
    while (left >= 0 && arr[left] == x)
        count++, left--;

    int right = ind + 1;
    while (right < n && arr[right] == x)
        count++, right++;

    return count;
}

int main()
{
  int t;
  scanf("%d",&t);
  while(t--)
  {
    int n;
    float k;
    scanf("%d %f",&n,&k);
    long int a[n];
    for (int i=0;i<n;i++)
    {
      scanf("%ld",&a[i]);
    }
    int array[2000]={0};
    for (int i=0;i<n;i++)
    {
      array[a[i]-1]++;
    }
    
  }
}
