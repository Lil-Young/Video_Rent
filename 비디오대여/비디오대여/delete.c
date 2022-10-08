// printf, scanf
#include<stdio.h>
// free, malloc
#include<stdlib.h>
// strcmp
#include<string.h>
// 사용할 자료형
#include"my_struct.h"
// scanf 보안 경고로 인한 컴파일 에러 방지
#define _CRT_SECURE_NO_WARINGS

void user_del(user* u_head, rent* r_head) {
	user* p = NULL;
	rent* r_p = NULL;
	p = u_head->next;
	r_p = r_head->next;
	char id[10];
	printf("삭제하고싶은 id를 입력해주세요: "); scanf("%s", id);
	while (r_p->next != NULL) {
		if (strcmp(r_p->user_id, id) == 0) {
			printf("대여한 비디오가 있습니다. 반납을 완료하고 다시 시도하세요\n");
			return 0;
		}
		r_p = r_p->next;
	}
	while (p->next != NULL) {
		if (strcmp(p->user_id, id) == 0) {
			break;
		}
		p = p->next;
	}
	if (p->next == NULL) {
		printf("삭제하고싶은 id가 존재하지 않습니다.\n");
	}
	else {
		printf("가입자 이름: %s, 가입자 id: %s를 삭제합니다.\n", p->user_name, p->user_id);
		// p가 가리키는 노드 양옆에 있는 노드들 연결
		p->prev->next = p->next;
		p->next->prev = p->prev;

		// p->user_name, p->user_id, p 메모리 해제
		free(p->user_name);
		free(p->user_id);
		free(p);
	}
	user_store(u_head);
}

void video_del(video* v_head) {
	video* p = NULL;
	p = v_head->next;
	char title[30];
	printf("삭제하고싶은 비디오 제목을 입력해주세요: "); scanf("%s", title);
	while (p->next != NULL) {
		if (strcmp(p->video_title, title) == 0) {
			break;
		}
		p = p->next;
	}
	if (p->next == NULL) {
		printf("삭제하고싶은 비디오가 존재하지 않습니다.\n");
	}
	else {
		printf("비디오 제목: %s, 비디오 재고: %d를 삭제합니다.\n", p->video_title, p->stock);
		// p가 가리키는 노드 양옆에 있는 노드들 연결
		p->prev->next = p->next;
		p->next->prev = p->prev;

		// p->video_title, p 메모리 해제
		free(p->video_title);
		free(p);
	}
	video_store(v_head);
}

void return_complete(rent* r_head, video* v_head, user* u_head) {
	rent* p = NULL;
	p = r_head->next;

	user* id_p = NULL;
	id_p = u_head->next;
	char id[10]; printf("본인의 id를 입력해주세요: "); scanf("%s", id);
	while (id_p->next != NULL) {
		if (strcmp(id_p->user_id, id) == 0) {
			printf("id가 확인되었습니다.\n");
			break;
		}
		id_p = id_p->next;
	}
	if (id_p->next == NULL) {
		printf("입력하신 id가 존재하지 않습니다.\n");
		return 0;
	}

	video* title_p = NULL;
	title_p = v_head->next;
	char title[30]; printf("반납하고싶은 비디오 제목을 입력해주세요: "); scanf("%s", title);
	while (title_p->next != NULL) {
		if (strcmp(title_p->video_title, title) == 0) {
			(title_p->stock)++;
			break;
		}
		title_p = title_p->next;
	}
	if (title_p->next == NULL) {
		printf("반납하고싶은 비디오 제목이 없습니다.\n");
		return 0;
	}

	while (p->next != NULL) {
		if (strcmp(p->video_title, title) == 0) {
			break;
		}
		p = p->next;
	}
	printf("%s가 %s를 반납합니다.\n", p->user_id, p->video_title);
	// p가 가리키는 노드 양옆에 있는 노드들 연결
	p->prev->next = p->next;
	p->next->prev = p->prev;
	// p->user_name, p->user_id, p->rent_date, p->return_date, p 메모리 해제
	free(p->video_title);
	free(p->user_id);
	free(p->rent_date);
	free(p->return_date);
	free(p);
	rent_store(r_head);
}