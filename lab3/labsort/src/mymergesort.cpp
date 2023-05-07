
#include <mysortfunctions.h>

std::vector<int> aux; // vetor auxiliar global
void mymergesort_recursive(std::vector<int> &v, SortStats &stats)
{

    // you need to set the counting of recursive recursive_calls
    stats.recursive_calls = 1;
    // you need to set the depth = the maximum height of the tree of recursion calls.
    stats.depth_recursion_stack = 1;
    // the tester already knows the size of v and the algorithm name, it already measures time
    // you may set custom1 field if you want to measure anything else.
    stats.custom1 = 2;

    int n = v.size();
    aux.resize(n);
    MergeSort(v, stats, 0, n - 1, 1);
}

void MergeSort(std::vector<int> &v, SortStats &stats, int i, int f, int profundidade)
{
    if (i < f)
    {
        int m = (i + f) / 2;
        MergeSort(v, stats, i, m, profundidade + 1);
        MergeSort(v, stats, m + 1, f, profundidade + 1);
        merge(v, stats, i, m, f);
    }

    if (profundidade > stats.depth_recursion_stack)
    {
        stats.depth_recursion_stack = profundidade;
    }

    stats.recursive_calls++;
}

void merge(std::vector<int> &v, SortStats &stats, int i, int m, int f)
{

    int i1 = i;
    int i2 = i;
    int i3 = m + 1;
    while (i2 <= m && i3 <= f)
    {
        if (v[i2] < v[i3])
        {
            aux[i1++] = v[i2++];
        }
        else
            aux[i1++] = v[i3++];
    }
    while (i2 <= m)
    {
        aux[i1++] = v[i2++];
    }
    while (i3 <= f)
    {
        aux[i1++] = v[i3++];
    }
    for (int j = i; j <= f; j++)
    {
        v[j] = aux[j];
    }
}

void mymergesort_iterative(std::vector<int> &v, SortStats &stats)
{
    // you need to set the counting of recursive recursive_calls
    stats.recursive_calls = 0;
    // you need to set the depth = the maximum height of the tree of recursion calls.
    stats.depth_recursion_stack = 0;
    // the tester already knows the size of v and the algorithm name, it already measures time
    // you may set custom1 field if you want to measure anything else.
    stats.custom1 = 2;

    int n = v.size();
    aux.resize(n);
    MergeSort_iter(v, stats, 0, n - 1, 1);
}

void MergeSort_iter(std::vector<int> &v, SortStats &stats, int i, int f, int profundidade)
{

    int p, r, m;
    int b = 1;
    while (b < f)
    {
        p = i;
        while (p + b <= f)
        {
            r = std::min(f, p - 1 + 2 * b);
            m = p + b - 1;
            merge(v, stats, p, m, r);
            p += 2 * b;
        }
        b *= 2;
    }
}
