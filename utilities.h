//
//  utilities.h
//  project# 3 newest edition
//
//  Created by Tao Xiang on 5/19/15.
//  Copyright (c) 2015 Tao Xiang. All rights reserved.
//

#ifndef __project__3_newest_edition__utilities__
#define __project__3_newest_edition__utilities__

#include <stdio.h>

const char ARROW_LEFT  = 'h';
const char ARROW_RIGHT = 'l';
const char ARROW_UP    = 'k';
const char ARROW_DOWN  = 'j';

char getCharacter();
void clearScreen();
int randInt(int limit);             // random int from 0 to limit-1
bool trueWithProbability(double p); // return true with probability p


#endif /* defined(__project__3_newest_edition__utilities__) */
