/**
 * Filename: Map.h
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

#ifndef MAP_H_
#define MAP_H_

#include <iostream>
#include <vector>
#include <sstream>
#include <set>

#include <boost/shared_ptr.hpp>

#include <homework1/Point.h>
#include <homework1/Cell.h>
#include <homework1/Path.h>


using namespace std;

/*
 * Map representation
 */
class Map {

public:

	/**
	 * Type of the cell
	 */
	typedef Cell CellType;

	/**
	 * Shared pointer to map
	 */
	typedef boost::shared_ptr<Map> Ptr;

	/**
	 * Allocates necessary array for the map
	 * @param width
	 * @param height
	 */
	Map(size_t width, size_t height);

public:

	/**
	 * Returns value of specified cell
	 * @param x X coordinate
	 * @param y Y coordinate
	 * @return Cell value
	 */
	CellType& at(size_t x, size_t y);

	/**
	 * Returns value of specified cell
	 * @param x X coordinate
	 * @param y Y coordinate
	 * @return Cell value
	 */
	const CellType& at(size_t x, size_t y) const;

	/**
	 * Returns value of specified cell
	 * @param point Point representing the coordinates
	 * @return
	 */
	CellType& at(const Point& point);

	/**
	 * Returns value of specified cell
	 * @param point Point representing the coordinates
	 * @return
	 */
	const CellType& at(const Point& point) const;

	/**
	 * Verifies the coordinates are within the map's bounds
	 * @param x X coordinate
	 * @param y Y coordinate
	 * @return
	 */
	bool isInBounds(size_t x, size_t y) const;

	/**
	 * Applies specified move from specified position and returns the position and cell's value
	 * @param currentPose
	 * @param move
	 * @param resultPoint
	 * @return Whether the point within the map bounds
	 */
	bool applyMove(const Point& currentPoint, const Move& move, Point& resultPoint) const;

	/**
	 * Applies specified move from specified position and returns the position and cell's value
	 * @param currentPose
	 * @param move
	 * @param resultCell
	 * @param resultPoint
	 * @return Whether the point within the map bounds
	 */
	bool applyMove(const Point& currentPoint, const Move& move, CellType& resultCell, Point& resultPoint) const;

	/**
	 * Returns all available moves with costs from specified point
	 * @note The moves are sorted by the ordered described in the homework
	 * @param currentPoint
	 * @return
	 */
	vector<Move> getAvailableMoves(const Point& currentPoint) const;

	/**
	 * Converts map to string representation
	 * @return
	 */
	string toString() const;

private:

	/**
	 * Map width
	 */
	size_t width_;

	/**
	 * Map height
	 */
	size_t height_;

	/**
	 * The map array
	 */
	vector<CellType> map_;

};

#endif /* MAP_H_ */
