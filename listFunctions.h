//creates new pointer and allocate memory for a new student
struct student *create_student(void) {
    struct student *s = (struct student *) malloc(sizeof(struct student));
    s->next = NULL;
    return s;
}

//Searching to the list for a student name
struct student *search_student_name(char *s) {
    previous = NULL;
    current = head;
    while (current != NULL) {
        if (strcmp(current->name, s) == 0)
            return current;
        previous = current;
        current = current->next;
    }
    return NULL;
}

//Searching to the list for a student surname
struct student *search_student_surname(char *s) {
    previous = NULL;
    current = head;
    while (current != NULL) {
        if (strcmp(current->surname, s) == 0)
            return current;
        previous = current;
        current = current->next;
    }
    return NULL;
}

int lastYearInTheList() {
    int result = 0;
    current = head;

    while (current != NULL) {
        result = current->year > result ? current->year : result;
        current = current->next;
    }
    return result;
}

//Searching to the list for a student AM
struct student *search_student_AM(int s) {
    previous = NULL;
    current = head;
    while (current != NULL) {
        if (current->AM == s)
            return current;
        previous = current;
        current = current->next;
    }
    return NULL;
}

//Adds a student to the list
void add_student(struct student *mystudent) {
    if (head == NULL) {
        head = mystudent;
        return;
    }

    current = head;
    previous = NULL;

    //skip all student of prior years
    while ((mystudent->year > current->year) && (current->next != NULL)) {
        previous = current;
        current = current->next;
    }

    //is the first student of the year
    if ((mystudent->year > current->year) && (current->next == NULL)) {
        mystudent->AM = mystudent->year * 100 + 1;
        current->next = mystudent;
        return;
    }

    int inserted = 0;
    //find the appropriate position in the current year
    while (current != NULL) {
        if (firstIsLess(current, mystudent)) {
            previous = current;
            current = current->next;
        } else {  // insert
            mystudent->next = current;
            if (previous == NULL) {
                head = mystudent;
            } else {
                previous->next = mystudent;
            }
            inserted = 1;
            break;
        }
    }
    // append
    if ((current == NULL) && (inserted == 0)) {
        previous->next = mystudent;
    }
}
