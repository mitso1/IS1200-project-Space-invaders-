/* mipslabdata.c
   This file compiled 2015 by F Lundevall
   from original code written by Axel Isaksson

   For copyright and licensing, see file COPYING */

#include <stdint.h>   /* Declarations of uint_32 and the like */
#include <pic32mx.h>  /* Declarations of system-specific addresses etc */
#include "spaceinv.h"  /* Declatations for these labs */

char textbuffer[4][16];

const uint8_t const font[] = {
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 94, 0, 0, 0, 0,
	0, 0, 4, 3, 4, 3, 0, 0,
	0, 36, 126, 36, 36, 126, 36, 0,
	0, 36, 74, 255, 82, 36, 0, 0,
	0, 70, 38, 16, 8, 100, 98, 0,
	0, 52, 74, 74, 52, 32, 80, 0,
	0, 0, 0, 4, 3, 0, 0, 0,
	0, 0, 0, 126, 129, 0, 0, 0,
	0, 0, 0, 129, 126, 0, 0, 0,
	0, 42, 28, 62, 28, 42, 0, 0,
	0, 8, 8, 62, 8, 8, 0, 0,
	0, 0, 0, 128, 96, 0, 0, 0,
	0, 8, 8, 8, 8, 8, 0, 0,
	0, 0, 0, 0, 96, 0, 0, 0,
	0, 64, 32, 16, 8, 4, 2, 0,
	0, 62, 65, 73, 65, 62, 0, 0,
	0, 0, 66, 127, 64, 0, 0, 0,
	0, 0, 98, 81, 73, 70, 0, 0,
	0, 0, 34, 73, 73, 54, 0, 0,
	0, 0, 14, 8, 127, 8, 0, 0,
	0, 0, 35, 69, 69, 57, 0, 0,
	0, 0, 62, 73, 73, 50, 0, 0,
	0, 0, 1, 97, 25, 7, 0, 0,
	0, 0, 54, 73, 73, 54, 0, 0,
	0, 0, 6, 9, 9, 126, 0, 0,
	0, 0, 0, 102, 0, 0, 0, 0,
	0, 0, 128, 102, 0, 0, 0, 0,
	0, 0, 8, 20, 34, 65, 0, 0,
	0, 0, 20, 20, 20, 20, 0, 0,
	0, 0, 65, 34, 20, 8, 0, 0,
	0, 2, 1, 81, 9, 6, 0, 0,
	0, 28, 34, 89, 89, 82, 12, 0,
	0, 0, 126, 9, 9, 126, 0, 0,
	0, 0, 127, 73, 73, 54, 0, 0,
	0, 0, 62, 65, 65, 34, 0, 0,
	0, 0, 127, 65, 65, 62, 0, 0,
	0, 0, 127, 73, 73, 65, 0, 0,
	0, 0, 127, 9, 9, 1, 0, 0,
	0, 0, 62, 65, 81, 50, 0, 0,
	0, 0, 127, 8, 8, 127, 0, 0,
	0, 0, 65, 127, 65, 0, 0, 0,
	0, 0, 32, 64, 64, 63, 0, 0,
	0, 0, 127, 8, 20, 99, 0, 0,
	0, 0, 127, 64, 64, 64, 0, 0,
	0, 127, 2, 4, 2, 127, 0, 0,
	0, 127, 6, 8, 48, 127, 0, 0,
	0, 0, 62, 65, 65, 62, 0, 0,
	0, 0, 127, 9, 9, 6, 0, 0,
	0, 0, 62, 65, 97, 126, 64, 0,
	0, 0, 127, 9, 9, 118, 0, 0,
	0, 0, 38, 73, 73, 50, 0, 0,
	0, 1, 1, 127, 1, 1, 0, 0,
	0, 0, 63, 64, 64, 63, 0, 0,
	0, 31, 32, 64, 32, 31, 0, 0,
	0, 63, 64, 48, 64, 63, 0, 0,
	0, 0, 119, 8, 8, 119, 0, 0,
	0, 3, 4, 120, 4, 3, 0, 0,
	0, 0, 113, 73, 73, 71, 0, 0,
	0, 0, 127, 65, 65, 0, 0, 0,
	0, 2, 4, 8, 16, 32, 64, 0,
	0, 0, 0, 65, 65, 127, 0, 0,
	0, 4, 2, 1, 2, 4, 0, 0,
	0, 64, 64, 64, 64, 64, 64, 0,
	0, 0, 1, 2, 4, 0, 0, 0,
	0, 0, 48, 72, 40, 120, 0, 0,
	0, 0, 127, 72, 72, 48, 0, 0,
	0, 0, 48, 72, 72, 0, 0, 0,
	0, 0, 48, 72, 72, 127, 0, 0,
	0, 0, 48, 88, 88, 16, 0, 0,
	0, 0, 126, 9, 1, 2, 0, 0,
	0, 0, 80, 152, 152, 112, 0, 0,
	0, 0, 127, 8, 8, 112, 0, 0,
	0, 0, 0, 122, 0, 0, 0, 0,
	0, 0, 64, 128, 128, 122, 0, 0,
	0, 0, 127, 16, 40, 72, 0, 0,
	0, 0, 0, 127, 0, 0, 0, 0,
	0, 120, 8, 16, 8, 112, 0, 0,
	0, 0, 120, 8, 8, 112, 0, 0,
	0, 0, 48, 72, 72, 48, 0, 0,
	0, 0, 248, 40, 40, 16, 0, 0,
	0, 0, 16, 40, 40, 248, 0, 0,
	0, 0, 112, 8, 8, 16, 0, 0,
	0, 0, 72, 84, 84, 36, 0, 0,
	0, 0, 8, 60, 72, 32, 0, 0,
	0, 0, 56, 64, 32, 120, 0, 0,
	0, 0, 56, 64, 56, 0, 0, 0,
	0, 56, 64, 32, 64, 56, 0, 0,
	0, 0, 72, 48, 48, 72, 0, 0,
	0, 0, 24, 160, 160, 120, 0, 0,
	0, 0, 100, 84, 84, 76, 0, 0,
	0, 0, 8, 28, 34, 65, 0, 0,
	0, 0, 0, 126, 0, 0, 0, 0,
	0, 0, 65, 34, 28, 8, 0, 0,
	0, 0, 4, 2, 4, 2, 0, 0,
	0, 120, 68, 66, 68, 120, 0, 0,
};

