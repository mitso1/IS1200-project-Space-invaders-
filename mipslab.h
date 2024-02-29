/* mipslab.h
   Header file for all labs.
   This file written 2015 by F Lundevall
   Some parts are original code written by Axel Isaksson

   Latest update 2015-08-28 by F Lundevall

   For copyright and licensing, see file COPYING */

/* Declare display-related functions from mipslabfunc.c */
void display_image(int x, const uint8_t *data);
void display_graphics(int x, const uint8_t *data);
void display_init(void);
void display_string(int line, char *s);
void display_update(void);
uint8_t spi_send_recv(uint8_t data);

/* Declare lab-related functions from mipslabfunc.c */
char * itoaconv( int num );
void labwork(void);
int nextprime( int inval );
void quicksleep(int cyc);
void tick( unsigned int * timep );

/* Declare display_debug - a function to help debugging.

   After calling display_debug,
   the two middle lines of the display show
   an address and its current contents.

   There's one parameter: the address to read and display.

   Note: When you use this function, you should comment out any
   repeated calls to display_image; display_image overwrites
   about half of the digits shown by display_debug.
*/
void display_debug( volatile int * const addr );

/* Declare bitmap array containing font */
extern const uint8_t const font[128*8];
/* Declare bitmap array containing icon */
extern const uint8_t const icon[128];
/* Declare bitmap array containing icon */
extern uint8_t graphics[];

extern const uint8_t gameover[512*1];

// extern uint8_t calcGraph[8*4096];

extern const uint8_t enemyIcon[9*1];

extern const uint8_t deadEnemyIcon0[9*1];

extern const uint8_t deadEnemyIcon1[9*1];

extern const uint8_t deadEnemyIcon2[9*1];

extern const uint8_t playerIcon[9*1];

extern const uint8_t obstacleIcon[9*1];

extern const uint8_t damagedObstacleIcon1[9*1];

extern const uint8_t damagedObstacleIcon2[9*1];

extern const uint8_t projectileIcon[9*1];

extern const int16_t startingEnemies[18*2];

extern int16_t enemies[18*2];

extern int16_t enemyDeathAnimation[18*2];

extern int16_t enemiesShootCount[18*2];

extern const int16_t startingEnemiesShootCount[18*2];

extern const int16_t startingObstacles[12*2];

extern int16_t obstacles[12*2];

extern int16_t obstacleHealth[12*2];

extern int16_t projectiles[144*2];

extern int16_t enemyProjectiles[144*2];

extern const int16_t startingXEnemySpeed[2*18];

extern int16_t xEnemySpeed[2*18];

extern const int16_t startingYEnemySpeed[2*18];

extern int16_t yEnemySpeed[2*18];

extern int16_t xProjectileSpeed[2*36];

int16_t highscores[2*128];

extern int16_t player;
/* Declare text buffer for display output */
extern char textbuffer[4][16];
/* Declare GAMESTATE */

extern uint8_t gamestate;
extern uint16_t score;
extern uint16_t highscore;
extern uint16_t nofHighscores;
extern uint8_t deathTimer;
extern uint8_t level;
extern uint8_t nofEnemies;
extern uint8_t nofObstacles;
extern uint8_t nofProjectiles;
extern uint8_t nofEnemyProjectiles;
extern uint8_t triggerCooldown;
extern uint8_t enemyMovementCount;
extern uint8_t enemyRndAssignment;
/* Declare functions written by students.
   Note: Since we declare these functions here,
   students must define their functions with the exact types
   specified in the laboratory instructions. */
/* Written as part of asm lab: delay, time2string */
void delay(int);
void time2string( char *, int );
char hexasc(int);
/* Written as part of i/o lab: getbtns, getsw, enable_interrupt */
uint8_t getbtns(int);
int getsw(void);
void enable_interrupt(void);
