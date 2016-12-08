#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "map.h"
#include <time.h>
#include <unistd.h>


void drawPadding(int amount);
void flashColony(int colonyNum, long mapArray[], int itemCount, colony **colonyList);
void printItem(long item,char *symbol) { 

int i,m;
int k = 0;
long item_holder = item;
for(i = 0; i < 64; ++i) { 
if(((item_holder >> i) & 1)) { 
printf(symbol); 
}
else { 
printf(" "); 
}
} 

}

void printPartition(long item, char *symbol, long range, long offset) { 

int i = 0; 

for(i = offset; i < range; i++) { 
if(i % 64 == 0)
printf("\n");
if(((item >> i) & 1)) {
printf(symbol);
}
else {
printf(" ");
}
}

} 

int printColony(long mapArray[],char *symbol,colony *theColony) {

int i,m,n;
int k = theColony->lineStart;
m = theColony->border;
for(i = theColony->border;i < theColony->boundary;++i) {
if(i % 64 == 0) { 
printPartition(mapArray[k],"x",64,m); 
k++;
m = 0;
}
}
if(theColony->boundary % 64) {
printPartition(mapArray[k],"x",theColony->boundary % 64,m);
printPartition(mapArray[k],".",64,theColony->boundary % 64); 
printf("\n");
}
return k - theColony->lineStart;
}





long initLine(void) {
long sequence = 0;
int i;
//srandom(time(NULL));
for(i = 0; i < 64; ++i) {
if((random() % 9) < 4) {
sequence += 1;
}
sequence <<= 1;
}

return sequence;
}


int colonyCollision(colony *colonyOne, colony *colonyTwo) { 
int i;
colony *lineRun; 
colony *lineControl;
int lineCount = 0;
if(colonyOne->lineStart == colonyTwo->lineStart) { 
if(colonyOne->boundary > colonyTwo->border)  { 
return -1; 
}
if(colonyTwo->boundary > colonyOne->border) { 
return -1; 
}
}

lineRun = (colonyOne->lineStart < colonyTwo->lineStart) ? colonyOne: colonyTwo; 
lineControl = (colonyOne->lineStart < colonyTwo->lineStart) ? colonyTwo: colonyOne;
lineCount = lineRun->lineStart;
for(i = lineRun->border; i < lineRun->boundary; ++i) { 
if(i % 64 == 0)
lineCount++; 
if(lineCount > lineControl->lineStart) { 
return -1; 
}
if(lineCount == lineControl->lineStart) { 
if( (i % 64) > lineControl->border) 
return -1;
}
}

return 0; 

} 
 







colony **generateColonies(long mapArray[], int length, int *colonyNum) { 

colony **colonyList = calloc(1,sizeof(colony *));
colony **colonyPtr = colonyList;
colony *newColony;
int colonyCount = 0; 
int i = 0;
long mapSize = length * 64; 
while(mapSize) { 
newColony = calloc(1,sizeof(colony)); 
newColony->border = 0;
newColony->boundary = 0;
newColony->colonyName = colonyCount; 
newColony->lineStart = random() % length; 
newColony->border = random() % 64;
newColony->boundary = random() % mapSize;
for(i = 0; i < colonyCount; ++i) { 
if(colonyCollision(newColony,colonyList[i])) { 
newColony->colonyName = -1;
break;
}
}
if(newColony->colonyName == -1) { 
free(newColony);
continue; 
} 
if((newColony->boundary - newColony->border) <= 0) {
free(newColony);
continue;
}
if(colonyCount == 0) { 
colonyList[0] = newColony; 
colonyCount++;
}
else { 
colonyPtr = calloc(colonyCount + 1,sizeof(colony *)); 
memcpy(colonyPtr,colonyList,colonyCount * sizeof(colony *)); 
free(colonyList); 
colonyList = colonyPtr; 
colonyList[colonyCount] = newColony; 
colonyCount++; 
}
mapSize -= (newColony->boundary - newColony->border);
if(colonyCount == length / 3) 
break;
}
memcpy(colonyNum,&colonyCount,sizeof(int)); 
return colonyList; 

}


void drawPadding(int amount) {

int i;
int mod_amount = amount - 1;
for(i = 0; i < mod_amount; ++i) {
printf(" ");
}
}




int main(int argc, char **argv) { 

int i,k,m;
FILE *fp; 
int userin = 0; 
long newItem = 0;
colony **colonyList;
int z = 0; 
int colonyNum = 0;
int itemCount = atoi(argv[1]); 
long mapArray[itemCount];
srandom(time(NULL)); 
for(i = 0; i < itemCount; ++i) { 
mapArray[i] = initLine();
}
for(i = 0; i < itemCount; ++i) {
printItem(mapArray[i],".");
printf("\n");
} 
sleep(2); 
system("clear");
colonyList = generateColonies(mapArray,itemCount,&colonyNum);
while(userin != 'q') { 
printf("%i colonies\n",colonyNum); 
printf("Enter colony to flash: \n"); 
userin = getchar(); 
while(userin < 0x30) { 
userin = getchar();
}
printf("%i\n",userin);
userin -= 0x30;
system("clear");
flashColony(userin,mapArray,itemCount,colonyList);
printf("Colony Stats:\n");
printf("size: %li\n",colonyList[userin]->boundary - colonyList[userin]->border); 
}

//for(z = 0; z < 16; ++z) { 
//flashColony(mapArray,itemCount);  
//sleep(1);
//system("clear");
//}

printf("\n");
return 0; 

}

void flashColony(int colonyNum, long mapArray[], int itemCount, colony **colonyList)  { 

int k  = colonyNum; 
int i;
for(i = 0; i < itemCount; ++i) {
if(colonyList[k]->lineStart == i) {
i += printColony(mapArray,"x",colonyList[k]);
}

printItem(mapArray[i],".");
printf("\n");
}
printf("\nColony %i\n",colonyList[k]->colonyName);

}