const uint8_t const icon[] = {
	255, 255, 255, 255, 255, 255, 127, 187,
	68, 95, 170, 93, 163, 215, 175, 95,
	175, 95, 175, 95, 223, 111, 175, 247,
	59, 237, 242, 254, 171, 254, 1, 255, 
	255, 255, 15, 211, 109, 58, 253, 8,
	178, 77, 58, 199, 122, 197, 242, 173,
	242, 237, 186, 215, 40, 215, 41, 214,
	35, 175, 91, 212, 63, 234, 149, 111,
	171, 84, 253, 252, 254, 253, 126, 184,
	195, 52, 201, 22, 225, 27, 196, 19,
	165, 74, 36, 146, 72, 162, 85, 8,
	226, 25, 166, 80, 167, 216, 167, 88,
	106, 149, 161, 95, 135, 91, 175, 87,
	142, 123, 134, 127, 134, 121, 134, 121,
	132, 59, 192, 27, 164, 74, 177, 70,
	184, 69, 186, 69, 254, 80, 175, 217,
};

uint8_t graphics[] = {
	255, 255, 0, 0, 0, 0, 0, 0,
	255, 255, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	255, 72, 72, 72, 72, 72, 72, 72,
	72, 72, 72, 72, 72, 72, 72, 72,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,

	74, 74, 74, 74, 74, 74, 74, 74,
	74, 74, 74, 74, 74, 74, 74, 74,
	74, 74, 74, 74, 74, 74, 74, 74,
	74, 74, 74, 74, 74, 74, 74, 74,
	74, 74, 74, 74, 74, 74, 74, 74,
	74, 74, 74, 74, 74, 74, 74, 74,
	74, 74, 74, 74, 74, 74, 74, 74,
	74, 74, 74, 74, 74, 74, 74, 74,
	74, 74, 74, 74, 74, 74, 74, 74,
	74, 74, 74, 74, 74, 74, 74, 74,
	74, 74, 74, 74, 74, 74, 74, 74,
	74, 74, 74, 74, 74, 74, 74, 74,
	74, 74, 74, 74, 74, 74, 74, 74,
	74, 74, 74, 74, 74, 74, 74, 74,
	74, 74, 74, 74, 74, 74, 74, 74,
	74, 74, 74, 74, 74, 74, 74, 74,


	255, 255, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 255, 255, 0, 0, 0, 0, // start of block 3
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,

	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,


	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 255, 1, 0, 0, 0, 0,
	0, 0, 1, 255, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,

	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
};

