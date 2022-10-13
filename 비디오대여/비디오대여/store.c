#include<stdio.h> //fopen, fclose, fprintf, fscanf
#include"my_struct.h" //����� �ڷ���
#define _CRT_SECURE_NO_WARINGS //fopen ���� ���� ���� ������ ���� ����

//�Լ� user_store�� void������ �����ϰ� �Ű�����(�Ķ����)�� ���޵� ���ڸ� �޴´�.
void user_store(user* u_head) {

	//�����ͺ��� ���� �� �ʱ�ȭ
	user* p = NULL;	
	p = u_head->next; 
	FILE* fp = NULL;

	fp = fopen("USER_FILE.txt", "w"); //USER_FILE.txt ������ w(����) ���� ����

	//���Ͽ� �����ϴ� ����
	while (p->next != NULL) {
		/*
		fprintf: ���ڿ��� ���Ͽ� ����
		p->next->next�� NULL�̸� fprintf �ƴϸ� else�� �̵��ϰ� fprintf
		���� ���� ������ ���� �ʱ� ����.
		*/
		if (p->next->next == NULL) {
			fprintf(fp, "%s %s", p->user_id, p->user_name);
		}
		else {
			fprintf(fp, "%s %s\n", p->user_id, p->user_name);
		}
		p = p->next; //�����ͺ��� p�� p->next�� ����Ų��.
	}
	fclose(fp); //���� ������ �ݱ�
}

//�Լ� video_store�� void������ �����ϰ� �Ű�����(�Ķ����)�� ���޵� ���ڸ� �޴´�.
void video_store(video* v_head) {

	//�����ͺ��� ���� �� �ʱ�ȭ
	video* p = NULL; 
	p = v_head->next; 
	FILE* fp = NULL;

	fp = fopen("VIDEO_FILE.txt", "w"); //VIDEO_FILE.txt ������ w(����) ���� ����

	//���Ͽ� �����ϴ� ����
	while (p->next != NULL) {
		/*
		fprintf: ���ڿ��� ���Ͽ� ����
		p->next->next�� NULL�̸� fprintf �ƴϸ� else�� �̵��ϰ� fprintf
		���� ���� ������ ���� �ʱ� ����.
		*/
		if (p->next->next == NULL) {
			fprintf(fp, "%s %d", p->video_title, p->stock);
		}
		else {
			fprintf(fp, "%s %d\n", p->video_title, p->stock);
		}
		p = p->next; //�����ͺ��� p�� p->next�� ����Ų��.
	}
	fclose(fp); //���� ������ �ݱ�
}

//�Լ� rent_store�� void������ �����ϰ� �Ű�����(�Ķ����)�� ���޵� ���ڸ� �޴´�.
void rent_store(rent* r_head) {
	//�����ͺ��� ���� �� �ʱ�ȭ
	rent* p = NULL; 
	p = r_head->next; 
	FILE* fp = NULL;

	fp = fopen("RENT_FILE.txt", "w"); //RENT_FILE.txt ������ w(����) ���� ����

	//���Ͽ� �����ϴ� ����
	while (p->next != NULL) {
		/*
		fprintf: ���ڿ��� ���Ͽ� ����
		p->next->next�� NULL�̸� fprintf �ƴϸ� else�� �̵��ϰ� fprintf
		���� ���� ������ ���� �ʱ� ����.
		*/
		if (p->next->next == NULL) {
			fprintf(fp, "%s %s %s %s", p->video_title, p->user_id, p->rent_date, p->return_date);
		}
		else {
			fprintf(fp, "%s %s %s %s\n", p->video_title, p->user_id, p->rent_date, p->return_date);
		}
		p = p->next; //�����ͺ��� p�� p->next�� ����Ų��.
	}
	fclose(fp); //���� ������ �ݱ�
}

//�Լ� return_store�� void������ �����ϰ� �Ű�����(�Ķ����)�� ���޵� ���ڸ� �޴´�.
void return_store(rent* return_head) {

	//�����ͺ��� ���� �� �ʱ�ȭ
	rent* p = NULL; 
	p = return_head->next; 
	FILE* fp = NULL;

	fp = fopen("RETURN_FILE.txt", "w"); //RETURN_FILE.txt ������ w(����) ���� ����

	//���Ͽ� �����ϴ� ����
	while (p->next != NULL) {
		/*
		fprintf: ���ڿ��� ���Ͽ� ����
		p->next->next�� NULL�̸� fprintf �ƴϸ� else�� �̵��ϰ� fprintf
		���� ���� ������ ���� �ʱ� ����.
		*/
		if (p->next->next == NULL) {
			fprintf(fp, "%s %s %s %s", p->video_title, p->user_id, p->rent_date, p->return_date);
		}
		else {
			fprintf(fp, "%s %s %s %s\n", p->video_title, p->user_id, p->rent_date, p->return_date);
		}
		p = p->next; //�����ͺ��� p�� p->next�� ����Ų��.
	}
	fclose(fp); //���� ������ �ݱ�
}