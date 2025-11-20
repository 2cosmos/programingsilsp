#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>
#include <mmsystem.h>

// 정답과 틀리면 스테이지는 그대로, 다른 문제 나옴

#pragma comment(lib,"winmm.lib")

int ifail; // 실패?
int* fptr = &ifail; // 실패 포인터
int life = 3; // 생명
int intans; // 정수가 답일 때
int* ia = &intans; // 정수 답 포인터
void right(); // 정답 효과음 재생
int ri(int t, int m); // 난수 생성 함수
void pickg(); // 난수 생성 후 caseg 에 보냄
void caseg(int n); // 각각에 해당하는 미니게임을 실행시킴
void g1(); // 게임
void g2();
void g3();
void g4();
void g5();
void g6();
void g7();
void g8();
void g9();
void g10();

int main()
{
	srand(time(NULL));
	// 시작 전 알림
	printf("====================\n\n노래가 끝날 때까지 40개의 미니게임을 전부 클리어하세요!\n노래의 길이는 1분 4초 입니다!\n목숨은 총 세 개 이며 문제를 틀릴 때마다 하나 씩 차감됩니다!\n목숨이 0 이 되거나 음악이 종료되면 게임이 끝납니다!\n행운을 빌어요!!\n(이건 외워두세요!)\n\n{\n강! : l\n중! : k\n약! : j\n}\n\n====================\n\n\n");
	//PlaySound(TEXT("ready.wav"), NULL, SND_ASYNC);
	mciSendString(TEXT("open \"ready.wav\" type waveaudio alias ready"), NULL, 0, NULL);
	mciSendString(TEXT("play ready"), NULL, 0, NULL);
	Sleep(14200);
	// 카운트 다운
	for (int i = 0; i < 3; i++)
	{
		PlaySound(TEXT("ding.wav"), NULL, SND_ASYNC);
		Sleep(600);
		printf("%d\n\n", 3 - i);
		Sleep(400);
	}
	Sleep(600);
	printf("====================\n\n시작!!!\n\n====================\n\n\n\n");
	//PlaySound(TEXT("tumble.wav"), NULL, SND_ASYNC || SND_LOOP);

	int soundplayskstn = ri(2, 1);
	if (soundplayskstn == 1)
	{
		mciSendString(TEXT("open \"tumble.wav\" type waveaudio alias tumble"), NULL, 0, NULL);
		mciSendString(TEXT("play tumble"), NULL, 0, NULL);
	}
	else if (soundplayskstn == 2)
	{
		mciSendString(TEXT("open \"choptumble.wav\" type waveaudio alias tumble"), NULL, 0, NULL);
		mciSendString(TEXT("play tumble"), NULL, 0, NULL);
	}

	// 시작
	time_t st = time(NULL); // 시작 시간
	for (int i = 0; i < 40; i++)
	{
		ifail = 0;
		if (i != 40)
			printf("\n\n%d 번째 문제!\n\n", i + 1);
		else if (i == 40)
			printf("\n\n LAST!!!!!!!\n\n");
		*fptr = 0;
		*ia = -10000;
		pickg();
		if (ifail)
		{
			//PlaySound(TEXT("wrong.wav"), NULL, SND_ASYNC);
			mciSendString(TEXT("close wrong"), NULL, 0, NULL);
			mciSendString(TEXT("open \"wrong.wav\" type waveaudio alias wrong"), NULL, 0, NULL);
			mciSendString(TEXT("play wrong"), NULL, 0, NULL);
			i--;
			life--;
			printf("남은 생명 %d", life);
			if (life == 0)
			{
				printf("\n\n남은 기회 전부 소진.. 실패!!\n\n");
				exit(0);
			}
		}
		if (time(NULL) - st >= 64)
		{
			printf("\n\n시간 종료.. 실패했습니다...\n\n");
			exit(0);
		}
	}
	printf("\n\n\n==================== 전부 클리어 하셨어요! 축하드립니다..... ====================\n\n\n");
}

// 함수 시작

void right()
{
	mciSendString(TEXT("close crr"), NULL, 0, NULL);
	mciSendString(TEXT("open \"cringring.wav\" type waveaudio alias crr"), NULL, 0, NULL);
	mciSendString(TEXT("play crr"), NULL, 0, NULL);
}

int ri(int t, int m)// 난수 생성 함수
{
	int su = rand() % t + m;
	return su;
}

