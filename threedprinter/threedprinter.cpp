#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

class Face;

vector<double> substract(vector<double> a, vector<double> b);
double dot(vector<double> a, vector<double> b);
vector<double> cross(vector<double> a, vector<double> b);
double tetrahederVolume(vector<double> a, vector<double> b, vector<double> c, vector<double> d);
vector<double> getCenter(vector<Face> faces);


class Face {
public:
	vector<vector<double>> vertex = vector<vector<double>>();
	int v = 0;
	vector<double> center;

	void addPoint(double x, double y, double z) {
		v++;
		vector<double> temp;
		temp.push_back(x);
		temp.push_back(y);
		temp.push_back(z);
		vertex.push_back(temp);
	}

	void calculateCenter() {
		center = vector<double>(3, 0);
		for (auto i : vertex) {
			center[0] += i[0];
			center[1] += i[1];
			center[2] += i[2];
		}
		center[0] /= v;
		center[1] /= v;
		center[2] /= v;
	}
	double baseCenterVolume(vector<double> c) {
		double volume = 0;
		auto a = vertex[0];
		for (int i = 1; i < vertex.size()-1; i++) {
			volume += tetrahederVolume(a, vertex[i], vertex[i + 1], c);
		}
		return volume;
	}
};

vector<double> substract(vector<double> a, vector<double> b) {
	for (int i = 0; i < a.size(); i++) {
		a[i] -= b[i];
	}
	return a;
}
double dot(vector<double> a, vector<double> b) {
	double sum = 0;
	for (int i = 0; i < a.size(); i++) {
		sum += a[i] * b[i];
	}
	return sum;
}

vector<double> cross(vector<double> a, vector<double> b) {
	vector<double> product;
	product.push_back(a[1] * b[2] - a[2] * b[1]);
	product.push_back(a[2] * b[0] - a[0] * b[2]);
	product.push_back(a[0] * b[1] - a[1] * b[0]);
	return product;
}

double tetrahederVolume(vector<double> a, vector<double> b, vector<double> c, vector<double> d) {
	double V = abs(dot(substract(a, d), cross(substract(b, d), substract(c, d)))) / 6;
	return V;
}

vector<double> getCenter(vector<Face> faces) {
	vector<double> center = vector<double>(3, 0);
	for (auto i : faces) {
		center[0] += i.center[0];
		center[1] += i.center[1];
		center[2] += i.center[2];
	}
	center[0] /= faces.size();
	center[1] /= faces.size();
	center[2] /= faces.size();
	return center;
}

int main() {

	/*
	Plan:
	for hver polyhedra:
		lagre alle faces
		finn ut midtpunktet til polyhedraen
		lag tetraheder fra face til midtpunkt
		legg sammen volum til tetrahedene

	legg sammen volumene til alle polyhedraene

	*/

	int n;
	cin >> n;

	double volume = 0;
	
	// polyhedra
	for (int i = 0; i < n; i++) {
		int f;
		cin >> f;
		//face
		vector<Face> faces;
		for (int j = 0; j < f; j++) {
			Face face;
			int v;
			cin >> v;
			for (int k = 0; k < v * 3; k += 3) {
				double x, y, z;
				cin >> x >> y >> z;
				face.addPoint(x,y,z);
			}
			face.calculateCenter();
			faces.push_back(face);
		}
		vector<double> center = getCenter(faces);
		for (auto a : faces) {
			volume += a.baseCenterVolume(center);
		}
	}
	cout << setprecision(2) << fixed << volume << endl;
	int a;
	cin >> a >> a;
}