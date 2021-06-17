#pragma once

/*
	2D vector class and utility static methods
	SharktasticA 2020
	https://sharktastica.co.uk
    https://github.com/SharktallicA
*/

#include <cmath>
#include <string>

using namespace std;

/*!
 * Two-dimensional vector for use with coordinate
 * values.
 */
class Vector2D
{
private:
    /*!
     * X-axis co-ordinate value.
     */
    double x;

    /*!
     * Y-axis co-ordinate value.
     */
    double y;

public:
    /*!
     * Default constructor.
     */
    Vector2D()
    {
        x = y = 0;
    }

    /*!
     * Default initialised constructor variant.
     * @param nX New X-axis coordinate value
     * @param nY New Y-axis coordinate value
     */
    Vector2D(double nX, double nY)
    {
        x = nX;
        y = nY;
    }

    /*!
     * Returns the vector's X-axis coordinate value.
     */
    double X()
    {
        return x;
    }

    /*!
     * Returns the vector's Y-axis coordinate value.
     */
    double Y()
    {
        return y;
    }

    /*!
     * Returns the vector's X-axis coordinate value
     * as a rounded integer.
     */
    int int_X()
    {
        return (int)round(x);
    }

    /*!
     * Returns the vector's Y-axis coordinate value
     * as a rounded integer.
     */
    int int_Y()
    {
        return (int)round(y);
    }

    /*!
     * Flags if one or both of the vector's components
     * currently have non-numerical values.
     */
    bool nan()
    {
        if (isnan(x) || isnan(y))
            return true;
        else
            return false;
    }

    /*!
     * Returns the vector's magnitude.
     * √(x^2 + y^2)
     */
    double len()
    {
        return sqrt(pow(x, 2) + pow(y, 2));
    }

    /*!
     * Returns a normalised copy of the vector.
     */
    Vector2D norm()
    {
        return Vector2D(x / len(), y / len());
    }

    /*!
     * Returns a presentable string representation of
     * the vector.
     */
    string to_str()
    {
        return "(" + to_string(x) + ", " + to_string(y) + ")";
    }

    /*!
     * Returns the absolute distance between two given vectors.
     * @param a First reference vector
     * @param b Second reference vector
     */
    static double dist(Vector2D a, Vector2D b)
    {
        return abs(sqrt(pow(a.X() - b.X(), 2) + pow(a.Y() - b.Y(), 2)));
    }

    /*!
     * Returns a normalised vector that flags the direction
     * between two given vectors.
     * @param a First reference vector
     * @param b Second reference vector
     */
    static Vector2D dir(Vector2D a, Vector2D b);
};

/*!
 * Overloaded operator to facilitate adding two vectors
 * together.
 * @param a First reference vector
 * @param b Second reference vector
 */
Vector2D operator +(Vector2D& a, Vector2D& b)
{
    return Vector2D(a.X() + b.X(), a.Y() + b.Y());
}

/*!
 * Overloaded operator to facilitate subtracting two vectors
 * together.
 * @param a First reference vector
 * @param b Second reference vector
 */
Vector2D operator -(Vector2D& a, Vector2D& b)
{
    return Vector2D(a.X() - b.X(), a.Y() - b.Y());
}

/*!
 * Overloaded operator to facilitate multiplying two vectors
 * together.
 * @param a First reference vector
 * @param b Second reference vector
 */
Vector2D operator *(Vector2D& a, Vector2D& b)
{
    return Vector2D(a.X() * b.X(), a.Y() * b.Y());
}

/*!
 * Overloaded operator to facilitate dividing two vectors
 * together.
 * @param a First reference vector
 * @param b Second reference vector
 */
Vector2D operator /(Vector2D& a, Vector2D& b)
{
    return Vector2D(a.X() / b.X(), a.Y() / b.Y());
}

/*!
 * Overloaded operator to facilitate evaluating if two
 * vectors are the same.
 * @param a First reference vector
 * @param b Second reference vector
 */
bool operator ==(Vector2D& a, Vector2D& b)
{
    if ((a.X() == b.X()) && (a.Y() == b.Y()))
        return true;
    else
        return false;
}

/*!
 * Overloaded operator to facilitate evaluating if two
 * vectors are different.
 * @param a First reference vector
 * @param b Second reference vector
 */
bool operator !=(Vector2D& a, Vector2D& b)
{
    if ((a.X() == b.X()) && (a.Y() == b.Y()))
        return false;
    else
        return true;
}

/*!
 * Static function to return the direction between two
 * given vectors.
 * @param a First reference vector
 * @param b Second reference vector
*/
Vector2D Vector2D::dir(Vector2D a, Vector2D b)
{
    return (a - b).norm();
}