#include<stdio.h> //fopen, fclose, fscanf, printf
#include<stdlib.h> //free, malloc
#include<string.h> //strcpy, strcmp
#include"my_struct.h" //사용할 자료형

//함수 user_open을 void형으로 선언하고 매개변수(파라미터)로 전달된 인자를 받는다.
void user_open(user* u_tail) {

	//포인터변수 선언 및 초기화
	user* p = NULL; 
	user* newNode = NULL; 
	FILE* fp = NULL;

	//변수 선언
	char id[10]; 
	char name[10];

	int is_eof = 0; //변수 선언 및 초기화

	fp = fopen("USER_FILE.txt", "r"); //USER_FILE.txt 파일을 r(읽기) 모드로 열기

	//파일이 있는지 확인하는 과정
	if (fp == NULL) {
		printf("USER_FILE이 존재하지 않습니다.\n");
		return 0;
	}
	else {
		printf("USER_FILE을 불러옵니다.\n");
	}
	//파일의 내용을 가져오는 과정
	while (1) {
		is_eof = fscanf(fp, "%s %s", id, name); //fscanf(fp, "%s %s", id, name)에서 id, name의 값을 읽을 수 없으면 EOF를 반환

		//is_eof와 EOF가 일치하면 파일의 끝이므로 반복문을 탈출하기 위해 break를 한다.
		if (is_eof == EOF) {
			break;
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
	}
	fclose(fp); //파일 포인터 닫기
}

//함수 video_open을 void형으로 선언하고 매개변수(파라미터)로 전달된 인자를 받는다.
void video_open(video* v_tail) {

	//포인터변수 선언 및 초기화
	video* p = NULL; 
	video* newNode = NULL; 
	FILE* fp = NULL;

	//변수 선언
	char title[30]; 
	int stock;

	int is_eof = 0; //변수 선언 및 초기화

	fp = fopen("VIDEO_FILE.txt", "r"); //VIDEO_FILE.txt 파일을 r(읽기) 모드로 열기

	//파일이 있는지 확인하는 과정
	if (fp == NULL) {
		printf("VIDEO_FILE이 존재하지 않습니다.\n");
		return 0;
	}
	else {
		printf("VIDEO_FILE을 불러옵니다.\n");
	}
	//파일의 내용을 가져오는 과정
	while (1) {
		is_eof = fscanf(fp, "%s %d", title, &stock); //fscanf(fp, "%s %d", title, &stock)에서 title, &stock의 값을 읽을 수 없으면 EOF를 반환

		//is_eof와 EOF가 일치하면 파일의 끝이므로 반복문을 탈출하기 위해 break를 한다.
		if (is_eof == EOF) {
			break;
		}

		//newNode, newNode->video_title 메모리 할당
		newNode = (user*)malloc(sizeof(user));
		newNode->video_title = (char*)malloc(sizeof(char) * strlen(title) + 1);

		strcpy(newNode->video_title, title); //strcpy로 title에 있는 문자열을 newNode->video_title로 복사
		newNode->stock = stock; //newNode->stock에 stock 저장

		//newNode 연결
		p = v_tail->prev; 
		newNode->next = p->next; 
		newNode->prev = p; 
		p->next = newNode;
		v_tail->prev = newNode;
	}
	fclose(fp); //파일 포인터 닫기
}

//함수 rent_open을 void형으로 선언하고 매개변수(파라미터)로 전달된 인자를 받는다.
void rent_open(rent* r_tail) {

	//포인터변수 선언 및 초기화
	rent* p = NULL; 
	rent* newNode = NULL; 
	FILE* fp = NULL;

	//변수 선언
	char title[30];	
	char id[10]; 
	char rent_d[10]; 
	char return_d[10];

	int is_eof = 0; //변수 선언 및 초기화

	fp = fopen("RENT_FILE.txt", "r"); //RENT_FILE.txt 파일을 r(읽기) 모드로 열기

	//파일이 있는지 확인하는 과정
	if (fp == NULL) {
		printf("RENT_FILE이 존재하지 않습니다.\n");
		return 0;
	}
	else {
		printf("RENT_FILE을 불러옵니다.\n");
	}
	//파일의 내용을 가져오는 과정
	while (1) {
		is_eof = fscanf(fp, "%s %s %s %s", title, id, rent_d, return_d); //fscanf(fp, "%s %s %s %s", title, id, rent_d, return_d)에서 title, id, rent_d, return_d의 값을 읽을 수 없으면 EOF를 반환
		
		//is_eof와 EOF가 일치하면 파일의 끝이므로 반복문을 탈출하기 위해 break를 한다.
		if (is_eof == EOF) {
			break;
		}

		//newNode, newNode->video_title, newNode->user_id, newNode->rent_date, newNode->return_date 메모리 할당
		newNode = (rent*)malloc(sizeof(rent));
		newNode->video_title = (char*)malloc(sizeof(char) * strlen(title) + 1);
		newNode->user_id = (char*)malloc(sizeof(char) * strlen(id) + 1);
		newNode->rent_date = (char*)malloc(sizeof(char) * strlen(rent_d) + 1);
		newNode->return_date = (char*)malloc(sizeof(char) * strlen(return_d) + 1);

		//strcpy로 title에 있는 문자열을 newNode->video_title로 복사, id에 있는 문자열을 newNode->user_id로 복사, rent_d에 있는 문자열을 newNode->rent_date로 복사, return_d에 있는 문자열을 newNode->return_date로 복사
		strcpy(newNode->video_title, title); 
		strcpy(newNode->user_id, id); 
		strcpy(newNode->rent_date, rent_d); 
		strcpy(newNode->return_date, return_d);

		//newNode 연결
		p = r_tail->prev; 
		newNode->next = p->next; 
		newNode->prev = p; 
		p->next = newNode; 
		r_tail->prev = newNode;
	}
	fclose(fp); //파일 포인터 닫기
}

//함수 return_open을 void형으로 선언하고 매개변수(파라미터)로 전달된 인자를 받는다.
void return_open(rent* return_tail) {

	//포인터변수 선언 및 초기화
	rent* p = NULL; 
	rent* newNode = NULL; 
	FILE* fp = NULL;

	//변수 선언
	char title[30];	
	char id[10]; 
	char rent_d[10]; 
	char return_d[10];

	int is_eof = 0; //변수 선언 및 초기화

	fp = fopen("RETURN_FILE.txt", "r"); //RETURN_FILE.txt 파일을 r(읽기) 모드로 열기

	//파일이 있는지 확인하는 과정
	if (fp == NULL) {
		printf("RETURN_FILE이 존재하지 않습니다.\n");
		return 0;
	}
	else {
		printf("RETURN_FILE을 불러옵니다.\n");
	}
	//파일의 내용을 가져오는 과정
	while (1) {
		is_eof = fscanf(fp, "%s %s %s %s", title, id, rent_d, return_d); //fscanf(fp, "%s %s %s %s", title, id, rent_d, return_d)에서 title, id, rent_d, return_d의 값을 읽을 수 없으면 EOF를 반환
		
		//is_eof와 EOF가 일치하면 파일의 끝이므로 반복문을 탈출하기 위해 break를 한다.
		if (is_eof == EOF) {
			break;
		}

		//newNode, newNode->video_title, newNode->user_id, newNode->rent_date, newNode->return_date 메모리 할당
		newNode = (rent*)malloc(sizeof(rent));
		newNode->video_title = (char*)malloc(sizeof(char) * strlen(title) + 1);
		newNode->user_id = (char*)malloc(sizeof(char) * strlen(id) + 1);
		newNode->rent_date = (char*)malloc(sizeof(char) * strlen(rent_d) + 1);
		newNode->return_date = (char*)malloc(sizeof(char) * strlen(return_d) + 1);

		//strcpy로 title에 있는 문자열을 newNode->video_title로 복사, id에 있는 문자열을 newNode->user_id로 복사, rent_d에 있는 문자열을 newNode->rent_date로 복사, return_d에 있는 문자열을 newNode->return_date로 복사
		strcpy(newNode->video_title, title); 
		strcpy(newNode->user_id, id); 
		strcpy(newNode->rent_date, rent_d); 
		strcpy(newNode->return_date, return_d);

		//newNode 연결
		p = return_tail->prev; 
		newNode->next = p->next; 
		newNode->prev = p; 
		p->next = newNode; 
		return_tail->prev = newNode;
	}
	fclose(fp); //파일 포인터 닫기
}