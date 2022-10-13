#include<stdio.h> //printf
#include<stdlib.h> //malloc ,exit
#include<string.h> //strcpy, strlen
#include"my_struct.h" //����� �ڷ���

//�Լ� user_insert�� void������ �����ϰ� �Ű�����(�Ķ����)�� ���޵� ���ڸ� �޴´�.
void user_insert(user* u_tail, user* u_head) {

	//���� ����
	char id[10]; 
	char name[10];

	//�����ͺ��� ���� �� �ʱ�ȭ
	user* p = NULL; 
	user* newNode = NULL; 
	p = u_head->next;

	printf("�����ڸ� �߰��մϴ�.\n");
	printf("������ �̸�:"); 
	scanf("%s", name); 
	printf("������ id: "); 
	scanf("%s", id);

	//�Է��� id�� �ߺ��Ǵ��� Ȯ���ϴ� ����
	while (p->next != NULL) {
		if (strcmp(p->user_id, id) == 0) {
			printf("�Է��Ͻ� id�� �̹� �����մϴ�. �ٽ� �õ����ּ���\n");
			return 0;
		}
		p = p->next;
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

	printf("������ �߰��� �Ϸ�Ǿ����ϴ�.\n");
	user_store(u_head); //user_store �Լ��� ȣ���ϰ� ���ڵ��� �����Ѵ�.
}

//�Լ� video_insert�� void������ �����ϰ� �Ű�����(�Ķ����)�� ���޵� ���ڸ� �޴´�.
void video_insert(video* v_tail, video* v_head) {

	//���� ����
	char title[30]; 
	int stock;

	//�����ͺ��� ���� �� �ʱ�ȭ
	video* p = NULL; 
	video* newNode = NULL; 
	p = v_head->next;

	printf("������ �߰��մϴ�.\n");
	printf("���� ����: "); scanf("%s", title);

	//�Է��� title�� �ߺ��Ǵ��� Ȯ���ϴ� ����
	while (p->next != NULL) {
		if (strcmp(p->video_title, title) == 0) {
			printf("�Է��Ͻ� ������ �̹� �����մϴ�. �ٽ� �õ����ּ���\n");
			return 0;
		}
		p = p->next;
	}
	printf("���: "); 
	scanf("%d", &stock);
	while (getchar() != '\n') {
		printf("���ڿ��� �Է��߽��ϴ�. ���α׷��� �����մϴ�. �ٽ� �õ����ּ���.");
		exit(1);
	}
	//newNode, newNode->video_title �޸� �Ҵ�
	newNode = (video*)malloc(sizeof(video));
	newNode->video_title = (char*)malloc(sizeof(char) * strlen(title) + 1);

	strcpy(newNode->video_title, title); //strcpy�� title�� �ִ� ���ڿ��� newNode->video_title�� ����
	newNode->stock = stock; //newNode->stock�� stock ����

	//newNode ����
	p = v_tail->prev; 
	newNode->next = p->next; 
	newNode->prev = p; p->next = newNode; 
	v_tail->prev = newNode;

	printf("���� �߰��� �Ϸ�Ǿ����ϴ�.\n");
	video_store(v_head); //video_store �Լ��� ȣ���ϰ� ���ڵ��� �����Ѵ�.
}

//�Լ� rent_insert�� void������ �����ϰ� �Ű�����(�Ķ����)�� ���޵� ���ڸ� �޴´�.
void rent_insert(rent* r_tail, video* v_head, user* u_head, rent* r_head) {

	//���� ����
	char id[10]; 
	char title[30]; 
	char rent_d[10]; 
	char return_d[10];

	//�����ͺ��� ���� �� �ʱ�ȭ
	rent* p = NULL; 
	rent* newNode = NULL; 
	user* id_p = NULL; 
	video* title_p = NULL; 
	rent* r_p = NULL; 
	id_p = u_head->next; 
	title_p = v_head->next; 
	r_p = r_head->next;

	printf("�����ڰ� ������ �뿩�մϴ�.\n");
	printf("������ id�� �Է����ּ���: "); scanf("%s", id);

	//�������� �������� id�� �ִ��� Ȯ���ϴ� ����
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
	printf("�뿩�ϰ���� ���� ������ �Է����ּ���: "); 
	scanf("%s", title);

	//�Է��� id�� �Է��� title�� ���� �뿩�ߴ��� Ȯ���ϴ� ����(���������� ���� ������ �� id�� 1���� ���� �� �ִ�.)
	while (r_p->next != NULL) {
		if ((strcmp(r_p->user_id, id) == 0) && (strcmp(r_p->video_title, title) == 0)) {
			printf("%s��(��) %s��(��) ���� �뿩�� ���� �ֽ��ϴ�. �ٽ� �õ����ּ���.\n", r_p->user_id, r_p->video_title);
			return 0;
		}
		r_p = r_p->next;
	}
	//��������� video title�� �ִ��� Ȯ���ϴ� ����
	while (title_p->next != NULL) {
		if (strcmp(title_p->video_title, title) == 0) {
			if (title_p->stock <= 0) {
				printf("���� ��� 0�� �Դϴ�. �ٽ� �õ����ּ���.\n");
				return 0;
			}
			else {
				(title_p->stock)--;
				break;
			}
		}
		title_p = title_p->next;
	}
	if (title_p->next == NULL) {
		printf("�뿩�ϰ���� ���� ������ �����ϴ�.\n");
		return 0;
	}
	printf("�뿩��¥: "); 
	scanf("%s", rent_d); 
	printf("�ݳ���¥: "); 
	scanf("%s", return_d);

	//newNode, newNode->video_title, newNode->user_id, newNode->rent_date, newNode->return_date �޸� �Ҵ�
	newNode = (rent*)malloc(sizeof(rent));
	newNode->video_title = (char*)malloc(sizeof(char) * strlen(title) + 1);
	newNode->user_id = (char*)malloc(sizeof(char) * strlen(id) + 1);
	newNode->rent_date = (char*)malloc(sizeof(char) * strlen(rent_d) + 1);
	newNode->return_date = (char*)malloc(sizeof(char) * strlen(return_d) + 1);

	//strcpy�� title�� �ִ� ���ڿ��� newNode->video_title�� ����, id�� �ִ� ���ڿ��� newNode->user_id�� ����, rent_d�� �ִ� ���ڿ��� newNode->rent_date�� ����, return_d�� �ִ� ���ڿ��� newNode->return_date�� ����
	strcpy(newNode->video_title, title); strcpy(newNode->user_id, id); strcpy(newNode->rent_date, rent_d); strcpy(newNode->return_date, return_d);

	//newNode ����
	p = r_tail->prev; 
	newNode->next = p->next; 
	newNode->prev = p; 
	p->next = newNode; 
	r_tail->prev = newNode;

	printf("�뿩�� �������� ���� �߰��� �Ϸ�Ǿ����ϴ�.\n");
	rent_store(r_head); //rent_store �Լ��� ȣ���ϰ� ���ڵ��� �����Ѵ�.
}

//�Լ� return_insert�� void������ �����ϰ� �Ű�����(�Ķ����)�� ���޵� ���ڸ� �޴´�.
void return_insert(rent* return_tail, rent* return_head, rent* val) {
	rent* p = NULL; 
	rent* new_p = NULL;
	p = return_head->next;
	printf("p�� �ּҰ� : %d\n", val);
	new_p = val;
	printf("p�� �ּҰ� : %d\n", new_p);
	printf("dd");
	p = return_tail->prev; new_p->next = p->next; new_p->prev = p; p->next = new_p; return_tail->prev = new_p; //newNode ����
	printf("�ݳ��� �Ϸ��� �������� ���� �߰��� �Ϸ�Ǿ����ϴ�.\n");
	return_store(return_head); //return_store �Լ��� ȣ���ϰ� ���ڵ��� �����Ѵ�.
}