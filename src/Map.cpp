/**
 * Filename: Map.cpp
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

#include <homework1/Map.h>

Map::Map(size_t width, size_t height) :
	width_(width), height_(height)
{
	map_.resize(width_ * height_);
}

Map::CellType& Map::at(size_t x, size_t y) {
	if (isInBounds(x, y))
		return map_[y * width_ + x];

	throw new string("Out of map coordinates");
}

Map::CellType& Map::at(const Point& point) {
	return at(point.x, point.y);
}

const Map::CellType& Map::at(const size_t x, size_t y) const {
	if (isInBounds(x, y))
			return map_[y * width_ + x];

	throw new string("Out of map coordinates");
}

const Map::CellType& Map::at(const Point& point) const {
	return at(point.x, point.y);
}

bool Map::isInBounds(size_t x, size_t y) const {
	return (x >= 0 && x < width_) &&
		   (y >= 0 && y < height_);
}

string Map::toString() const {
	int widthCounter = 0;
	stringstream output;

	foreach(Map::CellType cell, map_) {
//		output << cell.toString() << " ";
		output << cell.toString() << cell.getCameFrom().toString() << " ";

		if (widthCounter % width_ == width_ - 1)
			output << "\n";

		widthCounter++;
	}

	return output.str();
}


bool Map::applyMove(const Point& currentPoint, const Move& move,
		Point& resultPoint) const
{
	CellType cell;
	return applyMove(currentPoint, move, cell, resultPoint);
}

bool Map::applyMove(const Point& currentPoint, const Move& move,
		CellType& resultCell, Point& resultPoint) const
{
	int x = currentPoint.x;
	int y = currentPoint.y;

	if (move == Move::R)
		x++;
	if (move == Move::L)
		x--;
	if (move == Move::U)
		y--;
	if (move == Move::D)
		y++;
	if (move == Move::RD) {
		x++;
		y++;
	}
	if (move == Move::LD) {
		x--;
		y++;
	}
	if (move == Move::LU) {
		x--;
		y--;
	}
	if (move == Move::RU) {
		x++;
		y--;
	}

	if (!isInBounds(x, y))
		return false;

	resultPoint = Point(x, y);
	resultCell = this->at(resultPoint);

	return true;
}

vector<Move> Map::getAvailableMoves(const Point& currentPoint) const {
	vector<Move> moves;
	set<Move> blockedMoves;

	Point nextPoint;
	CellType nextCell;

	foreach(const Move& move, Move::getAllMoves()) {
		if (blockedMoves.count(move) == 0 && applyMove(currentPoint, move, nextCell, nextPoint)) {

			/**
			 * If next cell is traversable (=not water), add it to available moves,
			 * else if R,D,L or U is water, then diagonal also blocked.
			 */
			if (nextCell.isTraversable())
				moves.push_back(Move(move, nextCell.getCost()));
			else {

				if (move == Move::R) {
					blockedMoves.insert(Move::RU);
					blockedMoves.insert(Move::RD);
				}

				if (move == Move::D) {
					blockedMoves.insert(Move::RD);
					blockedMoves.insert(Move::LD);
				}

				if (move == Move::L) {
					blockedMoves.insert(Move::LU);
					blockedMoves.insert(Move::LD);
				}

				if (move == Move::U) {
					blockedMoves.insert(Move::LU);
					blockedMoves.insert(Move::RU);
				}

			}
		}
	}

	return moves;
}

Path Map::reconstructPath(const Point& start, const Point& goal) const {
	Path path;
	Point currentPoint = goal;

	while (true) {

		if (currentPoint == start)
			break;

		const Map::CellType& currentCell = this->at(currentPoint);
		path.addMove(Move(currentCell.getCameFrom().reverse(), currentCell.getCost()));

		Point parentPoint;
		this->applyMove(currentPoint, currentCell.getCameFrom(), parentPoint);

		currentPoint = parentPoint;
	}

	return path.reverse();
}
