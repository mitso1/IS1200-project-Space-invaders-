/* mipslabwork.c

   This file written 2015 by F Lundevall
   Updated 2017-04-21 by F Lundevall

   This file should be changed by YOU! So you must
   add comment(s) here with your name(s) and date(s):

   This file modified 2017-04-31 by Ture Teknolog

   Edited by Adam Brolin 11-02-24 

   For copyright and licensing, see file COPYING */

#include <stdint.h>   /* Declarations of uint_32 and the like */
#include <pic32mx.h>  /* Declarations of system-specific addresses etc */
#include "spaceinv.h"  /* Declatations for these labs */
int prime = 1234567;
int mytime = 0x5957;
int  count = 0;
int  testCount = 0;


char textstring[] = "text, more text, and even more text!";



/* Interrupt Service Routine */
void user_isr( void )
{

  if (gamestate == 0)
  {
    if (getbtns(3)) //& (PORTF & 0x80) btn4 
    {
      IFSCLR(0) = 0x100;
      gameinit();
      gamestate = 1;
    }
    if (getbtns(2)) //& (PORTF & 0x80) btn4 
    {
      IFSCLR(0) = 0x100;
      gameinit();
      gamestate = 4;
    }
    if (IFS(0) & 0x100)
    {
      IFSCLR(0) = 0x100; // reset
    }
    
  }
  
  
  if (gamestate == 1)
  {
    // btn1  PORTF & 0x10
    if (getbtns(0))// & (PORTF & 0x10) 
    {
      IFSCLR(1) = 0x1;
      // Pause
      //display_string(1, "Pause");
      gamestate = 0;
    }
    // btn2  PORTD & 0x20
    if (getbtns(1)) //& (PORTD & 0x20)(IFS(1) & 0x1)
    {
      // Move Right 
      IFSCLR(1) = 0x1;
      if ((player / 128) > 1)
        player -= 128;
    }
    // btn3 PORTD & 0x40
    if (getbtns(2)) //& (PORTD & 0x40)
    {
      // Shoot 
      IFSCLR(1) = 0x1;
      if ((nofProjectiles < sizeof(projectiles) / sizeof(uint16_t)) && triggerCooldown == 0)
      {
        projectiles[nofProjectiles] = (player / 128)*128 + 120;
        nofProjectiles++;
        triggerCooldown = 8; // 400 ms cooldown for shooting
      }
      
    }
    // btn4 PORTD & 0x80
    if (getbtns(3)) //& (PORTF & 0x80) 
    {
      // Move left 
      IFSCLR(1) = 0x1;
      if((player) < 3837 - 256) //124
        player += 128;
    }

    if (IFS(0) & 0x100)
    {
      IFSCLR(0) = 0x100; // reset
      count++;
      gameloop();
      if (triggerCooldown != 0)
      {
        triggerCooldown--;
      }
      drawGraphics();
      convGraph();
      display_graphics(0, graphics);
    }
  }

  if (gamestate == 2)
  {
    IFSCLR(0) = 0x100;
    display_graphics(0, gameover);
    if (getbtns(0)) 
    {
      IFSCLR(0) = 0x100;
      gamestate = 0;
    }
    
  }

  if (gamestate == 3)
  {
    IFSCLR(0) = 0x100;
    saveHighscore(score); 
  }
  
  /* if (gamestate == 4)
  {
    chooseInitials(); 
  } */
  
  if (gamestate == 4)
  {
    IFSCLR(0) = 0x100;
    leaderboard();
    display_update();


    if (getbtns(0)) 
    {
      gamestate = 0;
    }
  }
  
  
  /* if (IFS(0) & 0x800)
  {
    IFSCLR(0) = 0x800; // reset
    mytime += 3;
  } */
}

/* Lab-specific initialization goes here */
void labinit( void )
{
  //gameinit();
  TMR2 = 0; 
  T2CON = 0;                    // count wraps at 10
  PR2 = (80000000 / 256) / 20;  // PR2 = 80M / 256 / 10 = 31250  (max for 16 bit is 65535)

  IPCSET(2) = 0x1f00001e;             // second highest prority T2 and highest for INT2

  IECSET(0) = 0x900;            // interrupt enable for T2 and INT2

  /* CNENSET = 0x4000;             // enable CNEN14
  IECSET(1) = 0x1;   */            // interrupt enable CNIE

  
  T2CON = 0x8070;               // T2CON = 1000 0000 0111 0000

  enable_interrupt();
  // IFS0 & 0x100 interrupt flag

  volatile int *trise = (volatile int*) 0xbf886100;
  *trise &= ~0xff;
  TRISDSET = 0xfe0;
  TRISFSET = 0x2;
  return;
}

/* This function is called repetitively from the main program */
void labwork( void )
{
  
  /* prime = nextprime(prime);
  display_string(0, itoaconv(prime)); */
  //display_update();
}
