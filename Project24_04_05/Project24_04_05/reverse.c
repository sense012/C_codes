//#include <stdio.h>
//#pragma warning(disable:4996)
//#include <string.h>
////循环实现
////void reverse(char str[])
////{
////  int size = strlen(str); 
////	int x = 0;
////	int y = size - 1;
////	while (x < size/2)
////	{
////		char temp = '0';
////		temp = str[x];
////		str[x] = str[y];
////		str[y] = temp;
////		x++;
////		y--;
////	}
////}
//
////递归实现(指针)
//void reverse(char* str)
//{
//	int len = strlen(str);
//	char temp = *str;
//	*str = *(str+len-1);
//	*(str + len - 1) = '\0';//关键一步
//	if (strlen(str+1)>=2//
//		//len >= 4
//		)
//	{
//		reverse(str + 1);//关键二步
//	}
//	*(str + len - 1) = temp;//!!!!!!!!!!
//}
//
//int main()
//{
//	//printf("输入长度不超过20的字符串：\n");
//	char str[]="acbhr";
//	printf("%s\n", str);
//	//scanf("%s", str);
//	reverse(str);
//	printf("字符串已逆序：\n%s", str);
//}