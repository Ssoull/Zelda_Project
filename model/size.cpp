#include "size.h"

Size::Size(const int width, const int height) : m_width(width), m_height(height) {}

Size::Size(const int square) : m_width(square), m_height(square) {}

void Size::updateSize(const Size &new_size)
{
    m_width = new_size.m_width;
    m_height = new_size.m_height;
}


// GETTERS
Size Size::getSize() const
{
    return Size(m_width, m_height);
}

int Size::getWidth() const
{
    return m_width;
}

int Size::getHeight() const
{
    return m_height;
}
