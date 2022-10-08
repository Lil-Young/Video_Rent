// printf, scanf
#include<stdio.h>
// free, malloc
#include<stdlib.h>
// strcpy, strlen
#include<string.h>
// ����� �ڷ���
#include"my_struct.h"
// scanf ���� ���� ���� ������ ���� ����
#define _CRT_SECURE_NO_WARINGS

void id_update(user* u_head, rent* r_head) {
	user* u_p = NULL;
	rent* r_p = NULL;
	u_p = u_head->next;
	r_p = r_head->next;
	
	char id[10]; printf("������ id�� �Է����ּ���: "); scanf("%s", id);
	while (u_p->next != NULL) {
		if (strcmp(u_p->user_id, id) == 0) {
			printf("id�� Ȯ�εǾ����ϴ�.\n");
			break;
		}
		u_p = u_p->next;
	}
	if (u_p->next == NULL) {
		printf("�Է��Ͻ� id�� �������� �ʽ��ϴ�.\n");
		return 0;
	}
	char update_id[10]; printf("�����ϰ���� id�� �Է����ּ���: "); scanf("%s", update_id);
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
	printf("id�� ����Ǿ����ϴ�.\n");
	user_store(u_head);
	rent_store(r_head);
}

void stock_update(video* v_head) {
	video* p = NULL;
	p = v_head->next;
	char title[30]; printf("�����ϰ���� ���� ����� ������ �Է��ϼ���: "); scanf("%s", title);
	while (p->next != NULL) {
		if (strcmp(p->video_title, title) == 0) {
			printf("������ Ȯ�εǾ����ϴ�.\n");
			break;
		}
		p = p->next;
	}
	if (p->next == NULL) {
		printf("�Է��Ͻ� ������ �������� �ʽ��ϴ�.\n");
		return 0;
	}
	int update_stock; printf("��� �߰� �Ǵ� ���̷��� ������ �Է����ּ���: "); scanf("%d", &update_stock);
	p->stock += update_stock;
	video_store(v_head);
}

void return_update(rent* r_head) {
	rent* p = NULL;
	p = r_head->next;

	int cnt = 0;
	char id[10];
	printf("�뿩�� �������� id�� �Է����ּ���: "); scanf("%s", id);
	while (p->next != NULL) {
		if (strcmp(p->user_id, id) == 0) {
			cnt++;
			printf("������ id: %s, ���� ����: %s, �뿩��¥: %s, �ݳ���¥: %s\n"
				, p->user_id, p->video_title, p->rent_date, p->return_date);
		}
		p = p->next;
	}
	if (cnt == 0) {
		printf("�뿩�� �������� id�� �������� �ʽ��ϴ�. �ٽ� �õ����ּ���\n");
		return 0;
	}

	p = r_head->next;
	char title[30]; printf("�����ϰ���� ���� ������ �Է����ּ���: "); scanf("%s", title);
	while (p->next != NULL) {
		if (strcmp(p->video_title, title) == 0) {
			printf("������ Ȯ�εǾ����ϴ�.\n");
			break;
		}
		p = p->next;
	}
	if (p->next == NULL) {
		printf("�Է��Ͻ� ������ �������� �ʽ��ϴ�.\n");
		return 0;
	}
	char update_return[10]; printf("�����ϰ���� �ݳ���¥�� �Է����ּ���: "); scanf("%s", update_return);
	free(p->return_date);
	p->return_date = (char*)malloc(sizeof(char) * strlen(update_return) + 1);
	strcpy(p->return_date, update_return);
	rent_store(r_head);
}