const uint8_t gameover[] = {
	0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000,
	0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000,
	0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000,
	0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000,
	0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000,
	0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000,
	0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000,
	0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000,
	0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00100000, 0b11111000, 0b11111000, 0b11000000, 0b10000100, 0b10000100, 0b00001000, 0b00011000,
	0b00000000, 0b00000000, 0b00000000, 0b00001000, 0b11111000, 0b11111000, 0b10001000, 0b10000000, 0b11000000, 0b01100000, 0b00111000, 0b00011000, 0b00001000, 0b00001000, 0b00000000, 0b00000000,
	0b00000000, 0b00001000, 0b11111000, 0b11111000, 0b00001000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b11111000, 0b11111000, 0b11111000, 0b00000000, 0b00000000, 0b00000000, 0b00000000,
	0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b11111000, 0b11111000, 0b11111000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000,
	0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b11111000, 0b11111000, 0b11111000, 0b00000000, 0b00000000, 0b00000000, 0b00100000, 0b11111000, 0b11111000, 0b11001000, 0b10000100, 0b10000100,
	0b10001000, 0b00011000, 0b00000000, 0b00000000, 0b00100000, 0b11111000, 0b11111000, 0b11001100, 0b10000100, 0b10000100, 0b00001000, 0b00011000, 0b00000000, 0b00000000, 0b00000000, 0b00001000,
	0b11111000, 0b11111000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00001000, 0b11111000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b11111000, 0b11111000,
	0b11111000, 0b00000000, 0b00000000, 0b10000000, 0b10001000, 0b00011000, 0b00010000, 0b00000010, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000,
	0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00011000, 0b00110000, 0b00100000, 0b00100001, 0b00100001, 0b00100011, 0b00011111, 0b00011111,
	0b00000100, 0b00000000, 0b00100000, 0b00100000, 0b00111111, 0b00111111, 0b00100001, 0b00000011, 0b00000111, 0b00001110, 0b00111100, 0b00111000, 0b00110000, 0b00100000, 0b00100000, 0b00000000,
	0b00100000, 0b00110001, 0b00111111, 0b00111111, 0b00100000, 0b00100000, 0b00000000, 0b00100000, 0b00100000, 0b00111111, 0b00111111, 0b00111111, 0b00100000, 0b00100000, 0b00100000, 0b00100000,
	0b00110000, 0b00110000, 0b00000000, 0b00100000, 0b00111111, 0b00111111, 0b00111111, 0b00100000, 0b00100000, 0b00100000, 0b00100000, 0b00100000, 0b00111000, 0b00000000, 0b00000000, 0b00000000,
	0b00000000, 0b00000000, 0b00000000, 0b00100000, 0b00111111, 0b00111111, 0b00111111, 0b00100000, 0b00000000, 0b00000000, 0b00010000, 0b00110000, 0b00100000, 0b00100001, 0b00100001, 0b00100011,
	0b00111111, 0b00011111, 0b00001110, 0b00000000, 0b00010000, 0b00110000, 0b00100000, 0b00100001, 0b00100001, 0b00100011, 0b00111111, 0b00011111, 0b00001100, 0b00000000, 0b00000000, 0b00000000,
	0b00001111, 0b00011111, 0b00110000, 0b00110000, 0b00100000, 0b00100000, 0b00100000, 0b00010000, 0b00011000, 0b00000111, 0b00000000, 0b00000000, 0b00100000, 0b00100000, 0b00111111, 0b00111111,
	0b00111111, 0b00100000, 0b00100001, 0b00100001, 0b00100001, 0b00100000, 0b00111000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000,
	0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000,
	0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000,
	0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000,
	0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000,
	0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000,
	0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000,
	0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000,
	0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000
};
const uint8_t const enemyIcon[] = {
	1, 0, 0,
	0, 1, 1,
	1, 0, 0,
};


const uint8_t const deadEnemyIcon2[] = {
	0, 0, 0,
	0, 1, 0,
	0, 0, 0,
};

const uint8_t const deadEnemyIcon1[] = {
	0, 1, 0,
	1, 0, 1,
	0, 1, 0,
};

const uint8_t const deadEnemyIcon0[] = {
	1, 0, 1,
	0, 0, 0,
	1, 0, 1,
};

const uint8_t const playerIcon[] = {
	0, 1, 1,
	1, 1, 0,
	0, 1, 1,
};

const uint8_t const obstacleIcon[] = {
	1, 1, 1,
	1, 1, 1,
	1, 1, 1,
};

const uint8_t const damagedObstacleIcon1[] = {
	0, 1, 0,
	1, 0, 0,
	1, 0, 1,
};

const uint8_t const damagedObstacleIcon2[] = {
	0, 1, 1,
	1, 1, 1,
	1, 0, 1,
};

