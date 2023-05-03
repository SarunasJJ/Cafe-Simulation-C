#include "cafe.h"

int main(int argc, char *argv[]){
    srand(time(NULL));
    int numberOfPlates, eatTime, clientChance, washTime;
    int endTimeUnit;
    char filename[255];
    if(argc > 1){
        strcpy(filename, argv[1]);
    } else{
        strcpy(filename, "input.txt");
    }
    readFile(filename, &numberOfPlates, &eatTime, &clientChance, &washTime, &endTimeUnit);

    Stack *cleanPlateStack = stack_create();
    Stack *usedPlateStack = stack_create();
    Stack *clientLine = stack_create();

    BigInteger customersServed = newBigInt(0);
    BigInteger customersUnserved = newBigInt(0);
    BigInteger additionalPlates = newBigInt(0);
    
    int timeUnit = 1;
    int maxPlates = 0;
    int totalPlates = numberOfPlates;

    for(int i = 0; i<numberOfPlates; i++){
        stack_push(cleanPlateStack, 1);
    }

    while(timeUnit<=endTimeUnit){
        if(isInStack(usedPlateStack,timeUnit)){
            removeFromStack(usedPlateStack, timeUnit);
            numberOfPlates = totalPlates - stack_count(usedPlateStack);
            while(numberOfPlates != stack_count(cleanPlateStack)){
                stack_push(cleanPlateStack, timeUnit);
            }
        }
        if(numberOfPlates<=0){
            customersUnserved = bigIntegerAdd(customersUnserved, newBigInt(1));
            additionalPlates = bigIntegerAdd(additionalPlates, newBigInt(1));
            stack_push(clientLine, timeUnit);
        }
        if(stack_count(cleanPlateStack)>0 && stack_count(usedPlateStack)<totalPlates && randomNumber(1, 100) <= clientChance){
            stack_pop(cleanPlateStack);
            --numberOfPlates;
            customersServed = bigIntegerAdd(customersServed, newBigInt(1));
            stack_push(usedPlateStack, timeUnit+eatTime+washTime);
        }
        ++timeUnit;
    }
    FILE *output = fopen("results.txt", "w");
    if(output == NULL){
        exit(1);
    }
    fprintf(output, "Number of plates at the end %d\n", numberOfPlates);
    fprintf(output, "Total of %s customers were served\n", bigIntegerToString(customersServed));
    fprintf(output, "Total of %s customers were not served\n", bigIntegerToString(customersUnserved));
    fprintf(output, "Total of %s additional plates were needed\n", bigIntegerToString(additionalPlates));
    if(stack_count(clientLine)>0){
        fprintf(output, "Customers did not find any clean plates at:\n");
        while(stack_count(clientLine)>0){
            fprintf(output, "%d time units\n", stack_pop(clientLine));
        }
    }

    fclose(output);
    stack_done(&cleanPlateStack);
    stack_done(&usedPlateStack);
    stack_done(&clientLine);
    
    bigIntegerFree(customersServed);
    bigIntegerFree(customersUnserved);
    bigIntegerFree(additionalPlates);

    return 0;
}