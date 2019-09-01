#ifndef SIZE_H
#define SIZE_H

class Size
{
public:
    int m_width, m_height;
    Size(const int width, const int height);

    void updateSize(const Size &new_size);
};

#endif // SIZE_H
