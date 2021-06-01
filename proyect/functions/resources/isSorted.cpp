bool isSorted(int a[], int n)
{
  while (--n > 1)
    if (a[n] < a[n - 1])
      return false;
  return true;
}