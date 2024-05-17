#include <stdio.h>
#include <string.h>


void reverse(char* left,char* right) {
	while (left < right) {
		char temp = 0;
		temp= *left;
		*left = *right;
		*right = temp;
		left++;
		right--;
	}
}
void word_reverse(char* start) {
	while (*start) {
		char* end = start;
		while (*end != ' ' && *end != '\0') {
			end++;
		}
		reverse(start, end-1);
		if (*end == ' ')
			start = end + 1;
		else
			start = end;
	}
}
int main() {
	char arr[50] = { 0 };//字符串数组（最大为50）
	gets(arr);
	int len = strlen(arr);
	//1.全部翻转
	reverse(arr, arr+(len-1));
	//2.逐单词翻转
	word_reverse(arr);

	printf("%s", arr);
	return 0;
}