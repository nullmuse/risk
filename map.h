static const int MAP_LENGTH = 64; 
static const int MAP_HEIGHT = 40; 
static const char pixel = '.'; 
static const long MAP_MASK = 0xFFFFFFFE; 
static const int DEPLOYMENT_CONVENTIONAL = 0; 
static const int DEPLOYMENT_MESOPHERIC = 1; 
static const int DEPLOYMENT_ORBITAL = 2;
static const int deploymentRisks[] = {0,10,30};

typedef struct { 
int colonyName; 
int lineStart; 
long border; 
long boundary; 
int combatants;
int player;
int unitBonus;
} colony; 

typedef struct { 
int numOfUnits;
int boost;
int drawback;
int dietype;
} battalion;

static const char *factions[] = {"x","+","#","o","@","&","V","%","?"};
static const char *lords[] = {
"Glorious Leader Cardinale",
"Archpope Haubrich",
"Viceroy Dow",
"Colonel Roy",
"Duke Ems",
"Furor Oberbeck",
"Engineer Supreme Stuessel",
"Prator Ryan",
"Albatross Solis",
};
static const int faction_size = 9;
static const enum faction { 
checkers = 0,
chickfila,
burgerking,
kfc,
innout,
fiveguys,
skyline,
caesar,
alcohol
}; 










