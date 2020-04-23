    #include <iostream>
    #include <string>

    using namespace std;

    int main() {
        int a;

        string s = "simon says";
        cin >> a;
        cin.ignore();

        while (a--) {
            string b;
            getline(cin, b);
            if (b.size() > 11 && b.compare(0, 10, s) == 0) {
                cout << b.substr(11, string::npos) << "\n";
            }
            else cout << "\n";
        }


        return 0;
    }
