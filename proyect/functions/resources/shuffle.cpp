#include <bits/stdc++.h>

void shuffle(int a[], int n)
{
  for (int i = 0; i < n; i++)
    std::swap(a[i], a[rand() % n]);
}