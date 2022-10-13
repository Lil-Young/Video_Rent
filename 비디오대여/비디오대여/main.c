#include<stdio.h> //printf, scanf, getchar
#include<stdlib.h> //malloc
#include"my_struct.h" //����� �ڷ���
#define _CRT_SECURE_NO_WARINGS //scanf ���� ���� ���� ������ ���� ����
/*
* printf�� ���ڿ��� ����ϴ� �Լ�
* return 0�� �Լ��� �����Ѵ�.
* break�� �ݺ����� Ż���Ų�� ���� switch���� Ż���Ų��.
*/
int main(void) {

	//������ �����ͺ��� ���� �� �ʱ�ȭ
	int select = 0; 
	int func = 0;
	user* u_head = NULL; user* u_tail = NULL;
	video* v_head = NULL; video* v_tail = NULL;
	rent* r_head = NULL; rent* r_tail = NULL;
	rent* return_head = NULL; rent* return_tail = NULL;
	rent* pointer_val;

	//head, tail �޸��Ҵ�
	u_head = (user*)malloc(sizeof(user)); u_tail = (user*)malloc(sizeof(user));
	v_head = (video*)malloc(sizeof(video)); v_tail = (video*)malloc(sizeof(video));
	r_head = (rent*)malloc(sizeof(rent)); r_tail = (rent*)malloc(sizeof(rent));
	return_head = (rent*)malloc(sizeof(rent)); return_tail = (rent*)malloc(sizeof(rent));

	//head �ʱ�ȭ
	u_head->next = NULL; u_head->prev = NULL; u_head->user_id = NULL; u_head->user_name = NULL;
	v_head->next = NULL; v_head->prev = NULL; v_head->video_title = NULL;
	r_head->next = NULL; r_head->prev = NULL; r_head->video_title = NULL; r_head->user_id = NULL; r_head->rent_date = NULL; r_head->return_date = NULL;
	return_head->next = NULL; return_head->prev = NULL; return_head->video_title = NULL; return_head->user_id = NULL; return_head->rent_date = NULL; return_head->return_date = NULL;

	//tail �ʱ�ȭ
	u_tail->next = NULL; u_tail->prev = NULL; u_tail->user_id = NULL; u_tail->user_name = NULL;
	v_tail->next = NULL; v_tail->prev = NULL; v_tail->video_title = NULL;
	r_tail->next = NULL; r_tail->prev = NULL; r_tail->video_title = NULL; r_tail->user_id = NULL; r_tail->rent_date = NULL; r_tail->return_date = NULL;
	return_tail->next = NULL; return_tail->prev = NULL; return_tail->video_title = NULL; return_tail->user_id = NULL; return_tail->rent_date = NULL; return_tail->return_date = NULL;

	//head, tail ����
	u_head->next = u_tail; u_head->prev = NULL; u_tail->next = NULL; u_tail->prev = u_head;
	v_head->next = v_tail; v_head->prev = NULL; v_tail->next = NULL; v_tail->prev = v_head;
	r_head->next = r_tail; r_head->prev = NULL; r_tail->next = NULL; r_tail->prev = r_head;
	return_head->next = return_tail; return_head->prev = NULL; return_tail->next = NULL; return_tail->prev = return_head;

	//���� �ҷ�����
	user_open(u_tail); //user_open �Լ��� ȣ���ϰ� ���ڵ��� �����Ѵ�.
	video_open(v_tail); //video_open �Լ��� ȣ���ϰ� ���ڵ��� �����Ѵ�.
	rent_open(r_tail); //rent_open �Լ��� ȣ���ϰ� ���ڵ��� �����Ѵ�.
	return_open(return_tail); //return_open �Լ��� ȣ���ϰ� ���ڵ��� �����Ѵ�.

	//��� ���� �� ��� ����
	while (1) {
		printf("����ϰ���� ��带 �������ּ���.\n");
		printf("����� ���: 1, ������ ���: 2 :");
		int select = 0;
		scanf("%d", &select);
		while (getchar() != '\n');
		if (select == 1) {
			printf("����� ��带 �����մϴ�.\n");
			printf("��� -> 0: �ڷΰ���. 1: ������ �뿩�մϴ�. 2: �뿩 ������ ������ �����ݴϴ�. 3: ������ �ݳ��մϴ�. 4: ������ �˻��մϴ�.\n");
			while (1) {
				printf("������ ����� �Է����ּ���: ");
				scanf("%d", &func);
				while (getchar() != '\n');
				if (func == 0) {
					break;
				}
				switch (func) {
				case 1:
					rent_insert(r_tail, v_head, u_head, r_head); //rent_insert �Լ��� ȣ���ϰ� ���ڵ��� �����Ѵ�.
					break;
				case 2:
					user_video_show(v_head); //video_show �Լ��� ȣ���ϰ� ���ڵ��� �����Ѵ�.
					break;
				case 3:
					pointer_val = return_complete(r_head, v_head, u_head); //return_complete �Լ��� ȣ���ϰ� ���ڵ��� �����Ѵ�.
					printf("p�� �ּҰ� : %s\n", pointer_val->user_id);
					return_insert(return_tail, return_head, pointer_val);
					break;
				case 4:
					video_find(v_head); //video_find �Լ��� ȣ���ϰ� ���ڵ��� �����Ѵ�.
					break;
				default:
					printf("�߸� �Է��߽��ϴ�. ����� �ٽ��Է��ϼ���.\n");
				}
			}
		}
		else if (select == 2) {
			printf("������ ��带 �����մϴ�.\n");
			printf("��� -> 0: �ڷΰ���. 1: �����ڸ� �߰��մϴ�. 2: ������ �߰��մϴ�. 3: �����ڸ� �����ݴϴ�. 4: ��� ������ �����ݴϴ�. 5: �뿩�� �������� ������ �����ݴϴ�. 6: ������ �ݳ���¥�� ���� �������� ������ �����ݴϴ�. 7: �����ڸ� �����մϴ�. 8: ������ �����մϴ�. 9: �����ڸ� �˻��մϴ�. 10: ������ �˻��մϴ�. 11: �뿩�� �������� ������ �����ݴϴ�. 12: �������� id�� ������Ʈ �մϴ�. 13: ������ ��� ������Ʈ �մϴ�. 14: �ݳ���¥�� ������Ʈ�մϴ�. 15: �������� ��� ������ �ʱ�ȭ�մϴ�. 16: ������ ��� ������ �ʱ�ȭ�մϴ�. 17: �뿩�� �������� ������ �ʱ�ȭ�մϴ�.\n");
			while (1) {
				printf("������ ����� �Է����ּ���: ");
				scanf("%d", &func);
				while (getchar() != '\n');
				if (func == 0) {
					break;
				}
				switch (func) {
				case 1:
					user_insert(u_tail, u_head); //user_insert �Լ��� ȣ���ϰ� ���ڵ��� �����Ѵ�.
					break;
				case 2:
					video_insert(v_tail, v_head); //video_insert �Լ��� ȣ���ϰ� ���ڵ��� �����Ѵ�.
					break;
				case 3:
					user_show(u_head); //user_show �Լ��� ȣ���ϰ� ���ڵ��� �����Ѵ�.
					break;
				case 4:
					all_video_show(v_head); //video_show �Լ��� ȣ���ϰ� ���ڵ��� �����Ѵ�.
					break;
				case 5:
					rent_show(r_head); //rent_show �Լ��� ȣ���ϰ� ���ڵ��� �����Ѵ�.
					break;
				case 6:
					delayed_date(r_head); //delayed_date �Լ��� ȣ���ϰ� ���ڵ��� �����Ѵ�.
					break;
				case 7:
					user_del(u_head, r_head); //user_del �Լ��� ȣ���ϰ� ���ڵ��� �����Ѵ�.
					break;
				case 8:
					video_del(v_head, r_head); //video_del �Լ��� ȣ���ϰ� ���ڵ��� �����Ѵ�.
					break;
				case 9:
					user_find(u_head); //user_find �Լ��� ȣ���ϰ� ���ڵ��� �����Ѵ�.
					break;
				case 10:
					video_find(v_head); //video_find �Լ��� ȣ���ϰ� ���ڵ��� �����Ѵ�.
					break;
				case 11:
					rent_user_find(r_head); //rent_user_find �Լ��� ȣ���ϰ� ���ڵ��� �����Ѵ�.
					break;
				case 12:
					id_update(u_head, r_head); //id_update �Լ��� ȣ���ϰ� ���ڵ��� �����Ѵ�.
					break;
				case 13:
					stock_update(v_head); //stock_update �Լ��� ȣ���ϰ� ���ڵ��� �����Ѵ�.
					break;
				case 14:
					return_update(r_head); //return_update �Լ��� ȣ���ϰ� ���ڵ��� �����Ѵ�.
					break;
				case 15:
					user_all_del(u_head); //user_all_del �Լ��� ȣ���ϰ� ���ڵ��� �����Ѵ�.
					break;
				case 16:
					video_all_del(v_head); //video_all_del �Լ��� ȣ���ϰ� ���ڵ��� �����Ѵ�.
					break;
				case 17:
					rent_all_del(r_head); //rent_all_del �Լ��� ȣ���ϰ� ���ڵ��� �����Ѵ�.
					break;
				default :
					printf("�߸� �Է��߽��ϴ�. ����� �ٽ��Է��ϼ���.\n");
				}
			}
		}
		else {
			printf("�߸� �Է��߽��ϴ�. ��带 �ٽ� �������ּ���.\n");
		}
	}
}