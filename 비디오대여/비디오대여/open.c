// fopen, fclose, fscanf, printf
#include<stdio.h>
// free, malloc
#include<stdlib.h>
// strcpy, strcmp
#include<string.h>
// 사용할 자료형
#include"my_struct.h"

// 함수 open_F을 void형으로 선언하고 매개변수(파라미터)로 전달된 인자를 받는다.
void user_open(user* u_tail) {

	// 포인터변수 선언 및 초기화
	user* p = NULL;
	user* newNode = NULL;
	FILE* fp = NULL;

	// 변수 선언
	char id[10];
	char name[10];

	// 변수 선언 및 초기화
	int is_eof = 0;

	// PHONE_BOOK.txt 파일을 r(읽기) 모드로 열기
	fp = fopen("USER_FILE.txt", "r");
	// fp가 NULL이면 printf 아니면 else로 이동하고 printf
	if (fp == NULL) {
		printf("USER_FILE이 존재하지 않습니다.\n");
		return 0;
	}
	else {
		printf("USER_FILE을 불러옵니다.\n");
	}

	// 무한루프
	while (1) {
		// fscanf(fp, "%s %s", name, number)에서 name, number의 값을 읽을 수 없으면 EOF를 반환
		is_eof = fscanf(fp, "%s %s", id, name);

		// is_eof와 EOF가 일치하면 파일의 끝이므로 반복문을 탈출하기 위해 break를 한다.
		if (is_eof == EOF) {
			break;
		}
		// newNode, newNode->name, newNode->phone_num 메모리 할당
		newNode = (user*)malloc(sizeof(user));
		newNode->user_id = (char*)malloc(sizeof(char) * strlen(id) + 1);
		newNode->user_name = (char*)malloc(sizeof(char) * strlen(name) + 1);

		// strcpy로 name에 있는 문자열을 newNode->name으로 복사, number에 있는 문자열을 newNode->phone_num으로 복사
		strcpy(newNode->user_id, id);
		strcpy(newNode->user_name, name);


		// newNode 연결
		p = u_tail->prev;
		newNode->next = p->next;
		newNode->prev = p;
		p->next = newNode;
		u_tail->prev = newNode;
	}
	// 파일 포인터 닫기
	fclose(fp);
}

// 함수 open_F을 void형으로 선언하고 매개변수(파라미터)로 전달된 인자를 받는다.
void video_open(video* v_tail) {

	// 포인터변수 선언 및 초기화
	video* p = NULL;
	video* newNode = NULL;
	FILE* fp = NULL;

	// 변수 선언
	char title[30];
	int stock;

	// 변수 선언 및 초기화
	int is_eof = 0;

	// PHONE_BOOK.txt 파일을 r(읽기) 모드로 열기
	fp = fopen("VIDEO_FILE.txt", "r");
	// fp가 NULL이면 printf 아니면 else로 이동하고 printf
	if (fp == NULL) {
		printf("VIDEO_FILE이 존재하지 않습니다.\n");
		return 0;
	}
	else {
		printf("VIDEO_FILE을 불러옵니다.\n");
	}

	// 무한루프
	while (1) {
		// fscanf(fp, "%s %s", name, number)에서 name, number의 값을 읽을 수 없으면 EOF를 반환
		is_eof = fscanf(fp, "%s %d", title, &stock);

		// is_eof와 EOF가 일치하면 파일의 끝이므로 반복문을 탈출하기 위해 break를 한다.
		if (is_eof == EOF) {
			break;
		}
		// newNode, newNode->name, newNode->phone_num 메모리 할당
		newNode = (user*)malloc(sizeof(user));
		newNode->video_title = (char*)malloc(sizeof(char) * strlen(title) + 1);

		// strcpy로 name에 있는 문자열을 newNode->name으로 복사, number에 있는 문자열을 newNode->phone_num으로 복사
		strcpy(newNode->video_title, title);
		newNode->stock = stock;


		// newNode 연결
		p = v_tail->prev;
		newNode->next = p->next;
		newNode->prev = p;
		p->next = newNode;
		v_tail->prev = newNode;
	}
	// 파일 포인터 닫기
	fclose(fp);
}

void rent_open(rent* r_tail) {

	// 포인터변수 선언 및 초기화
	rent* p = NULL;
	rent* newNode = NULL;
	FILE* fp = NULL;

	// 변수 선언
	char title[30];
	char id[10];
	char rent_d[10];
	char return_d[10];

	// 변수 선언 및 초기화
	int is_eof = 0;

	// PHONE_BOOK.txt 파일을 r(읽기) 모드로 열기
	fp = fopen("RENT_FILE.txt", "r");
	// fp가 NULL이면 printf 아니면 else로 이동하고 printf
	if (fp == NULL) {
		printf("RENT_FILE이 존재하지 않습니다.\n");
		return 0;
	}
	else {
		printf("RENT_FILE을 불러옵니다.\n");
	}

	// 무한루프
	while (1) {
		// fscanf(fp, "%s %s", name, number)에서 name, number의 값을 읽을 수 없으면 EOF를 반환
		is_eof = fscanf(fp, "%s %s %s %s", title, id, rent_d, return_d);

		// is_eof와 EOF가 일치하면 파일의 끝이므로 반복문을 탈출하기 위해 break를 한다.
		if (is_eof == EOF) {
			break;
		}
		// newNode, newNode->name, newNode->phone_num 메모리 할당
		newNode = (rent*)malloc(sizeof(rent));
		newNode->video_title = (char*)malloc(sizeof(char) * strlen(title) + 1);
		newNode->user_id = (char*)malloc(sizeof(char) * strlen(id) + 1);
		newNode->rent_date = (char*)malloc(sizeof(char) * strlen(rent_d) + 1);
		newNode->return_date = (char*)malloc(sizeof(char) * strlen(return_d) + 1);

		// strcpy로 name에 있는 문자열을 newNode->name으로 복사, number에 있는 문자열을 newNode->phone_num으로 복사
		strcpy(newNode->video_title, title);
		strcpy(newNode->user_id, id);
		strcpy(newNode->rent_date, rent_d);
		strcpy(newNode->return_date, return_d);

		// newNode 연결
		p = r_tail->prev;
		newNode->next = p->next;
		newNode->prev = p;
		p->next = newNode;
		r_tail->prev = newNode;
	}
	// 파일 포인터 닫기
	fclose(fp);
}