#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

// 정답과 틀리면 스테이지는 그대로, 다른 문제 나옴

int ifail;
int* fptr = &ifail;
int life = 3;
int intans;
int* ia = &intans;
void pickg(); // 1 ~ 30 난수 생성 후 caseg 에 보냄
void caseg(int n); // 1 ~ 30 각각에 해당하는 미니게임을 실행시킴
void g1(); // 1 ... 30 번 게임
void g2();

int main()
{
	srand(time(NULL));
	// 시작 전 알림
	printf("====================\n\n잠시 후 무작위로 45개의 미니게임들이 튀어나옵니다!\n시간은 1분 20초로 제한 돼있습니다!\n주어진 시간 내로 모든 미니게임을 클리어하세요!\n\n====================\n\n\n");
	Sleep(3000);
	// 카운트 다운
	for (int i = 0; i < 3; i++)
	{
		printf("%d\n\n", 3 - i);
		Sleep(1000);
	}
	printf("====================\n\n시작!!!\n\n====================\n\n\n\n");
	// 시작
	for (int i = 0; i < 45; i++)
	{
		ifail = 0;
		printf("\n\n%d 번째 문제!\n\n", i + 1);
		*fptr = 0;
		*ia = 0;
		pickg();
		if (ifail)
		{
			i--;
			life--;
			printf("남은 생명 %d", life);
			if (life == 0)
			{
				printf("\n\n남은 기회 전부 소진.. 실패!!\n\n");
				exit(0);
			}
		}
	}
}

// 함수 시작

void pickg()
{
	int a = rand() % 2 + 1;
	caseg(a);
}

void caseg(int n)
{
	switch (n)
	{
	case 1:
		g1();
		break;
	case 2:
		g2();
		break;
	}
}

void g1() // 사칙연산
{
	int jd;
	char g;
	int a = rand() % 10 + 1;
	int b = rand() % 10 + 1;
	int giho = rand() % 5 + 1;
	switch (giho)
	{
	case 1:
		g = '+';
		jd = a + b;
		break;
	case 2:
		g = '-';
		jd = a - b;
		break;
	case 3:
		g = '*';
		jd = a * b;
		break;
	case 4:
		g = '/';
		jd = a / b;
		break;
	case 5:
		g = '%';
		jd = a % b;
		break;
	}
	printf("계산 하세요!\n%d %c %d = ??\n\n>> ", a, g, b);
	scanf("%d", ia);
	if (*ia == jd)
		printf("\n\n===== OOOOOOOOOOOOO 정답 OOOOOOOOOOOOO =====\n\n");
	else
	{
		printf("\n\n===== XXX 오답 XXX =====\n\n");
		(*fptr)++;
	}
}

void g2() // 문자열 따라 치기
{
	char cans[100];
	char tpt[4];
	for (int i = 0; i < 3; i++)
	{
		tpt[i] = 'a' + rand() % 26;
	}
	tpt[3] = '\0';
	printf("따라 치세요!\n");
	for (int i = 0; i < 3; i++)
	{
		printf("%c", tpt[i]);
	}
	printf("\n\n>> ");
	scanf("%s", cans);
	if (strcmp(tpt, cans) == 0)
		printf("\n\n===== OOOOOOOOOOOOO 정답 OOOOOOOOOOOOO =====\n\n");
	else
	{
		printf("\n\n===== XXX 오답 XXX =====\n\n");
		(*fptr)++;
	}
}