void pickg()
{
	int a = ri(9, 1);
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
	case 7:
		g7();
		break;
	case 8:
		g8();
		break;
	case 9:
		g9();
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
	printf("계산 하세요!\n\n%d %c %d = ??\n\n>> ", a, g, b);
	scanf("%d", ia);
	if (*ia == jd)
	{
		//PlaySound(TEXT("cringring.wav"), NULL, SND_ASYNC);
		right();
		printf("\n\n===== OOOOOOOOOOOOO 정답 OOOOOOOOOOOOO =====\n\n");
	}
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
	printf("\n\n따라 치세요!\n\n");
	for (int i = 0; i < 3; i++)
	{
		printf("%c", tpt[i]);
	}
	printf("\n\n>> ");
	scanf("%s", cans);
	if (strcmp(tpt, cans) == 0)
	{
		//PlaySound(TEXT("cringring.wav"), NULL, SND_ASYNC);
		right();
		printf("\n\n===== OOOOOOOOOOOOO 정답 OOOOOOOOOOOOO =====\n\n");
	}
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
		printf("%d ", list[i]);
	}
	printf("\n\n%d 번째 원소는?\n\n>> ", n);
	scanf("%d", ia);
	if (*ia == list[n - 1])
	{
		//PlaySound(TEXT("cringring.wav"), NULL, SND_ASYNC);
		right();
		printf("\n\n===== OOOOOOOOOOOOO 정답 OOOOOOOOOOOOO =====\n\n");
	}
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
		//PlaySound(TEXT("cringring.wav"), NULL, SND_ASYNC);
		right();
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
	{
		//PlaySound(TEXT("cringring.wav"), NULL, SND_ASYNC);
		right();
		printf("\n\n===== OOOOOOOOOOOOO 정답 OOOOOOOOOOOOO =====\n\n");
	}
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
	{
		//PlaySound(TEXT("cringring.wav"), NULL, SND_ASYNC);
		right();
		printf("\n\n===== OOOOOOOOOOOOO 정답 OOOOOOOOOOOOO =====\n\n");
	}
	else
	{
		printf("\n\n===== XXXXXXXXXXXXX 오답 XXXXXXXXXXXXX =====\n\n");
		(*fptr)++;
	}
}

void g7() // 오름차순 정렬
{
	int a, b, c, d, q, w, e, r;
	printf("\n\n");
	int arr[4];
	for (int i = 0; i < 4; i++)
	{
		arr[i] = ri(9, 0);
		printf("%d ", arr[i]);
	}
	for (int i = 0; i < 4; i++) // 3 0 7 2
	{
		int min = arr[i];
		for (int j = i; j < 4; j++)
		{
			if (min >= arr[j])
			{
				int tp = arr[j];
				arr[j] = arr[i];
				arr[i] = tp;
				min = tp;
			}
		}
	}
	a = arr[0];
	b = arr[1];
	c = arr[2];
	d = arr[3];
	printf("\n\n공백 포함 ↑오름↑ 차순으로 정렬하세요!\n\n>> ");
	scanf("%d %d %d %d", &q, &w, &e, &r);
	if (q == a && w == b && e == c && r == d)
	{
		//PlaySound(TEXT("cringring.wav"), NULL, SND_ASYNC);
		right();
		printf("\n\n===== OOOOOOOOOOOOO 정답 OOOOOOOOOOOOO =====\n\n");
	}
	else
	{
		printf("\n\n===== XXXXXXXXXXXXX 오답 XXXXXXXXXXXXX =====\n\n");
		(*fptr)++;
	}
}
void g8() // 내림차순 정렬
{
	int a, b, c, d, q, w, e, r;
	printf("\n\n");
	int arr[4];
	for (int i = 0; i < 4; i++)
	{
		arr[i] = ri(9, 0);
		printf("%d ", arr[i]);
	}
	for (int i = 0; i < 4; i++) // 3 0 7 2
	{
		int max = arr[i];
		for (int j = i; j < 4; j++)
		{
			if (max <= arr[j])
			{
				int tp = arr[j];
				arr[j] = arr[i];
				arr[i] = tp;
				max = tp;
			}
		}
	}
	a = arr[0];
	b = arr[1];
	c = arr[2];
	d = arr[3];
	printf("\n\n공백 포함 ↓내림↓ 차순으로 정렬하세요!\n\n>> ");
	scanf("%d %d %d %d", &q, &w, &e, &r);
	if (q == a && w == b && e == c && r == d)
	{
		//PlaySound(TEXT("cringring.wav"), NULL, SND_ASYNC);
		right();
		printf("\n\n===== OOOOOOOOOOOOO 정답 OOOOOOOOOOOOO =====\n\n");
	}
	else
	{
		printf("\n\n===== XXXXXXXXXXXXX 오답 XXXXXXXXXXXXX =====\n\n");
		(*fptr)++;
	}
}
void g9()
{
	char segi;
	char ans;
	char jd;
	int cs = ri(3, 1);
	switch (cs)
	{
	case 1:
		printf("\n\n강!\n\n>> ");
		jd = 'l';
		break;
	case 2:
		printf("\n\n중!\n\n>> ");
		jd = 'k';
		break;
	case 3:
		printf("\n\n약!\n\n>> ");
		jd = 'j';
		break;
	}
	scanf(" %c", &ans);
	if (ans == jd)
	{
		right();
		printf("\n\n===== OOOOOOOOOOOOO 정답 OOOOOOOOOOOOO =====\n\n");
	}
	else
	{
		printf("\n\n===== XXXXXXXXXXXXX 오답 XXXXXXXXXXXXX =====\n\n");
		(*fptr)++;
	}
}
void g10()
{

}
