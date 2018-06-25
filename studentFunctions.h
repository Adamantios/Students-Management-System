void recalculateAM(int YEAR) {
    if (head == NULL)
        return;

    int counter = 1;
    current = head;

    while (current != NULL) {
        if (current->year == YEAR)
            break;
        current = current->next;
    }
    while (current != NULL) {
        current->AM = YEAR * 100 + counter;
        counter++;
        current = current->next;
    }
}

//increases all the students AMs after "mystudent", that have been registered at the same year , by one
int firstIsLess(struct student *s1, struct student *s2) {
    int i = strcmp(s1->surname, s2->surname);
    if (i == 0)
        i = strcmp(s1->name, s2->name);
    return i < 0;
}

//inserts new student information shorted
void Insert() {
    struct student *mystudent = create_student();
    printf("Give the student name:");
    scanf("%s", &mystudent->name);
    printf("Give the student surname:");
    scanf("%s", &mystudent->surname);
    printf("Give the year of the student registration:");
    scanf("%d", &mystudent->year);

    // check if list is empty
    if (head == NULL) {
        mystudent->AM = mystudent->year * 100 + 1;
        head = mystudent;
        return;
    }

    // check if mystudent's year is less than of first student in the list
    if (mystudent->year < lastYearInTheList()) {
        printf("the year is closed for new students\n");
        free(mystudent);
        return;
    }

    add_student(mystudent);
    recalculateAM(mystudent->year);
}

//deletes student information depending to AM
void Del(void) {
    if (head == NULL) {
        printf("the list is empty");
        return;
    }

    int AM;
    struct student *tmp;
    printf("Give AM:");
    scanf("%d", &AM);

    tmp = search_student_AM(AM);

    if (tmp == NULL) {
        printf("%s", NO_AM_FOUND);
        return;
    }

    // check if mystudent's year is less than of first student in the list
    if (tmp->year < lastYearInTheList()) {
        printf("the year is closed. students of previous year cannot be deleted.\n");
        return;
    }
    if (previous == NULL)
        head = tmp->next;
    else
        previous->next = tmp->next;

    recalculateAM(tmp->year);
    free(tmp);
}

//refreshes student information depending to AM
void Refresh(void) {
    if (head == NULL) {
        printf("the list is empty");
        return;
    }

    int AM;
    struct student *tmp;
    printf("Give AM:");
    scanf("%d", &AM);

    tmp = search_student_AM(AM);

    if (tmp == NULL) {
        printf("%s", NO_AM_FOUND);
        return;
    }
    if (tmp->year < lastYearInTheList()) {
        printf("The year is closed. Students of previous year cannot be refreshed.\n");
        return;
    }

    printf("Give new name:");
    scanf("%s", &tmp->name);
    printf("Give new surname:");
    scanf("%s", &tmp->surname);

    if (previous == NULL)
        head = tmp->next;
    else
        previous->next = tmp->next;

    tmp->next = NULL;

    add_student(tmp);

    recalculateAM(tmp->year);
}

//shows a list of the students information
void List(void) {
    if (head == NULL) {
        printf("the list is empty");
        return;
    }

    current = head;
    char c;
    int i = 1;
    while (current != NULL) {
        printf("%2d: Student name: %s\n    Student surname: %s\n", i, &current->name, &current->surname);
        printf("    Student year of registration: %d\n    Student AM: %d\n", current->year, current->AM);
        i++;
        current = current->next;
    }
    printf("press enter to return...");
    do {   //Loop until 'Enter' is pressed
        c = getch();
    } while (c != '\r');
    printf("\n");
}
