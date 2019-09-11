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
#include "List.h"
#include "TransposeList.h"
#include "Utilities.h"
#include "Direction.h"


template<typename row,typename cell,int A>
struct DoTheMove{
	typedef typename PrependList<typename row::head,typename DoTheMove<typename row::next,cell,A>::moved>::list moved;
};

template<CellType t,Direction d,int m>
struct Move {
	static_assert(t != EMPTY,"move is empty");
	static const CellType type = t;
	static const Direction direction = d;
	static const int amount = m;
};

template<typename b, int R,int C,Direction D,int A>
struct MoveVehicleHorizontal{
	static_assert(R < b::lenght,"invalid R");
	static_assert(R >= 0,"invalid R");
	static_assert(C < b::width,"invalid C");
	static_assert(C >= 0,"invalid C");
	typedef typename GetAtIndex<R,typename b::board>::value row;
	typedef typename Conditional<D == Direction::RIGHT, row, typename reverseList<row>::list>::value actualRowPre;
	static const int colNum = ConditionalInteger<D == Direction::RIGHT, C, b::width - C -1>::value;
	typedef typename GetAtIndex<colNum,actualRowPre>::value car;
	static_assert(car::type != EMPTY,"the car posiition is emPtY");
	typedef typename DoTheMove<actualRowPre,car,A>::moved newRow;
  typedef typename Conditional<D == Direction::RIGHT, newRow, typename reverseList<newRow>::list>::value actualRowPost;
  typedef GameBoard<typename SetAtIndex<R,actualRowPost,typename b::board>::list> board;

};
template<typename b, int R,int C,Direction D,int A>
struct MoveVehicle{
	static_assert(R < b::lenght,"invalid R");
	static_assert(R >= 0,"invalid R");
	static_assert(C < b::width,"invalid C");
	static_assert(C >= 0,"invalid C");
	typedef typename GetAtIndex<R,typename b::board>::value row;
	typedef typename GetAtIndex<C,row>::value car;
	static_assert(car::type != EMPTY,"the car posiition is emPtY");
	static_assert(car::direction == LEFT ||car::direction == RIGHT ,"the car DIR is wrong1");
	typedef typename MoveVehicleHorizontal<b,R,C,D,A>::board board;
};

template<typename b, int R,int C,int A>
struct MoveVehicle<b,R,C,UP,A>{
	static_assert(R < b::lenght,"invalid R");
	static_assert(R >= 0,"invalid R");
	static_assert(C < b::width,"invalid C");
	static_assert(C >= 0,"invalid C");
	typedef typename GetAtIndex<R,typename b::board>::value row;
	typedef typename GetAtIndex<C,row>::value car;
	static_assert(car::type != EMPTY,"the car posiition is emPtY");
	static_assert(car::direction == UP ||car::direction == DOWN ,"the car DIR is wrong2");
	typedef typename Transpose<typename b::board>::matrix transposed;
// typedef GameBoard<typename Transpose<typename b::board>::matrix> newboard;
	typedef typename MoveVehicleHorizontal<GameBoard<transposed>,C,R,LEFT,A>::board done;
	typedef typename Transpose<typename done::board>::matrix transposedPost;
	typedef GameBoard<transposedPost> board;
};

template<typename b, int R,int C,int A>
struct MoveVehicle<b,R,C,DOWN,A>{
	static_assert(R < b::lenght,"invalid R");
	static_assert(R >= 0,"invalid R");
	static_assert(C < b::width,"invalid C");
	static_assert(C >= 0,"invalid C");
	typedef typename GetAtIndex<R,typename b::board>::value row;
	typedef typename GetAtIndex<C,row>::value car;
	static_assert(car::type != EMPTY,"the car posiition is emPtY");
	static_assert(car::direction == UP ||car::direction == DOWN ,"the car DIR is wrong3");
	typedef typename Transpose<typename b::board>::matrix transposed;
	typedef typename MoveVehicleHorizontal<GameBoard<transposed>,C,R,RIGHT,A>::board done;
	typedef typename Transpose<typename done::board>::matrix transposedPost;
	typedef GameBoard<transposedPost> board;
};
template<typename row,typename cell>
struct moveOnce{
 };

template<typename row,CellType t,Direction dir,int len>
struct moveOnce<row,BoardCell<t,dir,len>>{
	static_assert(row::head::type == EMPTY,"cant move car1");
	typedef typename SetAtIndex<0,BoardCell<t,dir,len>,row>::list list;
 };

template<CellType t,Direction dir,Direction dir2,int len,typename...TT>
struct moveOnce<List<BoardCell<t,dir,len>,TT...>,BoardCell<t,dir2,len>>{
	typedef typename moveOnce<List<TT...>,BoardCell<t,dir2,len>>::list moved;
	typedef typename SetAtIndex<0,BoardCell<t,dir,len>,moved>::list moved_aux;
	typedef typename PrependList<BoardCell<EMPTY,dir,len>,moved_aux>::list list;
 };

template<typename row,typename cell,int amount>
struct moveSeveral{
	typedef typename moveOnce<row,cell>::list newRow;
	typedef typename moveSeveral<typename newRow::next,cell,amount-1>::result result_aux;
	typedef typename PrependList<typename newRow::head,result_aux>::list result;
};

template<typename row,typename cell>
struct moveSeveral<row,cell,0>{
	typedef row result;
};

template<CellType t,Direction dir,Direction dir2,int len,typename...TT,int A>
struct DoTheMove<List<BoardCell<t,dir,len>,TT...>,BoardCell<t,dir2,len>,A>{
	typedef typename moveSeveral<List<BoardCell<t,dir2,len>,TT...>,BoardCell<t,dir,len>,A>::result moved;
};





#endif /* MOVEVEHICLE_H_ */
