#include<stdio.h> //fopen, fclose, fscanf, printf
#include<stdlib.h> //free, malloc
#include<string.h> //strcpy, strcmp
#include"my_struct.h" //����� �ڷ���

//�Լ� user_open�� void������ �����ϰ� �Ű�����(�Ķ����)�� ���޵� ���ڸ� �޴´�.
void user_open(user* u_tail) {

	//�����ͺ��� ���� �� �ʱ�ȭ
	user* p = NULL; 
	user* newNode = NULL; 
	FILE* fp = NULL;

	//���� ����
	char id[10]; 
	char name[10];

	int is_eof = 0; //���� ���� �� �ʱ�ȭ

	fp = fopen("USER_FILE.txt", "r"); //USER_FILE.txt ������ r(�б�) ���� ����

	//������ �ִ��� Ȯ���ϴ� ����
	if (fp == NULL) {
		printf("USER_FILE�� �������� �ʽ��ϴ�.\n");
		return 0;
	}
	else {
		printf("USER_FILE�� �ҷ��ɴϴ�.\n");
	}
	//������ ������ �������� ����
	while (1) {
		is_eof = fscanf(fp, "%s %s", id, name); //fscanf(fp, "%s %s", id, name)���� id, name�� ���� ���� �� ������ EOF�� ��ȯ

		//is_eof�� EOF�� ��ġ�ϸ� ������ ���̹Ƿ� �ݺ����� Ż���ϱ� ���� break�� �Ѵ�.
		if (is_eof == EOF) {
			break;
		}
		//newNode, newNode->user_id, newNode->user_name �޸� �Ҵ�
		newNode = (user*)malloc(sizeof(user));
		newNode->user_id = (char*)malloc(sizeof(char) * strlen(id) + 1);
		newNode->user_name = (char*)malloc(sizeof(char) * strlen(name) + 1);

		//strcpy�� id�� �ִ� ���ڿ��� newNode->user_id���� ����, name�� �ִ� ���ڿ��� newNode->user_name���� ����
		strcpy(newNode->user_id, id); 
		strcpy(newNode->user_name, name);

		//newNode ����
		p = u_tail->prev; 
		newNode->next = p->next; 
		newNode->prev = p; 
		p->next = newNode; 
		u_tail->prev = newNode;
	}
	fclose(fp); //���� ������ �ݱ�
}

//�Լ� video_open�� void������ �����ϰ� �Ű�����(�Ķ����)�� ���޵� ���ڸ� �޴´�.
void video_open(video* v_tail) {

	//�����ͺ��� ���� �� �ʱ�ȭ
	video* p = NULL; 
	video* newNode = NULL; 
	FILE* fp = NULL;

	//���� ����
	char title[30]; 
	int stock;

	int is_eof = 0; //���� ���� �� �ʱ�ȭ

	fp = fopen("VIDEO_FILE.txt", "r"); //VIDEO_FILE.txt ������ r(�б�) ���� ����

	//������ �ִ��� Ȯ���ϴ� ����
	if (fp == NULL) {
		printf("VIDEO_FILE�� �������� �ʽ��ϴ�.\n");
		return 0;
	}
	else {
		printf("VIDEO_FILE�� �ҷ��ɴϴ�.\n");
	}
	//������ ������ �������� ����
	while (1) {
		is_eof = fscanf(fp, "%s %d", title, &stock); //fscanf(fp, "%s %d", title, &stock)���� title, &stock�� ���� ���� �� ������ EOF�� ��ȯ

		//is_eof�� EOF�� ��ġ�ϸ� ������ ���̹Ƿ� �ݺ����� Ż���ϱ� ���� break�� �Ѵ�.
		if (is_eof == EOF) {
			break;
		}

		//newNode, newNode->video_title �޸� �Ҵ�
		newNode = (user*)malloc(sizeof(user));
		newNode->video_title = (char*)malloc(sizeof(char) * strlen(title) + 1);

		strcpy(newNode->video_title, title); //strcpy�� title�� �ִ� ���ڿ��� newNode->video_title�� ����
		newNode->stock = stock; //newNode->stock�� stock ����

		//newNode ����
		p = v_tail->prev; 
		newNode->next = p->next; 
		newNode->prev = p; 
		p->next = newNode;
		v_tail->prev = newNode;
	}
	fclose(fp); //���� ������ �ݱ�
}

