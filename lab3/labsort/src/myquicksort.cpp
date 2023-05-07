
#include <mysortfunctions.h>

// you only need to mantain the headers. You can create aux funcs, objects, or create a generic quicksort that can work with different functions to select the pivot.

/// the most comon quicksort, with 2 recursive calls
void myquicksort_2recursion_medianOf3(std::vector<int> &v, SortStats &stats)
{
    // you need to set the counting of recursive recursive_calls
    stats.recursive_calls = 1;
    // you need to set the depth = the maximum height of the tree of recursion calls.
    stats.depth_recursion_stack = 1;
    // the tester already knows the size of v and the algorithm name, it already measures time
    // you may set custom1 field if you want to measure anything else.
    stats.custom1 = 2;

    if (v.empty())
    {
        return;
    }
    int n = v.size();
    QuickSort_2recursion(v, stats, 0, n - 1, 1);
} // function myquicksort_2recursion_medianOf3

void Median3(std::vector<int> &v, int l, int r)
{
    int m = (l + r) / 2;
    if (v[l] >= v[r])
    {
        if (v[l] >= v[m])
        {
            if (v[m] >= v[r])
            {
                std::swap(v[m], v[l]);
            }
            else
                std::swap(v[r], v[l]);
        }
    }
    if (v[r] > v[l])
    {
        if (v[r] >= v[m])
        {
            if (v[m] >= v[l])
            {
                std::swap(v[m], v[l]);
            }
        }
        if (v[m] >= v[r])
        {
            std::swap(v[r], v[l]);
        }
    }
}

void QuickSort_2recursion(std::vector<int> &v, SortStats &stats, int min, int max, int profundidade)
{
    if (min < max)
    {
        int p;
        p = Partition_median3(v, stats, min, max);
        QuickSort_2recursion(v, stats, min, p - 1, profundidade + 1);
        QuickSort_2recursion(v, stats, p + 1, max, profundidade + 1);

        stats.recursive_calls += 2;
        if (profundidade > stats.depth_recursion_stack) {
                stats.depth_recursion_stack = profundidade;
        }
    }
}

int Partition_median3(std::vector<int> &v, SortStats &stats, int left, int right)
{
    Median3(v, left, right);
    int pivot = v[left];
    int l = left + 1;
    int r = right;
    while (true)
    {
        while (l < right && v[l] < pivot)
        {
            l++;
        }
        while (r > left && v[r] >= pivot)
        {
            r--;
        }

        if (l >= r)
            break;

        int aux = v[l];
        v[l] = v[r];
        v[r] = aux;
    }
    v[left] = v[r];
    v[r] = pivot;
    return r;
}

/// quicksort with one recursive call
void myquicksort_1recursion_medianOf3(std::vector<int> &v, SortStats &stats)
{
    // you need to set the counting of recursive recursive_calls
    stats.recursive_calls = 1;
    // you need to set the depth = the maximum height of the tree of recursion calls.
    stats.depth_recursion_stack = 1;
    // the tester already knows the size of v and the algorithm name, it already measures time
    // you may set custom1 field if you want to measure anything else.
    stats.custom1 = 2;

    if (v.empty())
    {
        return;
    }
    int n = v.size();
    QuickSort_1recursion(v, stats, 0, n - 1, 1);
} // function myquicksort_1recursion_medianOf3

void QuickSort_1recursion(std::vector<int> &v, SortStats &stats, int min, int max, int profundidade)
{
    while (min < max)
    {
        int p;
        p = Partition_median3(v, stats, min, max);
        if (p - min < max - p)
        {
            QuickSort_1recursion(v, stats, min, p - 1, profundidade + 1);
            min = p + 1;
        }
        else
        {
            QuickSort_1recursion(v, stats, p + 1, max, profundidade + 1);
            max = p - 1;
        }

        stats.recursive_calls += 1;
        if (profundidade > stats.depth_recursion_stack) {
                stats.depth_recursion_stack = profundidade;
        }
    }
}

/// quicksort with fixed pivot
/// be sure to compare with equivalent implementation
/// e.g., if you do 1 recursive call, compare with the 1recursion version
void myquicksort_fixedPivot(std::vector<int> &v, SortStats &stats)
{
    // you need to set the counting of recursive recursive_calls
    stats.recursive_calls = 1;
    // you need to set the depth = the maximum height of the tree of recursion calls.
    stats.depth_recursion_stack = 1;
    // the tester already knows the size of v and the algorithm name, it already measures time
    // you may set custom1 field if you want to measure anything else.
    stats.custom1 = 2;

    if (v.empty())
    {
        return;
    }
    int n = v.size();
    QuickSort_fixed(v, stats, 0, n - 1, 1);
} // myquicksort_fixedPivot

void QuickSort_fixed(std::vector<int> &v, SortStats &stats, int min, int max, int profundidade)
{
    if (min < max)
    {
        int p;
        p = Partition_fixed(v, stats, min, max);
        QuickSort_fixed(v, stats, min, p - 1, profundidade + 1);
        QuickSort_fixed(v, stats, p + 1, max, profundidade + 1);

        stats.recursive_calls += 2;
        if (profundidade > stats.depth_recursion_stack) {
                stats.depth_recursion_stack = profundidade;
        }
    }
}

int Partition_fixed(std::vector<int> &v, SortStats &stats, int left, int right)
{
    int pivot = v[left];
    int l = left + 1;
    int r = right;
    while (true)
    {
        while (l < right && v[l] < pivot)
        {
            l++;
        }
        while (r > left && v[r] >= pivot)
        {
            r--;
        }

        if (l >= r)
            break;

        int aux = v[l];
        v[l] = v[r];
        v[r] = aux;
    }
    v[left] = v[r];
    v[r] = pivot;
    return r;
}
