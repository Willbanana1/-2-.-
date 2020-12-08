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
extern const double epsilon;  //�������� �������� ��������


//�������
struct Interval * Create(double low, double high);
struct Interval * Create0();

//�������� ��� ��������� �� ���������
int Equals(Interval * a, Interval * b);

//������� �� �������� �������� � �����������
struct Interval * Create2(double center, double deviation);

//��������
void Add(struct Interval *A, struct Interval *B, struct Interval * Result);

//���������
void Sub(struct Interval *A, struct Interval *B, struct Interval * Result);

//���������
void Mul(struct Interval *A, struct Interval *B, struct Interval * Result);

//�������
void Div(struct Interval *A, struct Interval *B, struct Interval * Result);

//�� ���������� �����
void Read(FILE * F, Interval * Result);

//� ��������� ����
void Write(FILE * F, Interval * Result, char * Format);

//�� �������
void Print(Interval * Result, char * Format);

//��� �������
void Print2(Interval * Result, char * Format);

//������
void Input(Interval * Result, char * Prompt);

int error;
