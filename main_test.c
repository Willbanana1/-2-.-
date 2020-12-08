#include "interval.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	system("chcp 1251>nul"); //Windows code page "Russian"
	printf("Интервальные операции\n");
	printf("Часть 1\n");
	printf("Тесты\n");
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

	printf("\nЧасть 2\n");
	printf("Доказательство, что 2*2 = 5\n");
	printf("Пусть А = 2 +- 1\n");
	free(a);
	a = Create2(2, 1);
	printf("Если умножить А само на себя\n");
	Mul(a, a, c);
	printf("То получится\n");
	Print(c, 0);
	printf("\nв другой форме записи : ");
	Print2(c, 0);
	printf("то есть 5!\n");


	printf("\nЧасть 3. Калькулятор\n");
	Input(a, "Введите A\n");
	Input(b, "Введите В\n");
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
		printf("Ошибка деления на 0\n");
	else
	{
	printf("a/b="); Print(c, 0); printf("\n");
	Write(F, c, 0);
	}

	fclose(F);
	F = fopen("history.txt", "r");
	printf("В файле history.txt сохранено:\n");
	while (1)
	{
		Read(F, c);
		if (feof(F)) break;
		Print(c, NULL); printf("\n");
	}
	fclose(F);
	printf("Для завершения нажмите <ENTER>");
	getchar();
}