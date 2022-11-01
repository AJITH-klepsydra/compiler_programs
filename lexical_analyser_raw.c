#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

char *get_info(char i);

char *get_info_str(char *substr);

bool is_delimeter(char ltr) {
    if (ltr == ' ' || ltr == ';' || ltr == '+' || ltr == '=' || ltr == ',')return true;
    else return false;
}

char *substr(char *string, int start, int end) {
    char *result = malloc(sizeof(char) * (end - start) + 2);
    int k = 0;
    for (int i = start + 1; i < end; i++) {
        result[k] = string[i];
        k++;
    }
    return result;
}

int main() {
    printf("Lexical analyser!\n");
    char *input = "int 8ab;";
    int length = strlen(input);
    int l = 0, r = 0;
    if (input[0] == '/' && input[1] == '/') {
        printf("\nCOMMENT LINE\n");
        exit(1);
    }
    while (r <= length && l <= r) {
        if (!is_delimeter(input[r])) r++;
        else if (is_delimeter(input[r]) && l == r) {
            printf("<%c,'%s'>\n", input[r], get_info(input[r]));
            l = r;
            r++;
        } else {

            if (r - l != 1)
                printf("<%s,'%s'>\n", substr(input, l, r), get_info_str(substr(input, l, r)));
            l = r;
        }
    }
    return 0;
}

char *get_info_str(char *substr) {
    if ((substr[0] >= 65 && substr[0] <= 90) || (substr[0] >= 97 && substr[0] <= 122)) {
        for (int i = 0; i <= strlen(substr); i++) {
            if (((substr[0] >= 65 && substr[0] <= 90) || (substr[0] >= 97 && substr[0] <= 122))) {

            }
        }
        return "Identifier";
    } else {
        return "Number";
    }
}

char *get_info(char i) {
    if (i == '+' || i == '-' || i == '*' || i == '/' || i == '%' || i == '=')
        return "Operator";
    else
        return "Separator";
}
