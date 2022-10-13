#include<stdio.h> //printf
#include<stdlib.h> //malloc ,exit
#include<string.h> //strcpy, strlen
#include"my_struct.h" //사용할 자료형

//함수 user_insert를 void형으로 선언하고 매개변수(파라미터)로 전달된 인자를 받는다.
void user_insert(user* u_tail, user* u_head) {

	//변수 선언
	char id[10]; 
	char name[10];

	//포인터변수 선언 및 초기화
	user* p = NULL; 
	user* newNode = NULL; 
	p = u_head->next;

	printf("가입자를 추가합니다.\n");
	printf("가입자 이름:"); 
	scanf("%s", name); 
	printf("가입자 id: "); 
	scanf("%s", id);

	//입력한 id가 중복되는지 확인하는 과정
	while (p->next != NULL) {
		if (strcmp(p->user_id, id) == 0) {
			printf("입력하신 id가 이미 존재합니다. 다시 시도해주세요\n");
			return 0;
		}
		p = p->next;
	}
	//newNode, newNode->user_id, newNode->user_name 메모리 할당
	newNode = (user*)malloc(sizeof(user));
	newNode->user_id = (char*)malloc(sizeof(char) * strlen(id) + 1);
	newNode->user_name = (char*)malloc(sizeof(char) * strlen(name) + 1);

	//strcpy로 id에 있는 문자열을 newNode->user_id으로 복사, name에 있는 문자열을 newNode->user_name으로 복사
	strcpy(newNode->user_id, id);
	strcpy(newNode->user_name, name);

	//newNode 연결
	p = u_tail->prev; 
	newNode->next = p->next; 
	newNode->prev = p; 
	p->next = newNode; 
	u_tail->prev = newNode;

	printf("가입자 추가가 완료되었습니다.\n");
	user_store(u_head); //user_store 함수를 호출하고 인자들을 전달한다.
}

//함수 video_insert를 void형으로 선언하고 매개변수(파라미터)로 전달된 인자를 받는다.
void video_insert(video* v_tail, video* v_head) {

	//변수 선언
	char title[30]; 
	int stock;

	//포인터변수 선언 및 초기화
	video* p = NULL; 
	video* newNode = NULL; 
	p = v_head->next;

	printf("비디오를 추가합니다.\n");
	printf("비디오 제목: "); scanf("%s", title);

	//입력한 title이 중복되는지 확인하는 과정
	while (p->next != NULL) {
		if (strcmp(p->video_title, title) == 0) {
			printf("입력하신 비디오가 이미 존재합니다. 다시 시도해주세요\n");
			return 0;
		}
		p = p->next;
	}
	printf("재고: "); 
	scanf("%d", &stock);
	while (getchar() != '\n') {
		printf("문자열을 입력했습니다. 프로그램을 종료합니다. 다시 시도해주세요.");
		exit(1);
	}
	//newNode, newNode->video_title 메모리 할당
	newNode = (video*)malloc(sizeof(video));
	newNode->video_title = (char*)malloc(sizeof(char) * strlen(title) + 1);

	strcpy(newNode->video_title, title); //strcpy로 title에 있는 문자열을 newNode->video_title로 복사
	newNode->stock = stock; //newNode->stock에 stock 저장

	//newNode 연결
	p = v_tail->prev; 
	newNode->next = p->next; 
	newNode->prev = p; p->next = newNode; 
	v_tail->prev = newNode;

	printf("비디오 추가가 완료되었습니다.\n");
	video_store(v_head); //video_store 함수를 호출하고 인자들을 전달한다.
}

//함수 rent_insert를 void형으로 선언하고 매개변수(파라미터)로 전달된 인자를 받는다.
void rent_insert(rent* r_tail, video* v_head, user* u_head, rent* r_head) {

	//변수 선언
	char id[10]; 
	char title[30]; 
	char rent_d[10]; 
	char return_d[10];

	//포인터변수 선언 및 초기화
	rent* p = NULL; 
	rent* newNode = NULL; 
	user* id_p = NULL; 
	video* title_p = NULL; 
	rent* r_p = NULL; 
	id_p = u_head->next; 
	title_p = v_head->next; 
	r_p = r_head->next;

	printf("가입자가 비디오를 대여합니다.\n");
	printf("본인의 id를 입력해주세요: "); scanf("%s", id);

	//빌리려는 가입자의 id가 있는지 확인하는 과정
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
	printf("대여하고싶은 비디오 제목을 입력해주세요: "); 
	scanf("%s", title);

	//입력한 id가 입력한 title을 전에 대여했는지 확인하는 과정(비디오제목이 같은 비디오는 한 id당 1개만 빌릴 수 있다.)
	while (r_p->next != NULL) {
		if ((strcmp(r_p->user_id, id) == 0) && (strcmp(r_p->video_title, title) == 0)) {
			printf("%s는(은) %s를(을) 전에 대여한 적이 있습니다. 다시 시도해주세요.\n", r_p->user_id, r_p->video_title);
			return 0;
		}
		r_p = r_p->next;
	}
	//빌리고싶은 video title이 있는지 확인하는 과정
	while (title_p->next != NULL) {
		if (strcmp(title_p->video_title, title) == 0) {
			if (title_p->stock <= 0) {
				printf("현재 재고가 0개 입니다. 다시 시도해주세요.\n");
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
		printf("대여하고싶은 비디오 제목이 없습니다.\n");
		return 0;
	}
	printf("대여날짜: "); 
	scanf("%s", rent_d); 
	printf("반납날짜: "); 
	scanf("%s", return_d);

	//newNode, newNode->video_title, newNode->user_id, newNode->rent_date, newNode->return_date 메모리 할당
	newNode = (rent*)malloc(sizeof(rent));
	newNode->video_title = (char*)malloc(sizeof(char) * strlen(title) + 1);
	newNode->user_id = (char*)malloc(sizeof(char) * strlen(id) + 1);
	newNode->rent_date = (char*)malloc(sizeof(char) * strlen(rent_d) + 1);
	newNode->return_date = (char*)malloc(sizeof(char) * strlen(return_d) + 1);

	//strcpy로 title에 있는 문자열을 newNode->video_title로 복사, id에 있는 문자열을 newNode->user_id로 복사, rent_d에 있는 문자열을 newNode->rent_date로 복사, return_d에 있는 문자열을 newNode->return_date로 복사
	strcpy(newNode->video_title, title); strcpy(newNode->user_id, id); strcpy(newNode->rent_date, rent_d); strcpy(newNode->return_date, return_d);

	//newNode 연결
	p = r_tail->prev; 
	newNode->next = p->next; 
	newNode->prev = p; 
	p->next = newNode; 
	r_tail->prev = newNode;

	printf("대여한 가입자의 정보 추가가 완료되었습니다.\n");
	rent_store(r_head); //rent_store 함수를 호출하고 인자들을 전달한다.
}

//함수 return_insert를 void형으로 선언하고 매개변수(파라미터)로 전달된 인자를 받는다.
void return_insert(rent* return_tail, rent* return_head, rent* val) {
	rent* p = NULL; 
	rent* new_p = NULL;
	p = return_head->next;
	printf("p의 주소값 : %d\n", val);
	new_p = val;
	printf("p의 주소값 : %d\n", new_p);
	printf("dd");
	p = return_tail->prev; new_p->next = p->next; new_p->prev = p; p->next = new_p; return_tail->prev = new_p; //newNode 연결
	printf("반납을 완료한 가입자의 정보 추가가 완료되었습니다.\n");
	return_store(return_head); //return_store 함수를 호출하고 인자들을 전달한다.
}