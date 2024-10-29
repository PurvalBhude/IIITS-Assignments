#include <stdio.h>
#define min(a, b) ((a) > (b) ? (b) : (a))
void printmenu() {
    printf("a. String concatenation\n");
    printf("b. Finding length of the string\n");
    printf("c. Checking palindrome\n");
    printf("d. Two strings are same or not (string equality)\n");
    printf("e. Copying one string to another\n");
}
void strconcat(char *str1, char *str2) {
    int i = 0;
    while (str1[i] != '\0') {
        i++;
    }
    int j = 0;
    while (str2[j] != '\0') {
        str1[i] = str2[j];
        i++;
        j++;
    }
    str1[i] = '\0';
}
int strlength(char *str) {
    int count = 0;
    while (str[count] != '\0') {
        count++;
    }
    return count;
}

int palindrome(char *str) {
    int length = strlength(str);
    int left = 0;
    int right = length - 1;
    while (left < right) {
        if (str[left] != str[right]) {
            return 0;
        }
        left++;
        right--;
    }
    return 1;
}

int strsame(char *str1, char *str2) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return 0;
        }
        i++;
    }
    return str1[i] == '\0' && str2[i] == '\0';
}

void copystr(char *str1, char *str2) {
    int i = 0;
    while (str1[i] != '\0') {
        str2[i] = str1[i];
        i++;
    }
    str2[i] = '\0';
}

int main() {
    char str1[] = "Purval ";
    char str2[] = "Bhude";
    printf("Select one of the options:\n");
    char select;
    printmenu();
    printf("Selection: ");
    scanf(" %c", &select); 
    printf("\n");

    switch (select) {
        case 'a':
            strconcat(str1, str2);
            printf("String concatenation: %s\n", str1);
            break;
        case 'b':
            printf("Length of str1 is %d and str2 is %d\n", strlength(str1), strlength(str2));
            break;
        case 'c':
            if (palindrome(str1)) {
                printf("It is palindrome\n");
            } else {
                printf("It's not palindrome\n");
            }
            break;
        case 'd':
            if (strsame(str1, str2)) {
                printf("Strings are same\n");
            } else {
                printf("Strings are not same\n");
            }
            break;
        case 'e':
            copystr(str1, str2);
            printf("String 1 is same as string 2 (%s) as they are copied\n", str1, str2);
            break;
        default:
            printf("Wrong option chosen\n");
            break;
    }

    return 0;
}
