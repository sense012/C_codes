//#include <stdio.h>
//
//void print(int arr[],int sz)
//{
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d", arr[i]);
//	}
//	printf("\n");
//}
//
//void reverse(int arr[],int size)
//{
//	int left = 0;
//	int right = size - 1;
//	
//	while (left < right)
//	{
//		int temp = arr[left];
//		arr[left] = arr[right];
//		arr[right] = temp;
//		left++;
//		right--;
//	}
//}
//
//int main()
//{
//	int arr[10] = { 1,2,5,9,5,8,4,2 };
//	
//	print(arr,10);
//	reverse(arr,10);
//	print(arr,10);
//	//init(arr);
//	//print(arr,10);
//	return 0;
//}