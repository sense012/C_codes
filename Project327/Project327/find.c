//#include <stdio.h>//329���������
//int find(int arr[] , int x , int len)
////��������������в���
////xΪҪ���ҵ�Ԫ�أ�lenΪ���鳤��
//{
//	int left = 0;
//	int right = len - 1;
//	int mid = (left + right) / 2;
//	int m = -1;//�������շ����±�,δ�鵽�򷵻�-1
//	while (left <= right)
//	{
//		int mid = (left + right) / 2;//�������ѭ���ڲ�
//		if (arr[mid] == x)
//		{
//			m = mid;
//			break;
//		}
//		else if (arr[mid] > x)
//		{
//			right = mid - 1;//��һ��һ����Ҫ��
//		}
//		else if (arr[mid] < x)
//		{
//			left = mid + 1;
//		}
//
//	}
//
//	
//	return m;
//
//}
//int main()
//{
//	int a[] = { 1,2,3,5,6 };
//	int sz = sizeof(a) / sizeof(a[0]);
//	int b = find(a, 4 , sz);
//	printf("%d ", b);
//	return 0;
//}