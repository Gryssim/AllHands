#pragma once
#include "../include/Vector2.h"
#include "SearchCell.h"
#include <vector>

class PathFinding {
public:
	PathFinding(void);
	PathFinding(void);

	void FindPath(Vector2 currentPos, Vector2 targetPos);
	Vector2 NextPathPos();
	void ClearOpenList() { m_openList.clear(); }
	void ClearVisitedList() { m_visitedList.clear(); }
	void ClearPathToGoal() { m_pathToGoal.clear(); }
	bool m_initializedStartGoal;
	bool m_foundGoal;

private:
	void SetStartAndGoal(SearchCell start, SearchCell goal);
	void PathOpened(int x, int z, float newCost, SearchCell *parent);
	SearchCell *GetNextCell();
	void ContinuePath();

	SearchCell *m_startCell;
	SearchCell *m_goalCell;
	std::vector<SearchCell*> m_openList;
	std::vector<SearchCell*> m_visitedList;
	std::vector<Vector2*> m_pathToGoal;
};