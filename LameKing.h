/*
	LameKing.
	Функции для работы с с созданием поля, выводом поля, перемещением 
	короля по полю, нахождению вектора его пути, управлению полем
	Ширкунов А.В.
	ИВТ - 13БО
*/
#ifndef AlltheLameKingsMen
#define AlltheLameKingsMen
//Создаем двумерное поле.
int** CreateField(int rows, int**field);

//Вывод двумерного поля на экран.
void InputField(int rows, int**field);

//Освобождение памяти.
int** FreeField(int rows, int** field);

//Движение по строкам.
int FlashForward(int NeedRow, int CurRow, int vect, int** field);

//Движение по ряду.
int ThatsRight(int NeedRow, int CurCol, int NeedCol, int** field, int vect);

//Формирование вектора.
int* CreateVect(int CurRow, int NeedRow, int CurCol, int NeedCol, int** field, int* vect,int *counter);

//Счетчик элементов в векторе.
int Counter(int* vect, int** field, int NeedRow, int NeedCol);

//Проверка ввода. 1, если ошибка.
int CheckInput(int CurRow, int CurCol, int NeedRow, int NeedCol, int rows);
#endif //AlltheKingsMen