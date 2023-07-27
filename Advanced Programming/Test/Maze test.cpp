#include <iostream>
#include <ctime>

class MazeGenerator {
protected:
    static constexpr int GRID_WIDTH = 31;
    static constexpr int GRID_HEIGHT = 15;
    static constexpr char WALL = '#';
    static constexpr char PASSAGE = ' ';
    static constexpr int NORTH = 0;
    static constexpr int EAST = 1;
    static constexpr int SOUTH = 2;
    static constexpr int WEST = 3;

    char grid[GRID_WIDTH * GRID_HEIGHT];

public:
    MazeGenerator() {
        std::srand(std::time(nullptr));
        GenerateMaze();
        PrintGrid();
    }

    void GenerateMaze() {
        ResetGrid();
        Visit(1, 1);
    }

    void ResetGrid() {
        for (int i = 0; i < GRID_WIDTH * GRID_HEIGHT; ++i) {
            grid[i] = WALL;
        }
    }

    int Index(int x, int y) const {
        return y * GRID_WIDTH + x;
    }

    bool IsInBounds(int x, int y) const {
        return (x >= 0 && x < GRID_WIDTH) && (y >= 0 && y < GRID_HEIGHT);
    }

    void Visit(int x, int y) {
        grid[Index(x, y)] = PASSAGE;

        int dirs[] = {NORTH, EAST, SOUTH, WEST};
        for (int i = 0; i < 4; ++i) {
            int r = std::rand() % 4;
            std::swap(dirs[i], dirs[r]);
        }

        int dx[] = {0, 1, 0, -1};
        int dy[] = {-1, 0, 1, 0};

        for (int i = 0; i < 4; ++i) {
            int x2 = x + dx[dirs[i]] * 2;
            int y2 = y + dy[dirs[i]] * 2;

            if (IsInBounds(x2, y2)) {
                if (grid[Index(x2, y2)] == WALL) {
                    grid[Index(x2 - dx[dirs[i]], y2 - dy[dirs[i]])] = PASSAGE;
                    Visit(x2, y2);
                }
            }
        }
    }

    void PrintGrid() const {
        for (int y = 0; y < GRID_HEIGHT; ++y) {
            for (int x = 0; x < GRID_WIDTH; ++x) {
                std::cout << grid[Index(x, y)];
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    MazeGenerator mazeGenerator;
    return 0;
}
