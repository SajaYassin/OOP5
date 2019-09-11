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
  static const int indexIfFound = IndexOfX<typename GetAtIndex<rowIndex, typename b::board>::value,0, GetAtIndex<rowIndex,typename b::board>::value::size>::result;
  static const bool found = (indexIfFound != -1) && (WinningRow<typename GetAtIndex<rowIndex,typename b::board>::value, indexIfFound, WinningRow<typename GetAtIndex<rowIndex,typename b::board>::value>::size>::result);
};
#endif /* RUSHHOUR_H_ */
