#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

// 정답과 틀리면 스테이지는 그대로, 다른 문제 나옴

int ifail; // 실패?
int* fptr = &ifail; // 실패 포인터
int life = 3; // 생명
int intans; // 정수가 답일 때
int* ia = &intans; // 정수 답 포인터
int ri(int t, int m); // 난수 생성 함수
void pickg(); // 난수 생성 후 caseg 에 보냄
void caseg(int n); // 각각에 해당하는 미니게임을 실행시킴
void g1(); // 게임
void g2();
void g3();
void g4();
void g5();
void g6();

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
	time_t st = time(NULL); // 시작 시간
	for (int i = 0; i < 45; i++)
	{
		if (time(NULL) - st >= 80)
		{
			printf("\n\n시간 종료.. 실패했습니다...\n\n");
			exit(0);
		}
		ifail = 0;
		printf("\n\n%d 번째 문제!\n\n", i + 1);
		*fptr = 0;
		*ia = -10000;
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

int ri(int t, int m)// 난수 생성 함수
{
	int su = rand() % t + m;
	return su;
}

void pickg()
{
	int a = ri(6, 1);
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
	case 3:
		g3();
		break;
	case 4:
		g4();
		break;
	case 5:
		g5();
		break;
	case 6:
		g6();
		break;
	}
}

void g1() // 사칙연산
{
	int jd;
	char g;
	int a = ri(10, 1);
	int b = ri(10, 1);
	int giho = ri(5, 1);
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
		printf("\n\n===== XXXXXXXXXXXXX 오답 XXXXXXXXXXXXX =====\n\n");
		(*fptr)++;
	}
}

void g2() // 문자열 따라 치기
{
	char cans[100];
	char tpt[4];
	for (int i = 0; i < 3; i++)
	{
		tpt[i] = 'a' + ri(26, 0);
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
		printf("\n\n===== XXXXXXXXXXXXX 오답 XXXXXXXXXXXXX =====\n\n");
		(*fptr)++;
	}
}

void g3() // n 번째 원소는?
{
	int n = rand() % 10 + 1;
	int list[10];
	for (int i = 0; i < 10; i++)
	{
		list[i] = ri(9, 0);
		printf("%d", list[i]);
	}
	printf("\n\n\n%d 번째 원소는?\n\n>> ", n);
	scanf("%d", ia);
	if (*ia == list[n - 1])
		printf("\n\n===== OOOOOOOOOOOOO 정답 OOOOOOOOOOOOO =====\n\n");
	else
	{
		printf("\n\n===== XXXXXXXXXXXXX 오답 XXXXXXXXXXXXX =====\n\n");
		(*fptr)++;
	}
}

void g4()// 같은 문자 n번 입력
{
	char ans[100];
	char k = 'a' + ri(26, 0);
	int n = ri(10, 1);
	char* jd = malloc(sizeof(char) * 10 + 1);
	for (int i = 0; i < n; i++)
	{
		jd[i] = k;
	}
	jd[n] = '\0';
	printf("\n\n%c 를 %d 번 입력하세요!\n\n>> ", k, n);
	scanf("%s", ans);
	if (strcmp(jd, ans) == 0)
	{
		printf("\n\n===== OOOOOOOOOOOOO 정답 OOOOOOOOOOOOO =====\n\n");
		free(jd);
	}
	else
	{
		printf("\n\n===== XXXXXXXXXXXXX 오답 XXXXXXXXXXXXX =====\n\n");
		(*fptr)++;
		free(jd);
	}
}

void g5()// 나머지 유무
{
	int a = ri(100, 1);
	int b = ri(9, 1);
	int yon;
	if (a % b == 0)
		yon = 1;
	else
		yon = 0;
	printf("\n\n나누어 떨어지면 1 아니면 0!\n\n %d / %d\n\n>> ", a, b);
	scanf("%d", ia);
	if (*ia == yon)
		printf("\n\n===== OOOOOOOOOOOOO 정답 OOOOOOOOOOOOO =====\n\n");
	else
	{
		printf("\n\n===== XXXXXXXXXXXXX 오답 XXXXXXXXXXXXX =====\n\n");
		(*fptr)++;
	}
}

void g6()// 이진수 십진수로
{
	int ejin[4];
	int jd = 0;
	for (int i = 0; i < 4; i++)
	{
		ejin[i] = ri(2, 0);
		printf("%d", ejin[i]);
		jd += ejin[i] * (1 << (3 - i));
	}
	printf("\n\n이진수를 십진수로 변환하세요!\n\n>> ");
	scanf("%d", ia);
	if (*ia == jd)
		printf("\n\n===== OOOOOOOOOOOOO 정답 OOOOOOOOOOOOO =====\n\n");
	else
	{
		printf("\n\n===== XXXXXXXXXXXXX 오답 XXXXXXXXXXXXX =====\n\n");
		(*fptr)++;
	}
}
