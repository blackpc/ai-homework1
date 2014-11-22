/**
 * Filename: BfsPathFinder.cpp
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

#include <homework1/BfsPathFinder.h>


BfsPathFinder::BfsPathFinder() {
}

/**
 * Executes BFS search algorithm
 * @param start Starting point
 * @param goal Goal
 * @param map Map
 * @return Path
 */
Path BfsPathFinder::findPath(const Point& start, const Point& goal,
		const Map::Ptr map) const
{
	/**
	 * Clone map to prevent changes on original map
	 */
	Map localMap = *map;

	/**
	 * Unsorted queue of discovered points
	 */
	list<Point> openList;
	/**
	 * Open list hash
	 */
	set<Point> openListHash;

	Point currentPoint = start;
	localMap.at(currentPoint).setCameFrom(Move::L);

	openList.push_back(currentPoint);
	openListHash.insert(currentPoint);

	while(openList.size() > 0) {
		/**
		 * Fetch first discovered point from open list
		 */
		currentPoint = openList.front();

		/**
		 * Remove current point from lists
		 */
		openList.pop_front();
		openListHash.erase(currentPoint);

		/**
		 * Goal found
		 */
		if (currentPoint == goal)
		{
			return localMap.reconstructPath(start, goal);
		}

		/**
		 * Iterate over all available moves from current point
		 * note: the moves are sorted by the ordered described in the homework
		 *
		 */
		vector<Move> moves = localMap.getAvailableMoves(currentPoint);

		foreach(const Move& move, moves) {
			Map::CellType nextCell;
			Point nextPoint;

			if (localMap.applyMove(currentPoint, move, nextCell, nextPoint)) {

				/**
				 * If nextPoint not in open list and has no parent, then add it to open list
				 */
				if (openListHash.count(nextPoint) == 0 && localMap.at(nextPoint).getCameFrom().isNull()) {
					openList.push_back(nextPoint);
					openListHash.insert(nextPoint);
					localMap.at(nextPoint).setCameFrom(move.reverse());
				}
			}


		}
	}

	/**
	 * Path not found
	 */
	return Path();
}
