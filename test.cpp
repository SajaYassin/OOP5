/*
 * test.cpp
 *
 *  Created on: Sep 10, 2019
 *      Author: Saja
 */

#include "List.h"
#include "stdio.h"
#include "Utilities.h"
template <int N>
struct Int {
	static const int value = N;

};
int main(){
//typedef List<int> list;
////list::head x = 3;
////printf("%d",list::size);
//static_assert(list::size == 1,"fail");
typedef List<Int<1>, Int<2>, Int<3>> list;
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
static_assert(Conditional<(0 == 1), Int<0>, Int<1>>::value :: value== 1, "gg");
}



