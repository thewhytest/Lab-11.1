#include <stdio.h>

int main(void)
{
    int n;
    printf("Введите количество элементов n: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Некорректный размер массива\n");
        return 1;
    }

    int a[n];   // массив переменной длины (C99)

    for (int i = 0; i < n; i++)
    {
        printf("a[%d] = ", i + 1);
        scanf("%d", &a[i]);
    }

    // Поиск индексов минимального и максимального элементов
    int imin = 0, imax = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i] < a[imin]) imin = i;
        if (a[i] > a[imax]) imax = i;
    }

    // Границы: между ними, независимо от порядка
    int left  = (imin < imax) ? imin : imax;
    int right = (imin < imax) ? imax : imin;

    // Сумма и количество элементов строго между left и right
    long sum = 0;
    int cnt = 0;
    for (int i = left + 1; i < right; i++)
    {
        sum += a[i];
        cnt++;
    }

    if (cnt == 0)
        printf("Между минимальным (индекс %d) и максимальным (индекс %d) элементами нет других элементов\n",
               imin + 1, imax + 1);
    else
        printf("Среднее арифметическое элементов между min и max: %.2f\n",
               (double)sum / cnt);

    return 0;
}