//�Լ� rent_open�� void������ �����ϰ� �Ű�����(�Ķ����)�� ���޵� ���ڸ� �޴´�.
void rent_open(rent* r_tail) {

	//�����ͺ��� ���� �� �ʱ�ȭ
	rent* p = NULL; 
	rent* newNode = NULL; 
	FILE* fp = NULL;

	//���� ����
	char title[30];	
	char id[10]; 
	char rent_d[10]; 
	char return_d[10];

	int is_eof = 0; //���� ���� �� �ʱ�ȭ

	fp = fopen("RENT_FILE.txt", "r"); //RENT_FILE.txt ������ r(�б�) ���� ����

	//������ �ִ��� Ȯ���ϴ� ����
	if (fp == NULL) {
		printf("RENT_FILE�� �������� �ʽ��ϴ�.\n");
		return 0;
	}
	else {
		printf("RENT_FILE�� �ҷ��ɴϴ�.\n");
	}
	//������ ������ �������� ����
	while (1) {
		is_eof = fscanf(fp, "%s %s %s %s", title, id, rent_d, return_d); //fscanf(fp, "%s %s %s %s", title, id, rent_d, return_d)���� title, id, rent_d, return_d�� ���� ���� �� ������ EOF�� ��ȯ
		
		//is_eof�� EOF�� ��ġ�ϸ� ������ ���̹Ƿ� �ݺ����� Ż���ϱ� ���� break�� �Ѵ�.
		if (is_eof == EOF) {
			break;
		}

		//newNode, newNode->video_title, newNode->user_id, newNode->rent_date, newNode->return_date �޸� �Ҵ�
		newNode = (rent*)malloc(sizeof(rent));
		newNode->video_title = (char*)malloc(sizeof(char) * strlen(title) + 1);
		newNode->user_id = (char*)malloc(sizeof(char) * strlen(id) + 1);
		newNode->rent_date = (char*)malloc(sizeof(char) * strlen(rent_d) + 1);
		newNode->return_date = (char*)malloc(sizeof(char) * strlen(return_d) + 1);

		//strcpy�� title�� �ִ� ���ڿ��� newNode->video_title�� ����, id�� �ִ� ���ڿ��� newNode->user_id�� ����, rent_d�� �ִ� ���ڿ��� newNode->rent_date�� ����, return_d�� �ִ� ���ڿ��� newNode->return_date�� ����
		strcpy(newNode->video_title, title); 
		strcpy(newNode->user_id, id); 
		strcpy(newNode->rent_date, rent_d); 
		strcpy(newNode->return_date, return_d);

		//newNode ����
		p = r_tail->prev; 
		newNode->next = p->next; 
		newNode->prev = p; 
		p->next = newNode; 
		r_tail->prev = newNode;
	}
	fclose(fp); //���� ������ �ݱ�
}

//�Լ� return_open�� void������ �����ϰ� �Ű�����(�Ķ����)�� ���޵� ���ڸ� �޴´�.
void return_open(rent* return_tail) {

	//�����ͺ��� ���� �� �ʱ�ȭ
	rent* p = NULL; 
	rent* newNode = NULL; 
	FILE* fp = NULL;

	//���� ����
	char title[30];	
	char id[10]; 
	char rent_d[10]; 
	char return_d[10];

	int is_eof = 0; //���� ���� �� �ʱ�ȭ

	fp = fopen("RETURN_FILE.txt", "r"); //RETURN_FILE.txt ������ r(�б�) ���� ����

	//������ �ִ��� Ȯ���ϴ� ����
	if (fp == NULL) {
		printf("RETURN_FILE�� �������� �ʽ��ϴ�.\n");
		return 0;
	}
	else {
		printf("RETURN_FILE�� �ҷ��ɴϴ�.\n");
	}
	//������ ������ �������� ����
	while (1) {
		is_eof = fscanf(fp, "%s %s %s %s", title, id, rent_d, return_d); //fscanf(fp, "%s %s %s %s", title, id, rent_d, return_d)���� title, id, rent_d, return_d�� ���� ���� �� ������ EOF�� ��ȯ
		
		//is_eof�� EOF�� ��ġ�ϸ� ������ ���̹Ƿ� �ݺ����� Ż���ϱ� ���� break�� �Ѵ�.
		if (is_eof == EOF) {
			break;
		}

		//newNode, newNode->video_title, newNode->user_id, newNode->rent_date, newNode->return_date �޸� �Ҵ�
		newNode = (rent*)malloc(sizeof(rent));
		newNode->video_title = (char*)malloc(sizeof(char) * strlen(title) + 1);
		newNode->user_id = (char*)malloc(sizeof(char) * strlen(id) + 1);
		newNode->rent_date = (char*)malloc(sizeof(char) * strlen(rent_d) + 1);
		newNode->return_date = (char*)malloc(sizeof(char) * strlen(return_d) + 1);

		//strcpy�� title�� �ִ� ���ڿ��� newNode->video_title�� ����, id�� �ִ� ���ڿ��� newNode->user_id�� ����, rent_d�� �ִ� ���ڿ��� newNode->rent_date�� ����, return_d�� �ִ� ���ڿ��� newNode->return_date�� ����
		strcpy(newNode->video_title, title); 
		strcpy(newNode->user_id, id); 
		strcpy(newNode->rent_date, rent_d); 
		strcpy(newNode->return_date, return_d);

		//newNode ����
		p = return_tail->prev; 
		newNode->next = p->next; 
		newNode->prev = p; 
		p->next = newNode; 
		return_tail->prev = newNode;
	}
	fclose(fp); //���� ������ �ݱ�
}