// printf, scanf
#include<stdio.h>
// free, malloc
#include<stdlib.h>
// strcmp
#include<string.h>
// ����� �ڷ���
#include"my_struct.h"
// scanf ���� ���� ���� ������ ���� ����
#define _CRT_SECURE_NO_WARINGS

void user_del(user* u_head, rent* r_head) {
	user* p = NULL;
	rent* r_p = NULL;
	p = u_head->next;
	r_p = r_head->next;
	char id[10];
	printf("�����ϰ���� id�� �Է����ּ���: "); scanf("%s", id);
	while (r_p->next != NULL) {
		if (strcmp(r_p->user_id, id) == 0) {
			printf("�뿩�� ������ �ֽ��ϴ�. �ݳ��� �Ϸ��ϰ� �ٽ� �õ��ϼ���\n");
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
		printf("�����ϰ���� id�� �������� �ʽ��ϴ�.\n");
	}
	else {
		printf("������ �̸�: %s, ������ id: %s�� �����մϴ�.\n", p->user_name, p->user_id);
		// p�� ����Ű�� ��� �翷�� �ִ� ���� ����
		p->prev->next = p->next;
		p->next->prev = p->prev;

		// p->user_name, p->user_id, p �޸� ����
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
	printf("�����ϰ���� ���� ������ �Է����ּ���: "); scanf("%s", title);
	while (p->next != NULL) {
		if (strcmp(p->video_title, title) == 0) {
			break;
		}
		p = p->next;
	}
	if (p->next == NULL) {
		printf("�����ϰ���� ������ �������� �ʽ��ϴ�.\n");
	}
	else {
		printf("���� ����: %s, ���� ���: %d�� �����մϴ�.\n", p->video_title, p->stock);
		// p�� ����Ű�� ��� �翷�� �ִ� ���� ����
		p->prev->next = p->next;
		p->next->prev = p->prev;

		// p->video_title, p �޸� ����
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
	char id[10]; printf("������ id�� �Է����ּ���: "); scanf("%s", id);
	while (id_p->next != NULL) {
		if (strcmp(id_p->user_id, id) == 0) {
			printf("id�� Ȯ�εǾ����ϴ�.\n");
			break;
		}
		id_p = id_p->next;
	}
	if (id_p->next == NULL) {
		printf("�Է��Ͻ� id�� �������� �ʽ��ϴ�.\n");
		return 0;
	}

	video* title_p = NULL;
	title_p = v_head->next;
	char title[30]; printf("�ݳ��ϰ���� ���� ������ �Է����ּ���: "); scanf("%s", title);
	while (title_p->next != NULL) {
		if (strcmp(title_p->video_title, title) == 0) {
			(title_p->stock)++;
			break;
		}
		title_p = title_p->next;
	}
	if (title_p->next == NULL) {
		printf("�ݳ��ϰ���� ���� ������ �����ϴ�.\n");
		return 0;
	}

	while (p->next != NULL) {
		if (strcmp(p->video_title, title) == 0) {
			break;
		}
		p = p->next;
	}
	printf("%s�� %s�� �ݳ��մϴ�.\n", p->user_id, p->video_title);
	// p�� ����Ű�� ��� �翷�� �ִ� ���� ����
	p->prev->next = p->next;
	p->next->prev = p->prev;
	// p->user_name, p->user_id, p->rent_date, p->return_date, p �޸� ����
	free(p->video_title);
	free(p->user_id);
	free(p->rent_date);
	free(p->return_date);
	free(p);
	rent_store(r_head);
}