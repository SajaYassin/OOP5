/*
 * GameBoard.h
 *
 *  Created on: Sep 10, 2019
 *      Author: Saja
 */

#ifndef GAMEBOARD_H_
#define GAMEBOARD_H_
template <List list>
struct GameBoard{
	static const List board = list;
	static const int width = list::head::size;
	static const int lenght = list::size;
};



#endif /* GAMEBOARD_H_ */
