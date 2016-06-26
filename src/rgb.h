#ifndef RGB_H
#define RGB_H 1

#include <iostream>
//using namespace std;

class rgb {
public:
    rgb() { m_r = m_g = m_b = 0;}
    rgb(float red, float green, float blue);
    rgb(const rgb & original) { *this = original; }

    void setRed(float red) { m_r = red; }
    void setGreen(float green) { m_g = green; }
    void setBlue(float blue) { m_b = blue; }

    rgb& operator=(const rgb & right_op);
    rgb& operator+=(const rgb & right_op);
    rgb& operator*=(const rgb & right_op);
    rgb& operator/=(const rgb & right_op);
    rgb& operator*=(float right_op);
    rgb& operator/=(float right_op);

    rgb operator+() const { return *this; }
    rgb operator-() const { return rgb(-m_r, -m_g, -m_b); }

    float r() const { return m_r; }
    float g() const { return m_g; }
    float b() const { return m_b; }

    void clamp();

    friend std::ostream& operator<<(std::ostream& out, const rgb & the_rgb);
    friend rgb operator*(const rgb& c, float f);
    friend rgb operator*(float f, const rgb& c);
    friend rgb operator/(const rgb& c, float f);
    friend rgb operator+(const rgb& c1, const rgb& c2);
    friend rgb operator*(const rgb& c1, const rgb& c2);
    friend rgb operator/(const rgb& c1, const rgb& c2);

    // union { struct { float m_r, m_g, m_b; }; }
    float m_r, m_g, m_b;
};

inline rgb::rgb(float red, float green, float blue)
: m_r(red), m_g(green), m_b(blue) {}

inline rgb& rgb::operator+=(const rgb& right_op) {
    *this = *this + right_op;
    return *this;
}

inline rgb& rgb::operator*=(float right_op) {
    *this = *this * right_op;
    return *this;
}

inline rgb& rgb::operator/=(float right_op) {
    *this = *this / right_op;
    return *this;
}

inline rgb& rgb::operator*=(const rgb& right_op) {
    *this = *this * right_op;
    return *this;
}

inline rgb& rgb::operator/=(const rgb& right_op) {
    *this = *this / right_op;
    return *this;
}

inline rgb& rgb::operator=(const rgb& right_op) {
    m_r = right_op.m_r;
    m_g = right_op.m_g;
    m_b = right_op.m_b;
    return *this;
}

inline void rgb::clamp() {
    if (m_r > 1.0f) m_r = 1.0f;
    if (m_g > 1.0f) m_g = 1.0f;
    if (m_b > 1.0f) m_b = 1.0f;

    if (m_r < 0.0f) m_r = 0.0f;
    if (m_g < 0.0f) m_g = 0.0f;
    if (m_b < 0.0f) m_b = 0.0f;
}

inline std::ostream& operator << (std::ostream& out, const rgb& the_rgb) {
    out << the_rgb.m_r << ' ' 
        << the_rgb.m_g << ' '
        << the_rgb.m_b << ' ';
    return out;
}

inline rgb operator*(const rgb& c, float f) {
    return rgb(c.m_r*f, c.m_g*f, c.m_b*f);
}

inline rgb operator*(float f, const rgb& c) {
    return rgb(c.m_r*f, c.m_g*f, c.m_b*f);
}

inline rgb operator/(const rgb& c, float f) {
    return rgb(c.m_r/f, c.m_g/f, c.m_b/f);
}

inline rgb operator*(const rgb& c1, const rgb& c2)  {
    return rgb(c1.m_r * c2.m_r, c1.m_g * c2.m_g, c1.m_b * c2.m_b);
}

inline rgb operator/(const rgb& c1, const rgb& c2) {
    return rgb(c1.m_r / c2.m_r, c1.m_g / c2.m_g, c1.m_b / c2.m_b);
}

inline rgb operator+(const rgb& c1, const rgb& c2) {
    return rgb(c1.m_r + c2.m_r, c1.m_g + c2.m_g, c1.m_b + c2.m_b);
}

#endif
