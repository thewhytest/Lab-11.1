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

    // Поиск первого и второго нулевых элементов
    int first = -1, second = -1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
        {
            if (first == -1)
                first = i;
            else
            {
                second = i;
                break;
            }
        }
    }

    if (second == -1)
    {
        printf("В массиве меньше двух нулевых элементов\n");
        return 0;
    }

    if (second - first == 1)
    {
        printf("Между первым и вторым нулями нет элементов\n");
        return 0;
    }

    // Произведение элементов строго между нулями
    long long prod = 1;
    for (int i = first + 1; i < second; i++)
        prod *= a[i];

    printf("Произведение элементов между первым и вторым нулями: %lld\n", prod);

    return 0;
}
