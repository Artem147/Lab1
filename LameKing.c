/*
	LameKing.
	Функции для работы с созданием поля, выводом поля, перемещением Хромого 
	Короля по полю, нахождению вектора его пути, управлению полем
	Ширкунов А.В.
	ИВТ - 13БО
*/
#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <malloc.h>
//Создаем двумерное поле.
int** CreateField(int rows, int**field)
{
	field = malloc((rows+1) * sizeof(int*));
	if (!field) return NULL;
	int i = 1, count = 1, k = 1;
	while (i <= rows)
	{
		field[i] = malloc(sizeof(int) * (k+1));
		k = 1;
		while (k <= i)
		{
			field[i][k] = count;
			count++;
			k++;
		}
		i++;
	}
	return field;
}

//Вывод двумерного поля на экран.
void InputField(int rows, int**field)
{
	int i = 0, k;
	while (i <= rows)
	{
		k = 1;
		for (int form = rows; form - i + 1; form--) {
			printf(" ");//Почти идеальное распределение пробелов.
		}
		while (k <= i)
		{
			printf("%3d ", field[i][k]);
			k++;
		}
		printf("\n");
		i++;
	}
	return;
}

//Освобождение памяти.
int** FreeField(int rows, int** field)
{
	int k = 1, i = 1;
	while (i <= rows)
	{
		free(field[i]);
		i++;
	}
	free(field);
	return NULL;
}

//Движение по строкам.
int FlashForward(int NeedRow, int NeedCol, int CurRow, int vect, int** field)
{
	//Если мы двигаемся вниз, прибавляем к элементу номер строки +1.
	if (CurRow < NeedRow)
	{
		if (NeedCol <= (NeedRow / 2))
		{
			vect = vect + CurRow;
			CurRow++;
		}
		else
		{
			vect = vect + CurRow+1;
			CurRow++;
		}
	}
	else //Если мы двигаемся вверх, два случая:
		if (vect == field[CurRow][CurRow])//Если достигаем правого края двигаемся по нему.
			vect = vect - CurRow;
		else //Иначе вычитаем номер строки - 1. 
			vect = vect - CurRow + 1;
	return(vect);
}

//Движение по ряду вправо/влево.
int ThatsRight(int NeedRow, int CurCol, int NeedCol, int** field, int vect)
{
	if (vect < field[NeedRow][NeedCol])
		vect++;//Движение вправо.
	else
		vect--;//Движение влево.
	return vect;
}

//Формирование вектора.
int* CreateVect(int CurRow, int NeedRow, int CurCol, int NeedCol, int** field, int* vect, int* counter)
{
	int i = 1;//Счетчики.
	while (NeedRow != CurRow) 
	{
		vect = realloc(vect, (*counter) * sizeof(int*));
		if (!vect) return;
		if (vect[i] == field[NeedRow][NeedCol])//Если передвигаясь по строкам попали в нужную клетку.
		{
			(*counter)--;
			return vect;

		}
		else
			vect[i] = FlashForward(NeedRow, NeedCol, CurRow, vect[i - 1], field);
		if (NeedRow > CurRow) CurRow++;//Поднимаеся на строчку.
		else CurRow--;//Спускаемся на строчку.
		(*counter)++;
		i++;
	}
	while (vect[i - 1] != field[NeedRow][NeedCol]) //На нужной строке пока не придем в нужную клетку.
	{
		vect = realloc(vect, (*counter) * sizeof(int*));
		vect[i] = ThatsRight(NeedRow, CurCol, NeedCol, field, vect[i - 1]);
		i++;
		(*counter)++;
	}
	(*counter)--;
	return vect;
}

//Проверка ввода. 1, если ошибка.
int CheckInput(int CurRow, int CurCol, int NeedRow, int NeedCol, int rows)
{//Строки должны быть:
	if (rows <= 0) return 1;//Положительным числом.
	if (CurRow<0 || CurRow> rows || NeedRow > rows || NeedRow < 0 || CurCol < 0 || NeedCol < 0) return 1;
	if (NeedRow < NeedCol) return 1;//Кол-во столбцов не превышает кол-во строк.
	if (CurRow < CurCol) return 1;
	return 0;
}
