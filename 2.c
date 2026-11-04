#include <stdio.h>
#include <math.h>

#define N 100
#define A_BEG (-5.0)   // начало интервала
#define B_END 5.0      // конец интервала

// Функция, по которой вычисляются значения
double f(double x)
{
    return sin(x) + 0.5 * x;
}

// Вычисление значения i-го элемента массива
double calc_element(int i)
{
    double h = (B_END - A_BEG) / (N - 1);   // шаг по x
    double x = A_BEG + i * h;
    return f(x);
}

int main(void)
{
    double arr[N];
    double sum_pos = 0.0, sum_neg = 0.0;
    int cnt_pos = 0, cnt_neg = 0;

    // Заполнение массива
    for (int i = 0; i < N; i++)
        arr[i] = calc_element(i);

    // Накопление сумм и подсчёт количества
    for (int i = 0; i < N; i++)
    {
        if (arr[i] > 0)
        {
            sum_pos += arr[i];
            cnt_pos++;
        }
        else if (arr[i] < 0)
        {
            sum_neg += arr[i];
            cnt_neg++;
        }
    }

    // Среднее положительных
    double avg_pos = (cnt_pos > 0) ? sum_pos / cnt_pos : 0.0;

    // Вывод результата одной строкой
    printf("Массив: arr | сумма(+) = %.4f | сумма(-) = %.4f | "
           "кол-во(+) = %d | кол-во(-) = %d | среднее(+) = %.4f\n",
           sum_pos, sum_neg, cnt_pos, cnt_neg, avg_pos);

    return 0;
}
