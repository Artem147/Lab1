/*
	LameKing.
	������� ��� ������ � ��������� ����, ������� ����, ������������ ������� 
	������ �� ����, ���������� ������� ��� ����, ���������� �����
	�������� �.�.
	��� - 13��
*/
#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <malloc.h>
//������� ��������� ����.
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

//����� ���������� ���� �� �����.
void InputField(int rows, int**field)
{
	int i = 0, k;
	while (i <= rows)
	{
		k = 1;
		for (int form = rows; form - i + 1; form--) {
			printf(" ");//����� ��������� ������������� ��������.
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

//������������ ������.
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

//�������� �� �������.
int FlashForward(int NeedRow, int NeedCol, int CurRow, int vect, int** field)
{
	//���� �� ��������� ����, ���������� � �������� ����� ������ +1.
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
	else //���� �� ��������� �����, ��� ������:
		if (vect == field[CurRow][CurRow])//���� ��������� ������� ���� ��������� �� ����.
			vect = vect - CurRow;
		else //����� �������� ����� ������ - 1. 
			vect = vect - CurRow + 1;
	return(vect);
}

//�������� �� ���� ������/�����.
int ThatsRight(int NeedRow, int CurCol, int NeedCol, int** field, int vect)
{
	if (vect < field[NeedRow][NeedCol])
		vect++;//�������� ������.
	else
		vect--;//�������� �����.
	return vect;
}

//������������ �������.
int* CreateVect(int CurRow, int NeedRow, int CurCol, int NeedCol, int** field, int* vect, int* counter)
{
	int i = 1;//��������.
	while (NeedRow != CurRow) 
	{
		vect = realloc(vect, (*counter) * sizeof(int*));
		if (!vect) return;
		if (vect[i] == field[NeedRow][NeedCol])//���� ������������ �� ������� ������ � ������ ������.
		{
			(*counter)--;
			return vect;

		}
		else
			vect[i] = FlashForward(NeedRow, NeedCol, CurRow, vect[i - 1], field);
		if (NeedRow > CurRow) CurRow++;//���������� �� �������.
		else CurRow--;//���������� �� �������.
		(*counter)++;
		i++;
	}
	while (vect[i - 1] != field[NeedRow][NeedCol]) //�� ������ ������ ���� �� ������ � ������ ������.
	{
		vect = realloc(vect, (*counter) * sizeof(int*));
		vect[i] = ThatsRight(NeedRow, CurCol, NeedCol, field, vect[i - 1]);
		i++;
		(*counter)++;
	}
	(*counter)--;
	return vect;
}

//�������� �����. 1, ���� ������.
int CheckInput(int CurRow, int CurCol, int NeedRow, int NeedCol, int rows)
{//������ ������ ����:
	if (rows <= 0) return 1;//������������� ������.
	if (CurRow<0 || CurRow> rows || NeedRow > rows || NeedRow < 0 || CurCol < 0 || NeedCol < 0) return 1;
	if (NeedRow < NeedCol) return 1;//���-�� �������� �� ��������� ���-�� �����.
	if (CurRow < CurCol) return 1;
	return 0;
}
