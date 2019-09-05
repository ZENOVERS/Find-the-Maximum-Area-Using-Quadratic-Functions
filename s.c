#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include <math.h>
#include <ctype.h>

#define 세 (((len * 1 / 2) / 2))
#define 넓 2 * pow((((len * 1 / 2) / 2)), 2)
#define 가 len - 2 * ((((len * 1 / 2) / 2)))

void gotoxy(int x, int y)
{
	COORD Cur;
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

void CRB(void)
{
	while (getchar() != '\n');
}

int main()
{
	system("title Find the Maximum Area By Using Quadratic Functions");

	float len = 0, 가로, 세로, 넓이;
	char re; 

s:

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	puts("==============(벽)=============== ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	puts("l\t\t\t\tl\nl\t\t\t\tl\nl\t\t\t\tl\nl\t\t\t\tl\nl\t\t\t\tl  (울타리)\nl\t\t\t\tl\nl\t\t\t\tl\nl\t\t\t\tl\nl\t\t\t\tl\n---------------------------------");

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
	puts("\n\n설명. 뒤에는 벽이 있고 나머지 세 변은 울타리로 막아 우리를 만들 생각이다.\n울타리의 전체 길이를 설정해서 가능한 우리의 최대 넓이를 계산해보자.");

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	printf("\n\n총 울타리 길이를 입력하세요: ");
	scanf("%f", &len);

	CRB();

	if (len < 0)
	{
		printf("음수 또는 잘못된 값이 입력됐습니다.");
		return 0;
	}



	넓이 = (len * len) / 8;
	세로 = len / 4;
	가로 = len - (세로 * 2);

	system("cls");

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	puts("==============(벽)=============== ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	printf("l\t\t\t\tl\nl\t\t\t\tl\nl\t\t\t\tl\nl\t\t\t\tl\n\t넓이: %f \nl\t\t\t\tl\nl\t\t\t\tl\nl\t\t\t\tl\nl\t\t\t\tl\n---------------------------------\n", 넓);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	printf("[--------------------------------]");
	gotoxy(12, 11);
	printf("%f", 가);

	gotoxy(34, 1);
	printf("ㅜ");
	for (int i = 1; i < 9; i++)
	{
		gotoxy(35, i + 1);
		printf("l");
	}
	gotoxy(34, 10);
	printf("ㅗ");

	gotoxy(34, 5);
	printf("%f", 세);

	gotoxy(12, 11);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	printf("\n\n우리의 가능한 최대 넓이 : %f\n", 넓이);
	printf("세로 길이 : %f\n", 세로);
	printf("가로 길이 넓이 : %f\n\n\n", 가로);

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	printf("---풀이---\n\n");

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
	printf("총 울타리 길이 : %f\n\n\n", len);

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	printf("세로를 x, 가로를 (%f - 2x)라고 할 때, 우리의 넓이는 x(%f - 2x)식이 성립한다.\n", len, len);
	printf("이차함수의 최댓값과 최솟값을 이용하여 구하면, y = %fx - 2xx 식이 도출된다.\n", len);
	printf("이 식을 완전 제곱식을 이용하면, y = -2(xx - %fx + %f - %f)가 된다.\n", len * 1 / 2, pow((((len * 1 / 2) / 2)), 2), pow((((len * 1 / 2) / 2)), 2));
	printf("그러면 y = -2(x - %f)(x - %f) + %f\n", 세, 세, 넓);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
	printf("\n결론적으론 x에 넣은 값이 0이 되야 하니, 세로는 %f이고, 최대 넓이는 이차함수의 최댓값인 %f이다.\n\n\n", 세, 넓);

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
	printf("다시 계산하시겠습니까? (y / n 입력): ");
	scanf("%c", &re);

	CRB();

	if (re == 'y' || re == 'Y')
	{
		system("cls");
		len = 0, 가로 = 0, 세로 = 0, 넓이 = 0, re = 0;
		goto s;
	}

	return 0;
}