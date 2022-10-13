#include<stdio.h> //fopen, fclose, fprintf, fscanf
#include"my_struct.h" //사용할 자료형
#define _CRT_SECURE_NO_WARINGS //fopen 보안 경고로 인한 컴파일 에러 방지

//함수 user_store를 void형으로 선언하고 매개변수(파라미터)로 전달된 인자를 받는다.
void user_store(user* u_head) {

	//포인터변수 선언 및 초기화
	user* p = NULL;	
	p = u_head->next; 
	FILE* fp = NULL;

	fp = fopen("USER_FILE.txt", "w"); //USER_FILE.txt 파일을 w(쓰기) 모드로 열기

	//파일에 저장하는 과정
	while (p->next != NULL) {
		/*
		fprintf: 문자열을 파일에 저장
		p->next->next가 NULL이면 fprintf 아니면 else로 이동하고 fprintf
		파일 끝에 공백을 두지 않기 위함.
		*/
		if (p->next->next == NULL) {
			fprintf(fp, "%s %s", p->user_id, p->user_name);
		}
		else {
			fprintf(fp, "%s %s\n", p->user_id, p->user_name);
		}
		p = p->next; //포인터변수 p는 p->next를 가리킨다.
	}
	fclose(fp); //파일 포인터 닫기
}

//함수 video_store를 void형으로 선언하고 매개변수(파라미터)로 전달된 인자를 받는다.
void video_store(video* v_head) {

	//포인터변수 선언 및 초기화
	video* p = NULL; 
	p = v_head->next; 
	FILE* fp = NULL;

	fp = fopen("VIDEO_FILE.txt", "w"); //VIDEO_FILE.txt 파일을 w(쓰기) 모드로 열기

	//파일에 저장하는 과정
	while (p->next != NULL) {
		/*
		fprintf: 문자열을 파일에 저장
		p->next->next가 NULL이면 fprintf 아니면 else로 이동하고 fprintf
		파일 끝에 공백을 두지 않기 위함.
		*/
		if (p->next->next == NULL) {
			fprintf(fp, "%s %d", p->video_title, p->stock);
		}
		else {
			fprintf(fp, "%s %d\n", p->video_title, p->stock);
		}
		p = p->next; //포인터변수 p는 p->next를 가리킨다.
	}
	fclose(fp); //파일 포인터 닫기
}

//함수 rent_store를 void형으로 선언하고 매개변수(파라미터)로 전달된 인자를 받는다.
void rent_store(rent* r_head) {
	//포인터변수 선언 및 초기화
	rent* p = NULL; 
	p = r_head->next; 
	FILE* fp = NULL;

	fp = fopen("RENT_FILE.txt", "w"); //RENT_FILE.txt 파일을 w(쓰기) 모드로 열기

	//파일에 저장하는 과정
	while (p->next != NULL) {
		/*
		fprintf: 문자열을 파일에 저장
		p->next->next가 NULL이면 fprintf 아니면 else로 이동하고 fprintf
		파일 끝에 공백을 두지 않기 위함.
		*/
		if (p->next->next == NULL) {
			fprintf(fp, "%s %s %s %s", p->video_title, p->user_id, p->rent_date, p->return_date);
		}
		else {
			fprintf(fp, "%s %s %s %s\n", p->video_title, p->user_id, p->rent_date, p->return_date);
		}
		p = p->next; //포인터변수 p는 p->next를 가리킨다.
	}
	fclose(fp); //파일 포인터 닫기
}

//함수 return_store를 void형으로 선언하고 매개변수(파라미터)로 전달된 인자를 받는다.
void return_store(rent* return_head) {

	//포인터변수 선언 및 초기화
	rent* p = NULL; 
	p = return_head->next; 
	FILE* fp = NULL;

	fp = fopen("RETURN_FILE.txt", "w"); //RETURN_FILE.txt 파일을 w(쓰기) 모드로 열기

	//파일에 저장하는 과정
	while (p->next != NULL) {
		/*
		fprintf: 문자열을 파일에 저장
		p->next->next가 NULL이면 fprintf 아니면 else로 이동하고 fprintf
		파일 끝에 공백을 두지 않기 위함.
		*/
		if (p->next->next == NULL) {
			fprintf(fp, "%s %s %s %s", p->video_title, p->user_id, p->rent_date, p->return_date);
		}
		else {
			fprintf(fp, "%s %s %s %s\n", p->video_title, p->user_id, p->rent_date, p->return_date);
		}
		p = p->next; //포인터변수 p는 p->next를 가리킨다.
	}
	fclose(fp); //파일 포인터 닫기
}