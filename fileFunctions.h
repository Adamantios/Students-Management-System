//saves the informations to a file
void Save(void) {
    FILE *myfile;
    if ((myfile = fopen("mystudentsfile.dat", "w")) == NULL) {
        printf("file could not be created\n");
        return;
    }
    current = head;
    while (current != NULL) {
        fwrite(current, sizeof(struct student), 1, myfile);
        current = current->next;
    }
    fclose(myfile);
}

//loads the information from the file to the memory
void Load(void) {
    FILE *myfile;
    if ((myfile = fopen("mystudentsfile.dat", "r")) == NULL) {
        printf("%s", FILE_DOES_NOT_EXIST);
        return;
    }
    head = NULL;
    previous = NULL;
    current = NULL;

    int result;
    int counter = 0;

    while (!(feof(myfile))) {
        current = create_student();
        result = fread(current, sizeof(struct student), 1, myfile);

        if (result == 1) {
            if (head == NULL)
                head = current;
            else
                previous->next = current;
            previous = current;
            current->next = NULL;
            counter++;
        }
    }
    printf("\n%d records loaded from file mystudentsfile.dat\n\n", counter);
}
