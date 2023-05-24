#include "functions.h"


double f(double x) {	//������������� �������
	return log(x) * pow(x, 3);
}

double df(double x) {       //1-4 ����������� ������������� �������
	return pow(x, 2) * (3 * log(x) + 1);
}
double d2f(double x) {
	return x * (6 * log(x) + 5);
}
double d3f(double x) {
	return 6 * log(x) + 11;
}
double d4f(double x) {
	return 6 / x;
}


double integr_of_f(double x) {	//�� ��������
	return pow(x, 4) * (4 * log(x) - 1) / 16;
}


double f_0(double x)             //������������� �������, ��������� 0 �������
{
	return(7);
}

double df_0(double x) {        //1-4 ����������� ���������� 0 �������
	return 0;
}
double d2f_0(double x) {
	return 0;
}
double d3f_0(double x) {
	return 0;
}
double d4f_0(double x) {
	return 0;
}

double integr_0(double x)            //�������� ���������� 0 �������
{
	return(7 * x);
}


double f_1(double x)             //������������� �������, ��������� 1 �������
{
	return(4 * x - 3);
}

double df_1(double x) {          //1-4 ����������� ���������� 1 �������
	return 4;
}
double d2f_1(double x) {
	return 0;
}
double d3f_1(double x) {
	return 0;
}
double d4f_1(double x) {
	return 0;
}

double integr_1(double x)              //�������� ���������� 1 �������
{
	return 2 * pow(x, 2) - 3 * x;
}


double f_2(double x)             //������������� �������, ��������� 2 �������
{
	return(-pow(x, 2) - 8 * x + 1);
}

double df_2(double x) {         //1-4 ����������� ���������� 2 �������
	return -2 * x - 8;
}
double d2f_2(double x) {
	return -2;
}
double d3f_2(double x) {
	return 0;
}
double d4f_2(double x) {
	return 0;
}

double integr_2(double x)            //�������� ���������� 2 �������
{
	return -pow(x, 3) / 3 - 4 * pow(x, 2) + x;
}


double f_3(double x)             //������������� �������, ��������� 3 �������
{
	return 2 * pow(x, 3) - 5 * x - 2;
}

double df_3(double x) {         //1-4 ����������� ���������� 3 �������
	return 6 * pow(x, 2) - 5;
}
double d2f_3(double x) {
	return 12 * x;
}
double d3f_3(double x) {
	return 12;
}
double d4f_3(double x) {
	return 0;
}

double integr_3(double x)
{
	return pow(x, 4) / 2 - 2.5 * pow(x, 2) - 2 * x;   //�������� ���������� 3 �������
}