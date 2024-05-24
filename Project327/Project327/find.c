//#include <stdio.h>//329日晚上完成
//int find(int arr[] , int x , int len)
////仅限有序数组进行查找
////x为要查找的元素，len为数组长度
//{
//	int left = 0;
//	int right = len - 1;
//	int mid = (left + right) / 2;
//	int m = -1;//函数最终返回下标,未查到则返回-1
//	while (left <= right)
//	{
//		int mid = (left + right) / 2;//必须放在循环内部
//		if (arr[mid] == x)
//		{
//			m = mid;
//			break;
//		}
//		else if (arr[mid] > x)
//		{
//			right = mid - 1;//加一减一很重要！
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