#include "cafe.h"

void readFile(char fileName[], int *numberOfPlates, int *eatTime, int *clientChance, int *washTime, int *timeUnit){
    FILE *input = fopen(fileName, "r");
    if(input == NULL){
        printf("Could not open input file\n");
        exit(1);
    }
    fscanf(input, "%d", &(*numberOfPlates));
    fscanf(input, "%d", &(*eatTime));
    fscanf(input, "%d", &(*clientChance));
    fscanf(input, "%d", &(*washTime));
    fscanf(input, "%d", &(*timeUnit));
    fclose(input);
}

BigInteger newBigInt(int number){
    if (number == 0){
        BigInteger bigInt = createBigInteger();
        bigInt->sign = 0;
        bigInt->size = 1;
        bigInt->head = createDigit(0);
        return bigInt;
    }
    int size = 0;
    int temp = number;
    BigInteger bigInt = createBigInteger();
    bigInt->sign = (number < 0) ? 1 : 0;
    Digit *ptr = &(bigInt->head);
    temp = number;
    while (temp != 0){
        *ptr = createDigit(temp % 10);
        if (!*ptr){
            bigIntegerFree(bigInt);
            return NULL;
        }
        ptr = &((*ptr)->next);
        temp /= 10;
        ++size;
    }
    bigInt->size = size;
    removeZeros(bigInt);

    return bigInt;
}

int isInStack(Stack *stack, DATA_TYPE n){
    Node *current = stack->top;
    while (current != NULL){
        if (current->data == n){
            return 1;
        }
        current = current->next;
    }
    return 0;
}

void removeFromStack(Stack *stack, DATA_TYPE n){
    Node *current = stack->top;
    Node *previous = NULL;
    while (current != NULL){
        if (current->data == n){
            if (previous == NULL){
                stack->top = current->next;
            }
            else{
                previous->next = current->next;
            }
            Node *temp = current;
            current = current->next;
            free(temp);
        }
        else{
            previous = current;
            current = current->next;
        }
    }
}

int randomNumber(int min, int max){
    return (rand() % (max - min + 1)) + min;
}