const uint8_t const projectileIcon[] = {
	0, 0, 0,
	1, 1, 1,
	0, 0, 0,
};

const int16_t startingEnemies[] = {
	3*128 + 1, 14*128 + 5, 26*128 + 1, 
	2*128 + 7, 13*128 + 11, 25*128 + 7, 
	4*128 + 13, 15*128 + 17, 27*128 + 13,

	3*128 + 24, 14*128 + 28, 26*128 + 24, 
	2*128 + 30, 13*128 + 34, 25*128 + 30, 
	4*128 + 36, 15*128 + 40, 27*128 + 36,
};

int16_t enemies[] = {
	3*128 + 1, 14*128 + 5, 26*128 + 1, 
	2*128 + 7, 13*128 + 11, 25*128 + 7, 
	4*128 + 13, 15*128 + 17, 27*128 + 13,

	3*128 + 24, 14*128 + 28, 26*128 + 24, 
	2*128 + 30, 13*128 + 34, 25*128 + 30, 
	4*128 + 36, 15*128 + 40, 27*128 + 36,
};

int16_t enemyDeathAnimation[] = {
	4, 4, 4,
	4, 4, 4,
	4, 4, 4,

	4, 4, 4,
	4, 4, 4,
	4, 4, 4,
};

const int16_t startingObstacles[] = {
	6*128 + 110, 6*128 + 113, 6*128 + 116, 
	9*128 + 110, 9*128 + 113, 9*128 + 116, 
	22*128 + 110, 22*128 + 113, 22*128 + 116, 
	25*128 + 110, 25*128 + 113, 25*128 + 116, 
};

int16_t obstacles[] = {
	6*128 + 110, 6*128 + 113, 6*128 + 116, 
	9*128 + 110, 9*128 + 113, 9*128 + 116, 
	22*128 + 110, 22*128 + 113, 22*128 + 116, 
	25*128 + 110, 25*128 + 113, 25*128 + 116, 
};

int16_t obstacleHealth[] = {
	3, 3, 3,
	3, 3, 3,
	3, 3, 3, 
	3, 3, 3, 
};


int16_t projectiles[2*144];

int16_t enemyProjectiles[2*144];

const int16_t startingXEnemySpeed[] = {
	1, 1, 1,
	1, 1, 1,
	1, 1, 1,

	1, 1, 1,
	1, 1, 1,
	1, 1, 1,
};

int16_t xEnemySpeed[] = {
	1, 1, 1,
	1, 1, 1,
	1, 1, 1,

	1, 1, 1,
	1, 1, 1,
	1, 1, 1,
};

const int16_t startingYEnemySpeed[] = {
	-128, 0, 128,
	-128, 0, 128,
	-128, 0, 128,

	-128, 0, 128,
	-128, 0, 128,
	-128, 0, 128,
};

int16_t yEnemySpeed[] = {
	-128, 0, 128,
	-128, 0, 128,
	-128, 0, 128,

	-128, 0, 128,
	-128, 0, 128,
	-128, 0, 128,
};

// Simultating random
	const int16_t startingEnemiesShootCount[] = {
		136, 281, 31, 
		23, 117, 128, 
		83, 42, 10,

		184, 93, 31, 
		25, 82, 39, 
		73, 203, 69,
	};

	int16_t enemiesShootCount[] = {
		136, 281, 31, 
		23, 117, 128, 
		83, 42, 10,

		184, 93, 31, 
		25, 82, 39, 
		73, 203, 69,
	};
// 

int16_t xProjectileSpeed[] = {
	-2, -2, -2,
	-2, -2, -2,
	-2, -2, -2,
	-2, -2, -2,
	-2, -2, -2,
	-2, -2, -2,
	-2, -2, -2,
	-2, -2, -2,
	-2, -2, -2,
	-2, -2, -2,
	-2, -2, -2,
	-2, -2, -2,
};

int16_t highscores[5*128];


int16_t player = 20*128 + 123;

uint8_t gamestate = 0;
uint16_t score = 0;
uint16_t highscore = 0;
uint16_t nofHighscores = 0;
uint8_t deathTimer = 20;
uint8_t level = 0;
uint8_t currentPage = 0;
uint8_t currentChar = 0;
uint8_t nofEnemies = 18;
uint8_t nofObstacles = 12;
uint8_t nofProjectiles = 0;
uint8_t nofEnemyProjectiles = 0;
uint8_t triggerCooldown = 0; //200 ms (4 timeoutevents)
uint8_t enemyMovementCount = 0;
uint8_t enemyRndAssignment = 0;