//#include<stdio.h>
////汽水一元一瓶，两个空瓶可以换一瓶汽水。
//int soda(int money)
//{
//	int total = money;
//	int empty = total;
//	int exchange = 0;
//	while (empty >= 2)
//	{
//		exchange = empty / 2;
//		empty %= 2;
//		total += exchange;
//		empty += exchange;
//		/*
//		total+=empty/2;
//		empty=empty/2+empty%2;
//		*/
//	}
//	return total;
//}
//int main()
//{
//	int money = 20;
//	int total = soda(money);
//	int guilv = money * 2 - 1;//money不为零时正确
//	printf("%d\n%d", total,guilv);
//	return 0;
//}