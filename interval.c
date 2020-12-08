#pragma once
#include "interval.h"

//�������
struct Interval * Create(double low, double high)
{
	if (low > high) return Create(high, low);
	Interval * result = malloc(sizeof(Interval)); // relust - ���������, malloc - ���������� ��������� ������ ��� ���������. ����� ������ �������
	result->low = low;  // ������
	result->high = high;
	return result;
}

struct Interval * Create0()
{
	return Create(0, 0);
}

//�������� ��� ����������� ���������
int Equals(Interval * a, Interval * b)
{
	//��������� � ��������� epsilon
	if (fabs(a->low - b->low) > epsilon) return 0; // fabs-����� � ��������� �������
	if (fabs(a->high - b->high)> epsilon) return 0;
	return 1;
}

//������� �� �������� � �����������
struct Interval * Create2(double center, double deviation)
{
	return Create(center - deviation, center + deviation);
}

//������� ������� � �������� �� ���� ���������
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

//��������
void Add(struct Interval *A, struct Interval *B, struct Interval * Result)
{
	//������ � ��������������
	double temp[4] =
	{
		A->low + B->low,
		A->low + B->high,
		A->high + B->low,
		A->high + B->high,
	};
	Select(temp, Result);
};

//���������
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

//���������
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

//�������
void Div(struct Interval *A, struct Interval *B, struct Interval * Result)
{
	//��������: B �� ������ �������� 0. ����� ����� ���� ������������
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

//�� ���������� �����
void Read(FILE * F, Interval * Result)
{
	fscanf(F, "%lf %lf", &Result->low, &Result->high);
}

//� ��������� ����
void Write(FILE * F, Interval * Result, char * Format)
{
	if (Format == NULL)
		fprintf(F, "%.6f %.6f\n", Result->low, Result->high);
	else
		fprintf(F, Format, Result->low, Result->high);
}

//�� �������
void Print(Interval * Result, char * Format)
{
	if (Format == NULL)
		printf("[%.6f .. %.6f]", Result->low, Result->high);
	else
		printf(Format, Result->low, Result->high);
}

//��� �������
void Print2(Interval * Result, char * Format)
{
	if (Format == NULL)
		printf("[%.6f +- %.6f]\n", (Result->low + Result->high) / 2, (Result->high - Result->low) / 2);
	else
		printf(Format, (Result->low + Result->high) / 2, (Result->high - Result->low) / 2);
}

//������
void Input(Interval * Result, char * Prompt)
{
	if (Prompt) printf(Prompt);
	printf("low = "); scanf("%lf", &Result->low);
	printf("high= "); scanf("%lf", &Result->high);
}

const double epsilon = 0.01;
int error;