// printf, scanf
#include<stdio.h>
// free, malloc
#include<stdlib.h>
// strcpy, strlen
#include<string.h>
// 사용할 자료형
#include"my_struct.h"
// scanf 보안 경고로 인한 컴파일 에러 방지
#define _CRT_SECURE_NO_WARINGS

void id_update(user* u_head, rent* r_head) {
	user* u_p = NULL;
	rent* r_p = NULL;
	u_p = u_head->next;
	r_p = r_head->next;
	
	char id[10]; printf("본인의 id를 입력해주세요: "); scanf("%s", id);
	while (u_p->next != NULL) {
		if (strcmp(u_p->user_id, id) == 0) {
			printf("id가 확인되었습니다.\n");
			break;
		}
		u_p = u_p->next;
	}
	if (u_p->next == NULL) {
		printf("입력하신 id가 존재하지 않습니다.\n");
		return 0;
	}
	char update_id[10]; printf("수정하고싶은 id를 입력해주세요: "); scanf("%s", update_id);
	free(u_p->user_id);
	u_p->user_id = (char*)malloc(sizeof(char) * strlen(update_id) + 1);
	strcpy(u_p->user_id, update_id);

	while (r_p->next != NULL) {
		if (strcmp(r_p->user_id, id) == 0) {
			free(r_p->user_id);
			r_p->user_id = (char*)malloc(sizeof(char) * strlen(update_id) + 1);
			strcpy(r_p->user_id, update_id);
		}
		r_p = r_p->next;
	}
	printf("id가 변경되었습니다.\n");
	user_store(u_head);
	rent_store(r_head);
}

void stock_update(video* v_head) {
	video* p = NULL;
	p = v_head->next;
	char title[30]; printf("수정하고싶은 비디오 재고의 제목을 입력하세요: "); scanf("%s", title);
	while (p->next != NULL) {
		if (strcmp(p->video_title, title) == 0) {
			printf("비디오가 확인되었습니다.\n");
			break;
		}
		p = p->next;
	}
	if (p->next == NULL) {
		printf("입력하신 비디오가 존재하지 않습니다.\n");
		return 0;
	}
	int update_stock; printf("재고를 추가 또는 줄이려는 수량을 입력해주세요: "); scanf("%d", &update_stock);
	p->stock += update_stock;
	video_store(v_head);
}

void return_update(rent* r_head) {
	rent* p = NULL;
	p = r_head->next;

	int cnt = 0;
	char id[10];
	printf("대여한 가입자의 id를 입력해주세요: "); scanf("%s", id);
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
		return 0;
	}

	p = r_head->next;
	char title[30]; printf("수정하고싶은 비디오 제목을 입력해주세요: "); scanf("%s", title);
	while (p->next != NULL) {
		if (strcmp(p->video_title, title) == 0) {
			printf("비디오가 확인되었습니다.\n");
			break;
		}
		p = p->next;
	}
	if (p->next == NULL) {
		printf("입력하신 비디오가 존재하지 않습니다.\n");
		return 0;
	}
	char update_return[10]; printf("수정하고싶은 반납날짜를 입력해주세요: "); scanf("%s", update_return);
	free(p->return_date);
	p->return_date = (char*)malloc(sizeof(char) * strlen(update_return) + 1);
	strcpy(p->return_date, update_return);
	rent_store(r_head);
}