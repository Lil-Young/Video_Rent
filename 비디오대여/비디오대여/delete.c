#include<stdio.h> //printf, scanf
#include<stdlib.h> //free, malloc
#include<string.h> //strcmp
#include"my_struct.h" //사용할 자료형
#define _CRT_SECURE_NO_WARINGS //scanf 보안 경고로 인한 컴파일 에러 방지

//함수 user_del를 void형으로 선언하고 매개변수(파라미터)로 전달된 인자를 받는다.
void user_del(user* u_head, rent* r_head) {

	//포인터변수 선언 및 초기화
	user* p = NULL; 
	rent* r_p = NULL; 
	p = u_head->next; 
	r_p = r_head->next;

	char id[1000]; //변수 선언

	printf("회원을 삭제합니다.\n");
	printf("삭제하고싶은 id를 입력해주세요: "); 
	scanf("%s", id);

	//입력한 id가 대여한 비디오가 있는지 없는지 확인하는 과정
	while (r_p->next != NULL) {
		if (strcmp(r_p->user_id, id) == 0) {
			printf("대여한 비디오가 있습니다. 반납을 완료하고 다시 시도하세요\n");
			return 0;
		}
		r_p = r_p->next;
	}
	//입력한 id가 있는지 확인하는 과정
	while (p->next != NULL) {
		if (strcmp(p->user_id, id) == 0) {
			break;
		}
		p = p->next;
	}
	if (p->next == NULL) {
		printf("삭제하고싶은 id가 존재하지 않습니다. 다시 시도해주세요.\n");
	}
	else {
		printf("회원 이름: %s, 회원 id: %s를 삭제합니다.\n", p->user_name, p->user_id);

		//p가 가리키는 노드 양옆에 있는 노드들 연결
		p->prev->next = p->next; 
		p->next->prev = p->prev;

		// p->user_name, p->user_id, p 메모리 해제
		free(p->user_name); 
		free(p->user_id); 
		free(p);
	}
	user_store(u_head); //user_store 함수를 호출하고 인자들을 전달한다.
}

//함수 video_del를 void형으로 선언하고 매개변수(파라미터)로 전달된 인자를 받는다.
void video_del(video* v_head, rent* r_head) {

	//포인터변수 선언 및 초기화
	video* p = NULL;
	rent* r_p = NULL; 
	p = v_head->next; 
	r_p = r_head->next;

	char title[1000]; //변수 선언

	printf("비디오를 삭제합니다.\n");
	printf("삭제하고싶은 비디오 제목을 입력해주세요: "); 
	scanf("%s", title);

	//입력한 title이 대여된게 있는지 확인하는 과정
	while (r_p->next != NULL) {
		if (strcmp(r_p->video_title, title) == 0) {
			printf("대여된 비디오가 있습니다. 반납을 완료하고 다시 시도하세요\n");
			return 0;
		}
		r_p = r_p->next;
	}
	//입력한 title이 있는지 확인하는 과정
	while (p->next != NULL) {
		if (strcmp(p->video_title, title) == 0) {
			break;
		}
		p = p->next;
	}
	if (p->next == NULL) {
		printf("삭제하고싶은 비디오가 존재하지 않습니다. 다시 시도해주세요.\n");
	}
	else {
		printf("비디오 제목: %s, 비디오 재고: %d를 삭제합니다.\n", p->video_title, p->stock);

		//p가 가리키는 노드 양옆에 있는 노드들 연결
		p->prev->next = p->next; 
		p->next->prev = p->prev;

		//p->video_title, p 메모리 해제
		free(p->video_title);
		free(p);
	}
	video_store(v_head); //video_store 함수를 호출하고 인자들을 전달한다.
}

