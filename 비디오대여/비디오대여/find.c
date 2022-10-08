// printf, scanf
#include<stdio.h>
// 사용할 자료형
#include"my_struct.h"
// scanf 보안 경고로 인한 컴파일 에러 방지
#define _CRT_SECURE_NO_WARINGS

void user_find(user* u_head) {
	char name[10];
	printf("검색하고싶은 가입자 이름을 입력해주세요: "); scanf("%s", name);
	user* p = NULL;
	p = u_head->next;
	int cnt = 0;
	while (p->next != NULL) {
		if (strcmp(p->user_name, name) == 0) {
			cnt++;
			printf("가입자 이름: %s, 가입자 id: %s\n", p->user_name, p->user_id);
		}
		p = p->next;
	}
	if (cnt == 0) {
		printf("가입자가 존재하지 않습니다. 다시 시도해주세요\n");
	}
}

void video_find(video* v_head) {
	char title[30];
	printf("검색하고싶은 비디오 제목을 입력해주세요: "); scanf("%s", title);
	video* p = NULL;
	p = v_head->next;
	while (p->next != NULL) {
		if (strcmp(p->video_title, title) == 0) {
			printf("비디오 제목: %s, 비디오 재고: %d\n", p->video_title, p->stock);
			break;
		}
		p = p->next;
	}
	if (p->next == NULL) {
		printf("비디오가 존재하지 않습니다. 다시 시도해주세요\n");
	}
}

void rent_find(rent* r_head) {
	char id[10];
	printf("대여한 가입자의 id를 입력해주세요: "); scanf("%s", id);
	rent* p = NULL;
	p = r_head->next;
	int cnt = 0;
	while (p->next != NULL) {
		if (strcmp(p->user_id, id) == 0) {
			cnt++;
			printf("가입자 id: %s, 비디오 제목: %s, 대여날짜: %s, 반납날짜: %s\n"
				, p->user_id, p->video_title, p->rent_date, p->return_date);
		}
		p = p->next;
	}
	if (cnt == 0) {
		printf("대여한 가입자의 id가 존재하지 않습니다. 다시 시도해주세요\n");
	}
}
