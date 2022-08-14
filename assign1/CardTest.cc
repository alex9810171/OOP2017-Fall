/* Copyright (c) 1999 by The National Chengchi Univ. All Rights Reserved */

/***************************************************************************
  NAME
  CardTest.cc
  PURPOSE
  Testing card displaying
  NOTES

  AUTHOR
  Tsai-Yen Li (li@cs.nccu.edu.tw)
  HISTORY
  Tsai-Yen Li - Oct 7, 1999: Created.
 ***************************************************************************/

/* $Log:$ */

extern "C" {
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <assert.h>
}

#include <iostream>
#include "AnsiPrint.h"
#include "Cards.h"

using namespace std;

/**
 * Print my id 
 */
void
PrintMyID(const char *studId) {

	char *str= new char[sizeof(studId)+5];
	// we put string in a buffer first 
	sprintf(str,"ID: %s",studId);
	// print the buffer out with color
	AnsiPrint(str,yellow,red, true, true);
	cout << endl << endl;
	delete [] str;

}


/**
 * PrintUsage
 */
void
PrintUsage(const char *progName) {

	assert(progName);
	cout << "Usage: " << progName << " NCards [Seed]" << endl;

}

/**
 * Main Function Call
 */
int
main(int argc, char **argv) {

	int ncards=0;  // number of cards to draw

	if (argc==3) {
		long seed=atoi(argv[2]); // the third argument is the seed
		srand(seed);
		ncards=atoi(argv[1]); // the second argument is the number of cards
	} else if (argc==2) {
		ncards=atoi(argv[1]);
	} else {
		PrintUsage(argv[0]);
		exit(-1);
	}

	// You are asked to fill in a few missing statements here
	int cards[kNCards], card; // 0.card  1.color  2.number
	int i, j;

	if(ncards > 0 && ncards <= kNCards){
		for(i = 0;i < ncards;i ++){
			card = rand() % kNCards;
			for(j = 0;j < i;j ++)
				if(card == cards[j]){
					card = rand() % kNCards;
					j = -1;
				}
			cards[i] = card;
		}
		PrintCard(ncards, cards);
		PrintMyID("105703047");
	}
	else cout << "Sorry, number of cards can not exceed " << kNCards << " or below 1." << endl;
	// Print my id at the end of the program

	return 0;

}