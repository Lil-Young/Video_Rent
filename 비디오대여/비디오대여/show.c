// printf, scanf
#include<stdio.h>
// 사용할 자료형
#include"my_struct.h"
// scanf 보안 경고로 인한 컴파일 에러 방지
#define _CRT_SECURE_NO_WARINGS

// 대여가능한 비디오 목록 출력
void video_show(video* v_head) {
	video* p = NULL;
	p = v_head->next;
	if (p->next == NULL) {
		printf("대여가능한 비디오가 존재하지 않습니다.\n");
		return 0;
	}
	printf("*** 대여가능한 비디오 목록입니다. ***\n");
	while (p->next != NULL) {
		if (p->stock != 0) {
			printf("비디오 제목: %s, 비디오 재고: %d\n", p->video_title, p->stock);
		}
		p = p->next;
	}
}

// 가입자의 이름과 id 출력
void user_show(user* u_head) {
	user* p = NULL;
	p = u_head->next;
	if (p->next == NULL) {
		printf("가입자가 존재하지 않습니다.\n");
		return 0;
	}
	printf("*** 가입자 목록입니다. ***\n");
	while (p->next != NULL) {
		printf("가입자 이름: %s, 가입자 id: %s\n", p->user_name, p->user_id);
		p = p->next;
	}
}

void rent_show(rent* r_head) {
	rent* p = NULL;
	p = r_head->next;
	if (p->next == NULL) {
		printf("비디오를 대여한 가입자가 존재하지 않습니다.\n");
		return 0;
	}
	printf("*** 비디오를 대여한 가입자 id와 비디오 목록입니다. ***\n");
	while (p->next != NULL) {
		printf("가입자 id: %s, 비디오 제목: %s, 대여날짜: %s, 반납날짜: %s\n"
			, p->user_id, p->video_title, p->rent_date, p->return_date);
		p = p->next;
	}
}

void delayed_date(rent* r_head) {
	rent* p = NULL;
	p = r_head->next;
	char date[10]; 
	int cnt = 0;

	printf("*** 반납날짜가 지난 가입자 id와 비디오 목록입니다 ***.\n");
	printf("오늘 날짜를 입력해주세요: "); scanf("%s", date);
	while (p->next != NULL) {
		if (strcmp(p->return_date, date) < 0) {
			cnt++;
			printf("가입자 id: %s, 비디오 제목: %s, 대여날짜: %s, 반납날짜: %s\n"
				, p->user_id, p->video_title, p->rent_date, p->return_date);
		}
		p = p->next;
	}
	if (cnt == 0) {
		printf("반납날짜가 지난 가입자가 존재하지 않습니다.\n");
		return 0;
	}
}