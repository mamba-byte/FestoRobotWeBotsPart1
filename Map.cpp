#include "Map.h"
#include <algorithm>


Map::Map(int sizeX, int sizeY) : dimX(sizeX), dimY(sizeY)
{
    grid.resize(dimY, std::vector<int>(dimX, 0));
}

void Map::clearMap() {
    for (auto& row : grid) {
        std::fill(row.begin(), row.end(), 0);
    }
}

void Map::insertPoint(const Point& point) {
    if (point.getX() >= 0 && point.getX() < dimX &&
        point.getY() >= 0 && point.getY() < dimY)
    {
        grid[static_cast<int>(point.getY())][static_cast<int>(point.getX())] = 1;
    }
}

int Map::getGrid(int x, int y) const {
    if (x >= 0 && x < dimX && y >= 0 && y < dimY) {
        return grid[y][x];
    }
    return -1;
}

void Map::setGrid(int x, int y, int value) {
    if (x >= 0 && x < dimX && y >= 0 && y < dimY) {
        grid[y][x] = value;
    }
}

int Map::getNumberX() const {
    return dimX;
}

int Map::getNumberY() const {
    return dimY;
}

void Map::addGridSize(int deltaX, int deltaY) {
    dimX += deltaX;
    dimY += deltaY;
    grid.resize(dimY, std::vector<int>(dimX, 0));
    for (auto& row : grid) {
        row.resize(dimX, 0);
    }
}

void Map::setGridSize(int sizeX, int sizeY) {
    dimX = sizeX;
    dimY = sizeY;
    grid.resize(dimY, std::vector<int>(dimX, 0));
}

void Map::printInfo() const {
    std::cout << "Grid dimensions: " << dimX << " x " << dimY << std::endl;
}

void Map::showMap() const {
    for (const auto& row : grid) {
        for (auto cell : row) {
            std::cout << (cell == 0 ? '.' : 'x') << " ";
        }
        std::cout << std::endl;
    }
}
