#include <iostream>
#include <stack>

using namespace std;

int n, m;
int counter = 0;

pair<int, int> current;
stack<pair<int, int>> S;

static pair<char, bool> board[2000][2000];

void visit(pair<int, int> x) {

    S.push(x);

    while(!S.empty()) {

        current = S.top();
        board[current.first][current.second].second = true;
        S.pop();

        switch (board[current.first][current.second].first) {
            case 'B':
                if (current.first != n-1
                && !board[current.first + 1][current.second].second
                && board[current.first + 1][current.second].first != 'A')
                {
                    if (board[current.first + 1][current.second].first == 'C'
                        || board[current.first + 1][current.second].first == 'D'
                        || board[current.first + 1][current.second].first == 'F')
                        S.push(pair<int, int>(current.first + 1, current.second));
                }
                if (current.second != 0
                    && !board[current.first][current.second - 1].second
                    && board[current.first][current.second - 1].first != 'A')
                {
                    if (board[current.first][current.second - 1].first == 'D'
                        || board[current.first][current.second - 1].first == 'E'
                        || board[current.first][current.second - 1].first == 'F')
                        S.push(pair<int, int>(current.first, current.second - 1));
                }
                break;
            case 'C':
                if (current.first != 0
                && !board[current.first - 1][current.second].second
                && board[current.first - 1][current.second].first != 'A')
                {
                    if (board[current.first - 1][current.second].first == 'B'
                        || board[current.first - 1][current.second].first == 'E'
                        || board[current.first - 1][current.second].first == 'F')
                        S.push(pair<int, int>(current.first - 1, current.second));
                }
                if (current.second != 0
                && !board[current.first][current.second - 1].second
                && board[current.first][current.second - 1].first != 'A')
                {
                    if (board[current.first][current.second - 1].first == 'D'
                        || board[current.first][current.second - 1].first == 'E'
                        || board[current.first][current.second - 1].first == 'F')
                        S.push(pair<int, int>(current.first, current.second - 1));
                }
                break;
            case 'D':
                if (current.first != 0
                && !board[current.first - 1][current.second].second
                && board[current.first - 1][current.second].first != 'A')
                {
                    if (board[current.first - 1][current.second].first == 'B'
                        || board[current.first - 1][current.second].first == 'E'
                        || board[current.first - 1][current.second].first == 'F')
                        S.push(pair<int, int>(current.first - 1, current.second));
                }
                if (current.second != m-1
                && !board[current.first][current.second + 1].second
                   && board[current.first][current.second + 1].first != 'A')
                {
                    if (board[current.first][current.second + 1].first == 'B'
                        || board[current.first][current.second + 1].first == 'C'
                        || board[current.first][current.second + 1].first == 'F')
                        S.push(pair<int, int>(current.first, current.second + 1));
                }
                break;
            case 'E':
                if (current.first != n-1
                && !board[current.first + 1][current.second].second
                && board[current.first + 1][current.second].first != 'A')
                {
                    if (board[current.first + 1][current.second].first == 'C'
                        || board[current.first + 1][current.second].first == 'D'
                        || board[current.first + 1][current.second].first == 'F')
                        S.push(pair<int, int>(current.first + 1, current.second));
                }
                if (current.second != m-1
                && !board[current.first][current.second + 1].second
                && board[current.first][current.second + 1].first != 'A')
                {
                    if (board[current.first][current.second + 1].first == 'B'
                        || board[current.first][current.second + 1].first == 'C'
                        || board[current.first][current.second + 1].first == 'F')
                        S.push(pair<int, int>(current.first, current.second + 1));
                }
                break;
            case 'F':
                if (current.first != 0
                && !board[current.first - 1][current.second].second
                && board[current.first - 1][current.second].first != 'A')
                {
                    if (board[current.first - 1][current.second].first == 'B'
                        || board[current.first - 1][current.second].first == 'E'
                        || board[current.first - 1][current.second].first == 'F')
                        S.push(pair<int, int>(current.first - 1, current.second));
                }
                if (current.second != 0
                && !board[current.first][current.second - 1].second
                && board[current.first][current.second - 1].first != 'A')
                {
                    if (board[current.first][current.second - 1].first == 'D'
                        || board[current.first][current.second - 1].first == 'E'
                        || board[current.first][current.second - 1].first == 'F')
                        S.push(pair<int, int>(current.first, current.second - 1));
                }
                if (current.first != n-1
                && !board[current.first + 1][current.second].second
                && board[current.first + 1][current.second].first != 'A')
                {
                    if (board[current.first + 1][current.second].first == 'C'
                        || board[current.first + 1][current.second].first == 'D'
                        || board[current.first + 1][current.second].first == 'F')
                        S.push(pair<int, int>(current.first + 1, current.second));
                }
                if (current.second != m-1
                && !board[current.first][current.second + 1].second
                && board[current.first][current.second + 1].first != 'A')
                {
                    if (board[current.first][current.second + 1].first == 'B'
                        || board[current.first][current.second + 1].first == 'C'
                        || board[current.first][current.second + 1].first == 'F')
                        S.push(pair<int, int>(current.first, current.second + 1));
                }
                break;
            default:
                break;
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;


    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> board[i][j].first;
            board[i][j].second = false;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!board[i][j].second && board[i][j].first != 'A') {
                visit(pair<int,int>(i, j));
                counter += 1;
            }
            board[i][j].second = true;
        }
    }
    cout << counter;
    return 0;
}
