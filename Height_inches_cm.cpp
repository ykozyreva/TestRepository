/*�������� ���������, ������� ��������� ���� �� ������������ ��-
����� (����, �����) � ����������� (����������). ������ ���-
����� � ���� ���� ����� �����, ��������� � ���� �������������
����� � ��������� �� 1 �����. 1 ��� = 12 ������. 1 ���� = 2.54 ��.*/

#include <stdio.h>
#define inches 2.54
#define foot 12

int main()
{
	int height_foot, height_inches;
	double result;

	printf("Enter your height in foots&inches:\n");
	scanf("%d%d", &height_foot, &height_inches);

	result = height_foot * foot * inches;
	printf("Your height %d.%d = %lf cm\n", height_foot, height_inches, result);
	getchar();
	while(true){}
	return 0;
}