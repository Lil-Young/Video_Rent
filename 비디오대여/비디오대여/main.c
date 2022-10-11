// printf, scanf
#include<stdio.h>
// malloc
#include<stdlib.h>
// ����� �ڷ���
#include"my_struct.h"
// scanf ���� ���� ���� ������ ���� ����
#define _CRT_SECURE_NO_WARINGS

int main(void) {

	// ������ �����ͺ��� ���� �� �ʱ�ȭ
	int select = 0; int func = 0;
	user* u_head = NULL; user* u_tail = NULL;
	video* v_head = NULL; video* v_tail = NULL;
	rent* r_head = NULL; rent* r_tail = NULL;

	// head, tail �޸��Ҵ�
	u_head = (user*)malloc(sizeof(user)); u_tail = (user*)malloc(sizeof(user));
	v_head = (video*)malloc(sizeof(video)); v_tail = (video*)malloc(sizeof(video));
	r_head = (rent*)malloc(sizeof(rent)); r_tail = (rent*)malloc(sizeof(rent));

	// head �ʱ�ȭ
	u_head->next = NULL; u_head->prev = NULL; u_head->user_id = NULL; u_head->user_name = NULL;
	v_head->next = NULL; v_head->prev = NULL; v_head->video_title = NULL;
	r_head->next = NULL; r_head->prev = NULL; r_head->video_title = NULL; r_head->user_id = NULL; r_head->rent_date = NULL; r_head->return_date = NULL;

	// tail �ʱ�ȭ
	u_tail->next = NULL; u_tail->prev = NULL; u_tail->user_id = NULL; u_tail->user_name = NULL;
	v_tail->next = NULL; v_tail->prev = NULL; v_tail->video_title = NULL;
	r_tail->next = NULL; r_tail->prev = NULL; r_tail->video_title = NULL; r_tail->user_id = NULL; r_tail->rent_date = NULL; r_tail->return_date = NULL;

	// head, tail ����
	u_head->next = u_tail; u_head->prev = NULL; u_tail->next = NULL; u_tail->prev = u_head;
	v_head->next = v_tail; v_head->prev = NULL; v_tail->next = NULL; v_tail->prev = v_head;
	r_head->next = r_tail; r_head->prev = NULL; r_tail->next = NULL; r_tail->prev = r_head;
	user_open(u_tail);
	video_open(v_tail);
	rent_open(r_tail);
	while (1) {
		printf("�����: 1, ������: 2 :");
		int select = 0;
		scanf("%d", &select);
		while (getchar() != '\n');
		if (select == 1) {
			while (1) {
				printf("����� ��带 �������ּ��� : ");
				scanf("%d", &func);
				while (getchar() != '\n') {
					printf("����(��)�� �Է��߽��ϴ�. ���α׷��� �ٽ� �����ϰ� 1, 2, 3, 4, 5, 6 �߿� �ϳ��� ������\n");
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
					printf("���ڸ� �ٽ��Է��ϼ���\n");
					break;
				}
			}
		}
		else if (select == 2) {
			while (1) {
				printf("������ ��带 �������ּ��� : ");
				scanf("%d", &func);
				while (getchar() != '\n') {
					printf("����(��)�� �Է��߽��ϴ�. ���α׷��� �ٽ� �����ϰ� 1, 2, 3, 4, 5, 6 �߿� �ϳ��� ������\n");
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
					printf("���ڸ� �ٽ��Է��ϼ���\n");
					break;

				}
			}
		}
		else {
			printf("�ٽ��Է����ּ���\n");
		}
	}
}