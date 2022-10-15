#include<stdio.h> //printf, scanf
#include<stdlib.h> //free, malloc
#include<string.h> //strcpy, strlen
#include"my_struct.h" //사용할 자료형
#define _CRT_SECURE_NO_WARINGS //scanf 보안 경고로 인한 컴파일 에러 방지

//함수 id_update를 void형으로 선언하고 매개변수(파라미터)로 전달된 인자를 받는다.
void id_update(user* u_head, rent* r_head) {

	//포인터변수 선언 및 초기화
	user* u_p = NULL; 
	user* uf_p = NULL; 
	rent* r_p = NULL; 
	u_p = u_head->next; 
	uf_p = u_head->next; 
	r_p = r_head->next;

	//변수 선언
	char id[1000];
	char update_id[1000];

	printf("회원의 id를 업데이트합니다.\n");
	printf("본인의 id를 입력해주세요: "); 
	scanf("%s", id);

	//입력한 id가 있는지 확인하는 과정
	while (u_p->next != NULL) {
		if (strcmp(u_p->user_id, id) == 0) {
			printf("id가 확인되었습니다.\n");
			break;
		}
		u_p = u_p->next;
	}
	if (u_p->next == NULL) {
		printf("입력하신 id가 존재하지 않습니다. 다시 시도해주세요.\n");
		return 0;
	}

	printf("수정하고싶은 id를 입력해주세요: "); 
	scanf("%s", update_id);

	//입력한 id가 중복되는지 확인하는 과정
	while (uf_p->next != NULL) {
		if (strcmp(uf_p->user_id, update_id) == 0) {
			printf("입력한 id가 이미 존재합니다. 다시 시도해주세요.\n");
			return 0;
		}
		uf_p = uf_p->next;
	}
	free(u_p->user_id); //u_p->user_id 메모리 해제
	u_p->user_id = (char*)malloc(sizeof(char) * strlen(update_id) + 1); //u_p->user_id 메모리 할당
	strcpy(u_p->user_id, update_id); //strcpy로 update_id에 있는 문자열을 u_p->user_id로 복사

	//user의 user_id를 업데이트했으므로 rent의 user_id도 업데이트
	while (r_p->next != NULL) {
		if (strcmp(r_p->user_id, id) == 0) {
			free(r_p->user_id); //r_p->user_id 메모리 해제
			r_p->user_id = (char*)malloc(sizeof(char) * strlen(update_id) + 1); //r_p->user_id 메모리 할당
			strcpy(r_p->user_id, update_id); //strcpy로 update_id에 있는 문자열을 r_p->user_id로 복사
		}
		r_p = r_p->next;
	}

	printf("id가 변경되었습니다.\n");
	user_store(u_head); //user_store 함수를 호출하고 인자들을 전달한다.
	rent_store(r_head); //rent_store 함수를 호출하고 인자들을 전달한다.
}

//함수 stock_update를 void형으로 선언하고 매개변수(파라미터)로 전달된 인자를 받는다.
void stock_update(video* v_head) {

	//포인터변수 선언 및 초기화
	video* p = NULL; 
	p = v_head->next;

	//변수 선언
	char title[1000];
	int update_stock; 
	int temp;

	printf("비디오의 재고를 업데이트합니다.\n");
	printf("수정하고싶은 재고의 비디오 제목을 입력하세요: "); scanf("%s", title);

	//입력한 title이 있는지 확인하는 과정
	while (p->next != NULL) {
		if (strcmp(p->video_title, title) == 0) {
			printf("비디오가 확인되었습니다.\n");
			break;
		}
		p = p->next;
	}
	if (p->next == NULL) {
		printf("입력하신 비디오가 존재하지 않습니다. 다시 시도해주세요.\n");
		return 0;
	}

	printf("재고를 추가 또는 줄이려는 수량을 입력해주세요: "); 
	scanf("%d", &update_stock);
	temp = p->stock;
	p->stock += update_stock; //p->stock = p->stock + update_stock
	if (p->stock < 0) {
		p->stock = temp;
		printf("재고가 0 미만입니다. 다시 시도해주세요.\n");
		return 0;
	}

	printf("재고가 변경되었습니다.\n");
	video_store(v_head); //video_store 함수를 호출하고 인자들을 전달한다.
}

//함수 return_update를 void형으로 선언하고 매개변수(파라미터)로 전달된 인자를 받는다.
void return_update(rent* r_head) {

	//포인터변수 선언 및 초기화
	rent* p = NULL; 
	p = r_head->next;

	//변수 선언
	int cnt = 0; 
	char id[1000];
	char title[1000];
	char update_return[1000];

	printf("반납날짜를 업데이트합니다.\n");
	printf("대여한 회원의 id를 입력해주세요: "); 
	scanf("%s", id);

	//입력한 id가 빌린 비디오 제목외 나머지 정보들을 보여주는 과정
	while (p->next != NULL) {
		if (strcmp(p->user_id, id) == 0) {
			cnt++;
			printf("회원 id: %s, 비디오 제목: %s, 대여날짜: %s, 반납날짜: %s\n"
				, p->user_id, p->video_title, p->rent_date, p->return_date);
		}
		p = p->next;
	}
	if (cnt == 0) {
		printf("대여한 회원의 id가 존재하지 않습니다. 다시 시도해주세요.\n");
		return 0;
	}

	p = r_head->next;
	printf("수정하고싶은 반납날짜의 비디오 제목을 입력해주세요: "); 
	scanf("%s", title);

	//입력한 title이 있는지 확인하는 과정
	while (p->next != NULL) {
		if (strcmp(p->video_title, title) == 0) {
			printf("비디오가 확인되었습니다.\n");
			break;
		}
		p = p->next;
	}
	if (p->next == NULL) {
		printf("입력하신 비디오가 존재하지 않습니다. 다시 시도해주세요.\n");
		return 0;
	}

	printf("수정하고싶은 반납날짜를 입력해주세요: "); 
	scanf("%s", update_return);
	free(p->return_date); //p->return_date 메모리 해제
	p->return_date = (char*)malloc(sizeof(char) * strlen(update_return) + 1); //p->return_date 메모리 할당
	strcpy(p->return_date, update_return); //strcpy로 update_return에 있는 문자열을 p->return_date로 복사
	printf("반납날짜가 변경되었습니다.\n");
	rent_store(r_head); //rent_store 함수를 호출하고 인자들을 전달한다.
}