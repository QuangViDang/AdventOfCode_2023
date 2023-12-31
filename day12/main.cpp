#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <cstring>
#include <unordered_map>
#include <iomanip>
#include <queue>
#include <numeric>
#include <map>
#include <sstream>
#include <cassert>

using ll = long long;
using ld = double;

#define eb emplace_back
#define fi first
#define se second

using namespace std;

const int nm = 202;

string s;
vector<int> a;
ll dp[nm][nm][nm];

ll calc(int i, int j, int k) {
    ll &res = dp[i][j][k];
    if (res != -1) return res;
    if (i == s.length()) {
        if (j >= a.size()) return res = (k == 0);
        if (j + 1 == a.size()) {
            return res = (k == a.back());
        }
        return res = 0;
    }
    if (s[i] == '.') {
        if (k) {
            if (j < a.size() && k == a[j]) return res = calc(i + 1, j + 1, 0);        
            else return res = 0;
        } else {
            return res = calc(i + 1, j, 0);
        }
    }
    if (s[i] == '#') {
        return res = calc(i + 1, j, k + 1);
    }
    res = calc(i + 1, j, k + 1);
    if (k) {
        if (j < a.size() && k == a[j]) res += calc(i + 1, j + 1, 0);
    } else {
        res += calc(i + 1, j, 0);
    }
    return res;
}

ll f() {
    memset(dp, -1, sizeof(dp));
    return calc(0, 0, 0);
}

void unfold() {
    string tmp = s;
    for (int i = 0; i < 4; ++i) tmp += "?" + s;
    s = tmp;
    int n = a.size();
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < n; ++j) a.eb(a[j]);
    }
}

