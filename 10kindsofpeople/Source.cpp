#include <iostream>
#include <vector>
#include <string.h>


using namespace std;

int floodfill(int map[], int visited[], long& height, long& width, int x, int y, int& color, int& originalVal) {
	if (x < 0 || x >= height || y < 0 || y >= width) return 0;
	if (visited[x*width +y] > 0) return 0;
	if (map[x*width + y] == originalVal) {
		visited[x*width + y] = color;
		floodfill(map, visited, height, width, x + 1, y, color, originalVal);
		floodfill(map, visited, height, width, x - 1, y, color, originalVal);
		floodfill(map, visited, height, width, x, y + 1, color, originalVal);
		floodfill(map, visited, height, width, x, y - 1, color, originalVal);
		
	}
	return 1;
}


int main() {
	

	long height, width;
	cin >> height >> width;

	int* map = new int[height*width]();
	int* visited = new int[height*width]();
	char a;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			cin >> a;
			map[i*width +j] = a - '0';
		}
		cin.ignore();
	}

	int color = 1;

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (floodfill(map, visited, height, width, i, j, color, map[i*width+j])) color++;
			}
		}

	int n;
	cin >> n;

	int r1, c1, r2, c2;

	while (n--) {
		cin >> r1 >> c1 >> r2 >> c2;
		r1--;
		r2--;
		c1--;
		c2--;
		if (map[r1*width + c1] != map[r2*width + c2]) cout << "neither\n";
		else {
			if (visited[r1*width + c1] == visited[r2*width + c2]) {
				cout << (map[r1*width + c1] ? "decimal\n" : "binary\n");
			}
			else cout << "neither\n";
		}
	}

	return 0;
}