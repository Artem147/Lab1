/*
	LameKing.
	������� ��� ������ � � ��������� ����, ������� ����, ������������ 
	������ �� ����, ���������� ������� ��� ����, ���������� �����
	�������� �.�.
	��� - 13��
*/
#ifndef AlltheLameKingsMen
#define AlltheLameKingsMen
//������� ��������� ����.
int** CreateField(int rows, int**field);

//����� ���������� ���� �� �����.
void InputField(int rows, int**field);

//������������ ������.
int** FreeField(int rows, int** field);

//�������� �� �������.
int FlashForward(int NeedRow, int CurRow, int vect, int** field);

//�������� �� ����.
int ThatsRight(int NeedRow, int CurCol, int NeedCol, int** field, int vect);

//������������ �������.
int* CreateVect(int CurRow, int NeedRow, int CurCol, int NeedCol, int** field, int* vect,int *counter);

//������� ��������� � �������.
int Counter(int* vect, int** field, int NeedRow, int NeedCol);

//�������� �����. 1, ���� ������.
int CheckInput(int CurRow, int CurCol, int NeedRow, int NeedCol, int rows);
#endif //AlltheKingsMen