/*Написать программу, которая переводит рост из американской си-
стемы (футы, дюймы) в европейскую (сантиметры). Данные вво-
дятся в виде двух целых чисел, выводятся в виде вещественного
числа с точностью до 1 знака. 1 фут = 12 дюймов. 1 дюйм = 2.54 см.*/

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