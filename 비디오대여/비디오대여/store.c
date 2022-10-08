// fopen, fclose, fprintf, fscanf
#include<stdio.h>
// 사용할 자료형
#include"my_struct.h"
//fopen 보안 경고로 인한 컴파일 에러 방지
#define _CRT_SECURE_NO_WARINGS

void user_store(user* u_head) {

	// 포인터변수 선언 및 초기화
	user* p = NULL;
	p = u_head->next;
	FILE* fp = NULL;

	// PHONE_BOOK.txt 파일을 w(쓰기) 모드로 열기
	fp = fopen("USER_FILE.txt", "w");

	// file_p->next가 NULL이 아니면 반복문을 돌리고 NULL이 되면 반복문을 종료한다.
	while (p->next != NULL) {

		/*
		fprintf: 문자열을 파일에 저장
		file_p->next->next가 NULL이면 fprintf 아니면 else로 이동하고 fprintf
		파일 끝에 공백을 두지 않기 위함.
		*/
		if (p->next->next == NULL) {
			fprintf(fp, "%s %s", p->user_id, p->user_name);
		}
		else {
			fprintf(fp, "%s %s\n", p->user_id, p->user_name);
		}

		// 포인터변수 file_p는 file_p->next를 가리킨다.
		p = p->next;
	}
	// 파일 포인터 닫기
	fclose(fp);
}

void video_store(video* v_head) {

	// 포인터변수 선언 및 초기화
	video* p = NULL;
	p = v_head->next;
	FILE* fp = NULL;

	// PHONE_BOOK.txt 파일을 w(쓰기) 모드로 열기
	fp = fopen("VIDEO_FILE.txt", "w");

	// file_p->next가 NULL이 아니면 반복문을 돌리고 NULL이 되면 반복문을 종료한다.
	while (p->next != NULL) {

		/*
		fprintf: 문자열을 파일에 저장
		file_p->next->next가 NULL이면 fprintf 아니면 else로 이동하고 fprintf
		파일 끝에 공백을 두지 않기 위함.
		*/
		if (p->next->next == NULL) {
			fprintf(fp, "%s %d", p->video_title, p->stock);
		}
		else {
			fprintf(fp, "%s %d\n", p->video_title, p->stock);
		}

		// 포인터변수 file_p는 file_p->next를 가리킨다.
		p = p->next;
	}
	// 파일 포인터 닫기
	fclose(fp);
}

void rent_store(rent* r_head) {

	// 포인터변수 선언 및 초기화
	rent* p = NULL;
	p = r_head->next;
	FILE* fp = NULL;

	// PHONE_BOOK.txt 파일을 w(쓰기) 모드로 열기
	fp = fopen("RENT_FILE.txt", "w");

	// file_p->next가 NULL이 아니면 반복문을 돌리고 NULL이 되면 반복문을 종료한다.
	while (p->next != NULL) {

		/*
		fprintf: 문자열을 파일에 저장
		file_p->next->next가 NULL이면 fprintf 아니면 else로 이동하고 fprintf
		파일 끝에 공백을 두지 않기 위함.
		*/
		if (p->next->next == NULL) {
			fprintf(fp, "%s %s %s %s", p->video_title, p->user_id, p->rent_date, p->return_date);
		}
		else {
			fprintf(fp, "%s %s %s %s\n", p->video_title, p->user_id, p->rent_date, p->return_date);
		}

		// 포인터변수 file_p는 file_p->next를 가리킨다.
		p = p->next;
	}
	// 파일 포인터 닫기
	fclose(fp);
}