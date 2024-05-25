//#include <stdio.h>
//#pragma warning(disable:4996)
////自制n的k次方  
//double Pow(double n,double k)
//{
//	if (k == 0)
//	{
//		return 1;
//	}
//	else if (k > 0)
//	{
//		return n * Pow(n ,k-1);
//	}
//	else
//	{
//		k = -k;
//		return 1 / (n * Pow(n ,k-1));//记得打括号
//	}
//}
//
//int main()
//{
//	double a;
//	double b;
//	scanf("%lf %lf", &a, &b);
//	printf("%lf的%lf次方为: %lf\n", a, b, Pow(a, b));
//	return 0;
//}