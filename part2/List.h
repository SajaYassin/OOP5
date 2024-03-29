/*
 * List.h
 *
 *  Created on: Sep 10, 2019
 *      Author: Saja
 */

#ifndef LIST_H_
#define LIST_H_

template<typename... TT>
struct List {
	static const int size = 0;
 	typedef void head;
	typedef List<> next;
};

template<typename T,typename... TT>
struct List<T,TT...> {
	static const int size = sizeof...(TT) + 1;
	typedef T head;
	typedef List<TT...> next;
};

template <typename T>
struct List<T> {
	typedef T head;
	static const int size = 1;
	typedef List<> next;
};

template <typename T,typename List>
struct PrependList {
};

template <typename T, typename... TT>
struct PrependList<T,List<TT...>> {
	typedef List<T,TT...> list;
};

template <int N, typename T, typename ...TT>
struct SetAtIndex{};

template <int N, typename T, typename H, typename... TT>
struct SetAtIndex<N,T,List<H, TT...>>{
  typedef typename SetAtIndex<N-1,T,List<TT...>>::list tail;
  typedef typename PrependList<H,tail>::list list;
};

template <typename T, typename H, typename ...TT>
struct SetAtIndex<0,T,List<H,TT...>>{
  typedef List<T,TT...> list;
};

template<int N, typename T>
struct GetAtIndex {};

template<int N, typename T, typename... TT >
struct GetAtIndex<N, List<T, TT... > > {
typedef typename GetAtIndex<N-1, List<TT... >>::value value;
};

template<typename T, typename... TT>
struct GetAtIndex<0, List<T, TT... > > {
typedef T value;
};
template <typename T,typename List>
struct PrependListlast {
};

template <typename T, typename... TT>
struct PrependListlast<T,List<TT...>> {
	typedef List<TT...,T> list;
};

template<typename listIn>
struct reverseList{};

template<typename T>
struct reverseList<List<T>>{
	typedef  List<T>  list;
};

template<typename T, typename... TT>
struct reverseList<List<T,TT...>>{
	typedef typename PrependListlast<T,typename reverseList<List<TT...>>::list>::list list;
};



#endif /* LIST_H_ */
