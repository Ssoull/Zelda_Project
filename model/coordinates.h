#ifndef COORDINATES_H
#define COORDINATES_H


class Coordinates
{
private:
    int m_coordX, m_coordY;

public:
    Coordinates();
    Coordinates(const int coordX, const int coordY);

    void updateCoord(const Coordinates &new_coord);
    void updateCoord(const int new_coord_x, const int new_coord_y);

    // GETTERS
    Coordinates getCoordinates() const;
    int getX() const;
    int getY() const;
};

#endif // COORDINATES_H
