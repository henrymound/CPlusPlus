#ifndef __board_h_
#define __board_h_
//#define LEVELS 3
#include"object.h"
#include"gboard.h"

class Board;

#include"pac.h"
#include"types.h"
#include"element.h"
#include"blank.h"
#include"walls.h"
#include"specwall.h"
#include"food.h"
#include"supefood.h"
#include"sizes.h"
#include"usrinter.h"

#include"dynamiel.h"

static int foods=168;	//how many food items there are on each board

#define initen {0}

static char boards[LEVELS][BOARDHEIGHT+1][BOARDWIDTH+1]= {
    {   {"OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO"},
        {"Oo . . .O. . . . . . . .O. . . oO"},
        {"O OOOOO O OOOOOOOOOOOOO O OOOOO O"},
        {"O.O. . . . . . . . . . . . . .O.O"},
        {"O O O O OOO OOOOOOOOO OOO O O O O"},
        {"O. .O.O. . . . . . . . . .O.O. .O"},
        {"OOO O O OOOOO OOOOO OOOOO O O OOO"},
        {"O. .O. . . .O. . . .O. . . .O. .O"},
        {"O O O OOOOO O O___O O OOOOO O O O"},
        {"O.O. . . .O.O.O   O.O.O. . . .O.O"},
        {"O O OOOOO O O O   O O O OOOOO O O"},
        {"O.O. . . .O.O.O   O.O.O. . . .O.O"},
        {"O OOO O O O O OOOOO O O O O OOO O"},
        {"O. . .O.O. . . . . . . .O.O. . .O"},
        {"O OOOOO O O OOOOOOOOO O O OOOOO O"},
        {"O. . . . .O. . . . . .O. . . . .O"},
        {"O OOOOOOO O OOOOOOOOO O OOOOOOO O"},
        {"O. .O. . . . . . . . . . . .O. .O"},
        {"OOO O OOO O OOOOOOOOO O OOO O OOO"},
        {"O. .O. . .O. . . . . .O. . .O. .O"},
        {"O OOOOOOO O OOOOOOOOO O OOOOOOO O"},
        {"Oo . . . .O. . . . . .O. . . . oO"},
        {"OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO"}
    },
    {   {"OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO"},
        {"Oo . . .O. . . . . . . .O. . . oO"},
        {"O OOOOO O O OOOOOOOOO O O OOOOO O"},
        {"O.O. .O. .O. . . . . .O. .O. .O.O"},
        {"O O O O OOO OOO O OOO OOO O O O O"},
        {"O. .O.O. . . . .O. . . . .O.O. .O"},
        {"OOO O O O OOO OOOOO OOO O O O OOO"},
        {"O. .O. .O. .O. . . .O. .O. .O. .O"},
        {"O OOOOO O O O O___O O O O OOOOO O"},
        {"O.O. . . .O.O.O   O.O.O. . . .O.O"},
        {"O O OOOOO O O O   O O O OOOOO O O"},
        {"O.O. . . .O.O.O   O.O.O. . . .O.O"},
        {"O OOO O O O O OOOOO O O O O OOO O"},
        {"O. . .O.O. . . . . . . .O.O. . .O"},
        {"OOOOOOO O O OOOOOOOOO O O OOOOOOO"},
        {"O. . . . .O. . . . . .O. . . . .O"},
        {"O OOOOOOO O OOOOOOOOO O OOOOOOO O"},
        {"O. .O. . . . . . . . . . . .O. .O"},
        {"OOO O OOO O OOOOOOOOO O OOO O OOO"},
        {"O. .O. . .O. . . . . .O. . .O. .O"},
        {"O OOOOOOO O OOOOOOOOO O OOOOOOO O"},
        {"Oo . . . .O. . . . . .O. . . . oO"},
        {"OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO"}
    },
    {   {"OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO"},
        {"Oo . . .O. . . . . . . .O. . . oO"},
        {"O OOOOO O OOOOO O OOOOO O OOOOO O"},
        {"O.O. .O. . . . .O. . . . .O. .O.O"},
        {"O O O OOOOOOO O O O OOOOOOO O O O"},
        {"O. .O.O. . . .O. .O. . . .O.O. .O"},
        {"OOO O O O OOO OOOOO OOO O O O OOO"},
        {"O. .O. .O. . . . . . . .O. .O. .O"},
        {"O O OOO OOO O O___O O OOO OOO O O"},
        {"O.O. . . .O.O.O   O.O.O. . . .O.O"},
        {"O O OOOOO O O O   O O O OOOOO O O"},
        {"O.O. . . .O.O.O   O.O.O. . . .O.O"},
        {"O OOO O O O O OOOOO O O O O OOO O"},
        {"O. . .O.O. . . . . . . .O.O. . .O"},
        {"O OOOOO O O OOOOOOOOO O O OOOOO O"},
        {"O. . . . .O. . . . . .O. . . . .O"},
        {"O OOOOOOO O OOOOOOOOO O OOOOOOO O"},
        {"O. .O. . .O. . . . . .O. . .O. .O"},
        {"OOO O OOO O OOOOOOOOO O OOO O OOO"},
        {"O. .O. . .O. . . . . .O. . .O. .O"},
        {"O OOOOOOO O OOOOOOOOO O OOOOOOO O"},
        {"Oo . . . .O. . . . . .O. . . . oO"},
        {"OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO"}
    },
    {   {"OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO"},
        {"Oo . . .O. . . . . . . .O. . . oO"},
        {"O OOOOO O O OOOOOOOOO O O OOOOO O"},
        {"O.O. .O. .O. . .O. . .O. .O. .O.O"},
        {"O O O O OOOOO O O O OOOOO O O O O"},
        {"O. .O.O. . . .O. .O. . . .O.O. .O"},
        {"OOO O O OOOOO OOOOO OOOOO O O OOO"},
        {"O. .O. . . .O. . . .O. . . .O. .O"},
        {"O OOO OOOOO O O___O O OOOOO OOO O"},
        {"O.O. . . .O.O.O   O.O.O. . . .O.O"},
        {"O O OOOOO O O O   O O O OOOOO O O"},
        {"O.O.O. . .O.O.O   O.O.O. . .O.O.O"},
        {"O O O O O O O OOOOO O O O O O O O"},
        {"O.O. .O.O. . . . . . . .O.O. .O.O"},
        {"O OOOOO O O OOOOOOOOO O O OOOOO O"},
        {"O. . . . .O. . . . . .O. . . . .O"},
        {"O OOOOOOO O OOOOOOOOO O OOOOOOO O"},
        {"O. .O. . . . . . . . . . . .O. .O"},
        {"OOO O OOOOO OOOOOOOOO OOOOO O OOO"},
        {"O. .O. . .O. . . . . .O. . .O. .O"},
        {"O OOOOOOO O OOOOOOOOO O OOOOOOO O"},
        {"Oo . . . .O. . . . . .O. . . . oO"},
        {"OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO"}
    },
    {   {"OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO"},
        {"Oo . . .O. . . .O. . . .O. . . oO"},
        {"O OOOOO O O OOO O OOO O O OOOOO O"},
        {"O.O. .O. .O. . .O. . .O. .O. .O.O"},
        {"O O O OOOOOOO O O O OOOOOOO O O O"},
        {"O. .O. . . . .O. .O. . . . .O. .O"},
        {"OOO O O OOOOO OOOOO OOOOO O O OOO"},
        {"O. .O.O. . .O. . . .O. . .O.O. .O"},
        {"O OOO OOOOO O O___O O OOOOO OOO O"},
        {"O. . . . .O.O.O   O.O.O. . . . .O"},
        {"O OOOOOOO O O O   O O O OOOOOOO O"},
        {"O. .O. . .O.O.O   O.O.O. . .O. .O"},
        {"O O O O O O O OOOOO O O O O O O O"},
        {"O.O. .O.O. . . .O. . . .O.O. .O.O"},
        {"O OOOOO O O OOO O OOO O O OOOOO O"},
        {"O. . . . .O.O. . . .O.O. . . . .O"},
        {"O OOOOOOO O O OOOOO O O OOOOOOO O"},
        {"O. .O. . . .O. . . .O. . . .O. .O"},
        {"OOO O OOOOOOO OOOOO OOOOOOO O OOO"},
        {"O. .O. . . .O. .O. .O. . . .O. .O"},
        {"O OOOOOOO O OOO O OOO O OOOOOOO O"},
        {"Oo . . . .O. . .O. . .O. . . . oO"},
        {"OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO"}
    },
    {   {"OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO"},
        {"Oo . . .O. . . . . . . .O. . . oO"},
        {"O OOOOO O O O OOOOO O O O OOOOO O"},
        {"O.O. .O. .O.O. .O. .O.O. .O. .O.O"},
        {"O O O OOOOO O O O O O OOOOO O O O"},
        {"O. .O.O. . . .O.O.O. . . .O.O. .O"},
        {"OOO O O OOOOO O O O OOOOO O O OOO"},
        {"O. .O.O. . . .O. .O. . . .O.O. .O"},
        {"O OOO O OOO O O___O O OOO O OOO O"},
        {"O. . . . .O.O.O   O.O.O. . . . .O"},
        {"O OOOOOOO O O O   O O O OOOOOOO O"},
        {"O. .O. . .O.O.O   O.O.O. . .O. .O"},
        {"O O O O O O O OOOOO O O O O O O O"},
        {"O.O. .O.O. .O. .O. .O. .O.O. .O.O"},
        {"O OOOOO OOO OOO O OOO OOO OOOOO O"},
        {"O.O. . . .O. . . . . .O. . . .O.O"},
        {"O O OOOOO O O OOOOO O O OOOOO O O"},
        {"O. . . . . .O. . . .O. . . . . .O"},
        {"OOOOOOO O OOO OOOOO OOO O OOOOOOO"},
        {"O. . . .O. . . .O. . . .O. . . .O"},
        {"O OOOOO O OOOOO O OOOOO O OOOOO O"},
        {"Oo . . .O. . . .O. . . .O. . . oO"},
        {"OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO"}
    },
    {   {"OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO"},
        {"Oo . . .O. . . . . . . .O. . . oO"},
        {"O OOOOO O OOOOOOOOOOOOO O OOOOO O"},
        {"O.O. .O. .O. . .O. . .O. .O. .O.O"},
        {"O O O OOOOO O O O O O OOOOO O O O"},
        {"O. .O.O. . .O.O. .O.O. . .O.O. .O"},
        {"OOOOO O OOOOO OOOOO OOOOO O OOOOO"},
        {"O. . .O. . .O. . . .O. . .O. . .O"},
        {"O OOO O OOO O O___O O OOO O OOO O"},
        {"O. . . . .O.O.O   O.O.O. . . . .O"},
        {"OOOOOOOOO O O O   O O O OOOOOOOOO"},
        {"O. . . .O.O.O.O   O.O.O.O. . . .O"},
        {"O O OOO O O O OOOOO O O O OOO O O"},
        {"O.O. .O. . .O. .O. .O. . .O. .O.O"},
        {"O OOO OOOOO OOO O OOO OOOOO OOO O"},
        {"O.O. . . .O. . . . . .O. . . .O.O"},
        {"O O OOOOO O O OOOOO O O OOOOO O O"},
        {"O. .O. . . .O. . . .O. . . .O. .O"},
        {"OOOOO O O OOO OOOOO OOO O O OOOOO"},
        {"O. . .O.O. . . .O. . . .O.O. . .O"},
        {"O OOOOO O OOOOO O OOOOO O OOOOO O"},
        {"Oo . . .O. . . .O. . . .O. . . oO"},
        {"OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO"}
    },
    {   {"OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO"},
        {"Oo . . .O. . . .O. . . .O. . . oO"},
        {"O OOOOO O O OOO O OOO O O OOOOO O"},
        {"O.O. .O. .O. . .O. . .O. .O. .O.O"},
        {"O O O OOOOO O O O O O OOOOO O O O"},
        {"O. .O.O. . .O.O. .O.O. . .O.O. .O"},
        {"OOOOO O OOOOO OOOOO OOOOO O OOOOO"},
        {"O. . .O. . .O. . . .O. . .O. . .O"},
        {"O OOO O OOO O O___O O OOO O OOO O"},
        {"O. . . . .O.O.O   O.O.O. . . . .O"},
        {"OOOOOOOOO O O O   O O O OOOOOOOOO"},
        {"O. . . .O.O.O.O   O.O.O.O. . . .O"},
        {"O O OOO O O O OOOOO O O O OOO O O"},
        {"O.O. .O. . .O. .O. .O. . .O. .O.O"},
        {"O OOO OOOOO OOO O OOO OOOOO OOO O"},
        {"O.O. . . .O. . . . . .O. . . .O.O"},
        {"O O OOOOO O O OOOOO O O OOOOO O O"},
        {"O. .O. . . .O. . . .O. . . .O. .O"},
        {"OOOOO O O OOO OOOOO OOO O O OOOOO"},
        {"O. . .O.O. . . .O. . . .O.O. . .O"},
        {"O OOOOO O OOOOO O OOOOO O OOOOO O"},
        {"Oo . . .O. . . .O. . . .O. . . oO"},
        {"OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO"}
    },
    {   {"OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO"},
        {"Oo . . . . . . . . . . . . . . oO"},
        {"O O OOOOOOOOOOOOOOOOOOOOOOOOO O O"},
        {"O.O. .O. . . . .O. . . . .O. .O.O"},
        {"O O O O OOO O O O O O OOO O O O O"},
        {"O. .O.O. . .O.O. .O.O. . .O.O. .O"},
        {"OOO O O OOOOO OOOOO OOOOO O O OOO"},
        {"O. .O.O. . .O. . . .O. . .O.O. .O"},
        {"O OOO O OOO O O___O O OOO O OOO O"},
        {"O. . .O. .O.O.O   O.O.O. .O. . .O"},
        {"O OOO OOO O O O   O O O OOO OOO O"},
        {"O. .O. .O.O.O.O   O.O.O.O. .O. .O"},
        {"O O OOO O O O OOOOO O O O OOO O O"},
        {"O.O. .O. . .O. .O. .O. . .O. .O.O"},
        {"O OOO OOOOO OOO O OOO OOOOO OOO O"},
        {"O. . . . .O. . . . . .O. . . . .O"},
        {"O OOOOOOO O OOOOOOOOO O OOOOOOO O"},
        {"O. .O. . .O. . . . . .O. . .O. .O"},
        {"OOO O O O O OOOOOOOOO O O O O OOO"},
        {"O. . .O.O.O. .O. .O. .O.O.O. . .O"},
        {"O OOOOO O O O O O O O O O OOOOO O"},
        {"Oo . . .O. .O. .O. .O. .O. . . oO"},
        {"OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO"}
    },
    {   {"OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO"},
        {"Oo . . . .O. . . . . .O. . . . oO"},
        {"O OOOOO O O O O O O O O O OOOOO O"},
        {"O.O. .O.O. .O.O.O.O.O. .O.O. .O.O"},
        {"O O O O OOO O O O O O OOO O O O O"},
        {"O. .O.O. . .O.O. .O.O. . .O.O. .O"},
        {"OOO O O OOOOO OOOOO OOOOO O O OOO"},
        {"O. .O.O. . .O. . . .O. . .O.O. .O"},
        {"O OOO O OOO O O___O O OOO O OOO O"},
        {"O. . .O. .O.O.O   O.O.O. .O. . .O"},
        {"OOOOO OOO O O O   O O O OOO OOOOO"},
        {"O. .O. .O.O.O.O   O.O.O.O. .O. .O"},
        {"O O OOO O O O OOOOO O O O OOO O O"},
        {"O.O. .O.O. .O. .O. .O. . .O. .O.O"},
        {"O OOO O OOO OOO O OOO OOO O OOO O"},
        {"O.O. .O. .O. . . . . .O. .O. .O.O"},
        {"O O OOOOO O OOOOOOOOO O OOOOO O O"},
        {"O.O.O. . . . . . . . . . . .O.O.O"},
        {"O O O O O OOOOOOOOOOOOO O O O O O"},
        {"O.O. .O.O.O. .O. .O. .O.O.O. .O.O"},
        {"O OOOOO O O O O O O O O O OOOOO O"},
        {"Oo . . .O. .O. .O. .O. .O. . . oO"},
        {"OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO"}
    },
    {   {"OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO"},
        {"Oo . . . .O. . .O. . .O. . . . oO"},
        {"O OOOOO O O O O O O O O O OOOOO O"},
        {"O.O. . .O. .O.O.O.O.O. .O. . .O.O"},
        {"O O O OOOOOOO O O O OOOOOOO O O O"},
        {"O. .O.O. . . .O. .O. . . .O.O. .O"},
        {"OOO O O OOOOO OOOOO OOOOO O O OOO"},
        {"O. .O.O. . .O. . . .O. . .O.O. .O"},
        {"O OOO O OOO O O___O O OOO O OOO O"},
        {"O. . .O. .O.O.O   O.O.O. .O. . .O"},
        {"OOOOO OOO O O O   O O O OOO OOOOO"},
        {"O. .O. .O.O.O.O   O.O.O.O. .O. .O"},
        {"O O OOO O O O OOOOO O O O OOO O O"},
        {"O.O. .O.O.O. . . . . .O.O.O. .O.O"},
        {"O OOO O O O OOOOOOOOO O O O OOO O"},
        {"O.O. . .O.O. . . . . .O.O. . .O.O"},
        {"O O OOOOO O OOOOOOOOO O OOOOO O O"},
        {"O.O.O. . .O. . . . . .O. . .O.O.O"},
        {"O O O O O OOOOOOOOOOOOO O O O O O"},
        {"O.O. .O.O.O. .O. .O. .O.O.O. .O.O"},
        {"O OOOOO O O O O O O O O O OOOOO O"},
        {"Oo . . .O. .O. .O. .O. .O. . . oO"},
        {"OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO"}
    },
    {   {"OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO"},
        {"Oo . . . .O. . .O. . .O. . . . oO"},
        {"O OOOOO O O O O O O O O O OOOOO O"},
        {"O.O. . .O. .O.O.O.O.O. .O. . .O.O"},
        {"O O O OOOOOOO O O O OOOOOOO O O O"},
        {"O. .O.O. . . .O. .O. . . .O.O. .O"},
        {"OOOOO O OOOOO OOOOO OOOOO O OOOOO"},
        {"O. . .O. . .O. . . .O. . .O. . .O"},
        {"O OOO O OOO O O___O O OOO O OOO O"},
        {"O. . .O. .O.O.O   O.O.O. .O. . .O"},
        {"OOOOO OOO O O O   O O O OOO OOOOO"},
        {"O. .O. . .O.O.O   O.O.O. . .O. .O"},
        {"O O OOOOO O O OOOOO O O OOOOO O O"},
        {"O.O. .O. .O. . . . . .O. .O. .O.O"},
        {"O OOO O OOO OOOOOOOOO OOO O OOO O"},
        {"O. . . . .O. . . . . .O. . . . .O"},
        {"O O OOOOO O OOOOOOOOO O OOOOO O O"},
        {"O.O.O. . .O. . . . . .O. . .O.O.O"},
        {"O O O O O OOOOOOOOOOOOO O O O O O"},
        {"O.O. .O.O.O. .O. .O. .O.O.O. .O.O"},
        {"O OOOOO O O O O O O O O O OOOOO O"},
        {"Oo . . .O. .O. .O. .O. .O. . . oO"},
        {"OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO"}
    },
    {   {"OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO"},
        {"Oo . . . . .O. .O. .O. . . . . oO"},
        {"O OOOOOOOOO O O O O O OOOOOOOOO O"},
        {"O.O. .O. . . .O.O.O. . . .O. .O.O"},
        {"O O O O O O OOO O OOO O O O O O O"},
        {"O. .O. .O.O. . .O. . .O.O. .O. .O"},
        {"OOOOOOO O O O OOOOO O O O OOOOOOO"},
        {"O. . .O. .O.O. . . .O.O. .O. . .O"},
        {"O OOO OOO O O O___O O O OOO OOO O"},
        {"O. . .O. .O.O.O   O.O.O. .O. . .O"},
        {"OOOOO O O O O O   O O O O O OOOOO"},
        {"O. .O. .O.O.O.O   O.O.O.O. .O. .O"},
        {"O O OOOOO O O OOOOO O O OOOOO O O"},
        {"O.O. .O. .O.O. . . .O.O. .O. .O.O"},
        {"O OOO O OOO OOOOOOOOO OOO O OOO O"},
        {"O.O. .O. .O. . . . . .O. .O. .O.O"},
        {"O O OOO O O OOOOOOOOO O O OOO O O"},
        {"O.O.O. .O.O. . . . . .O.O. .O.O.O"},
        {"O O O O O OOOOOOOOOOOOO O O O O O"},
        {"O.O. .O.O.O. .O. .O. .O.O.O. .O.O"},
        {"O OOOOO O O O O O O O O O OOOOO O"},
        {"Oo . . .O. .O. .O. .O. .O. . . oO"},
        {"OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO"}
    },
    {   {"OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO"},
        {"Oo . . . . .O. .O. .O. . . . . oO"},
        {"O OOOOOOOOO O O O O O OOOOOOOOO O"},
        {"O.O. .O. . . .O.O.O. . . .O. .O.O"},
        {"O O O O OOOOOOO O OOOOOOO O O O O"},
        {"O. .O.O. . . .O. .O. . . .O.O. .O"},
        {"OOOOO O OOO O OOOOO O OOO O OOOOO"},
        {"O. . .O. .O.O. . . .O.O. .O. . .O"},
        {"O OOOOOOO O O O___O O O OOOOOOO O"},
        {"O. . .O. . .O.O   O.O. . .O. . .O"},
        {"OOOOO O OOOOO O   O OOOOO O OOOOO"},
        {"O. .O. . . .O.O   O.O. . . .O. .O"},
        {"O O O OOO O O OOOOO O O OOO O O O"},
        {"O.O. . . .O.O. . . .O.O. . . .O.O"},
        {"O OOOOO OOO OOOOOOOOO OOO OOOOO O"},
        {"O.O. .O. . . . . . . . . .O. .O.O"},
        {"O O O OOOOO OOOOOOOOO OOOOO O O O"},
        {"O.O.O. . .O. . . . . .O. . .O.O.O"},
        {"O O O OOO OOOOOOOOOOOOO OOO O O O"},
        {"O.O. . .O. . . . . . . .O. . .O.O"},
        {"O OOO O OOOOOOOOOOOOOOOOO O OOO O"},
        {"Oo . .O. . . . . . . . . .O. . oO"},
        {"OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO"}
    },
    {   {"OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO"},
        {"Oo . . . . .O. .O. .O. . . . . oO"},
        {"O OOOOOOOOO O O O O O OOOOOOOOO O"},
        {"O.O. .O. . . .O.O.O. . . .O. .O.O"},
        {"O O O O O O OOO O OOO O O O O O O"},
        {"O. .O. .O.O. . .O. . .O.O. .O. .O"},
        {"OOOOOOO O O O OOOOO O O O OOOOOOO"},
        {"O. . . . .O.O. . . .O.O. . . . .O"},
        {"O OOO OOO O O O___O O O OOO OOO O"},
        {"O. . .O. .O.O.O   O.O.O. .O. . .O"},
        {"OOOOOOO OOO O O   O O OOO OOOOOOO"},
        {"O. . .O. .O.O.O   O.O.O. .O. . .O"},
        {"O O O OOO O O OOOOO O O OOO O O O"},
        {"O.O.O.O. .O.O. . . .O.O. .O.O.O.O"},
        {"O O O O OOO OOOOOOOOO OOO O O O O"},
        {"O.O. .O. .O. . . . . .O. .O. .O.O"},
        {"O O OOOOO O OOOOOOOOO O OOOOO O O"},
        {"O.O.O. . .O. . . . . .O. . .O.O.O"},
        {"O O O OOO O OOOOOOOOO O OOO O O O"},
        {"O.O. . . .O. . . . . .O. . . .O.O"},
        {"O OOO O OOOOOOOOOOOOOOOOO O OOO O"},
        {"Oo . .O. . . . . . . . . .O. . oO"},
        {"OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO"}
    },
    {   {"OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO"},
        {"Oo . . . . .O. .O. .O. . . . . oO"},
        {"O OOOOOOOOO O O O O O OOOOOOOOO O"},
        {"O.O. . . . . .O.O.O. . . . . .O.O"},
        {"O O OOOOOOOOOOO O OOOOOOOOOOO O O"},
        {"O. . .O. . . .O. .O. . . .O. . .O"},
        {"OOOOO O OOOOO OOOOO OOOOO O OOOOO"},
        {"O. .O. . .O. . . . . .O. . .O. .O"},
        {"O O O OOO O O O___O O O OOO O O O"},
        {"O.O. .O. .O.O.O   O.O.O. .O. .O.O"},
        {"O OOO O O O O O   O O O O O OOO O"},
        {"O. . . .O. .O.O   O.O. .O. . . .O"},
        {"OOOOO OOOOOOO OOOOO OOOOOOO OOOOO"},
        {"O. . .O. . .O. . . .O. . .O. . .O"},
        {"O OOO O OOO OOOOOOOOO OOO O OOO O"},
        {"O.O. .O. .O. . . . . .O. .O. .O.O"},
        {"O O OOOOO O OOOOOOOOO O OOOOO O O"},
        {"O.O.O. . .O. . . . . .O. . .O.O.O"},
        {"O O O O OOOOOOOOOOOOOOOOO O O O O"},
        {"O.O. .O. . . . . . . . . .O. .O.O"},
        {"O OOOOO O OOOOOOOOOOOOO O OOOOO O"},
        {"Oo . . .O. . . . . . . .O. . . oO"},
        {"OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO"}
    }
};

