#include "../include/PathFinding.h"

PathFinding::PathFinding(void) {
	m_initializedStartGoal = false;
	m_foundGoal = false;
}

PathFinding::~PathFinding(void) {

}

void PathFinding::FindPath(Vector2 currentPos, Vector2 targetPos) {
	if (!m_initializedStartGoal) {
		for (int i = 0; i < m_openList.size(); i++) {
			delete m_openList[i];
		}
		m_openList.clear();
		for (int i = 0; i < m_visitedList.size(); i++) {
			delete m_visitedList[i];
		}
		m_visitedList.clear();
		for (int i = 0; i < m_pathToGoal.size(); i++) {
			delete m_pathToGoal[i];
		}
		m_pathToGoal.clear();

		//Initialize Start
		SearchCell start;
		start.m_xcoord = currentPos.getX;
		start.m_ycoord = currentPos.getY;

		//Initialize Goal
		SearchCell goal;
		goal.m_xcoord = targetPos.getX;
		goal.m_ycoord = targetPos.getY;

		SetStartAndGoal(start, goal);
		m_initializedStartGoal = true;
	}
	if (m_initializedStartGoal) {
		ContinuePath();
	}
}

void PathFinding::SetStartAndGoal(SearchCell start, SearchCell goal) {
	m_startCell = new SearchCell(start.m_xcoord, start.m_ycoord, NULL);
	m_goalCell = new SearchCell(goal.m_xcoord, goal.m_ycoord, &goal);

	m_startCell->G = 0;
	m_startCell->H = m_startCell->ManHattanDistance(m_goalCell);
	m_startCell->parent = 0;

	m_openList.push_back(m_startCell);
}

SearchCell * PathFinding::GetNextCell() {
	float bestF = 999999.0f;
	int cellIndex = -1;
	SearchCell *nextCell = NULL;

	for (int i = 0; i < m_openList.size(); i++) {
		if (m_openList[i]->GetF() < bestF) {
			bestF = m_openList[i]->GetF();
			cellIndex = i;
		}
	}
	if (cellIndex >= 0) {
		nextCell = m_openList[cellIndex];
		m_visitedList.push_back(nextCell);
		m_openList.erase(m_openList.begin() + cellIndex);
	}
	return nextCell;
}

void PathFinding::PathOpened(int x, int y, float newCost, SearchCell *parent) {
	/*if(CELL_BLOCKED){
	return;
	}
	*/
	int id = y *WORLD_SIZE + x;
	for (int i = 0; i < m_visitedList.size(); i++) {
		if (id == m_visitedList[i]->m_id) {
			return;
		}
	}
	SearchCell *newChild = new SearchCell(x, y, parent);
	newChild->G = newCost;
	newChild->H = parent->ManHattanDistance(m_goalCell);

	for (int i = 0; i < m_openList.size(); i++) {
		if (id == m_openList[i]->m_id) {
			float newF = newChild->G + newCost + m_openList[i]->H;
			if (m_openList[i]->GetF() > newF) {
				m_openList[i]->G = newChild->G + newCost;
				m_openList[i]->parent = newChild;
			}
			else { //if F is not better
				delete newChild;
				return;
			}
		}
	}
	m_openList.push_back(newChild);
}

void PathFinding::ContinuePath() {
	for (int i = 0; i < 4; i++) {
		if (m_openList.empty()) { return; }
		SearchCell *currentCell = GetNextCell();
		if (currentCell->m_id == m_goalCell->m_id) {
			m_goalCell->parent = currentCell->parent;
			SearchCell *getPath;
			for (getPath = m_goalCell; getPath != NULL; getPath = getPath->parent) {
				m_pathToGoal.push_back(new Vector2(getPath->m_xcoord, 0, getPath->m_ycoord));
			}
			m_foundGoal = true;
			return;
		}
		else {
			//right side
			PathOpened(currentCell->m_xcoord + 1, currentCell->m_ycoord, currentCell->G + 1, currentCell);
			//left side
			PathOpened(currentCell->m_xcoord - 1, currentCell->m_ycoord, currentCell->G + 1, currentCell);
			//Up
			PathOpened(currentCell->m_xcoord, currentCell->m_ycoord + 1, currentCell->G + 1, currentCell);
			//Down
			PathOpened(currentCell->m_xcoord, currentCell->m_ycoord - 1, currentCell->G + 1, currentCell);
			//Diagnal left-up
			//PathOpened(currentCell->m_xcoord -1, currentCell->m_ycoord + 1, currentCell->G + 1.414f, currentCell);
			//Diagnal right-up
			//PathOpened(currentCell->m_xcoord + 1, currentCell->m_ycoord + 1, currentCell->G + 1.414f, currentCell);
			//Diagnal left-down
			//PathOpened(currentCell->m_xcoord - 1, currentCell->m_ycoord - 1, currentCell->G + 1.414f, currentCell);
			//Diagnal right-down
			//PathOpened(currentCell->m_xcoord + 1, currentCell->m_ycoord - 1, currentCell->G + 1.414f, currentCell);
			for (int i = 0; i < m_openList.size(); i++) {
				if (currentCell->m_id == m_openList[i]->m_id) {
					m_openList.erase(m_openList.begin() + i);
				}
			}
		}
	}
}

Vector2 PathFinding::NextPathPos() {//pass object somehow
	int index = 1;
	Vector2 nextPos;
	nextPos.getX = m_pathToGoal[m_pathToGoal.size() - index]->getX;
	nextPos.getY = m_pathToGoal[m_pathToGoal.size() - index]->getY;

	Vector2 distance = nextPos - pos; //objects current posistion
	if (index < m_pathToGoal.size()) {
		if (distance.Length() < radius) { //objects radius
			m_pathToGoal.erase(m_pathToGoal.end() - index);
		}
	}
	return nextPos;
}