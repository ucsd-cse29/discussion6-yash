#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void parse_sscanf(char* str) {
    char value1[100], value2[100], value3[100];
    sscanf(str, "/path?value1=%[^&]&value2=%[^&]&value3=%s", value1, value2, value3);
    printf("Value1: %s\n", value1);
    printf("Value2: %s\n", value2);
    printf("Value3: %s\n", value3);
}

void parse_strtok(char* str) {
    char* after_qmark = strchr(str, '?') + 1;
    char* token = strtok(after_qmark, "&");

    // Simply prints out the value after each key, DOES NOT perform any storing
    while (token != NULL) {
        if (strncmp(token, "value1=", 7) == 0) {
            printf("Value1: %s\n", token+7);
        } else if (strncmp(token, "value2=", 7) == 0) {
            printf("Value2: %s\n", token+7);
        } else if (strncmp(token, "value3=", 7) == 0) {
            printf("Value3: %s\n", token+7);
        }
        token = strtok(NULL, "&");
    }
}

// goal is to extract the TA Names from the string
int main() {

    char str[] = "/path?value1=thisisvalue1&value2=thisisvalue2&value3=thisisvalue3";

    // Method 1: sscanf
    parse_sscanf(str);

    // Method 2: strtok
    parse_strtok(str);

}