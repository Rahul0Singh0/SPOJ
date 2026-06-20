// https://www.spoj.com/problems/PALIN/
#include <iostream>
#include <string>
using namespace std;

bool allNine(const string &s) {
    for (char c : s) {
        if (c != '9')
            return false;
    }
    return true;
}

string nextPalindrome(string num) {
    int n = num.size();

    // Special case: all 9s
    if (allNine(num)) {
        string ans = "1";
        ans.append(n - 1, '0');
        ans += "1";
        return ans;
    }

    string pal = num;

    // Mirror left to right
    for (int i = 0; i < n / 2; i++) {
        pal[n - 1 - i] = pal[i];
    }

    // If mirrored number is already greater
    if (pal > num) {
        return pal;
    }

    // Increase middle and propagate carry
    int carry = 1;
    int mid = n / 2;

    if (n % 2 == 1) {
        int digit = (pal[mid] - '0') + carry;
        pal[mid] = (digit % 10) + '0';
        carry = digit / 10;
        mid--;
    } else {
        mid--;
    }

    while (mid >= 0 && carry) {
        int digit = (pal[mid] - '0') + carry;
        pal[mid] = (digit % 10) + '0';
        carry = digit / 10;
        mid--;
    }

    // Mirror again
    for (int i = 0; i < n / 2; i++) {
        pal[n - 1 - i] = pal[i];
    }

    return pal;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        string k;
        cin >> k;
        cout << nextPalindrome(k) << "\n";
    }

    return 0;
}