#ifndef COORDINATES_H
#define COORDINATES_H


class Coordinates
{
public:
    int m_coordX, m_coordY;
    Coordinates();
    Coordinates(const int coordX, const int coordY);

    void updateCoord(const Coordinates &new_coord);
    void updateCoord(const int new_coord_x, const int new_coord_y);
};

#endif // COORDINATES_H
