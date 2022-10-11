// printf, scanf
#include<stdio.h>
// malloc
#include<stdlib.h>
// 사용할 자료형
#include"my_struct.h"
// scanf 보안 경고로 인한 컴파일 에러 방지
#define _CRT_SECURE_NO_WARINGS

int main(void) {

	// 변수와 포인터변수 선언 및 초기화
	int select = 0; int func = 0;
	user* u_head = NULL; user* u_tail = NULL;
	video* v_head = NULL; video* v_tail = NULL;
	rent* r_head = NULL; rent* r_tail = NULL;

	// head, tail 메모리할당
	u_head = (user*)malloc(sizeof(user)); u_tail = (user*)malloc(sizeof(user));
	v_head = (video*)malloc(sizeof(video)); v_tail = (video*)malloc(sizeof(video));
	r_head = (rent*)malloc(sizeof(rent)); r_tail = (rent*)malloc(sizeof(rent));

	// head 초기화
	u_head->next = NULL; u_head->prev = NULL; u_head->user_id = NULL; u_head->user_name = NULL;
	v_head->next = NULL; v_head->prev = NULL; v_head->video_title = NULL;
	r_head->next = NULL; r_head->prev = NULL; r_head->video_title = NULL; r_head->user_id = NULL; r_head->rent_date = NULL; r_head->return_date = NULL;

	// tail 초기화
	u_tail->next = NULL; u_tail->prev = NULL; u_tail->user_id = NULL; u_tail->user_name = NULL;
	v_tail->next = NULL; v_tail->prev = NULL; v_tail->video_title = NULL;
	r_tail->next = NULL; r_tail->prev = NULL; r_tail->video_title = NULL; r_tail->user_id = NULL; r_tail->rent_date = NULL; r_tail->return_date = NULL;

	// head, tail 연결
	u_head->next = u_tail; u_head->prev = NULL; u_tail->next = NULL; u_tail->prev = u_head;
	v_head->next = v_tail; v_head->prev = NULL; v_tail->next = NULL; v_tail->prev = v_head;
	r_head->next = r_tail; r_head->prev = NULL; r_tail->next = NULL; r_tail->prev = r_head;
	user_open(u_tail);
	video_open(v_tail);
	rent_open(r_tail);
	while (1) {
		printf("사용자: 1, 관리자: 2 :");
		int select = 0;
		scanf("%d", &select);
		while (getchar() != '\n');
		if (select == 1) {
			while (1) {
				printf("사용자 모드를 선택해주세요 : ");
				scanf("%d", &func);
				while (getchar() != '\n') {
					printf("문자(열)을 입력했습니다. 프로그램을 다시 실행하고 1, 2, 3, 4, 5, 6 중에 하나를 고르세요\n");
					return 0;
				}
				if (func == 0) {
					break;
				}
				switch (func) {
				case 1:
					rent_insert(r_tail, v_head, u_head, r_head);
					break;
				case 2:
					video_show(v_head);
					break;
				case 3:
					return_complete(r_head, v_head, u_head);
					break;
				case 4:
					video_find(v_head);
					break;
				default:
					printf("숫자를 다시입력하세요\n");
					break;
				}
			}
		}
		else if (select == 2) {
			while (1) {
				printf("관리자 모드를 선택해주세요 : ");
				scanf("%d", &func);
				while (getchar() != '\n') {
					printf("문자(열)을 입력했습니다. 프로그램을 다시 실행하고 1, 2, 3, 4, 5, 6 중에 하나를 고르세요\n");
					return 0;
				}
				if (func == 0) {
					break;
				}
				switch (func) {
				case 1:
					user_insert(u_tail, u_head);
					break;
				case 2:
					video_insert(v_tail, v_head);
					break;
				case 3:
					user_show(u_head);
					break;
				case 4:
					video_show(v_head);
					break;
				case 5:
					rent_show(r_head);
					break;
				case 6:
					delayed_date(r_head);
					break;
				case 7:
					user_del(u_head, r_head);
					break;
				case 8:
					video_del(v_head);
					break;
				case 9:
					user_find(u_head);
					break;
				case 10:
					video_find(v_head);
					break;
				case 11:
					rent_find(r_head);
					break;
				case 12:
					id_update(u_head, r_head);
					break;
				case 13:
					stock_update(v_head);
					break;
				case 14:
					return_update(r_head);
					break;
				default :
					printf("숫자를 다시입력하세요\n");
					break;

				}
			}
		}
		else {
			printf("다시입력해주세요\n");
		}
	}
}