/*
 * RushHour.h
 *
 *  Created on: Sep 11, 2019
 *      Author: Saja
 */

#ifndef RUSHHOUR_H_
#define RUSHHOUR_H_


#include "CellType.h"
#include "Direction.h"
#include "GameBoard.h"
#include "BoardCell.h"
#include "List.h"

template<typename row,int index, int rowSize>
struct WinningRow{
    static const bool recursive = (WinningRow<row,index+1,rowSize>::result && (GetAtIndex<index,row>::value::type == EMPTY || GetAtIndex<index,row>::value::type == X));
  	static const bool result = ConditionalInteger<recursive,1,0>::value;
};

template<typename row,int rowSize>
struct WinningRow<row,-1,rowSize>{
    static const bool recursive = false;
  	static const bool result = false;
};
template<typename row,int rowSize>
struct WinningRow<row, rowSize,rowSize>{
  static const bool result = 1;
};
template<typename row,int index,int rowSize>
struct IndexOfX{
  static const int result = ConditionalInteger<GetAtIndex<index,row>::value::type == X,index,IndexOfX<row,index+1,rowSize>::result>::value;
};
template<typename row,int rowSize>
struct IndexOfX<row,rowSize,rowSize>{
  static const int result =-1;
};
template<typename b, int rowIndex, int length>
struct CheckWinAux{
  typedef typename GetAtIndex<rowIndex,typename b::board>::value row;
  static const int indexIfFound = IndexOfX<row,0, row::size>::result;
  static const bool found = ConditionalInteger<(WinningRow<row , indexIfFound, row::size>::result),1,CheckWinAux<b,rowIndex+1,length>::found>::value;
//  static const bool found = false;
};
template<typename b, int length>
struct CheckWinAux<b, length, length>{
  static const bool found = false;
};

template<typename b>
struct CheckWin{
  static const bool result = CheckWinAux<b,0,b::board::size>::found;
};
#endif /* RUSHHOUR_H_ */