class DynamicElement;
class G_Board;

//the following is the list structure for the DynamicElements, the sprites.
//it includes a pointer to the element, what graphical id it has
//the coordinates and a pointer to the next element of the structure

struct liststruct {
    DynamicElement/* Moveables*/ *g;
    GID_TYPE gid;
    int x,y;
    struct liststruct*next;
};

class Board : public Object
{

    static liststruct* list;	//pointer to list of recently display sprites
    static liststruct* oldlist;	//pointer to list of next most recently

    static Element *board[BOARDWIDTH][BOARDHEIGHT];	//matrix pointer to elements

    static G_Board* gboard;		//pointer to the class which handles
    //the graphical elements of the board

    static void replace(Element*);	//?????????

    static UserInterface* u;	//pointer to the user interface
    static Board* _instance;	//pointer to the instance of the board

protected:

    Board();	//constructor

public:

    static Board* instance();	//returns the pointer to the instance
    ~Board();			//destructor
    static void start(int);	//initialize board for a given level
    static void draw(void);	//draw entire board
    static void delta_draw(void);	//draw changes of the board
    static void sprite(DynamicElement *);	//let dynamicelement be a sprite
    static void eat(int,int);	//removes whats at coordinates
    static typ what_is(int,int); 	//what "class" element at coordinates is
};

#endif






