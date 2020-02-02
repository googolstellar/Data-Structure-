//Program to find the substring 
#include<stdio.h>
int main(){
    char str[100], subStr[20];
    int i, j = 0, k = 0, count = 0, flag = 0, strLen = 0, subStrLen = 0;
    printf("Enter the string(max 100 char): ");
    fgets(str, 100, stdin); 
    printf("Enter the subString: ");
    fgets(subStr, 20, stdin);
    for(i = 0; str[i] != '\0'; i++);
    strLen = i-1;
    for(i = 0; subStr[i] != '\0'; i++);
    subStrLen = i-1;
    i = 0;
    while(i < strLen){
        flag = 0;
        j = 0;
        if(str[i] == subStr[j]){
            k = i;
            while(str[k] == subStr[j] && k != strLen && j != subStrLen){
                k++;
                j++;
            }
            if(j == subStrLen && (str[k] == ' ' || k == strLen)){
                count++;
                i = k + 1;
                flag = 1;
            }
        }
        if(flag == 0){
            while(str[i] != ' ' && i < strLen)
                i++;
            i++;
        }
    }
    printf("The substring occured %d times ", count);
    return 0;
}