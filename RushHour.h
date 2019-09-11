/*
 * RushHour.h
 *
 *  Created on: Sep 11, 2019
 *      Author: Saja
 */

#ifndef RUSHHOUR_H_
#define RUSHHOUR_H_

#include "MoveVehicle.h"

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
  static const bool found = 0;
};

template<typename b>
struct CheckWin{
  static const bool result = CheckWinAux<b,0,b::board::size>::found;
};

template<typename row,CellType car,int index,int rowSize>
struct IndexOfCar{
  static const int result = ConditionalInteger<GetAtIndex<index,row>::value::type == car,index,IndexOfCar<row,car,index+1,rowSize>::result>::value;
};
template<typename row,CellType car,int rowSize>
struct IndexOfCar<row,car,rowSize,rowSize>{
  static const int result =-1;
};

template<typename b, CellType car, int rowIndex, int rowSize>
struct FindCarAux{
  typedef typename GetAtIndex<rowIndex,typename b::board>::value actualRow;
  static const int foundCol = IndexOfCar<actualRow,car,0,actualRow::size>::result;
  static const int col = ConditionalInteger<foundCol != -1, foundCol, FindCarAux<b,car,rowIndex+1, rowSize>::col>::value;
  static const int row = ConditionalInteger<foundCol != -1, rowIndex, FindCarAux<b,car,rowIndex+1, rowSize>::row>::value;
};

template<typename b, CellType car, int rowSize>
struct FindCarAux<b,car,rowSize,rowSize>{
  static const int col = -1;
  static const int row = -1;
};

template<typename b, CellType car>
struct FindCar{
  static const int row = FindCarAux<b,car,0,b::board::size>::row;
  static const int col = FindCarAux<b,car,0,b::board::size>::col;
};

template<typename b, typename M>
  struct CheckSolutionAux{};
  
template<typename b, typename M, typename ...MM>
  struct CheckSolutionAux<b,List<M,MM...>>{
    typedef typename MoveVehicle<b,FindCar<b,M::type>::row,FindCar<b,M::type>::col,M::direction, M::amount>::board boardMoved;
    typedef typename CheckSolutionAux<boardMoved,MM...>::board board;
  };
template<typename b, typename M>
  struct CheckSolutionAux<b,List<M>>{
    typedef typename MoveVehicle<b,FindCar<b,M::type>::row,FindCar<b,M::type>::col,M::direction, M::amount>::board board;
  };
  
template<typename b, typename M>
  struct CheckSolution{};
  
  
template<typename b, typename M, typename ...MM>
struct CheckSolution<b,List<M,MM...>>{
  typedef typename CheckSolutionAux<b,List<M,MM...>>::board board;
  const bool result = CheckWin<board>::result;
};
#endif /* RUSHHOUR_H_ */
