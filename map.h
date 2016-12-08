static const int MAP_LENGTH = 64; 
static const int MAP_HEIGHT = 40; 
static const char pixel = '.'; 
static const long MAP_MASK = 0xFFFFFFFE; 

typedef struct { 
int colonyName; 
int lineStart; 
long border; 
long boundary; 
int combatants;
int player;
} colony; 

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










