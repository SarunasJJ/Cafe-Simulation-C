#ifndef CAFE_H_
#define CAFE_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "stack.h"
#include "BigInteger.h"

void readFile(char fileName[], int *numberOfPlates, int *eatTime, int *clientChance, int *washTime, int *timeUnit);
BigInteger newBigInt(int number);
int isInStack(Stack *stack, DATA_TYPE value);
void removeFromStack(Stack *stack, DATA_TYPE n);
int randomNumber(int min, int max);

#endif