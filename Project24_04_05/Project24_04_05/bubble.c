#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void bubble(int arrr[],int size)
{
	for (int j = 0; j < size - 1; j++)
	{
		int flag = 1;
		//һ��ð������
		for (int i = 0; i < size - 1 - j; i++)//ÿ��ð����������һ��
		{
			if (arrr[i] > arrr[i + 1])
			{
				int temp = arrr[i];
				arrr[i] = arrr[i + 1];
				arrr[i + 1] = temp;
				flag = 0;//ֻҪ����������˵����һ�ػ�������
			}
		}
		if (flag == 1)
		{
			break;//�Ѿ���������ǰ�˳�
		}
	}
}
int main()
{
	srand((unsigned int)time(NULL));
	int arr[10] = { 0 ,-1,0,5,6,8,8,7,3,4};
	//for (int i = 0; i < 10; i++)
	//{
	//	arr[i] = rand()%21;//0��20�������
	//	printf("arr[%d]=%d\n", i, arr[i]);
	//}
	int sz = sizeof(arr) / sizeof(arr[0]);
	//int arr[10] = { 9,5,8,7,6,4,2,3,1,0 };
	bubble(arr,sz);
	printf("-------------\n");
	for (int i = 0; i < 10; i++)
	{
		printf("arr[%d]=%d\n", i, arr[i]);
	}
	return 0;
}