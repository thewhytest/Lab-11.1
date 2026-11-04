#include <stdio.h>

#define N 10

int main(void)
{
    float A[N];      // исходный массив
    float B[N];      // преобразованный массив
    float temp;
    float sum = 0.0f;

    // 1. Ввод с консоли
    for (int i = 0; i < N; i++)
    {
        printf("a[%d] = ", i + 1);
        scanf("%f", &temp);
        A[i] = temp;
    }

    // 2. Преобразование: обнулить отрицательные элементы
    for (int i = 0; i < N; i++)
    {
        if (A[i] < 0)
            B[i] = 0;
        else
            B[i] = A[i];
    }

    // 3. Вывод таблицы
    printf("\n| %-6s | %-17s | %-14s |\n", "индекс", "исходное значение", "новое значение");
    printf("|--------|-------------------|----------------|\n");
    for (int i = 0; i < N; i++)
    {
        printf("| %-6d | %-17.2f | %-14.2f |\n", i + 1, A[i], B[i]);
    }

    // 4. Среднее арифметическое
    for (int i = 0; i < N; i++)
        sum += B[i];

    printf("\nСреднее арифметическое: %.2f\n", sum / N);

    return 0;
}
