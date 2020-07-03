/*
	LameKing.
	Лабораторная работа №1 по нахождению
	вектора пути Хромого короля по полю из
	прямоугольников.
	Ширкунов А.В.
	ИВТ - 13БО
*/
/*тесты
работает вверх
40
15 5
1 1

работает вниз
7
2 1
6 3

работает на месте
1 1
1 1
1 1

не работает
-1/ы
15 2
13 7

15
16 14
12 11
*/
#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <malloc.h>
#include "LameKing.h"
void main()
{
	printf("Laboratory work #1 <LameKing>\n");
	printf("on finding vector of the Lame king's path through\n");
	printf("on finding vector made of rectangles.\n");
	printf("Shirkunov A.V.\n");
	printf("IVT - 13BO\n");
	//Кол-во строк, текущая строка, текущий столбец, нужная строка, нужный столбец, кол-во элементов.
	int rows, CurRow, CurCol, NeedRow, NeedCol, NumberEl=0;
	int* counter;
	counter = &NumberEl;
	int* vect;//Вектор.
	int**field = NULL;//Поле.
	printf("Number of rows: ");
	if (scanf("%d", &rows, "\n") < 0) return;

	field = CreateField(rows, field);
	InputField(rows, field);

	printf("Current position: ");
	if (scanf("%d", &CurRow) < 0) return;
	if (scanf("%d", &CurCol) < 0) return;
	printf("Need position: ");
	if (scanf("%d", &NeedRow) < 0) return;
	if (scanf("%d", &NeedCol) < 0) return;
	if (CheckInput(CurRow, CurCol, NeedRow, NeedCol, rows)) return;

	printf("Vector: ");
	vect = malloc(sizeof(int));
	if (!vect) return;
	vect[0] = field[CurRow][CurCol];
	if (vect[0] != field[NeedRow][NeedCol])
	{	
		NumberEl = 2;
		vect = CreateVect(CurRow, NeedRow, CurCol, NeedCol, field, vect, counter);
	}
	else NumberEl = 0;
	for (int i = 0; i < NumberEl; i++)
		printf("%d ", vect[i]);

	printf("\n");
	free(vect);
	field = FreeField(rows, field);
	system("pause");
	return;
}