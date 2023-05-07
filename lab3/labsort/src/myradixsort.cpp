
#include <mysortfunctions.h>

void myradixsort(std::vector<int> &v, SortStats &stats)
{
    // you need to set the counting of recursive recursive_calls
    stats.recursive_calls = 0;
    // you need to set the depth = the maximum height of the tree of recursion calls.
    stats.depth_recursion_stack = 0;
    // the tester already knows the size of v and the algorithm name, it already measures time
    // you may set custom1 field if you want to measure anything else.
    stats.custom1 = 2;

    if (v.empty())
    {
        return;
    }
    int n = v.size();
    // int base = 2;
    int d = 0;                                             // número de dígitos do maior número
    int max_value = *std::max_element(v.begin(), v.end()); // encontra o maior valor em v
    while (max_value != 0)
    {
        max_value /= 2;
        d++;
    }

    std::queue<int> q[2];
    for (int i = 0, factor = 0; i < d; i++, factor ++)
    {
        // distribui os elementos de v nas filas de acordo com o dígito correspondente
        for (int j = 0; j < n; j++)
        {
            // int digito = (v[j]>>factor) & 1;
            q[(v[j]>>factor) & 1].push(v[j]);
        }
        // coleta os elementos das filas na ordem correta
        int k = 0;
        for (int j = 0; j < 2; j++)
        {
            while (!q[j].empty())
            {
                v[k++] = q[j].front();
                q[j].pop();
            }
        }
    }
}
