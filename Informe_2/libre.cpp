#include <bits/stdc++.h>

std::vector<int> generate_vector(int V)
{
    std::vector<int> a(V);
    for (int i = 0; i < V; ++i)
        a[i] = (rand() % V) * (2 * (rand() % 2) - 1);
    return a;
}

void replace(int tam, std::vector<int> &a)
{
    for (int i = 0; i < a.size(); ++i)
    {
        a[i] = (rand() % tam) * (2 * (rand() % 2) - 1);
    }
}

template <typename T>
void print_vec(std::vector<T> t)
{
    for (auto i : t)
        std::cout << i << ",";
    std::cout << "\n";
}

double insertionSort(std::vector<int> &a)
{
    unsigned t0, t1;
    t0 = clock();

    for (int p = 1; p < a.size(); ++p)
    {
        int tmp = std::move(a[p]);
        int j;
        for (j = p; j > 0 && tmp < a[j - 1]; --j)
            a[j] = std::move(a[j - 1]);
        a[j] = std::move(tmp);
    }

    t1 = clock();
    double time = 1000L * (double(t1 - t0) / CLOCKS_PER_SEC);
    return time;
}

void Quick(std::vector<int> items)
{
    if (items.size() > 1)
    {
        std::vector<int> smaller;
        std::vector<int> same;
        std::vector<int> larger;
        auto chosenItem = items[items.size() / 2];

        for (auto &i : items)
        {
            if (i < chosenItem)
                smaller.push_back(std::move(i));
            else if (chosenItem < i)
                larger.push_back(std::move(i));
            else
                same.push_back(std::move(i));
        }

        Quick(smaller);
        Quick(larger);

        std::move(begin(smaller), end(smaller), begin(items));
        std::move(begin(same), end(same), begin(items) + smaller.size());
        std::move(begin(larger), end(larger), end(items) - larger.size());
    }
}

double Quick_init(std::vector<int> it)
{
    unsigned t0, t1;
    t0 = clock();
    Quick(it);
    double time = 1000L * (double(t1 - t0) / CLOCKS_PER_SEC);
    return time;
}

void mergeSort(std::vector<int> left, std::vector<int> right, std::vector<int> bars)
{
    int nL = left.size();
    int nR = right.size();
    int i = 0, j = 0, k = 0;

    while (j < nL && k < nR)
    {
        if (left[j] < right[k])
        {
            bars[i] = left[j];
            j++;
        }
        else
        {
            bars[i] = right[k];
            k++;
        }
        i++;
    }
    while (j < nL)
    {
        bars[i] = left[j];
        j++;
        i++;
    }
    while (k < nR)
    {
        bars[i] = right[k];
        k++;
        i++;
    }
}

void merge(std::vector<int> bar)
{
    if (bar.size() <= 1)
        return;
    int mid = bar.size() / 2;
    std::vector<int> left;
    std::vector<int> right;

    for (size_t j = 0; j < mid; j++)
        left.push_back(bar[j]);
    for (size_t j = 0; j < (bar.size()) - mid; j++)
        right.push_back(bar[mid + j]);

    merge(left);
    merge(right);
    mergeSort(left, right, bar);
}

double merge_init(std::vector<int> bar)
{
    unsigned t0, t1;
    t0 = clock();
    merge(bar);
    t1 = clock();
    double time = 1000L * (double(t1 - t0) / CLOCKS_PER_SEC);
    return time;
}

int get_max(std::vector<int> v)
{
    int max = v[0], cont = 0;
    for (auto i = 1; i < v.size(); ++i)
    {
        if (v[i] > max)
        {
            max = v[i];
            ++cont;
        }
    }
    return cont;
}

bool comp(int a, int b)
{
    return (a < b);
}

void semiordenar(std::vector<int> &v)
{
    std::vector<int>::iterator ip;
    std::partial_sort(v.begin(), v.begin() + 1, v.end(), comp);
}

//fibonacci recursivo
int fib_rec(int n)
{
    if (n <= 1)
        return n;
    return fib_rec(n - 1) + fib_rec(n - 2);
}

//fibonacci iterativo
int fib_it(int n)
{
    if (n <= 1)
        return n;

    int x1 = 0, x2 = 1, temp = 0;
    int *_x1 = &x1;
    int *_x2 = &x2;
    int *_temp = &temp;

    for (int i = 2; i <= n; ++i)
    {
        temp = x1 + x2;
        *_x1 = x2;
        *_x2 = temp;
        *_temp = 0;
    }

    return x2;
}

//fibonacci double
double fib_rec_dou(double n)
{
    if (n <= 1)
        return n;
    return fib_rec(n - 1.0) + fib_rec(n - 2.0);
}

//fibonacci double it
double fib_it_rec(double n)
{
    if (n <= 1)
        return n;

    double x1 = 0, x2 = 1, temp = 0;
    double *_x1 = &x1;
    double *_x2 = &x2;
    double *_temp = &temp;

    for (int i = 2; i <= n; ++i)
    {
        temp = x1 + x2;
        *_x1 = x2;
        *_x2 = temp;
        *_temp = 0;
    }

    return x2;
}
