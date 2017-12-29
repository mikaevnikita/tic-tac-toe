#include "position_class.h"

Position::Position(const int& row, const int& col):row(row),col(col){}
int Position::getRow() const{
    return row;
}
int Position::getCol() const{
    return col;
}
void Position::setRow(const int& new_row){
    row = new_row;
}

void Position::setCol(const int& new_col){
    col = new_col;
}
