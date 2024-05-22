#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>
#pragma warning(disable:4996)
//顾客结构体的声明
struct customer
{
	int arrive_hour;//到达时间（时）
	int arrive_min; //到达时间（分）
	int line;//队伍长度（前面几人排队）
	int wait_time;//等待时间
	int start_time;//开始办理业务时间
	int win;//办理业务窗口编号
	int handle_time;//业务持续时间
};
//冒泡排序函数，将数组从小到大排列
void bubble(int arrr[], int size)
{
	int j = 0;
	for (j = 0; j < size - 1; j++)
	{
		int flag = 1;
		//一躺冒泡排序
		int i = 0;
		for (i = 0; i < size - 1 - j; i++)//每趟冒泡排序少排一个
		{
			if (arrr[i] > arrr[i + 1])
			{
				int temp = arrr[i];
				arrr[i] = arrr[i + 1];
				arrr[i + 1] = temp;
				flag = 0;//只要发生交换，说明上一回还是无序
			}
		}
		if (flag == 1)
		{
			break;//已经有序则提前退出
		}
	}
}

//排序函数SORT(j[0]),可实现：将数组j中为-1的元素都放到后面
void SORT(int* p)
{
	int temp[25] = { 0 };//临时数组
	int j = 0;
	int i = 0;
	bubble(p, 25);//调用自定义的冒泡排序函数实现从小到大排列
	for (i = 0; i < 25; i++)
	{
		if (*(p + i) != -1)
		{
			temp[j] = *(p + i);
			j++;
		}
	}
	for (i = 0; i <= j; i++)
	{
		*(p + i) = temp[i];
	}
	for (i = j ; i < 25; i++)
	{
		*(p + i) = -1;
	}
}
//顾客数组初步初始化函数(该函数返回值为当天顾客总数)
int customer_init(struct customer* p)
{
	int m = 0;	//m为初始顾客总数
	int a = 0;  //a为顾客数组的下标，用于给顾客数组赋值
	//得到随机时间（i为时、j为分）
	int i = 0;
	int v = 0;
	for (i = 9; i < 17; i++)
	{
		int n = 0;//局部变量n为每个小时的顾客总数
		int j[25] = { 0 };//数组j存储顾客抵达时的“分钟”
		int x = 0;
		int y = 0;
		n = rand() % 26 ;//随机生成每个小时的顾客数（0-25）
		if (n > 0)//若该小时没人，则进入下个小时的循环
		{
			int y = 0;
			for (y = 0; y < n; y++)
			{
				j[y] = rand() % 60;//n个时刻（范围为0到59分）
			}//该循环结束后，分钟数组j[25]前n项赋值完成，后25-n项为0
		}
		//接下来将后25-n项赋值为-1，防止与“0分钟”冲突
		for (y = n; y < 25; y++)
		{
			j[y] = -1;
		}
		SORT(j);//调用自定义的排序函数，将j中的-1都放到后面，并且其他值从小到大排列
		for (x = 24; x >= 0; x--)
		{
			if (j[x] != -1)
			{
				n = x + 1;//通过最后一个顾客的下标得到该小时顾客数量
				m += n;//统计顾客总数
				break;
			}
		}
		//接下来将j中不为-1的值(即数组j中的前n项)赋给顾客数组
		for (x = a; x < n + a; x++)
		{
			(p + x)->arrive_hour = i;
			(p + x)->arrive_min = j[x-a];//x-a为各个小时j的前n项
		}	
		a += n;
	}
	for (v = 0; v < m; v++)
	{
		(p + v)->handle_time = rand() % 30 + 1;//随机办理业务时间（1-30min）
	}
	return m;
}
//窗口初始化函数
void win_init(int* p, int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		*(p + i) = 900;
	}
}
//搜索函数
int find_min(int* p, int n)
{
	int min = *p;
	int i = 0;
	int x = 0;//要返回的下标
	for (i = 0; i < n; i++)
	{
		if (*(p + i) <= min)
			min = *(p + i);
	}
	for (i = 0; i < n; i++)
	{
		if (*(p + i) == min)
		{
			x = i;
			break;
		}		
	}
	return x;
}
//时间加法函数（三或四位数表示时间）
int time_add(int a, int b)//a只为三或四位数时间；b只可能是三或四位数时间，或两位数分钟（不存在100分钟）
{
	int ma = 0;
	int ha = 0;
	int mb = 0;
	int hb = 0;//将a、b拆分成时、分
	int e = 0;
	int flag = 0;
	int n = 0;//返回结果
	ma = a % 100;
	mb = b % 100;
	ha = a / 100;
	hb = b / 100;
	e = ma + mb;
	if (e >= 60)
		flag = 1;

	if (flag)
		n = (ha + hb + 1) * 100 + (ma + mb - 60);
	else
		n = a + b;
	return n;
}
//时间减法函数（a大b小且a、b均为三或四位数时间）
int time_sub(int a, int b)
{
	int ma = 0;
	int mb = 0;
	int ha = 0;
	int hb = 0;//将a、b拆分成时、分
	int n = 0;//返回结果
	int hn = 0;
	int mn = 0;//返回结果的时、分
	ma = a % 100;
	mb = b % 100;
	ha = a / 100;
	hb = b / 100;
	if (ma <= mb)
	{
		hn = ha - hb - 1;
		mn = 60 + ma - mb;
		//以下两行防止mn>60
		hn += (mn / 60);
		mn = mn % 60;
	}
	else
	{
		hn = ha - hb;
		mn = ma - mb;
	}
	n = hn * 100 + mn;//返回结果任为三位数时间(两位或一位则不足一小时)
	//如120表示相差1小时20分,100表示相差1小时
	return n;
}
//业务办理函数
int service(int* w, int* count_W, int n, int m, struct customer* cust, int* count_wait, FILE* fp)
{
	int sum = 0;//最终服务顾客总数
	int x = 1;
	//用while循环，按序号为顾客办理业务
	while (x <= m)
	{
		int i = 0;//存放最早空闲的窗口下标
		int L = 0;//L为排队人数
		int t = 0;//t为等待时间（三位数表示）
		int y = 0;
		int arrive_time = 0;//顾客到达时间（三或四位数表示）
		int sh = 0;
		int sm = 0;//业务开始办理的时、分
		i = find_min(w, n);//调用搜索函数，找到最早空闲的窗口下标 
		y = x - 1;//y为顾客下标
		//判断是否需要等待
		arrive_time = ((cust + y)->arrive_hour) * 100 + (cust + y)->arrive_min;
		if (arrive_time >= *(w + i))
		{
			L = 0;
			t = 0;
			(cust + y)->start_time = arrive_time;
		}
		else
		{
			//查找排队情况
			int z = 0;
			for (z = y-1; z >= 0; z--)
			{
				if (arrive_time < time_add((cust + z)->handle_time, (cust + z)->start_time))
					L++;//提前离开的顾客同样会被计算在内
				else
					break;
			}
			t = time_sub(*(w + i), arrive_time);
			(cust + y)->start_time = time_add(arrive_time , t);
		}
		//以上得到了排队、等待情况
		sh = (cust + y)->start_time / 100;
		sm = (cust + y)->start_time % 100;
		(cust + y)->line = L;
		(cust + y)->wait_time = (t / 100) * 60 + t % 100;//等待时间单位为分钟
		(cust + y)->win = i;
		//判断顾客是否离开
		if (((t > 30) && ((cust + y)->handle_time <= 10)) || ((t > 45) && ((cust + y)->handle_time <= 20)))
		{
			printf("%3d号顾客%2d点%0.2d分来，前面%2d人排队，提前离开\n", x,
				(cust + y)->arrive_hour, (cust + y)->arrive_min, L);//输出
			fprintf(fp, "%3d号顾客%2d点%0.2d分来，前面%2d人排队，提前离开\n", x,
				(cust + y)->arrive_hour, (cust + y)->arrive_min, L);//写入txt文件
		}
		else
		{
			//判断顾客业务开始时间是否下班
			if (((cust + y)->start_time) > 1700)		
				break;		
			else
			{
				//办理业务
				if (arrive_time >= *(w + i))
					*(w + i) = time_add(arrive_time, (cust + y)->handle_time);
				else
					*(w + i) = time_add(*(w + i), (cust + y)->handle_time);
				//统计已办理业务的顾客、等待时间
				sum++;
				*(count_W + i) += 1;
				*(count_wait + y) = (cust + y)->wait_time;
				printf("%3d号顾客%2d点%0.2d分来，前面%2d人排队，等待%3d分钟后，%2d点%0.2d分在%d号窗口办理业务，时长%2d分钟\n",
					x, (cust + y)->arrive_hour, (cust + y)->arrive_min, L, (cust + y)->wait_time, sh, sm, i + 1, (cust + y)->handle_time);//输出
				fprintf(fp, "%3d号顾客%2d点%0.2d分来，前面%2d人排队，等待%3d分钟后，%2d点%0.2d分在%d号窗口办理业务，时长%2d分钟\n",
					x, (cust + y)->arrive_hour, (cust + y)->arrive_min, L, (cust + y)->wait_time, sh, sm, i + 1, (cust + y)->handle_time);//写入至文件中
			}		
		}		
		x++;
	}
	return sum;
}
//计算等待时间最大值的函数
int longest_time(int* p, int n)
{
	int max = *p;
	int i = 0;
	for (i = 0; i < n; i++)
	{
		if (*(p + i) >= max)
			max = *(p + i);
	}
	return max;
}
//计算等待时间平均值的函数
int mean_time(int* p, int n, int m)//n为数组大小，m为数组中有效数据的数量（即被接待的顾客总数）
{
	int sum = 0;//sum为被接待顾客等待时间之和
	int i = 0;
	for (i = 0; i < n; i++)
	{
		sum += *(p + i);
	}
	return sum / m;
}
//文件创建函数
FILE* file_init()
{
	FILE* fp = NULL;
	time_t timep;
	struct tm* p;
	char name[256] = { 0 };//文件名字符数组
	time(&timep);//获取从1970至今过了多少秒，存入time_t类型的timep变量中
	p = localtime(&timep);//用localtime将秒数转化为struct tm结构体
	sprintf(name, "%0.2d%0.2d%0.2d陈睿.txt", p->tm_hour, p->tm_min, p->tm_sec);//把时间写入字符数组
	fp = fopen(name, "w");
	if (fp == NULL)//判断文件是否成功打开
		perror("");
	return fp;
}
int main()
{
	int n = 1;//窗口数量
	int sum = 0;//最终服务顾客总数
	int m = 0;//顾客数量
	int longest = 0;//最长等待时间
	int mean = 0;//平均等待时间
	struct customer Customer[8 * 25];//顾客初始的总数量(小于等于200)
	int W[7] = { 0 };//创建窗口数组，W[i]为窗口将要工作到的时间
	srand(time(NULL));//每次运行时种子不同，使得到的随机数不同
	while (1)//使用while循环，实现多次输入窗口数并运行程序
	{
		int count_W[7] = { 0 };//创建窗口计数数组，count_W[i]为窗口服务人数
		int count_wait[8 * 25] = { 0 };//创建(重新初始化)等待时间统计数组
		printf("请输入银行1到7之间的窗口数(输入其他数据则程序结束)：");
		scanf("%d", &n);
		if (n >= 1 && n <= 7)
		{
			FILE* fp = NULL;
			int i = 0;
			fp = file_init();//窗口数合法，则调用文件创建函数(函数返回值为文件指针)，按当前时间创建一个文件
			fprintf(fp, "窗口数为:%d\n", n);//将窗口数量写入到文件中
			m = customer_init(&Customer[0]);//调用顾客数组初步初始化函数，并用m接收顾客总数量（0<=m<=200）
			win_init(W, n);//调用窗口初始化函数，将W前n项均赋值为900(表示9时00分)
			sum = service(W, count_W, n, m, &Customer[0], count_wait, fp);//调用业务办理函数，该函数返回值为服务顾客总数
			printf("一共服务%3d名顾客\n", sum);//输出
			fprintf(fp, "一共服务%3d名顾客\n", sum);//写入文件
			for (i = 0; i < n; i++)
			{
				printf("%d号窗口接待%2d名顾客\n", i + 1, count_W[i]);//输出
				fprintf(fp, "%d号窗口接待%2d名顾客\n", i + 1, count_W[i]);//写入文件
			}
			longest = longest_time(count_wait, 8 * 25);//调用longest_time函数，求得最长等待时间
			mean = mean_time(count_wait, 8 * 25, sum);//调用mean_time函数，求得平均等待时间
			printf("顾客最长等待时间为%3d分钟，平均等待时间为%3d分钟\n", longest, mean);//输出
			fprintf(fp, "顾客最长等待时间为%3d分钟，平均等待时间为%3d分钟\n", longest, mean);//写入文件
			fclose(fp);
		}
		else
			break;
	}
	return 0;
}