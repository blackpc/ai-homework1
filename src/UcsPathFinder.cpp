/**
 * Filename: UcsPathFinder.cpp
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

#include <homework1/UcsPathFinder.h>


UcsPathFinder::UcsPathFinder() {
}

/**
 * Executes UCS search algorithm
 * @param start Starting point
 * @param goal Goal
 * @param map Map
 * @return Path
 */
Path UcsPathFinder::findPath(const Point& start, const Point& goal,
		Map::Ptr map) const
{
	/**
	 * Clone map to prevent changes on original map
	 */
	Map localMap = *map;

	/**
	 * Sorted map of Points by cost and the path
	 */
	multimap<WeightedPoint, Path> openList;
	/**
	 * Open list hash
	 */
	set<Point> openListHash;

	Point currentPoint = start;
	Path currentPath;

	openList.insert(make_pair(WeightedPoint(currentPoint, 0), currentPath));
	openListHash.insert(currentPoint);

	while(openList.size() > 0) {
		/**
		 * Fetch point with the lowest cost
		 */
		currentPoint = openList.begin()->first;
		currentPath = openList.begin()->second;

		/**
		 * Remove current point from lists
		 */
		openList.erase(openList.begin());
		openListHash.erase(currentPoint);

		/**
		 * Goal found
		 */
		if (currentPoint == goal)
			return currentPath;


		/**
		 * Iterate over all available moves from current point
		 */
		vector<Move> moves = localMap.getAvailableMoves(currentPoint);

		foreach(const Move& move, moves) {
			Map::CellType nextCell;
			Point nextPoint;

			if (localMap.applyMove(currentPoint, move, nextCell, nextPoint)) {

				/**
				 * If nextPoint not in open list, add it to open list
				 */
				if (openListHash.count(nextPoint) == 0) {
					Path pathToNext = currentPath;
					pathToNext.addMove(move);

					openList.insert(make_pair(WeightedPoint(nextPoint, move.getCost()), pathToNext));
					openListHash.insert(nextPoint);
				}
			}


		}
	}

	/**
	 * Path not found
	 */
	return Path();
}
