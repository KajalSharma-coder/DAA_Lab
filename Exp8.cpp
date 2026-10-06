#include <iostream>
#include <vector>
#include <string>

using namespace std;

int LCS(string &s1, string &s2, vector<vector<int>> &b) {

    int m = s1.size();
    int n = s2.size();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 0; i <= m; i++) {
        dp[i][0] = 0;
    }

    for (int j = 0; j <= n; j++) {
        dp[0][j] = 0;
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {

            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                b[i][j] = 0;
            }
            else if (dp[i - 1][j] > dp[i][j - 1]) {
                dp[i][j] = dp[i - 1][j];
                b[i][j] = 1;
            }
            else {
                dp[i][j] = dp[i][j - 1];
                b[i][j] = 2;
            }
        }
    }

    return dp[m][n];
}

int main() {

    string s1, s2;

    cout << "Enter first string: ";
    cin >> s1;

    cout << "Enter second string: ";
    cin >> s2;

    vector<vector<int>> b(m + 1, vector<int>(n + 1, 0));

    int length = LCS(s1, s2, b);

    cout << "\nLength of LCS = " << length << endl;

    int i = s1.size();
    int j = s2.size();

    string lcs = "";

    while (i > 0 && j > 0) {

        if (b[i][j] == 0) {
            lcs = s1[i - 1] + lcs;
            i--;
            j--;
        }
        else if (b[i][j] == 1) {
            i--;
        }
        else {
            j--;
        }
    }

    cout << "LCS = " << lcs << endl;

    return 0;
}