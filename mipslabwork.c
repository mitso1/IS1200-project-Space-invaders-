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
#include "mipslab.h"  /* Declatations for these labs */
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
    if (/* condition */) // btn4
    {
      /* New game */
    }
    if (/* condition */) // btn3
    {
      /* Leaderboards */
    }
    
  }
  
  
  if (gamestate == 1)
  {
    if (/* condition */) // btn4
    {
      /* Move left */
    }
    if (/* condition */) // btn2
    {
      /* Move Right */
    }
    if (/* condition */) // btn3
    {
      /* Shoot */
    }
    if (/* condition */) // btn1
    {
      /* Pause */
    }
    if (IFS(0) & 0x100)
    {
      IFSCLR(0) = 0x100; // reset
      count++;
      gameloop();


      if (count == 10)
      {
        time2string(textstring, mytime);
        //display_string(3, textstring);
        display_update();
        tick(&mytime);

        display_graphics(0, graphics);
        if (testCount == 10)
        {
          gamestate = 0;
          T2CONCLR = 0x8000;
        }
        
        count = 0;
        testCount++;
      }

    }
  }

  if (gamestate == 2)
  {
    if (/* condition */) // btn4
    {
      /* New game */
    }
    if (/* condition */) // btn3
    {
      /* Resume */
    }
  }

  if (gamestate == 3)
  {
    if (/* condition */) // btn4
    {
      /* New game */
    }
    if (/* condition */) // btn3
    {
      /* Save Score */
    }
  }
  
  if (gamestate == 4)
  {
    if (/* condition */) // btn4
    {
      /* Letter select left */
    }
    if (/* condition */) // btn2
    {
      /* Letter select right */
    }
    if (/* condition */) // btn3
    {
      /* Letter save */
    }

    if (/* condition */) // btn1
    {
      /* Main menu */
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
  gameinit();
  TMR2 = 0; 
  T2CON = 0;                    // count wraps at 10
  PR2 = (80000000 / 256) / 10;  // PR2 = 80M / 256 / 10 = 31250  (max for 16 bit is 65535)

  IPCSET(2) = 0x1f00001e;             // second highest prority T2 and highest for INT2

  IECSET(0) = 0x900;            // interrupt enable for T2 and INT2
  
  T2CON = 0x8070;               // T2CON = 1000 0000 0111 0000

  enable_interrupt();
  // IFS0 & 0x100 interrupt flag

  volatile int *trise = (volatile int*) 0xbf886100;
  *trise &= ~0xff;
  TRISDSET = 0xfe0;
  return;
}

/* This function is called repetitively from the main program */
void labwork( void )
{
  /* prime = nextprime(prime);
  display_string(0, itoaconv(prime)); */
  //display_update();
}
