#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count_characters(FILE *file) {
    int characters = 0;
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        characters++;
    }
    return characters;
}

int count_words(FILE *file) {
    int words = 0;
    char ch;
    char last_char = ' ';
    while ((ch = fgetc(file)) != EOF) {
        if ((ch == ' ' || ch == ',' || ch == '\n' || ch == '\t') && (last_char != ' ' && last_char != ',' && last_char != '\n' && last_char != '\t')) {
            words++;
        }
        last_char = ch;
    }
    // Add the last word if the file doesn't end with a delimiter
    if (last_char != ' ' && last_char != ',' && last_char != '\n' && last_char != '\t') {
        words++;
    }
    return words;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("�÷�: %s [-c|-w] [file_name]\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[2], "r");
    if (file == NULL) {
        perror("�޷����ļ�");
        return 1;
    }

    if (strcmp(argv[1], "-c") == 0) {
        int characters = count_characters(file);
        printf("�ַ�����%d\n", characters);
    } else if (strcmp(argv[1], "-w") == 0) {
        int words = count_words(file);
        printf("��������%d\n", words);
    } else {
        printf("��Ч�Ĳ��� '%s'. ��ʹ�� '-c' �� '-w'.\n", argv[1]);
        fclose(file);
        return 1;
    }

    fclose(file);
    return 0;
}

