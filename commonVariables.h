char *digits = "0123456789";

enum {
    Exit = 0, insert, del, refresh, list, save
};

struct student {
    char name[30];
    char surname[50];
    int year;
    int AM;
    struct student *next;
};

struct student *head = NULL;
struct student *previous = NULL;
struct student *current = NULL;
