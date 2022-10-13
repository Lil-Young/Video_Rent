#include<stdio.h> //printf, scanf
#include"my_struct.h" //사용할 자료형
#define _CRT_SECURE_NO_WARINGS //scanf 보안 경고로 인한 컴파일 에러 방지

//함수 user_video_show를 void형으로 선언하고 매개변수(파라미터)로 전달된 인자를 받는다.
void user_video_show(video* v_head) {

	//포인터변수 선언 및 초기화
	video* p = NULL; 
	p = v_head->next;

	printf("대여가능한 비디오를 보여줍니다.\n");
	if (p->next == NULL) {
		printf("대여가능한 비디오가 존재하지 않습니다. 다시 시도해주세요.\n");
		return 0;
	}
	printf("*** 대여가능한 비디오 목록입니다. ***\n");

	//대여 가능한 비디오(들)를 보여주는 과정
	while (p->next != NULL) {
		if (p->stock != 0) {
			printf("비디오 제목: %s, 비디오 재고: %d\n", p->video_title, p->stock);
		}
		p = p->next;
	}
}

//함수 all_video_show를 void형으로 선언하고 매개변수(파라미터)로 전달된 인자를 받는다.
void all_video_show(video* v_head) {

	//포인터변수 선언 및 초기화
	video* p = NULL; 
	p = v_head->next;
	printf("모든 비디오를 보여줍니다.\n");
	if (p->next == NULL) {
		printf("비디오가 존재하지 않습니다. 다시 시도해주세요.\n");
		return 0;
	}
	printf("*** 모든 비디오 목록입니다. ***\n");

	//모든 비디오(들)를 보여주는 과정
	while (p->next != NULL) {
		printf("비디오 제목: %s, 비디오 재고: %d\n", p->video_title, p->stock);
		p = p->next;
	}
}

//함수 user_show를 void형으로 선언하고 매개변수(파라미터)로 전달된 인자를 받는다.
void user_show(user* u_head) {

	//포인터변수 선언 및 초기화
	user* p = NULL; 
	p = u_head->next;
	printf("가입자를 보여줍니다.\n");
	if (p->next == NULL) {
		printf("가입자가 존재하지 않습니다. 다시 시도해주세요.\n");
		return 0;
	}
	printf("*** 가입자 목록입니다. ***\n");

	//가입자(들)를 보여주는 과정
	while (p->next != NULL) {
		printf("가입자 이름: %s, 가입자 id: %s\n", p->user_name, p->user_id);
		p = p->next;
	}
}

//함수 rent_show를 void형으로 선언하고 매개변수(파라미터)로 전달된 인자를 받는다.
void rent_show(rent* r_head) {

	//포인터변수 선언 및 초기화
	rent* p = NULL;
	p = r_head->next;

	printf("비디오를 대여한 가입자의 정보를 보여줍니다.\n");
	if (p->next == NULL) {
		printf("비디오를 대여한 가입자가 존재하지 않습니다. 다시 시도해주세요.\n");
		return 0;
	}
	printf("*** 비디오를 대여한 가입자 id와 비디오 목록입니다. ***\n");

	//비디오를 대여한 가입자(들)를 보여주는 과정
	while (p->next != NULL) {
		printf("가입자 id: %s, 비디오 제목: %s, 대여날짜: %s, 반납날짜: %s\n"
			, p->user_id, p->video_title, p->rent_date, p->return_date);
		p = p->next;
	}
}

//함수 delayed_date를 void형으로 선언하고 매개변수(파라미터)로 전달된 인자를 받는다.
void delayed_date(rent* r_head) {

	//포인터변수 선언 및 초기화
	rent* p = NULL; 
	p = r_head->next;

	//변수 선언
	char date[10];
	int cnt = 0;

	printf("반납날짜가 지난 가입자의 정보를 보여줍니다.\n");
	if (p->next == NULL) {
		printf("비디오를 대여한 가입자가 존재하지 않습니다. 다시 시도해주세요.\n");
		return 0;
	}
	printf("*** 반납날짜가 지난 가입자 id와 비디오 목록입니다 ***.\n");
	printf("오늘 날짜를 입력해주세요: "); scanf("%s", date);

	//입력한 date보다 높은(반납날짜가지난) 가입자(들)를 보여주는 과정
	while (p->next != NULL) {
		if (strcmp(p->return_date, date) < 0) {
			cnt++;
			printf("가입자 id: %s, 비디오 제목: %s, 대여날짜: %s, 반납날짜: %s\n"
				, p->user_id, p->video_title, p->rent_date, p->return_date);
		}
		p = p->next;
	}
	if (cnt == 0) {
		printf("반납날짜가 지난 가입자가 존재하지 않습니다. 다시 시도해주세요.\n");
		return 0;
	}
}

//함수 return_show를 void형으로 선언하고 매개변수(파라미터)로 전달된 인자를 받는다.
void return_show(rent* return_head) {

	//포인터변수 선언 및 초기화
	rent* p = NULL; 
	p = return_head->next;

	printf("비디오를 반납을 완료한 가입자의 정보를 보여줍니다.\n");
	if (p->next == NULL) {
		printf("비디오를 반납한 가입자가 존재하지 않습니다. 다시 시도해주세요.\n");
		return 0;
	}
	printf("*** 비디오를 반납한 가입자 id와 비디오 목록입니다. ***\n");

	//비디오를 반납한 가입자(들)를 보여주는 과정
	while (p->next != NULL) {
		printf("가입자 id: %s, 비디오 제목: %s, 대여날짜: %s, 반납날짜: %s\n"
			, p->user_id, p->video_title, p->rent_date, p->return_date);
		p = p->next;
	}
}