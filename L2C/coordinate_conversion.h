#ifndef COORDINATE_CONVERSION_H
#define COORDINATE_CONVERSION_H

/**
 * @brief Convert polar cordinants to cartesian cordinants
 * 
 * @param radius Double value of r in polar cordinants
 * @param angle Double value of theta in polar cordinants
 * @param xCoordinate Double value of x value in cartesian cordinants
 * @param yCoordinate Double value of y value in cartesian cordinants
 */
void polar_to_cartesian(double radius, double angle, double* xCoordinate, double* yCoordinate);

/**
 * @brief Convert cartesian cordinants to polar cordinants
 * 
 * @param xCoordinate Double value of x value in cartesian cordinants
 * @param yCoordinate Double value of y value in cartesian cordinants
 * @param radius Double value of r in polar cordinants
 * @param angle Double value of theta in polar cordinants
 */
void cartesian_to_polar(double xCoordinate, double yCoordinate, double* radius, double* angle);

#endif