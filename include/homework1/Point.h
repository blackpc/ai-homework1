/**
 * Filename: Point.h
 *   Author: Igor Makhtes
 *     Date: Nov 21, 2014
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2014
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef POINT_H_
#define POINT_H_

/**
 * Represents x-y coordinates on the map
 */
class Point {
public:

	/**
	 * X coordinate
	 */
	size_t x;

	/**
	 * Y coordinate
	 */
	size_t y;

	Point() {
		x = 0;
		y = 0;
	}

	Point(size_t x, size_t y) {
		this->x = x;
		this->y = y;
	}

	bool operator ==(const Point& other) const {
		return this->x == other.x && this->y == other.y;
	}

	bool operator <(const Point& other) const {
		if (this->x < other.x)
			return true;

		return this->y < other.y;
	}

private:
};



#endif /* POINT_H_ */
