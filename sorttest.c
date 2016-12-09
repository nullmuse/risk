#include <stdio.h>
#include <stdlib.h>



void riskSort(int unitArray[], int arrayLength) {
int tripwire,tripcan;
int i,k,tmp;
tripwire = 1;
tripcan = 0;
while(tripwire) {
tripwire = 0;
for(k = 0; k < arrayLength; ++k) { 
for(i = 0; i < arrayLength; ++i) {
if(unitArray[k] > unitArray[i]) {
tripwire++;
tmp = unitArray[k];
unitArray[k] = unitArray[i];
unitArray[i] = tmp; 
}
}
}

}
}



int main(void) { 

int i;
int arr1[] = {1,2,3,4,5,6,7,8,9,40}; 

int arrlen = 10; 

riskSort(arr1,10); 

for(i = 0; i < arrlen; ++i) {
printf("%i ",arr1[i]);
}
printf("\n");

return 0; 

}

