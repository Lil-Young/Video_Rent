#pragma once
//사용할 구조체
typedef struct User {
	char* user_id;
	char* user_name;
	struct User* next;
	struct User* prev;
}user;

typedef struct Video {
	char* video_title;
	int stock;
	struct Video* next;
	struct Video* prev;
}video;

typedef struct Rent {
	char* video_title;
	char* user_id;
	char* rent_date;
	char* return_date;
	struct Rent* next;
	struct Rent* prev;
}rent;
