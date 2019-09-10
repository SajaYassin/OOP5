#ifndef BOARDCELL_H_
#define 	BOARDCELL_H_

template<CellType t,Direction dir,int len>
struct BoardCell{
	static const CellType type = t;
	static const Direction direction = dir;
	static const int lenght = len;
};

#endif /* BOARDCELL	_H_ */
