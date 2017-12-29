#ifndef POSITION_CLASS_H
#define POSITION_CLASS_H


class Position
{
    int row;
    int col;
public:
    Position(const int& row = 0, const int& col = 0);
    int getRow() const;
    int getCol() const;
    void setRow(const int& new_row);
    void setCol(const int& new_col);
 };

#endif // POSITION_CLASS_H
