#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 10
char *s_gets(char *, int);
struct book{
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};

int main(void){
    struct book libraty[MAXBKS];
    int count = 0;
    int index, filencount;
    FILE *pbooks;
    int size = sizeof(struct book);

    if ((pbooks = fopen("book.dat", "a+b")) == NULL){
        fputs("Cat't open book,dat file\n", stderr);
        exit(1);
    }

    rewind(pbooks);  //定位到文件开始，只用于读取，写入还是追加
    while (count < MAXBKS && fread(&libraty[count], size,
        1, pbooks) == 1){
            if (count == 0)
                puts("Current contents of book.dat:");
            printf("%s by %s:$%.2f\n", libraty[count].title,
                libraty[count].author, libraty[count].value);
            count++;
    }
    filencount = count;
    if (count == MAXBKS){
        fputs("The book.dat file is full.", stderr);
        exit(2);
    }

    puts("Please add new book titles.");
    puts("Press [enter] at the start of a line to stop.");
    while (count < MAXBKS && s_gets(libraty[count].title, MAXTITL) != NULL
        && libraty[count].title[0] != '\0'){
            puts("Now enter the author.");
            s_gets(libraty[count].author, MAXAUTL);
            puts("Now enter the value.");
            scanf("%f", &libraty[count++].value);
            while (getchar() != '\n') continue;
            if (count < MAXBKS)
                puts("Enter the next title.");
        }

        if (count > 0){
            puts("Here is the list of your books:");
            for (index = 0; index < count; index++)
                printf("%s by %s:$%.2f\n", libraty[index].title,
                    libraty[index].author, libraty[index].value);
            fwrite(&libraty[filencount], size, count - filencount,
                    pbooks);
        }
        else puts("No book? Too bad.\n");

        puts("Bye.\n");
        fclose(pbooks);

        return 0;
}