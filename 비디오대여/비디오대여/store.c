// fopen, fclose, fprintf, fscanf
#include<stdio.h>
// ����� �ڷ���
#include"my_struct.h"
//fopen ���� ���� ���� ������ ���� ����
#define _CRT_SECURE_NO_WARINGS

void user_store(user* u_head) {

	// �����ͺ��� ���� �� �ʱ�ȭ
	user* p = NULL;
	p = u_head->next;
	FILE* fp = NULL;

	// PHONE_BOOK.txt ������ w(����) ���� ����
	fp = fopen("USER_FILE.txt", "w");

	// file_p->next�� NULL�� �ƴϸ� �ݺ����� ������ NULL�� �Ǹ� �ݺ����� �����Ѵ�.
	while (p->next != NULL) {

		/*
		fprintf: ���ڿ��� ���Ͽ� ����
		file_p->next->next�� NULL�̸� fprintf �ƴϸ� else�� �̵��ϰ� fprintf
		���� ���� ������ ���� �ʱ� ����.
		*/
		if (p->next->next == NULL) {
			fprintf(fp, "%s %s", p->user_id, p->user_name);
		}
		else {
			fprintf(fp, "%s %s\n", p->user_id, p->user_name);
		}

		// �����ͺ��� file_p�� file_p->next�� ����Ų��.
		p = p->next;
	}
	// ���� ������ �ݱ�
	fclose(fp);
}

void video_store(video* v_head) {

	// �����ͺ��� ���� �� �ʱ�ȭ
	video* p = NULL;
	p = v_head->next;
	FILE* fp = NULL;

	// PHONE_BOOK.txt ������ w(����) ���� ����
	fp = fopen("VIDEO_FILE.txt", "w");

	// file_p->next�� NULL�� �ƴϸ� �ݺ����� ������ NULL�� �Ǹ� �ݺ����� �����Ѵ�.
	while (p->next != NULL) {

		/*
		fprintf: ���ڿ��� ���Ͽ� ����
		file_p->next->next�� NULL�̸� fprintf �ƴϸ� else�� �̵��ϰ� fprintf
		���� ���� ������ ���� �ʱ� ����.
		*/
		if (p->next->next == NULL) {
			fprintf(fp, "%s %d", p->video_title, p->stock);
		}
		else {
			fprintf(fp, "%s %d\n", p->video_title, p->stock);
		}

		// �����ͺ��� file_p�� file_p->next�� ����Ų��.
		p = p->next;
	}
	// ���� ������ �ݱ�
	fclose(fp);
}

void rent_store(rent* r_head) {

	// �����ͺ��� ���� �� �ʱ�ȭ
	rent* p = NULL;
	p = r_head->next;
	FILE* fp = NULL;

	// PHONE_BOOK.txt ������ w(����) ���� ����
	fp = fopen("RENT_FILE.txt", "w");

	// file_p->next�� NULL�� �ƴϸ� �ݺ����� ������ NULL�� �Ǹ� �ݺ����� �����Ѵ�.
	while (p->next != NULL) {

		/*
		fprintf: ���ڿ��� ���Ͽ� ����
		file_p->next->next�� NULL�̸� fprintf �ƴϸ� else�� �̵��ϰ� fprintf
		���� ���� ������ ���� �ʱ� ����.
		*/
		if (p->next->next == NULL) {
			fprintf(fp, "%s %s %s %s", p->video_title, p->user_id, p->rent_date, p->return_date);
		}
		else {
			fprintf(fp, "%s %s %s %s\n", p->video_title, p->user_id, p->rent_date, p->return_date);
		}

		// �����ͺ��� file_p�� file_p->next�� ����Ų��.
		p = p->next;
	}
	// ���� ������ �ݱ�
	fclose(fp);
}