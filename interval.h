#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct Interval
{
	double low;
	double high;
} Interval;

extern int error;
extern const double epsilon;  //Точность проверки значений


//Создать
struct Interval * Create(double low, double high);
struct Interval * Create0();

//Сравнить два интервала на равенство
int Equals(Interval * a, Interval * b);

//Создать по среднему значению и погрешности
struct Interval * Create2(double center, double deviation);

//Сложение
void Add(struct Interval *A, struct Interval *B, struct Interval * Result);

//Вычитание
void Sub(struct Interval *A, struct Interval *B, struct Interval * Result);

//Умножение
void Mul(struct Interval *A, struct Interval *B, struct Interval * Result);

//Деление
void Div(struct Interval *A, struct Interval *B, struct Interval * Result);

//из текстового файла
void Read(FILE * F, Interval * Result);

//В текстовый файл
void Write(FILE * F, Interval * Result, char * Format);

//На консоль
void Print(Interval * Result, char * Format);

//Как среднее
void Print2(Interval * Result, char * Format);

//ввести
void Input(Interval * Result, char * Prompt);

int error;
