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
	typedef GetAtIndex<R,b>::value row;
	typedef GetAtIndex<C,row>::value car;
	static_assert(car::type != EMPTY,"the car posiition is emPtY");
	typedef typename DoTheMove<row,car,A>::moved newRow;

	typename setAtIndex<R,newRow,b> board;

};

template<List row,BoardCell cell,int amount>
struct moveSeveral{
	typedef moveOnce<row,cell>::list newRow;
	typedef List<newResult::head,moveSeveral<newRow::tail,cell,mount-1>::result> result;
};

template<List row,BoardCell cell>
struct moveSeveral<row,cell,0>{
	typedef row result;
};

template<List row,BoardCell cell,int A>
struct DoTheMove{
	typedef typename List<row::head,DoTheMove<row::tail,cell,A>::moved> moved;
};
template<CellType t,Direction dir,int len,typename...TT,int A>
struct DoTheMove<List<BoardCell<t,dir,len>,TT...>,BoardCell<t,dir,len>,A>{
	typedef typename moveSeveral<List<BoardCell<t,dir,len>,TT...>,BoardCell<t,dir,len>,A> moved;
};

template<List row,BoardCell cell>
struct moveOnce{
 };

template<List row,BoardCell cell,CellType t,Direction dir,int len>
struct moveOnce<row,BoardCell<t,dir,len>>{
	static_assert(row::head::type == EMPTY,"cant move car1");
	typedef SetAtIndex<0,BoardCell<t,dir,len>,row> list;
 };

template<CellType t,Direction dir,int len,typename...TT>
struct moveOnce<List<BoardCell<t,dir,len>,TT...>,BoardCell<t,dir,len>>{
	typedef moveOnce<List<TT...>,BoardCell<t,dir,len>>::list moved;
	typedef List<BoardCell<EMPTY,dir,len>,setAtIndex<0,BoardCell<t,dir,len>,moved>::list> list;
 };



#endif /* MOVEVEHICLE_H_ */
