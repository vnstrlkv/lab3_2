#include <stdio.h>
#include <Windows.h>
#include <conio.h>



//10. Произвольная последовательность строк и целых переменных.
//Бай со значением 0 - обозначает начало строки (последовательность символов, ограниченная нулем). 
//Байт со значением N является началом последовательности N целых чисел. Конец последовательности - два нулевых байта.

void menu(char *arr, int *num);

void addint(char *arr, int *num, int *b, int n)
{
	arr[(*num)++] = n;
	char *p = &arr[*num];
	for (int i = 0; i < n; i++)
	{
		*((int*)p) = b[i];
		p = p + sizeof(int);
		*num += sizeof(int);
	}
}
void addchar(char *arr, int *num, char *buf)
{
	for (int i = 0; buf[i] != '\0'; i++)
	{
		arr[(*num)++] = buf[i];
	}
}

void showmenu()
{
	system("cls");
	printf("1: input\n");
	printf("2: showINT\n");
	printf("3: showCHAR\n");
	printf("4: showpack\n");
}
void showINT(char *arr, int num)
{
	printf("\nunpack array\n");
	for (int i = 0; i < num; i++)
	{
		printf("%d|", arr[i]);
	}
	system("pause");
}
void showCHAR(char *arr, int num)
{
	printf("\nunpack array\n");
	for (int i = 0; i < num; i++)
	{
		printf("%c|", arr[i]);
	}
	system("pause");
}
void showpack(char *arr)
{
	int i = 0;
	while ((arr[i] != NULL) || (arr[i + 1] != NULL))
	{
		if (arr[i] == NULL)
		{
			while (arr[i + 1] != NULL)
			{
				printf("%c ", arr[i + 1]);
				i++;
			}
			i += 2;
		}
		if (arr[i] != NULL)
		{
			int n = arr[i];
			i++;
			for (int k = 0; k < n; k++)
			{
				printf("%d ", *((int*)(arr + i)));
				i += sizeof(int);
			}
		}
	}
	system("pause");
}

void input(char *arr, int *num)
{
	printf("1: add char\n");
	printf("2: add int\n");
	char buf[15], key = 0;
	key = getch();
	switch (key)
	{
	case '1':
	{
		if (arr[*num] == NULL && arr[*num - 1] == NULL)
			*num -= 2;
		printf("input char:\n");
		arr[(*num)++] = NULL;

		while (key != 'y')
		{
			gets_s(buf);
			addchar(arr, num, buf);
			printf("\nthat's all? (y-exit)\n");
			key = getch();
		}
		arr[(*num)++] = NULL;
		break;
	}
	case '2':
	{
		if (arr[*num] == NULL && arr[*num - 1] == NULL)
			*num -= 2;
		printf("input int:\n");
		int n = 0;
		int temp[50];
		char key = 0;
		while (key != 'y')
		{
			scanf("%d", &temp[n]);
			n++;
			printf("\nthat's all? (y-exit)\n");
			key = getch();
		}
		addint(arr, num, temp, n);
		break;
	}
	}
	arr[*num] == NULL;
	arr[*num + 1] == NULL;
	*num += 2;
	menu(arr, num);
}

void menu(char *arr, int *num)
{
	showmenu();
	char key;
	key = getch();
	switch (key)
	{
	case '1':
	{
		input(arr, num);
		break;
	}
	case '2':
	{
		showINT(arr, *num);
		break;
	}
	case '3':
	{
		showCHAR(arr, *num);
		break;
	}
	case '4':
	{
		showpack(arr);
		break;
	}
	case '\033':
	{
		exit(0);
		break;
	}
	}
	menu(arr, num);
}

void main()
{
	char arr[200] = { NULL,NULL };
	int num = 2;
	menu(arr, &num);
}