#ifndef COORDINATES_H
#define COORDINATES_H


class Coordinates
{
private:
    unsigned int m_coordX, m_coordY;

public:
    Coordinates();
    Coordinates(const unsigned int coord_x, const unsigned int coord_y);

    void updateCoord(const Coordinates &new_coord);
    void updateCoord(const unsigned int new_coord_x, const unsigned int new_coord_y);

    // GETTERS
    Coordinates getCoordinates() const;
    unsigned int getX() const;
    unsigned int getY() const;
};

#endif // COORDINATES_H
