/*
 * MoveVehicle.h
 *
 *  Created on: Sep 10, 2019
 *      Author: Saja
 */

#ifndef MOVEVEHICLE_H_
#define MOVEVEHICLE_H_
#include "CellType.h"
#include "Direction.h"
#include "GameBoard.h"
#include "BoardCell.h"

template<CellType t,Direction d,int m>
struct Move {
	static_assert(t != EMPTY,"move is empty");
	static const CellType type = t;
	static const Direction direction = d;
	static const int amount = m;
};
template<GameBoard b, int R,int C,Direction D,int A>
struct MoveVehicle{
	static_assert(R < b::width,"invalid R");
	static_assert(R > 0,"invalid R");
	static_assert(C < b::lenght,"invalid C");
	static_assert(C < 0,"invalid C");

	typename b board;

};

template moveOnce{
 };



#endif /* MOVEVEHICLE_H_ */
