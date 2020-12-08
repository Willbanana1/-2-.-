#pragma once
#include "interval.h"

//Создать
struct Interval * Create(double low, double high)
{
	if (low > high) return Create(high, low);
	Interval * result = malloc(sizeof(Interval)); // relust - указатель, malloc - побайтовое выдиление памяти для указателя. Чтобы задать границы
	result->low = low;  // Ссылка
	result->high = high;
	return result;
}

struct Interval * Create0()
{
	return Create(0, 0);
}

//Сравнить два интервалана равенство
int Equals(Interval * a, Interval * b)
{
	//Сравнение с точностью epsilon
	if (fabs(a->low - b->low) > epsilon) return 0; // fabs-числа с плавающей запятой
	if (fabs(a->high - b->high)> epsilon) return 0;
	return 1;
}

//Создать по значению и погрешности
struct Interval * Create2(double center, double deviation)
{
	return Create(center - deviation, center + deviation);
}

//Выбрать минимум и максимум из всех вариантов
void Select(double p[4], Interval * Result)
{
	int i;
	Result->low = Result->high = p[0];
	for (i = 1; i < 4; i++)
	{
		if (p[i] < Result->low) Result->low = p[i];
		if (p[i] > Result->high) Result->high = p[i];
	}
}

//Сложение
void Add(struct Interval *A, struct Interval *B, struct Interval * Result)
{
	//Массив с инициализацией
	double temp[4] =
	{
		A->low + B->low,
		A->low + B->high,
		A->high + B->low,
		A->high + B->high,
	};
	Select(temp, Result);
};

//Вычитание
void Sub(struct Interval *A, struct Interval *B, struct Interval * Result)
{
	double temp[4] =
	{
		A->low - B->low,
		A->low - B->high,
		A->high - B->low,
		A->high - B->high,
	};
	Select(temp, Result);
};

//Умножение
void Mul(struct Interval *A, struct Interval *B, struct Interval * Result)
{
	double temp[4] =
	{
		A->low * B->low,
		A->low * B->high,
		A->high * B->low,
		A->high * B->high,
	};
	Select(temp, Result);
};

//Деление
void Div(struct Interval *A, struct Interval *B, struct Interval * Result)
{
	//Проверка: B не должно включать 0. Иначе может быть переполнение
	error = 1;
	if (B->low * B->high <= 0) return;
	error = 0;
	{
		double temp[4] =
		{
			A->low / B->low,
			A->low / B->high,
			A->high / B->low,
			A->high / B->high,
		};
		Select(temp, Result);
	}
};

//из текстового файла
void Read(FILE * F, Interval * Result)
{
	fscanf(F, "%lf %lf", &Result->low, &Result->high);
}

//В текстовый файл
void Write(FILE * F, Interval * Result, char * Format)
{
	if (Format == NULL)
		fprintf(F, "%.6f %.6f\n", Result->low, Result->high);
	else
		fprintf(F, Format, Result->low, Result->high);
}

//На консоль
void Print(Interval * Result, char * Format)
{
	if (Format == NULL)
		printf("[%.6f .. %.6f]", Result->low, Result->high);
	else
		printf(Format, Result->low, Result->high);
}

//Как среднее
void Print2(Interval * Result, char * Format)
{
	if (Format == NULL)
		printf("[%.6f +- %.6f]\n", (Result->low + Result->high) / 2, (Result->high - Result->low) / 2);
	else
		printf(Format, (Result->low + Result->high) / 2, (Result->high - Result->low) / 2);
}

//ввести
void Input(Interval * Result, char * Prompt)
{
	if (Prompt) printf(Prompt);
	printf("low = "); scanf("%lf", &Result->low);
	printf("high= "); scanf("%lf", &Result->high);
}

const double epsilon = 0.01;
int error;