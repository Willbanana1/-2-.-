#include "interval.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	system("chcp 1251>nul"); //Windows code page "Russian"
	printf("������������ ��������\n");
	printf("����� 1\n");
	printf("�����\n");
	Interval * a = Create(0.99, 1.01);
	Print(a, "a = [%.2f .. %.2f]\n");
	Interval * b = Create(1.99, 2.01);
	Print(b, "b = [%.2f .. %.2f]\n");
	Interval * c = Create0();

	Add(a, b, c);
	Interval * control = Create(2.98, 3.02);
	if (!Equals(c, control)) printf("a+b error\n");
	free(control);
	Print(c, "a+b = [%.2f .. %.2f]\n");

	Sub(a, b, c);
	control = Create(-1.02, -0.98);
	if (!Equals(c, control)) printf("a-b error\n");
	free(control);
	Print(c, "a-b = [%.2f .. %.2f]\n");

	Mul(a, b, c);
	control = Create(1.97, 2.03);
	if (!Equals(c, control)) printf("a*b error\n");
	free(control);
	Print(c, "a*b = [%.2f .. %.2f]\n");

	Div(a, b, c);
	control = Create(0.49, 0.51);
	if (!Equals(c, control)) printf("a/b error\n");
	free(control);
	Print(c, "a/b = [%.2f .. %.2f]\n");

	printf("\n����� 2\n");
	printf("��������������, ��� 2*2 = 5\n");
	printf("����� � = 2 +- 1\n");
	free(a);
	a = Create2(2, 1);
	printf("���� �������� � ���� �� ����\n");
	Mul(a, a, c);
	printf("�� ���������\n");
	Print(c, 0);
	printf("\n� ������ ����� ������ : ");
	Print2(c, 0);
	printf("�� ���� 5!\n");


	printf("\n����� 3. �����������\n");
	Input(a, "������� A\n");
	Input(b, "������� �\n");
	FILE * F = fopen("history.txt","w");
	Write(F, a, 0);
	Write(F, b, 0);

	Add(a, b, c);
	printf("a+b="); Print(c, 0); printf("\n");
	Write(F, c, 0);

	Sub(a, b, c);
	printf("a-b="); Print(c, 0); printf("\n");
	Write(F, c, 0);

	Mul(a, b, c);
	printf("a*b="); Print(c, 0); printf("\n");
	Write(F, c, 0);

	Div(a, b, c);
	if (error)
		printf("������ ������� �� 0\n");
	else
	{
	printf("a/b="); Print(c, 0); printf("\n");
	Write(F, c, 0);
	}

	fclose(F);
	F = fopen("history.txt", "r");
	printf("� ����� history.txt ���������:\n");
	while (1)
	{
		Read(F, c);
		if (feof(F)) break;
		Print(c, NULL); printf("\n");
	}
	fclose(F);
	printf("��� ���������� ������� <ENTER>");
	getchar();
}