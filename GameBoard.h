/*
 * GameBoard.h
 *
 *  Created on: Sep 10, 2019
 *      Author: Saja
 */

#ifndef GAMEBOARD_H_
#define GAMEBOARD_H_
#include "List.h"
#include "BoardCell.h"

template<typename list>
struct GameBoard{
	typedef list board;
	static const int width = list::head::size;
	static const int lenght = list::size;
};




#endif /* GAMEBOARD_H_ */
