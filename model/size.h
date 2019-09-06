#ifndef SIZE_H
#define SIZE_H

class Size
{
private:
    int m_width, m_height;

public:
    Size(const int width, const int height);
    Size(const int square);

    void updateSize(const Size &new_size);

    // GETTERS
    Size getSize() const;
    int getWidth() const;
    int getHeight() const;
};

#endif // SIZE_H
