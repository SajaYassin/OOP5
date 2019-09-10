/*
 * Utilities.h
 *
 *  Created on: Sep 10, 2019
 *      Author: Saja
 */

#ifndef UTILITIES_H_
#define UTILITIES_H_

template<bool cond, int True, int False>
struct ConditionalInteger{
};

template<int True, int False>
struct ConditionalInteger<true,True,  False> {
	static const int value = True;
};

template<int True, int False>
struct ConditionalInteger<false ,True,  False>{
	static const int value = False;
};

template<bool cond, typename True, typename False>
struct Conditional{
};

template<typename True, typename False>
struct Conditional<true,True,  False> {
	typedef True value;
};

template<typename True, typename False>
struct Conditional<false ,True,  False>{
	typedef False value;
};



#endif /* UTILITIES_H_ */
