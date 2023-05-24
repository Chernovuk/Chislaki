#include "functions.h"


double f(double x) {	//������������� �������
	return log(x) * pow(x, 3);
}

double integr_of_f(double x) {	//�� ��������
	return pow(x, 4) * (4 * log(x) - 1) / 16;
}


double f_0(double x)             //������������� �������, ��������� 0 �������
{
	return(7);
}

double integr_0(double x)            //�������� ���������� 0 �������
{
	return(7 * x);
}

double f_1(double x)             //������������� �������, ��������� 1 �������
{
	return(4 * x - 3);
}

double integr_1(double x)              //�������� ���������� 1 �������
{
	return 2 * pow(x, 2) - 3 * x;
}

double f_2(double x)             //������������� �������, ��������� 2 �������
{
	return(-pow(x, 2) - 8 * x + 1);
}

double integr_2(double x)            //�������� ���������� 2 �������
{
	return -pow(x, 3) / 3 - 4 * pow(x, 2) + x;
}

double f_3(double x)             //������������� �������, ��������� 3 �������
{
	return 2 * pow(x, 3) - 5 * x - 2;
}

double integr_3(double x)
{
	return pow(x, 4) / 2 - 2.5 * pow(x, 2) - 2 * x;   //�������� ���������� 3 �������
}