//함수 return_complete를 void형으로 선언하고 매개변수(파라미터)로 전달된 인자를 받는다.
void return_complete(rent* r_head, video* v_head, user* u_head, rent* return_tail, rent* return_head) {

	//포인터변수 선언 및 초기화
	rent* p = NULL; 
	user* id_p = NULL; 
	video* title_p = NULL; 
	rent* new_p = NULL;
	p = r_head->next; 
	id_p = u_head->next; 
	title_p = v_head->next;
	new_p = return_head->next;

	//변수 선언
	char id[1000];
	char title[1000];

	printf("회원이 비디오를 반납합니다.\n");
	printf("본인의 id를 입력해주세요: "); 
	scanf("%s", id);

	//입력한 id가 있는지 확인하는 과정
	while (id_p->next != NULL) {
		if (strcmp(id_p->user_id, id) == 0) {
			printf("id가 확인되었습니다.\n");
			break;
		}
		id_p = id_p->next;
	}
	if (id_p->next == NULL) {
		printf("입력하신 id가 존재하지 않습니다. 다시 시도해주세요.\n");
		return 0;
	}

	printf("반납하고싶은 비디오 제목을 입력해주세요: "); 
	scanf("%s", title);

	//입력한 title이 있는지 확인하는 과정
	while (p->next != NULL) {
		if (strcmp(p->video_title, title) == 0) {
			break;
		}
		p = p->next;
	}
	if (p->next == NULL) {
		printf("반납하고싶은 비디오 제목이 없습니다. 다시 시도해주세요.\n");
		return 0;
	}

	printf("%s가 %s를 반납합니다.\n", p->user_id, p->video_title);

	//입력한 title의 재고를 추가하는 과정
	while (title_p->next != NULL) {
		if (strcmp(title_p->video_title, title) == 0) {
			(title_p->stock)++;
			break;
		}
		title_p = title_p->next;
	}

	//p가 가리키는 노드 양옆에 있는 노드들 연결
	p->prev->next = p->next; 
	p->next->prev = p->prev;

	rent_store(r_head); //rent_store 함수를 호출하고 인자들을 전달한다.

	//p가 가리키는 노드는 반납을 했으므로 반납정보에 추가한다.
	new_p = return_tail->prev;
	p->next = new_p->next;
	p->prev = new_p;
	new_p->next = p;
	return_tail->prev = p;

	printf("반납을 완료한 회원의 정보 추가가 완료되었습니다.\n");
	return_store(return_head); //return_store 함수를 호출하고 인자들을 전달한다.

}

//함수 user_all_del를 void형으로 선언하고 매개변수(파라미터)로 전달된 인자를 받는다.
void user_all_del(user* u_head) {

	//포인터변수 선언 및 초기화
	user* p = NULL; 
	p = u_head->next;

	//초기화 과정
	while (p->next != NULL) {

		//p가 가리키는 노드 양옆에 있는 노드들 연결
		p->prev->next = p->next; 
		p->next->prev = p->prev;

		//p->user_id, p->user_name, p 메모리 해제
		free(p->user_id); 
		free(p->user_name); 
		free(p);

		p = u_head->next; //포인터변수 p는 u_head->next를 가리킨다.
	}
	printf("회원의 정보를 초기화합니다.\n");
	user_store(u_head); //user_store 함수를 호출하고 인자들을 전달한다.
}

//함수 video_all_del를 void형으로 선언하고 매개변수(파라미터)로 전달된 인자를 받는다.
void video_all_del(video* v_head) {

	//포인터변수 선언 및 초기화
	video* p = NULL; 
	p = v_head->next;

	//초기화 과정
	while (p->next != NULL) {

		//p가 가리키는 노드 양옆에 있는 노드들 연결
		p->prev->next = p->next; 
		p->next->prev = p->prev;

		//p->video_title, p 메모리 해제
		free(p->video_title); 
		free(p);

		p = v_head->next; //포인터변수 p는 v_head->next를 가리킨다.
	}
	printf("비디오의 정보를 초기화합니다.\n");
	video_store(v_head); //video_store 함수를 호출하고 인자들을 전달한다.
}

//함수 rent_reurn_all_del를 void형으로 선언하고 매개변수(파라미터)로 전달된 인자를 받는다.
void rent_return_all_del(rent* r_head, rent* return_head) {

	//포인터변수 선언 및 초기화
	rent* p = NULL; 
	rent* return_p = NULL;
	p = r_head->next;
	return_p = return_head->next;

	//초기화 과정
	while (p->next != NULL) {

		//p가 가리키는 노드 양옆에 있는 노드들 연결
		p->prev->next = p->next; 
		p->next->prev = p->prev;

		//p->user_id, p->video_title, p->rent_date, p->return_date, p 메모리 해제
		free(p->user_id); 
		free(p->video_title); 
		free(p->rent_date); 
		free(p->return_date); 
		free(p);

		p = r_head->next; //포인터변수 p는 r_head->next를 가리킨다.
	}
	printf("대여한 회원의 정보를 초기화합니다.\n");
	rent_store(r_head); //rent_store 함수를 호출하고 인자들을 전달한다.

	//초기화 과정
	while (return_p->next != NULL) {

		//return_p가 가리키는 노드 양옆에 있는 노드들 연결
		return_p->prev->next = return_p->next;
		return_p->next->prev = return_p->prev;

		//return_p->user_id, return_p->video_title, return_p->rent_date, return_p->return_date, return_p 메모리 해제
		free(return_p->user_id);
		free(return_p->video_title);
		free(return_p->rent_date);
		free(return_p->return_date);
		free(return_p);

		return_p = return_head->next; //포인터변수 return_p는 return_head->next를 가리킨다.
	}
	printf("반납을 완료한 회원의 정보를 초기화합니다.\n");
	return_store(return_head); //return_store 함수를 호출하고 인자들을 전달한다.

}