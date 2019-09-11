/*
 * test.cpp
 *
 *  Created on: Sep 10, 2019
 *      Author: Saja
 */

#include "List.h"
#include "stdio.h"
#include "Utilities.h"
#include "BoardCell.h"
#include "GameBoard.h"
#include "MoveVehicle.h"
#include "Printer.h"
#include "TransposeList.h"
#include "RushHour.h"

template <int N>
struct Int {
	static const int value = N;

};
int main(){
//typedef List<int> list;
////list::head x = 3;
////printf("%d",list::size);
//static_assert(list::size == 1,"fail");
/*typedef List<Int<1>, Int<2>, Int<3>> list;
typedef typename PrependList<Int<4>, list>::list newList;
typedef typename PrependList<Int<5>, newList>::list newNewList;
printf("%d",newList::size);
static_assert(newList ::size == 4,"fail");
static_assert(newList ::head :: value == 4,"fail");
static_assert(newList ::next ::head:: value == 1,"fail");

static_assert(newNewList ::size == 5,"fail");
static_assert(newNewList ::head :: value == 5,"fail");
static_assert(newNewList ::next ::head:: value == 4,"fail");
static_assert(GetAtIndex<1,list>::value::value == 2,"fail");
static_assert(GetAtIndex<0,list>::value::value == 1,"fail");
static_assert(GetAtIndex<2,list>::value:: value == 3,"fail");

static_assert(ConditionalInteger<(0 != 1), 0, 1>::value == 0,"fail");
static_assert(ConditionalInteger<(0 == 1), 0, 1>::value == 1,"fail");

static_assert(Conditional<(0 != 1), Int<0>, Int<1>>::value :: value == 0,"d");
static_assert(Conditional<(0 == 1), Int<0>, Int<1>>::value :: value== 1, "gg");*/

    typedef GameBoard< List<
            List < BoardCell< X , RIGHT , 2>, BoardCell< X , LEFT , 2>, BoardCell< EMPTY , RIGHT , 0> >,
            List < BoardCell< EMPTY , RIGHT , 0>, BoardCell< EMPTY , RIGHT , 0>, BoardCell< A , RIGHT , 1> >
    > > gameBoard;

    static_assert(BoardCell< X , RIGHT , 2>::type == X,"fail");
    static_assert(BoardCell< X , RIGHT , 2>::direction == RIGHT,"fail");
    static_assert(BoardCell< X , RIGHT , 2>::lenght == 2,"fail");
    static_assert(gameBoard::lenght == 2,"fail");
    static_assert(gameBoard::width== 3,"fail");
    static_assert(gameBoard::board::head::head::type == X,"fail");
//    int moount = Move<EMPTY, UP, 1>::amount;
    static_assert(Move<X, UP, 1>::amount == 1,"fail");
    static_assert(Move<X, UP, 1>::direction == UP,"fail");
    static_assert(Move<X, UP, 1>::type == X,"fail");

//    typedef GameBoard<List< List< BoardCell<EMPTY, UP, 0>, BoardCell<EMPTY, UP, 0>>,
//    List< BoardCell<X, RIGHT, 1>, BoardCell<A, UP, 1>>,
//    List< BoardCell<EMPTY, UP, 0>, BoardCell<EMPTY, UP, 0>>>> gameBoard1;
//    Printer<gameBoard1>::print(std::cout);

    typedef GameBoard< List<
            List < BoardCell< EMPTY , RIGHT , 1>, BoardCell< EMPTY , RIGHT , 0>, BoardCell< EMPTY , RIGHT , 0>, BoardCell< EMPTY , RIGHT , 0>, BoardCell< O , DOWN , 1>, BoardCell< EMPTY , RIGHT , 0> >,
            List < BoardCell< EMPTY , RIGHT , 2>, BoardCell< EMPTY , RIGHT , 0>, BoardCell< A , RIGHT , 2>, BoardCell< A , LEFT , 2>, BoardCell< O , DOWN , 3>, BoardCell< EMPTY , RIGHT , 0> >,
            List < BoardCell< EMPTY , RIGHT , 3>, BoardCell< EMPTY , RIGHT , 0>, BoardCell< X , RIGHT , 2>, BoardCell< X , LEFT , 2>, BoardCell< O , UP , 3>, BoardCell< EMPTY , RIGHT , 0> >,
            List < BoardCell< EMPTY , RIGHT , 0>, BoardCell< EMPTY , RIGHT , 0>, BoardCell< EMPTY , RIGHT , 0>, BoardCell< EMPTY , RIGHT , 0>, BoardCell< EMPTY , RIGHT , 0>, BoardCell< EMPTY , RIGHT , 0> >,
            List < BoardCell< EMPTY , RIGHT , 0>, BoardCell< EMPTY , RIGHT , 0>, BoardCell< B , DOWN , 2>, BoardCell< P , RIGHT , 3>, BoardCell< P , RIGHT , 3>, BoardCell< P , LEFT , 3> >,
            List < BoardCell< EMPTY , RIGHT , 0>, BoardCell< EMPTY , RIGHT , 0>, BoardCell< B , UP , 2>, BoardCell< EMPTY , RIGHT , 0>, BoardCell< C , RIGHT , 2>, BoardCell< C , LEFT , 2> >
    > > gameBoard1;
    printf("*****************\n");
    Printer<gameBoard1>::print(std::cout);
    printf("*****************\n");
    printf("%d",CheckWin<gameBoard1>::result);
//    template<typename b, int R,int C,Direction D,int A>
    /*typedef typename MoveVehicle<gameBoard1,2,3,RIGHT,1>::board afterBoard;
    Printer<afterBoard>::print(std::cout);
    printf("*****************\n");*/
    /*typedef typename MoveVehicle<gameBoard1,2,3,LEFT,1>::board afterBoard2;
    Printer<afterBoard2>::print(std::cout);
    printf("*****************\n");
    typedef typename MoveVehicle<afterBoard2,2,1,LEFT,1>::board afterBoard3;
    Printer<afterBoard3>::print(std::cout);
    printf("*****************\n");
    typedef typename MoveVehicle<afterBoard3,2,1,RIGHT,4>::board afterBoard4;
    Printer<afterBoard4>::print(std::cout);
    printf("*****************\n");
    typedef typename MoveVehicle<afterBoard4,1,2,RIGHT,2>::board afterBoard5;
    Printer<afterBoard5>::print(std::cout);
    printf("*****************\n");
//    typedef typename MoveVehicle<afterBoard5,0,4,LEFT,1>::board afterBoard6;
//	Printer<afterBoard6>::print(std::cout);
//	printf("*****************\n");
	typedef GameBoard<typename Transpose<typename afterBoard5::board>::matrix> newboard;
	Printer<newboard>::print(std::cout);
	printf("*****************\n");
    typedef typename MoveVehicle<afterBoard5,4,2,UP,2>::board afterBoard6;
    Printer<afterBoard6>::print(std::cout);
	printf("*****************\n");
    typedef typename MoveVehicle<afterBoard6,2,2,DOWN,2>::board afterBoard7;
    Printer<afterBoard7>::print(std::cout);*/

}



