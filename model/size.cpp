#include "size.h"

Size::Size(const int width, const int height) : m_width(width), m_height(height) {}



void Size::updateSize(const Size &new_size)
{
    m_width = new_size.m_width;
    m_height = new_size.m_height;
}