int main() {
    // Dữ liệu đầu vào
    string input = R"(??????.??#. 2 3
??.?###????????? 2 4 4
?????????.??##? 1 2 1 1 5
?##?.????.?#?.?#? 3 1 1 2 2
?#?.#?##???? 3 1 4
??#????#?? 4 4
???????#?.??? 2 2
?.???????#? 2 3
.?????.???? 1 1
#??????????# 1 3 3 1
??.??.??..#? 2 1 1 1
.??#?#?#?? 1 4
#???????.?? 6 1
???#???#??# 1 2 5
.#?.??#.?#? 1 2 1
?#?#??????.#.? 9 1
#?????.???? 5 2
?????????????? 1 1 3 5
.???.??##?.???.#?? 2 3 3 1
?#??#???#??????? 2 6 1 3
??.??#???.?# 1 1 4 1
?#????###.???#?? 8 6
?????????..? 2 1 1 1
??.??####..? 2 6 1
.????##???????? 2 4 1 1
?????.?##???..??? 1 3
??.???.?????#??.? 1 4
#?#?###?..?.#??..#?. 8 1 1 2
??#??????#??#???? 9 5
???##???##?.??#???. 2 3 2 1 1 2
?#?#???.?? 6 1
?????#?????#? 1 8
??????.???##?#??#.? 2 1 1 8
?????#.???? 1 1 3
??????.??. 1 1 1
.?.##????#?#??#?.? 9 2
???#??????#??. 1 11
??#?.#?.?? 3 2 1
#????.???#.???? 1 2 3 2
.??.???.??#? 2 3 3
??.????????#?.??? 1 8 2
.?#??#?.???.. 6 1
?????.????#.? 1 1 4
.??#??.??????? 4 4 1
?.#???????.?????? 3 1 1 2 1
##.?????#??#???#?# 2 1 1 1 5 1
...??????.#???#??#? 1 1 1 1 7
???##???????#??? 7 2 1 1
##.????????????.. 2 9 1
??##?.????#? 4 1 3
?#??????#. 1 1 1
?#...?.?##?#?????? 1 1 4 1 1 1
?#????#???#??.?##? 3 7 4
.#???##??###???? 2 10
.?#?.?#??????. 1 7
#.?.?????###.? 1 1 7 1
???..#.??? 1 1 1
???###????????#?#. 12 4
????..??.?.???. 2 1 1 1 2
???.#??????#? 1 8
??#.???.?..??##?.. 1 5
??#????.????.??. 5 1 1 1
##???..#.???#???. 2 2 1 5
??##?.?##.???#.???.? 4 3 1 1 2 1
?????????????.# 2 1 1 1 1
.???#?#??#?.???# 1 6 1 1
?#?#???.??#?? 3 1 4
???#???#??#??#??# 1 3 1 5 1
.????.#??# 3 4
?????.????### 4 6
????#??.#????.??? 2 2 3 1 1
???#?...?#???. 4 5
?????..?#?.? 1 1 2 1
???.??###??##? 1 9
?.?#?#????.??#?.??# 1 7 2 1
?##???..???##.?#.. 4 5 1
????#.??#. 1 1
?.??#?.??#? 1 4
???#????????#??.? 1 2 2 5 1
?##?????#??#???.???? 4 3 4 1 2
???#???.??.?## 5 2
?????#???#?#.????#? 2 8 2 1
..??#?..??? 2 1 1
.??##??#????###?? 9 4
???.??????????? 1 3 1 3
.#?##??#?##????#?? 10 1 3
.???#.?##?? 1 1 3
?#??#?.??? 2 1 2
.?#?.?????? 2 3 1
?.#.???#.? 1 1 1
??#?????#?#?. 5 4
??.?#?#.???? 1 3 2 1
???????#?#??????? 3 6 5
?????????.#???? 7 4
.?###??.?????#?? 6 5
??#?????#####?.# 3 9 1
.#???.???.?? 3 1 2
??#?????????#? 9 2
?????????#?? 1 2 1 2
.?????#???.??? 8 1
?#?.?#?????#???#. 1 1 8
???#??#?###?#??#? 1 14
????#?.??# 1 2 1
?#####.?#?????. 6 1 2
#?????.??#? 5 1 2
?#?????.#?#? 6 1 1
?.????#?????####?.. 1 3 7
?????#???#????##? 1 3 8
..????????..?? 4 1 2
??.#?#???.. 2 3 1
##?#?.???#?.. 5 1 1
?#?#??..#?#.? 2 3 3 1
?#?#????...??????? 1 1 2 3 1 1
..?#???..??? 5 1
??#?.???.???? 2 3 3
..??#?????##??? 6 5
##???..##???##?? 5 2 3
#???#???#####????#. 1 1 9 2
#.??????#.?##?##??? 1 2 1 2 6 1
???.#????? 1 1 1
????.???..???. 2 1 1 2
.?#??.??.#.#. 3 1 1 1
??????.?##?? 1 1 1 3
?#??#??#?.??#?. 1 1 2 1 2
??????##?? 1 1 5
.???#????? 1 1 1
?#?.??????. 1 1 2
?.?.?#??????.??#. 1 2 1 3
.??#??????.??.#.? 8 1 1
???#?.???###? 2 1 3
?##?.?.???.???????#? 3 2 1 5
?..????#???##?? 1 2 1 4 1
???##???..???.?? 5 2
..##????##?##?.?.??. 11 1
??.??..?#???? 2 1 1 1
??.#???#?#???? 1 1 6 1
?#??.??#???# 1 1 3 1
???.??.?????? 1 2 1 1
???.#??.?? 2 2 1
???.?#?.???????? 1 3 5
?????#???#??##. 1 6 1 3
.#??.?.?.? 2 1 1
#?##??#?????? 7 3
??.?.???#??????? 1 1 6 1
?????#.?#???..??? 5 3 1
#??#???????.????#.# 4 1 2 1 3 1
.???????.?? 4 1
...??#?#?#?????# 5 4
#...??#?????#?#?.? 1 3 7
????.#?.#.??##??? 1 1 1 4 1
???..?#?????#??? 1 1 2 2 1
?????..??##? 1 4
.#??????#??#?? 1 1 1 6
?..?#?????#???. 3 3
??.##?#???????#. 1 7 2 1
?????##..#?.?. 5 1 1
..??????##??? 4 2
?????.?????. 2 1 1 1
..???##?#???.??#.?#? 1 6 2 3
????????#??????. 1 1 7
#??#???#?#.???#?#?? 10 6
.#?????#??.?# 1 2 2 1
.?..??.????# 1 1 4
????#?#??.. 2 6
.?#..????. 2 1
?????#?#?#???????.?? 2 8 4 1
#?????#???? 1 5 2
???.???#?###?#?##??? 2 13 1
?#????.???##.# 2 1 4 1
??????????.??. 3 4 1
???????.#???.?#??? 1 3 1 1 2 1
.??.#?###?. 1 6
.#.?#????#? 1 1 3
?????????##.?# 2 4 2 2
????.?..??. 1 2
???????#?? 1 1 1
???????#??. 5 1
??#.??#?????## 1 1 1 5
???.?.?#?.? 1 2 1
.???##???? 2 6
#?.?#?.????#???#? 1 2 1 2 4
???.?####?#? 2 6
???.##.?.#?# 2 3
?.???#?#??# 1 5 1
?.??#?##?.##?#?#?. 6 7
..?#??..?. 3 1
???#?#??#.??#..???# 1 1 4 2 1 1
#????.?????? 1 1 3
?#?#?.??##?#??? 5 1 2 2
..?#?#?#????#?? 7 4
???.??#??????..????? 3 1
????#???.????#?????? 1 3 8 1
.????#????#??##???## 6 1 8
??.#????????.? 1 1 2 2
???#????#?##?????? 1 1 1 4 1 1
#.??.????#??###...? 1 1 1 6 1
???#??##??#?? 1 5 2
#.#???#??????.?? 1 3 2 1 1
??#..?.#?? 2 1 1
..??????#. 1 2
#??????#??.???.???#? 4 1 3 1 1 2
?.#??????##?#??#?? 3 8
?#???.????.????? 1 2 2 2 1
???????#???.?? 5 1 1 1
..?????#?#??#? 1 3 2
#??.####?.?? 1 1 4 2
???????#??###??#?. 1 1 13
.?#.??#?..??#??#? 1 2 1 5
#?#?#??.??.. 1 5 1
.????????.?.??. 2 1 1 1 1
##???????.? 4 1 1
#?#?.??##??????.#?. 4 5 1 1 1
#?#????#??.???? 1 1 1 3 3
???.?????.##??## 2 6
...???#?????? 1 1
##?#??????????.??. 8 3
..??#?????#??????#? 4 5 3
????????#??? 1 2 4
?.#??.??##?.?. 3 3
???.??#.?# 3 3 1
?#????.?.? 1 1
?#???????#????? 4 3 3 1
.?.??#????.?.. 7 1
????#.?.#..? 3 1 1 1
.??#?#?????.?????#?. 5 2 1 1 1 1
??????.?????#?.??# 4 4 1
???###.?#?#????? 1 4 1 6
???????.???#??? 6 3
??#?###?????????? 6 1 1 3
.??#.???##??#????#?. 1 4 2 4
#.??##?#??????#????? 1 10 2 1 1
.??.#??#????#? 1 1 5 1
.?#????..????? 4 1 4
????..?#??... 1 3
?.????#??? 1 1 5
??#?.#??.??????? 4 3 2 2
?#????#???????##?? 3 1 2 1 2 2
##?.?#.??? 2 2 1
?.????????.?##???.?. 7 4
..#???.?????#? 2 7
#?.???..#??? 2 3 1 2
????????##. 1 3
?????#??#?. 1 5
???????#?#????.??? 10 2
????????#????????. 7 1
???...#??# 2 1 1
??.#???#?#?###?.#? 2 2 8 2
#???#?????? 1 3 2
.?.?..???#???? 1 4
????.##???#?###?? 1 1 4 1 5
??#???#??# 2 2 1
??#?##??????? 7 1
??#?#.##?#? 1 3 4
??#???#?..?????.?? 6 2
?.?????.?#?#??#? 1 1 7
#??.???#???##??#. 1 9
?.?.?..?.??? 1 1 1 3
.?????????#.???? 1 1 1 1 3
?#???????? 5 1 1
.#?##??#?. 4 1
.?#????#??. 3 3
.?#.??#??###?? 1 8 1
???#??.???.? 4 1
?.#????##???? 1 2 4 1
.???##.????#??##.??? 5 2 1 3 2
???##?##???? 8 1
?###????#????.?? 5 2 1
#?.???????? 1 4
???#.?#??. 3 1
????.#?#?##?????? 2 1 8
.##?.?##?????# 2 3 2
.?#..????##??????##. 1 2 4 4
?.?#???###? 1 2 4
??????#??????#???? 7 5
??##?#..??? 6 1
??????.???#. 4 1 1
.??.?.????? 2 1 1
?????#.?##?#?##??? 1 1 10
#?##?#??.? 1 5 1
?.?#?#???..???? 1 5 1 1
?..????##???????..?. 1 2 9 1
?#?#..?.???#?#? 1 1 1 4
?#.??????# 1 5
.??????#???#?##???. 4 9
.?.???????## 1 2 1 2
????.#?.????# 1 2 5
?????.?????. 1 1 3
..??..???? 2 1
??#.??#??##??#? 1 1 7 2
??????#??#?.??.#.? 6 1
????.????#?#???.#??? 1 1 1 6 4
?.??.#??????????? 1 1 2 4 1
???..????? 1 1 1
.?#?????.?#.??#?.. 3 1 1 3
?#??????#?#??##??# 6 3 3 1
#?#???.??.?????.? 5 1 5
???????##?.????#???? 6 5
??##???#???? 4 5
?.##????#???.???#?? 3 5 4
??#?#?.??.??## 5 2
??.?????.#? 2 2
?#??##??#?????#???.? 6 2 1 5 1
????#?#.?? 1 3 1
??.#??.??#??????.?? 2 3 6
?.???#.?????#??# 1 1 1 1 4
?#??????#?? 2 1 4
??????.???#?? 2 2 3 1
??.??#..##? 1 1 2
???.?????. 3 2
?..#???#???????#???? 8 4
??#??????##? 3 1 4
.?#??#????????.?? 1 7 1
??#??#?..?#??###? 1 3 8
..#????###? 1 4
?#.???#???..?.?# 2 6 1 2
?.??#?##?.???#??? 1 1 2 1 3
?.?????#??#???.??? 4 1 4
?.???##???#????? 1 8
?#??#?????????##?##? 7 2 5
.??..?????#?###??#? 2 1 1 8
#???##?.?.???##??##? 2 3 5 2
???#..?#??#?? 1 1 5
??????.????. 4 2
?#??.?????.?? 1 3 1 1
#?#?.?#?.???# 4 1 4
?????......?.???.?.. 1 1
??.?????#??##?? 1 4 2 4
..?#???..??.??# 4 3
.?.??#????.??. 1 3 1
?#??.#?????.?. 2 5
.?..?#?#???##?? 1 10
?.???????###?#?. 2 6
??#????.?.????#.. 3 1 1 2 1
?#??????.?#?#.? 3 1 4
?#?##??#??.?##. 6 3 2
#?###???.???...??#?# 5 1 1 1 1 3
.?#????????????. 2 3 1 1 1
.?#??#??#??.#???? 1 2 3 1 1
??#??.????.#? 3 4 2
##...?#??..??###???? 2 2 8
##??#?#?.?#.????? 8 1 4
##???.???? 2 1 1
#??##?.????#????.??. 1 4 1 3 2 1
?.?.?#?##?###?? 1 9
?????##.?#?? 1 5 1 1
???..#?#???#???. 1 1 4 1 1
??##?.????????? 4 3 2
#?#????.???.???#. 1 1 1 1 4
???..????#? 1 3 1
?##????##???.??? 6 2 1 1
#???.#..#?#?? 1 1 1 3
.??????.?????# 6 3 1
.??.?##??????#?.#?#? 1 5 1 1 4
#?.?.?????.?#? 1 5 1
????????#???#?. 1 1 1 3 1
.??????#?#?.?#?##?? 1 5 7
.????#??#??#.??.? 11 1
?#??..#.?????### 3 1 3 3
???.?#.??.?#. 2 1 1 1
#.??????????#?.#### 1 10 4
?????.???# 1 2
???..???????## 1 1 3 2
???????#.? 2 1 1
#????##?????? 1 1 5 1
.???.??#???..?? 1 1 4 1 1
?..?...???#??? 1 2 1
#???.?#??#????? 1 1 1 7
?.#??.##????? 1 6
.?????#.?.? 2 1
?#???????#?#??.?.? 3 9
##????????#?##.#.# 6 1 4 1 1
???.?#?##.??#. 5 3
?..?..#?##.? 1 4 1
.?#??#??.?##????#?. 6 2 1 2
?#??#.?#.?.????? 3 1 1 1 1
???????.?#??????# 3 2 6 1
?#?..??.##?#?.?? 2 5 1
?#...#??#? 1 1 1
?.#????##???#?. 3 7
??..#??##? 1 2 3
??????.?##?? 2 3
????.#???????#?#?. 2 1 1 6
???????#??? 1 1
?...????.???# 3 4
.#??##??.????. 1 2
?????.?#???? 1 2 6
?#???#?.#? 2 2 2
??#??????? 5 1
?.????##??.?.???... 3 1
..##??#??.? 5 1
???.??#?##???? 2 1 4 2
???????#????????..? 8 1 1 1
??#.???.???#???? 2 1 1 2 1
?#?##.??#??????#? 4 3 2 1 2
??????#.???? 1 3 3
?##.?#.??#?.??????#? 3 2 4 2 3
.#?#???#??# 3 1 1
.??.???????## 1 1 4
#??#??.#???# 1 4 2 1
???#?#??.. 1 1 1
????#.?????.. 4 1 1
??????.???.?? 1 2 1 1
#.##??#?.?#..??#?.? 1 6 2 2 1
???.??..?#?.. 3 1 3
????#????#?#####??#? 2 1 9 3
??#?#??.#?##??##.. 4 8
??????#?#???#?.?.? 12 1
?..?????##???#? 1 12
.#????#??#.? 1 6 1
???#?#??#?#??????? 1 1 1 1 4 3
?.??#.??.??? 1 1 2
???#???#.??#?? 5 1
.????#.?#?? 1 3 4
?#.#?#?????##.?# 1 5 3 2
???????#?????????. 2 1 5 1 2
#?#?#?#??#.#???.???? 8 1 1 1 1 1
?????#??#??.?# 2 8 1
?#??#???#??.?#.?? 9 2 1
?????##?#?.?. 1 6 1
???????.?...?#? 1 4 1 2
?.#????.????????.?.? 3 1
#????????#????#???.? 1 10 1 2
???.#???.#?#?????# 3 1 1 9
.?????.?????? 1 1 2 1
#?.??##??????#? 2 3 4
?????.??????.? 2 1
?#?#?#??#?. 1 7
.????.???#?.???# 3 5 2 1
??#????##?. 3 4
?.???????????#??#??. 2 5 2 1
?????#??#???..???? 1 3 1 1 2
.????#?????.. 1 3 3
?##???????? 4 3
??#??#?????#? 2 2 1 1
?#?????#?#?#..#??.?# 2 3 5 1 1 1
?????#???.?#???##??. 6 1 9
???????#??#??#. 1 1 9
##????????.??..#?# 4 1 3 1 1 1
???#.??.???. 1 1 1 1
?.?#????.#??? 1 6 1 1
?????#??????.? 1 3 3
?#????.???# 3 1 4
#??#?#?#??.?#? 8 1 1
?????????#??? 2 5
??#?.??????.###?#?. 4 1 5
#?.?#.??#????? 1 1 1 4
#.???.??#???? 1 1 4 1
?#??????#??? 2 4
?#?????????#??#.???? 5 1 3 1 1 1
??????##??????#?#??? 1 8 7
#?#??.????.#?#? 3 1 1 1 1
?.??#.#?##. 1 1 4
???.??#??#.???? 1 1 6 1 1
#?????#??# 1 4 2
?.?????.?#????? 1 1 1 4 1
.?....??.#?. 1 2
.#???#????#.???##??. 10 5
???????.#? 5 2
?.##??..????# 4 1 1
??#?????#???.??? 6 4 1 1
??.?.?##?.???.?? 1 1 4 3
?????.???.????#? 1 2 2 1 4
?..??##?#..???.? 1 5 1 1
???.???#??.#?.????? 3 4 2 1
???#???#?? 1 4
###??..???..?. 5 2
#????????#? 1 3 4
??.???????.?#?.?# 1 1 2 2 2
??.??.?..?????. 1 2 1 2 1
????#???.?? 1 5 2
#?.?..?#??##?.???# 2 1 7 1 2
.#??..#.??#????## 1 1 9
??????.???#????? 2 1 7
?###???.??? 3 2
?.#?.?##?? 1 1 2
???###???.??#?.??? 6 2 3
?????#??.????????? 4 1 1 2 1 1
?#.?##??##?#. 1 7 1
??.???????#???##? 1 1 1 8
.???????.????????? 5 7
..#?????????#???#.?? 1 2 8
#??##????#????#. 2 4 2 3
.??#???#??? 2 3
?#???#???## 1 1 3
???#?#??.?#? 5 1
??##??.?.????#? 5 1 1 2
?##?#??#??????## 8 1 3
?##??#???????? 5 1 1 1
??###?????#???.??#. 1 9 1 1 1
?#.??????# 2 2 3
?#??#???#?.?.?????? 10 1 1 1 1
??#???#??. 1 3
?#??#.???? 2 1 1
???.???#??????.? 2 6 1
#?#?.??.#.??##? 1 2 1 1 5
???????????.?#?. 1 3 1
.?#?#?..#. 4 1
??#?#????. 3 1 1
?#??????#?????? 10 2
#.????????#?#??? 1 2 1 5
?????????#.#? 1 2 1 2
??#?#?##???.?.? 9 1
??????.???.. 5 2
.?????#??? 3 3
??.????????? 1 1 2 1
.#???????##. 1 1 3
?##?#???#?..??#??#?# 3 1 2 6 1
.?..##???? 3 1
??????#.?????? 1 2 1 5
???#.????#?? 1 1 1 4
???#????.? 2 2 1
.#??.???#??????.? 2 7
?.?.###?#?.?. 1 6
?.?##.?.?? 1 2 1
?#...?.?#??#?.???.? 1 4
?????????.??? 4 4 1
??#???????.#. 7 1
?.???#?????????#??? 1 1 7 3 2
.??#.?????.?.?.? 2 1 2 1 1
.???##????#? 6 1
.##?..??????? 3 6
.#??#?#??#?.??.?. 4 5 1 1
?.???.???? 1 1 1
????????????#??? 3 3 5 1
??.???.??? 1 3 1
???##????. 6 1
?##?.???#? 2 1 2
.?.????.??#??#?#? 1 1 6 1
#??????#.? 5 1
.?#????????.? 2 1 1
?.???..???????? 3 3 2
????????#??# 1 1 4 1
##..??#??.?????? 2 4 1 2
???#???#???#????? 1 7 4 1
..????#???????? 3 3
.#?#????##?.??????? 9 2
???#???#??.?##?? 1 2 2 3
???#?????#?.??????? 1 1 5 1 1 1
????#??.???#. 7 1 1
#?.?.?##??????.??#?? 2 1 6 2 1 1
##??????#.##???#?? 5 1 8
?.?.??#?????#?? 1 1 7 1
??#.????#? 1 3
?#?#?#??#??? 7 3
#???#?#?????? 3 4 1 1
#????#??.??? 1 5 1
#?????#?.. 1 1 3
?.?????#?##?.?##? 10 2
?..??????.?.?????..# 1 6 1 1 1
#?#.??.???????#??? 3 9
.???#..?.?.??##. 4 4
?#?#???#.????#?.???# 1 5 6 1 1
?#.#??#??? 1 2 2
??????#????? 2 7
????.??????..?.?? 2 1 1
??##???##??.??#.?? 3 6 1
.?##??????#?#???#?. 12 3
???.?.#???.?#??? 1 3 5
.??#??##??#???# 7 1 1 1
?.??#.??????????#? 1 1 5 1 3
??#????.??..????.? 3 2
?#??#???..? 4 1 1
??????..???.. 3 1
??????#????#?.??.#? 2 4 2 1 2
.???#??..??###??. 6 6
?#??#?????#?????? 5 7
???##?#?#?#?###??. 1 3 5 3 1
#?????#??.??????# 5 1 1 6
?#??????????????? 5 1 1 4
?.?#?????.? 1 2 4
?.???#????#?#???###? 1 1 2 1 1 8
?#??#?#????.?.??.# 1 5 2 1 1 1
?####?#?????? 6 3
???.?????.??????.# 2 1 1 4 1 1
.??#?#??#?.# 5 2 1
.#?.????.#.##??? 1 3 1 5
?..???##??#?? 3 2
?#??###?##???.?? 2 10
.#?#??.??#. 4 3
#??#.?##???? 1 2 6
????#???.??##?##?# 7 4 2 1
.?.????????.#?? 1 1 1 2
#???.#?.???.##?? 4 1 1 1 4
#???#??.?##?.. 5 4
??????#??#.?.??. 1 1 3 1 1
??.???????? 2 7
???..??#???????? 2 3 2 1
.?#????.????#? 4 1 2
?#?..##???#??? 2 9
.?.???#??#?#????.?? 1 10
.??###?...?#?? 4 4
.#??????##??.? 3 5
?.?#.???????#???#. 1 1 1 7
#???#?????# 2 7
???.?#??#??..?.?? 1 7 1 2
??????.??? 1 2 3
?#??#??.#?#???#???#? 1 3 3 1 5
?..##.?.?#???#?#?#?? 1 2 1 1 1 5
??#???????#??? 11 1
#?###??#?.? 8 1
.#?#??###??????..?? 8 1 1
?#.????.??.??. 2 2 1 1
?#??##?.#?? 6 1 1
??#.??#?#?.?#.?. 3 1 1 1 1
#?#.?#?.??..?#? 3 2 1 1
??????????#??. 1 2 5
???#?????# 3 1 2
???.?????????# 2 2 1 3
?#?##???.???.# 5 1 1 1
??????#?#?????#.. 1 7 2
??.?#?.?????# 1 1 2 1
#??#?.?????#?#??#?? 4 1 2 1 3
???????.?? 2 1 1
?#..#??.??#?.# 1 2 3 1
??#????????? 5 1
???#?###.#???..#??? 3 3 1 1 3
?..???#??????.???. 6 2
.??#?#?##???????? 8 4
??????##?#?#??? 10 1 1
??????#?.. 1 3
...??????...#??.? 2 3
????#?#???? 4 4
?#???..?#?#? 4 3
.?????#???????#???? 6 3
?.????#??????##.?? 4 6
??.?.??.?? 1 1 1
????.???#????#??? 2 1 2 3 4
?.?.??#?#??#?#?#?#? 1 12
??#?#.?????.??# 1 1 3 2
#???..??##????? 1 6 1
?????.?.??#?. 1 1 1 3
...??.???#?###??. 2 6
??.???..?? 1 2
.#?.????..? 2 3
#?#??#?..??#????. 1 5 4 1
??.#.#???#.????#?##? 1 1 1 1 1 6
?#??...??#?. 1 4
.?????????. 3 4
???????#?#???????# 12 1
#??##????#?? 1 3 1 3
?#?##????#.????. 8 1 2
?.???.????# 3 2 1
???#????#???#?? 1 2 5 3
?.?#.?????..? 1 1 1 1
.??.???#?????.???? 2 2 6 1 2
?.???.???#?????.?# 1 1 1 4 1 1
#.##???#?#????. 1 6 2 1
?????#..?????#? 1 1 1 7
?.?.??#.????##?.??? 1 2 1 5 1
?#?#?#???#?#????? 1 3 6 2
??.#?.#?????# 2 1 4 2
?##???.???. 3 1 2
?.#???.?...##???? 1 3 1 2 1
???#????????????? 4 1 2 4
?.?#?????#?#?# 1 1 9
??????...???##??. 2 1 4
???###???#?. 2 4 2
?.??#.??#??#..????? 1 1 1 5 3 1
??.??????#?????? 2 1 3 1
.#?.??#????#?.#. 1 6 1 1
?????##??####?????#? 2 10 1 1
?????#?..??.???#?? 7 2 6
???#.??##?##?.????? 1 1 7 1 3
.?#?#????? 3 1 1
??.?#?#?.?...?? 2 1 2 1 1
?..?#?.??.#?#?? 3 4
#?#.??.??????????. 3 1 6
??#???..??.?. 3 1
??.???.??????.?.?? 1 1 3 1 1 1
?????#?.?.?????#?##? 1 3 1 1 5
?.####.?.??#.? 4 3 1
#????????####??#? 2 2 5 2
?...#??#?##??????? 1 2 4 1 1 2
?##?.?????#???.? 3 1 2 1 1
##..##???#. 2 2 1
..#??????#? 1 1 3
?????????# 1 1 1
?#..????????#??.? 1 3
??##??.?..??#??? 5 5
???#?????.#?#? 1 6 1 1
.??#????##????. 1 6
#??#?????????.??#?.? 7 4 2
.????##?#?? 1 2 1
???#??...??? 5 2
?.??#?#?##?.? 8 1
?????.####???#??.?. 5 4 5
???#????##? 1 7
?#????###???? 2 6
????.?#???##????? 1 9 1
???????.????## 1 1 1 6
???.?#??..???#??#?? 2 1 1 8
.????.???..? 2 2
?.#?#?#???? 1 3 1
?.???#?##??.???.???? 6 2
.##?#?????????#???# 4 13
?##?.?..???# 3 3
?.?##??.??#?..??. 4 4 1
.?#??.??#??#?? 2 7
#??.#?????????#???? 1 15
???.???#?.#?#.? 3 4 3 1
???#??????.?# 7 1 1
?#????####???. 9 1
??????#???? 2 4 1
.?#???????#???#.???# 13 2 1
??##???#??????#?##?. 6 1 1 8
????#??.???? 2 1 3
???????#???#?#? 1 1 4 3
?.##??...?? 4 2
#?##?????????#???# 5 3 6
.???#???#. 5 1
?#??#?#?###????..? 12 1
.#??????????.??????? 3 7 1 3
?????????? 1 6
?#?..????#? 2 5
?..?.#?#?? 1 3
?????.?????#? 1 1 1 5
?##?#?###??#????. 13 1
.??.????.?? 2 1 1
..#?#?#??.#.#?? 6 1 1
??#?#?.##??.? 3 2 1
.????#???.?#? 1 5 1
#.????.???????#?? 1 1 10
????#.??.???#.???? 1 2 1 1 1 2
#.??.???#???#. 1 3 3
???.?.?????????#?.?? 2 1 2 1 3 1
??.??#????# 1 3 1
??##????#?#??##?#??. 10 5
???#???.??.????? 5 1 1 1
????.#????#????#.. 2 11
..??????#??.??#??? 4 3
?#?????.???.??.???? 2 1 1 2 1 2
?.?#????????? 3 1
.???.??#???#???##?? 3 11
??#??#?#??#?.?#???? 2 4 2 3 1
??????##.???.#?? 1 5 1 1
?.#??????#????#?. 1 1 9
?.#??.?#??????.? 3 6
?.#.??????? 1 1 2
?????????##?. 3 6
#?#???...?? 1 3
?###??.????#???????? 5 4 6
???????????#??#??#?? 11 1 1 1
???#??????. 1 3 1
?#??.???#??#? 2 2 5
?###..???##?. 4 3
?##?#?.##???##?.?.# 6 7 1
?##?#??#???. 6 2 1
#??.??.?#????##???#? 1 1 1 9 1
??#????.???#.??. 1 5 3 1
?#?????.???. 2 1 3
?????.?#?#?###???. 4 7
????..?#?#? 1 3
??..?#?????? 2 2 2
???????.???? 5 1
?????.#.?.???##? 3 1 1 3
.????????.#.#. 2 1 1 1
.??#?.?#????#??# 2 8 1
?#?.???#.????? 3 3 4
.??#?##?#???#?.#?? 1 11 1
..???#???...?.?.? 2 1
??.??...#????????? 1 1 1 2 2 2
????..??????.??#. 2 6 3
.??.#?#??#??. 2 1 4
#???#?#.?#?#.?#?? 7 1 1 1 1
?.#????#???#???#? 12 1
..???#???#??????# 6 1 1 1 1
????.?#?.???? 4 3 3
???#???#.??#?#??? 1 5 6
????????.???.???#??# 7 1 2 2 1
??##??.??#.????. 4 2 2
?##?#?##???#.????#?? 11 5 1
..?.?#????? 1 1 2
.??#????????.#???. 9 3
????.#..?#.?#?#?#?? 1 1 1 8
#???#?..???#? 1 2 1 2
??#?.#.##??????# 1 1 1 7 1
?..??#?#?.??#?.? 1 4 3
?????.??.. 1 1
??..#?????.#.?? 1 1 2 1 1
????..?##??????##?# 3 13
?#.????.??.?#????#?# 1 1 1 2 4 3
??#??.???? 4 1
#????#.??? 6 2
#?????.???????? 6 1 5
???#???#.#???.?? 4 2 3 2
#????????? 4 2
#.?.???.???? 1 1 1 1
.#???????.? 3 1
???.??#???###?#?#.#? 1 4 4 1 1 1
?????#???? 6 2
??.#.????#.??#?#??? 2 1 5 1 1 1
??????###?##?? 1 9
.???????????. 3 1 3
.?????#??##?.????. 11 2
??????##??????#???. 2 1 5 1 1
.#??###??.???? 6 1 2 1
.????.??#??????? 4 2 1 1
#????????.#?????#? 2 1 2 4 1
???.##.?#? 2 2 2
?..??????###?????.? 1 9 1
?#??????#???? 2 1 3 2
??##???#??#???? 1 2 6
??.??????????.. 3 3
#?#??.???.?.?? 5 3 1
???.??#?#???????### 1 1 1 1 6
??#??????.??? 5 3 2
??????.???????#? 3 1 3 1 2
.##?#????###?.??# 2 8 1 1
?????????.?#. 1 1 1 1
?..#????#??###?????? 7 9
.???.?#?.#.?.#? 1 3 1 2
.??#.????? 2 1
##..#?????#???? 2 1 1 4 1
?????...??? 1 1 2
??.#?.????#?? 1 6
??????#?#??????? 1 10 2
??#???????.??.?.???# 4 1 1 1 1 3
.#????.??#????. 2 2 4 1
?????????#???. 6 1 4
.???????.??# 6 3
?.??#???.??##? 6 3
.????.??#?? 2 3
????###????????#?##? 1 17
??.#.?####?.#? 1 1 4 1
??#??#?#???.?#.? 6 2
???#????##??#?.?.? 9 2
?.???.??.????#??? 2 7
?#??#???#???#? 8 1
#??????##??? 3 1 2 1
#..???????.#?#?? 1 4 1 3
?????##?????????.# 8 2 1
..??????.?#????##. 3 8
??..????#?#?###??.?? 1 12 1
.??.???#?. 1 5
??#?????????.? 7 1
??.##?#???. 1 7
#?????#???????# 1 1 1 1 4
.???????#? 1 3
????#??.?#.????? 6 1 1 1 1
#..??#??#???.??#? 1 7 3
???.??????????? 1 1 8 1
?.???.##??..??##??? 1 4 5
...?.?????.??.??##. 1 4
????.??????? 1 1 1 1
.??#?..#?.?.#???. 1 2 2 2 1
?#???????????.#?#? 1 1 1 3 3
????.#?.?????#.. 1 1 1 1 2
?????????????##? 1 4 1 1 2
.???.??##???#???? 1 5 3 1
?##???????..?.?? 4 1 1 1 2
.#???.????#???#? 1 1 1 3 1
??.???#???##???#. 2 13
???????##???# 4 4 1
????????#.???#??.. 1 1 3 6
.??##?##?????????. 12 1
??###?.#????.? 4 5
###?...#??#? 4 4
.?#??#.????#.???? 5 2 1 3
??##.??#?#?.???.??. 3 1 1 1 1 2
?##?.?###??#??????. 3 9 1
##???#.?#????#?? 3 1 1 5
??????????#?????# 2 4 6 1
?????#??##?#..#??.? 10 2
?#????#?..???.#? 3 3 2 1
?##????#???? 2 2 1
#?#???????#?#??#? 3 2 8
??..?#???? 2 1 2
????.##?##.?.??..?# 2 2 2 1 1 1
.#?????#?. 1 2 1
??#??#....?# 5 1
????.?#??#?????.#.? 1 1 5 3 1
?????.?.??.???. 1 2 1 1 2
???.??#????#.?#. 2 7 1
?#.#?.?#?.???? 2 1 3 2
??#.#???????#?#??.#? 1 1 2 2 2 2
##???##????## 3 3 1 2
??????????.#??? 1 2 1 3
??.???#???.?? 2 1 3 2
????##?????##??#??# 6 6 1 2
#???????.??????? 3 2 4
..#?.?#?#.???????? 2 2 1 5 1
???#?#.??????#. 1 3 2 1
??.????????? 1 2 1 1
#?.#???.#? 2 1 2
?.???.?#?? 2 1
????.???#?#.?# 3 6 1
?.??#?.????.##???? 4 3 2
???#??#??.#???##?.? 3 3 7 1
?????#????# 1 5 1
#??#?????##?? 1 1 7
.???#?.?#??? 4 2
#?#?##???#?#??#.?? 1 1 3 5 1 1
?.???.???.?#?.???.? 1 1 1 3 2 1
????#.?????.??##? 1 1 4
?.?????.????# 1 4 3 1
#???.?.?## 4 3
??#?.?#???.. 3 3
??..?#?##???. 4 1
.??...???. 2 1
??????.??..?? 4 1
?????.?#?? 1 1 3
?????#?.?.??.??? 1 5 1 1 1
????????#???????? 1 6 1 2
???????.?#.? 1 1 1 2
????????#? 2 5
??????????.??? 1 1 1 3
?.????????#?? 1 6
.?.??????.???? 4 1
?.???.???#.???? 2 3 1 1
????.?#?#???#?#?.? 1 8
.????##??? 1 4
#???#.??????? 2 1 5 1
????????????# 1 1 1 1
??????#??????# 1 1 4 1
.?#?.?#??#?????? 1 9
????#??.??#. 1 2 3
?.?#??.??????#.?#?. 1 4 1 5 2
???.##?#?#?#??#??#? 1 12 1
?##???????????? 2 1 7
..?##?.#??????.? 4 1 1 1
.?..?##???. 1 4
?????####?##?????. 11 1
#?#?.???.?? 4 1 1
#??.#?#???. 3 5
?????..??????.????? 4 4 1
#??.?#??#?##??# 2 1 8
?..????###.?? 1 1 3 1
?.?##?#?#??.#?? 1 7 1 1
????..???#????????? 3 11
#??#?????#??##?## 1 3 10
??##?#?.?# 6 1
?????###.??.. 1 3 2
#??.?.#?.?.? 3 1 1
###?#?.????.????#?#. 5 2 1 1 1 1
??????#??# 4 1 2
?###.?????#?#??? 3 5
???#???????#? 7 2
?????.??#?.?? 2 2 1 1
#..#.?.?????#?.? 1 1 6
??????.??#??#?? 1 8
???#???#???#?? 1 1 3 2
#???..#?.???? 1 1 1 4
.???.?.?????#? 3 1 4
.??#.?###?#? 1 1 6
?#???.?#?#?##.# 1 1 6 1
?#?????#???..#.?? 8 2 1
##??.?.???#?? 2 1 2
?????#????#?.???? 2 2 3 1 1
??..?#??.?#?? 2 2 1 1
??.????..?##??#??? 1 2 4 2 1
.???.?#????.?? 1 6
?.##?????#..????. 8 1 1
??.#?..???#. 2 2 2 1
???#?#??????..??? 1 7 1 1
????.??#.????#?? 1 1 3 1 3
????????..?.???##? 1 2 2 1 5
..?#??##??.?? 6 2
???.?###??# 2 6
????????##??###???? 13 1
??.?.#?#???##?? 1 1 1 7
.###.?#?#???.? 3 5
?###??..??#?##? 5 6
...?????.?#.? 2 2
#.?#?..##.?????? 1 1 2 1 2
????#????????#?? 5 3
#.??##?#??#?.? 1 8
.??#?#??..?#??#?.?? 5 2 2 1
.##.??????##?. 2 7
???##??????.#.?? 6 2 1 1
.??#??#????.??? 6 1
???..???###?????? 1 1 1 6 1
??????????? 2 2 4
?.?.#?#.?????? 1 3 2 2
????.?.?##?.? 3 4
..####??#?#??#?.?.#. 4 4 2 1 1
.??#??..?#??#. 2 5
..?.???#..?#.???.#? 1 2 2 1
?#????#???????? 8 2
?#???....?#???#?? 2 1 2 3 1
???.##????#????? 1 11
.?????#.??#?##???? 4 1 2 6
?.#???#??? 2 1 1
##?????#??? 2 2 2
???#????#??????#? 5 1 2 1
????.#?????#?#????#? 1 1 4 1 2 4
?.??????##?#???.???? 1 2 8 3
???#??.?.?? 2 1
.??.?#???##?????#?. 6 3
.???#??.?.? 4 1
.#?#???.?. 5 1
?.????.???#???? 1 1 1 3 1
???.???#?###?##?##? 1 1 11
??.??.??.?? 1 1
.????#?#?? 1 4
.?.??????#????.?? 1 6
..???.?.?#.???? 2 1 1 1 1
.?##????#?#???#? 4 1 1 2 3
.?##?#?????#?#?? 6 3
????#?.???.? 1 2
????#.#.???##??#?? 3 1 6)";
    
    // Đọc từ stringstream thay vì cin
    istringstream ss(input);
    
    // Chương trình chính giữ nguyên
    ios::sync_with_stdio(0);
    cin.tie(0);
    string line;
    int tmp;
    ll res = 0, res2 = 0;
    
    // Thay thế cin và getline bằng stringstream
    while (getline(ss, line)) {
        // cout << line << "\n";
        istringstream lineStream(line);
        lineStream >> s;
        a.clear();
        while (lineStream >> tmp) a.eb(tmp);
        res += f();
        unfold();
        res2 += f();
    }
    cout << res << "\n";
    cout << res2 << "\n";
}