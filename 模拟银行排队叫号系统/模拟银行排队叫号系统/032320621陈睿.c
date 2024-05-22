#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>
#pragma warning(disable:4996)
//�˿ͽṹ�������
struct customer
{
	int arrive_hour;//����ʱ�䣨ʱ��
	int arrive_min; //����ʱ�䣨�֣�
	int line;//���鳤�ȣ�ǰ�漸���Ŷӣ�
	int wait_time;//�ȴ�ʱ��
	int start_time;//��ʼ����ҵ��ʱ��
	int win;//����ҵ�񴰿ڱ��
	int handle_time;//ҵ�����ʱ��
};
//ð�����������������С��������
void bubble(int arrr[], int size)
{
	int j = 0;
	for (j = 0; j < size - 1; j++)
	{
		int flag = 1;
		//һ��ð������
		int i = 0;
		for (i = 0; i < size - 1 - j; i++)//ÿ��ð����������һ��
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

//������SORT(j[0]),��ʵ�֣�������j��Ϊ-1��Ԫ�ض��ŵ�����
void SORT(int* p)
{
	int temp[25] = { 0 };//��ʱ����
	int j = 0;
	int i = 0;
	bubble(p, 25);//�����Զ����ð��������ʵ�ִ�С��������
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
//�˿����������ʼ������(�ú�������ֵΪ����˿�����)
int customer_init(struct customer* p)
{
	int m = 0;	//mΪ��ʼ�˿�����
	int a = 0;  //aΪ�˿�������±꣬���ڸ��˿����鸳ֵ
	//�õ����ʱ�䣨iΪʱ��jΪ�֣�
	int i = 0;
	int v = 0;
	for (i = 9; i < 17; i++)
	{
		int n = 0;//�ֲ�����nΪÿ��Сʱ�Ĺ˿�����
		int j[25] = { 0 };//����j�洢�˿͵ִ�ʱ�ġ����ӡ�
		int x = 0;
		int y = 0;
		n = rand() % 26 ;//�������ÿ��Сʱ�Ĺ˿�����0-25��
		if (n > 0)//����Сʱû�ˣ�������¸�Сʱ��ѭ��
		{
			int y = 0;
			for (y = 0; y < n; y++)
			{
				j[y] = rand() % 60;//n��ʱ�̣���ΧΪ0��59�֣�
			}//��ѭ�������󣬷�������j[25]ǰn�ֵ��ɣ���25-n��Ϊ0
		}
		//����������25-n�ֵΪ-1����ֹ�롰0���ӡ���ͻ
		for (y = n; y < 25; y++)
		{
			j[y] = -1;
		}
		SORT(j);//�����Զ��������������j�е�-1���ŵ����棬��������ֵ��С��������
		for (x = 24; x >= 0; x--)
		{
			if (j[x] != -1)
			{
				n = x + 1;//ͨ�����һ���˿͵��±�õ���Сʱ�˿�����
				m += n;//ͳ�ƹ˿�����
				break;
			}
		}
		//��������j�в�Ϊ-1��ֵ(������j�е�ǰn��)�����˿�����
		for (x = a; x < n + a; x++)
		{
			(p + x)->arrive_hour = i;
			(p + x)->arrive_min = j[x-a];//x-aΪ����Сʱj��ǰn��
		}	
		a += n;
	}
	for (v = 0; v < m; v++)
	{
		(p + v)->handle_time = rand() % 30 + 1;//�������ҵ��ʱ�䣨1-30min��
	}
	return m;
}
//���ڳ�ʼ������
void win_init(int* p, int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		*(p + i) = 900;
	}
}
//��������
int find_min(int* p, int n)
{
	int min = *p;
	int i = 0;
	int x = 0;//Ҫ���ص��±�
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
//ʱ��ӷ�������������λ����ʾʱ�䣩
int time_add(int a, int b)//aֻΪ������λ��ʱ�䣻bֻ������������λ��ʱ�䣬����λ�����ӣ�������100���ӣ�
{
	int ma = 0;
	int ha = 0;
	int mb = 0;
	int hb = 0;//��a��b��ֳ�ʱ����
	int e = 0;
	int flag = 0;
	int n = 0;//���ؽ��
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
//ʱ�����������a��bС��a��b��Ϊ������λ��ʱ�䣩
int time_sub(int a, int b)
{
	int ma = 0;
	int mb = 0;
	int ha = 0;
	int hb = 0;//��a��b��ֳ�ʱ����
	int n = 0;//���ؽ��
	int hn = 0;
	int mn = 0;//���ؽ����ʱ����
	ma = a % 100;
	mb = b % 100;
	ha = a / 100;
	hb = b / 100;
	if (ma <= mb)
	{
		hn = ha - hb - 1;
		mn = 60 + ma - mb;
		//�������з�ֹmn>60
		hn += (mn / 60);
		mn = mn % 60;
	}
	else
	{
		hn = ha - hb;
		mn = ma - mb;
	}
	n = hn * 100 + mn;//���ؽ����Ϊ��λ��ʱ��(��λ��һλ����һСʱ)
	//��120��ʾ���1Сʱ20��,100��ʾ���1Сʱ
	return n;
}
//ҵ�������
int service(int* w, int* count_W, int n, int m, struct customer* cust, int* count_wait, FILE* fp)
{
	int sum = 0;//���շ���˿�����
	int x = 1;
	//��whileѭ���������Ϊ�˿Ͱ���ҵ��
	while (x <= m)
	{
		int i = 0;//���������еĴ����±�
		int L = 0;//LΪ�Ŷ�����
		int t = 0;//tΪ�ȴ�ʱ�䣨��λ����ʾ��
		int y = 0;
		int arrive_time = 0;//�˿͵���ʱ�䣨������λ����ʾ��
		int sh = 0;
		int sm = 0;//ҵ��ʼ�����ʱ����
		i = find_min(w, n);//���������������ҵ�������еĴ����±� 
		y = x - 1;//yΪ�˿��±�
		//�ж��Ƿ���Ҫ�ȴ�
		arrive_time = ((cust + y)->arrive_hour) * 100 + (cust + y)->arrive_min;
		if (arrive_time >= *(w + i))
		{
			L = 0;
			t = 0;
			(cust + y)->start_time = arrive_time;
		}
		else
		{
			//�����Ŷ����
			int z = 0;
			for (z = y-1; z >= 0; z--)
			{
				if (arrive_time < time_add((cust + z)->handle_time, (cust + z)->start_time))
					L++;//��ǰ�뿪�Ĺ˿�ͬ���ᱻ��������
				else
					break;
			}
			t = time_sub(*(w + i), arrive_time);
			(cust + y)->start_time = time_add(arrive_time , t);
		}
		//���ϵõ����Ŷӡ��ȴ����
		sh = (cust + y)->start_time / 100;
		sm = (cust + y)->start_time % 100;
		(cust + y)->line = L;
		(cust + y)->wait_time = (t / 100) * 60 + t % 100;//�ȴ�ʱ�䵥λΪ����
		(cust + y)->win = i;
		//�жϹ˿��Ƿ��뿪
		if (((t > 30) && ((cust + y)->handle_time <= 10)) || ((t > 45) && ((cust + y)->handle_time <= 20)))
		{
			printf("%3d�Ź˿�%2d��%0.2d������ǰ��%2d���Ŷӣ���ǰ�뿪\n", x,
				(cust + y)->arrive_hour, (cust + y)->arrive_min, L);//���
			fprintf(fp, "%3d�Ź˿�%2d��%0.2d������ǰ��%2d���Ŷӣ���ǰ�뿪\n", x,
				(cust + y)->arrive_hour, (cust + y)->arrive_min, L);//д��txt�ļ�
		}
		else
		{
			//�жϹ˿�ҵ��ʼʱ���Ƿ��°�
			if (((cust + y)->start_time) > 1700)		
				break;		
			else
			{
				//����ҵ��
				if (arrive_time >= *(w + i))
					*(w + i) = time_add(arrive_time, (cust + y)->handle_time);
				else
					*(w + i) = time_add(*(w + i), (cust + y)->handle_time);
				//ͳ���Ѱ���ҵ��Ĺ˿͡��ȴ�ʱ��
				sum++;
				*(count_W + i) += 1;
				*(count_wait + y) = (cust + y)->wait_time;
				printf("%3d�Ź˿�%2d��%0.2d������ǰ��%2d���Ŷӣ��ȴ�%3d���Ӻ�%2d��%0.2d����%d�Ŵ��ڰ���ҵ��ʱ��%2d����\n",
					x, (cust + y)->arrive_hour, (cust + y)->arrive_min, L, (cust + y)->wait_time, sh, sm, i + 1, (cust + y)->handle_time);//���
				fprintf(fp, "%3d�Ź˿�%2d��%0.2d������ǰ��%2d���Ŷӣ��ȴ�%3d���Ӻ�%2d��%0.2d����%d�Ŵ��ڰ���ҵ��ʱ��%2d����\n",
					x, (cust + y)->arrive_hour, (cust + y)->arrive_min, L, (cust + y)->wait_time, sh, sm, i + 1, (cust + y)->handle_time);//д�����ļ���
			}		
		}		
		x++;
	}
	return sum;
}
//����ȴ�ʱ�����ֵ�ĺ���
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
//����ȴ�ʱ��ƽ��ֵ�ĺ���
int mean_time(int* p, int n, int m)//nΪ�����С��mΪ��������Ч���ݵ������������Ӵ��Ĺ˿�������
{
	int sum = 0;//sumΪ���Ӵ��˿͵ȴ�ʱ��֮��
	int i = 0;
	for (i = 0; i < n; i++)
	{
		sum += *(p + i);
	}
	return sum / m;
}
//�ļ���������
FILE* file_init()
{
	FILE* fp = NULL;
	time_t timep;
	struct tm* p;
	char name[256] = { 0 };//�ļ����ַ�����
	time(&timep);//��ȡ��1970������˶����룬����time_t���͵�timep������
	p = localtime(&timep);//��localtime������ת��Ϊstruct tm�ṹ��
	sprintf(name, "%0.2d%0.2d%0.2d���.txt", p->tm_hour, p->tm_min, p->tm_sec);//��ʱ��д���ַ�����
	fp = fopen(name, "w");
	if (fp == NULL)//�ж��ļ��Ƿ�ɹ���
		perror("");
	return fp;
}
int main()
{
	int n = 1;//��������
	int sum = 0;//���շ���˿�����
	int m = 0;//�˿�����
	int longest = 0;//��ȴ�ʱ��
	int mean = 0;//ƽ���ȴ�ʱ��
	struct customer Customer[8 * 25];//�˿ͳ�ʼ��������(С�ڵ���200)
	int W[7] = { 0 };//�����������飬W[i]Ϊ���ڽ�Ҫ��������ʱ��
	srand(time(NULL));//ÿ������ʱ���Ӳ�ͬ��ʹ�õ����������ͬ
	while (1)//ʹ��whileѭ����ʵ�ֶ�����봰���������г���
	{
		int count_W[7] = { 0 };//�������ڼ������飬count_W[i]Ϊ���ڷ�������
		int count_wait[8 * 25] = { 0 };//����(���³�ʼ��)�ȴ�ʱ��ͳ������
		printf("����������1��7֮��Ĵ�����(��������������������)��");
		scanf("%d", &n);
		if (n >= 1 && n <= 7)
		{
			FILE* fp = NULL;
			int i = 0;
			fp = file_init();//�������Ϸ���������ļ���������(��������ֵΪ�ļ�ָ��)������ǰʱ�䴴��һ���ļ�
			fprintf(fp, "������Ϊ:%d\n", n);//����������д�뵽�ļ���
			m = customer_init(&Customer[0]);//���ù˿����������ʼ������������m���չ˿���������0<=m<=200��
			win_init(W, n);//���ô��ڳ�ʼ����������Wǰn�����ֵΪ900(��ʾ9ʱ00��)
			sum = service(W, count_W, n, m, &Customer[0], count_wait, fp);//����ҵ����������ú�������ֵΪ����˿�����
			printf("һ������%3d���˿�\n", sum);//���
			fprintf(fp, "һ������%3d���˿�\n", sum);//д���ļ�
			for (i = 0; i < n; i++)
			{
				printf("%d�Ŵ��ڽӴ�%2d���˿�\n", i + 1, count_W[i]);//���
				fprintf(fp, "%d�Ŵ��ڽӴ�%2d���˿�\n", i + 1, count_W[i]);//д���ļ�
			}
			longest = longest_time(count_wait, 8 * 25);//����longest_time�����������ȴ�ʱ��
			mean = mean_time(count_wait, 8 * 25, sum);//����mean_time���������ƽ���ȴ�ʱ��
			printf("�˿���ȴ�ʱ��Ϊ%3d���ӣ�ƽ���ȴ�ʱ��Ϊ%3d����\n", longest, mean);//���
			fprintf(fp, "�˿���ȴ�ʱ��Ϊ%3d���ӣ�ƽ���ȴ�ʱ��Ϊ%3d����\n", longest, mean);//д���ļ�
			fclose(fp);
		}
		else
			break;
	}
	return 0;
}