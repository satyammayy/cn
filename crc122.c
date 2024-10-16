#include<stdio.h> 
#include<string.h> 
#define POLY_LEN strlen(generator)

char inputData[28], checksum[28], generator[28];
int dataLen, i, j, errorPos;

void performXOR() {
    for(j = 1; j < POLY_LEN; j++)
        checksum[j] = (checksum[j] == generator[j]) ? '0' : '1';
}

void computeCRC() {
    for(i = 0; i < POLY_LEN; i++)
        checksum[i] = inputData[i];
    do {
        if(checksum[0] == '1') performXOR();
        for(j = 0; j < POLY_LEN - 1; j++)
            checksum[j] = checksum[j + 1];
        checksum[j] = inputData[i++];
    } while(i <= dataLen + POLY_LEN - 1);
}

int main() {
    strcpy(generator, "1100000001111");
    printf("\nEnter data: ");
    scanf("%s", inputData);
    printf("\n-----------------------\n");
    printf("\nGenerating polynomial: %s", generator);

    dataLen = strlen(inputData);
    for(i = dataLen; i < dataLen + POLY_LEN - 1; i++)
        inputData[i] = '0';

    printf("\n--------------------------\n");
    printf("Modified data is: %s", inputData);
    printf("\n-----------------------\n");

    computeCRC();
    printf("Checksum is: %s", checksum);

    for(i = dataLen; i < dataLen + POLY_LEN - 1; i++)
        inputData[i] = checksum[i - dataLen];

    printf("\n-----------------------\n");
    printf("\nFinal codeword is: %s", inputData);
    printf("\n------------------------\n");

    computeCRC();
    for(i = 0; (i < POLY_LEN - 1) && (checksum[i] != '1'); i++);
    if(i < POLY_LEN - 1)
        printf("Error detected\n\n");
    else
        printf("\nNo error detected\n\n");

    printf("\n-----------------------");
    printf("\nInsert error and test ");
    
    do {
        printf("\n\tEnter the position where error is to be inserted: ");
        scanf("%d", &errorPos);
    } while(errorPos == 0 || errorPos > dataLen + POLY_LEN - 1);

    inputData[errorPos - 1] = (inputData[errorPos - 1] == '0') ? '1' : '0';
    
    printf("\n-----------------------\n");
    printf("\nErroneous data: %s\n", inputData);

    computeCRC();
    for(i = 0; (i < POLY_LEN - 1) && (checksum[i] != '1'); i++);
    if(i < POLY_LEN - 1)
        printf("Error detected\n\n");
    else
        printf("\nNo error detected\n\n");

    printf("\n-----------------------");
    return 0;
}
