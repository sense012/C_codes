#include <stdio.h>
//int main()
//{
//	struct stu
//	{
//		int a;
//		int b;
//	};
//	struct stu S[2] = { {1,2},{3,4} };
//	struct stu* p = &S;
//	p->a = 5;
//	
//	//S.a = 0;
//	printf("%d %d", S[0].a, S[1].b);
//	return 0;
//}

//void sort(int* p)
//{
//	int temp[25] = { 0 };//ÁÙÊ±Êı×é
//	int j = 0;
//	for (int i = 0; i < 25; i++)
//	{
//		if (*(p + i) != -1)
//		{
//			temp[j] = *(p + i);
//			j++;
//		}
//	}
//	for (int i = 0; i <= j; i++)
//	{
//		*(p + i) = temp[i];
//	}
//	for (int i = j ; i < 25; i++)
//	{
//		*(p + i) = -1;
//	}
//}
//int main()
//{
//	int m[25] = { 1,2,5,-1,3,6,7,8,9,10,-1,2,3,4,-1,6,7,8,9,20,-1,22,23,24,25 };
//	sort(m);
//	
//	return 0;
//}