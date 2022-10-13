#include<stdio.h> //printf, scanf
#include"my_struct.h" //사용할 자료형
#define _CRT_SECURE_NO_WARINGS //scanf 보안 경고로 인한 컴파일 에러 방지

//함수 user_find를 void형으로 선언하고 매개변수(파라미터)로 전달된 인자를 받는다.
void user_find(user* u_head) {

	//포인터변수 선언 및 초기화
	user* p = NULL; 
	p = u_head->next;

	//변수 선언
	int cnt = 0; 
	char name[10];

	printf("가입자를 검색합니다.\n");
	printf("검색하고싶은 가입자 이름을 입력해주세요: "); scanf("%s", name);

	//입력한 name의 정보들을 보여주는 과정
	while (p->next != NULL) {
		if (strcmp(p->user_name, name) == 0) {
			cnt++;
			printf("가입자 이름: %s, 가입자 id: %s\n", p->user_name, p->user_id);
		}
		p = p->next;
	}
	if (cnt == 0) {
		printf("가입자가 존재하지 않습니다. 다시 시도해주세요.\n");
	}
}

//함수 video_find를 void형으로 선언하고 매개변수(파라미터)로 전달된 인자를 받는다.
void video_find(video* v_head) {

	char title[30]; //변수 선언

	//포인터변수 선언 및 초기화
	video* p = NULL; 
	p = v_head->next;

	printf("비디오를 검색합니다.\n");
	printf("검색하고싶은 비디오 제목을 입력해주세요: "); scanf("%s", title);

	//입력한 title의 정보들을 보여주는 과정
	while (p->next != NULL) {
		if (strcmp(p->video_title, title) == 0) {
			printf("비디오 제목: %s, 비디오 재고: %d\n", p->video_title, p->stock);
			break;
		}
		p = p->next;
	}
	if (p->next == NULL) {
		printf("비디오가 존재하지 않습니다. 다시 시도해주세요.\n");
	}
}

//함수 rent_user_find를 void형으로 선언하고 매개변수(파라미터)로 전달된 인자를 받는다.
void rent_user_find(rent* r_head) {

	//변수 선언
	char id[10]; 
	int cnt = 0;

	//포인터변수 선언 및 초기화
	rent* p = NULL; 
	p = r_head->next;

	printf("대여한 가입자를 검색합니다.\n");
	printf("대여한 가입자의 id를 입력해주세요: "); scanf("%s", id);

	//입력한 id의 정보들을 보여주는 과정
	while (p->next != NULL) {
		if (strcmp(p->user_id, id) == 0) {
			cnt++;
			printf("가입자 id: %s, 비디오 제목: %s, 대여날짜: %s, 반납날짜: %s\n"
				, p->user_id, p->video_title, p->rent_date, p->return_date);
		}
		p = p->next;
	}
	if (cnt == 0) {
		printf("대여한 가입자의 id가 존재하지 않습니다. 다시 시도해주세요.\n");
	}
}
