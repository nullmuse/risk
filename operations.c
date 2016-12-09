#include <stdio.h>
#include <stdlib.h>
#include "map.h"


void populateReinforcements(colony *colonyList, int colonyCount) { 
int i;
for(i = 0; i < colonyCount; ++i) { 
colonyList[i]->combatants = 1 + colonyList[i]->unitBonus; 
}
}

int calculateDeployment(colony *colonyOne, colony *colonyTwo) { 
int colonyHigh,colonyLow; 
colonyHigh = (colonyOne->lineStart > colonyTwo->lineStart) ? colonyOne: colonyTwo;
colonyLow = (colonyOne->lineStart < colonyTwo->lineStart) ? colonyOne: colonyTwo;
if((colonyHigh - colonyLow) > 3) { 
return DEPLOYMENT_ORBITAL; 
}
if((colonyHigh - colonyLow) >= 2) {
return DEPLOYMENT_MESOPHERIC; 
}
return DEPLOYMENT_CONVENTIONAL; 

}

int calculateDeploymentLoss(int units, int deploymentType) { 
int i; 
for(i = 0; i < units; ++i) { 
if((random() % 100) < deploymentRisks[deploymentType]) { 
units--; 
}
}
return units; 
}


void riskSort(int unitArray[], int arrayLength) { 
int tripwire = 1;
int i,k,tmp;
while(tripwire) {
tripwire = 0;
for(k = 0; k < arrayLength; ++k) {  
for(i = 0; i < arrayLength; ++i) { 
if(unitArray[k] < unitArray[i]) { 
tripwire++;
tmp = unitArray[k]; 
unitArray[k] = unitArray[i];
unitArray[i] = tmp; 
} 
}
}
}

void enemyContact(battalion *attacker, battalion *defender) { 
int i;
int combatants = (defender->numOfUnits > attacker->numOfUnits) ? defender->numOfUnits: attacker->numOfUnits
int defenseArray[defender->numOfUnits];
int assaultArray[attacker->numOfUnits]; 
for(i = 0; i < defender->numOfUnits; ++i) { 
defenseArray[i] = (random() % defender->dietype) + defender->boost + defender->drawback; 
}
for(i = 0; i < attacker->numOfUnits; ++i) {
assaultArray[i] = (random() % attacker->dietype) + attacker->boost + attacker->drawback;
} 






