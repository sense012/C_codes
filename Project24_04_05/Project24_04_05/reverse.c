//#include <stdio.h>
//#pragma warning(disable:4996)
//#include <string.h>
////ѭ��ʵ��
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
////�ݹ�ʵ��(ָ��)
//void reverse(char* str)
//{
//	int len = strlen(str);
//	char temp = *str;
//	*str = *(str+len-1);
//	*(str + len - 1) = '\0';//�ؼ�һ��
//	if (strlen(str+1)>=2//
//		//len >= 4
//		)
//	{
//		reverse(str + 1);//�ؼ�����
//	}
//	*(str + len - 1) = temp;//!!!!!!!!!!
//}
//
//int main()
//{
//	//printf("���볤�Ȳ�����20���ַ�����\n");
//	char str[]="acbhr";
//	printf("%s\n", str);
//	//scanf("%s", str);
//	reverse(str);
//	printf("�ַ���������\n%s", str);
//}