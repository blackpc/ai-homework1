/**
 * Filename: WeightedPoint.h
 *   Author: Igor Makhtes
 *     Date: Nov 22, 2014
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

#ifndef WEIGHTEDPOINT_H_
#define WEIGHTEDPOINT_H_


#include <homework1/Point.h>

/**
 * Represents a point with cost value
 */
class WeightedPoint : public Point {

public:

	WeightedPoint(const Point& point) : Point(point), cost_(0) { }
	WeightedPoint(const Point& point, int cost) : Point(point), cost_(cost) { }

	operator Point() {
		return Point(Point::x, Point::y);
	}

	bool operator <(const WeightedPoint& other) const {
		return this->cost_ < other.cost_;
	}

	bool operator ==(const WeightedPoint& other) const {
		return (Point)*this == (Point)other;
	}

public:

	void setCost(int cost) {
		cost_ = cost;
	}

	int getCost() const {
		return cost_;
	}

private:

	int cost_;


};



#endif /* WEIGHTEDPOINT_H_ */
