
string b;
string s;
int n;
int dp[1000009][2][2];

int f (int index, int last, int present)
{
    if (index == n) {
        if (present == 1) {
            return 0;
        }
        return 1;
    }
    int &result = dp[index][last][present];
    if (result != -1) {
        return result;
    }
    result = 0;
    if (s[index] == '*' && present == 0) {
        return 0;
    }
    if (s[index] != '*' && s[index] != '?' && present == 1) {
        return 0;
    }

    if (s[index] != '?') {
        if (s[index] == '*') {
            result+= (f(index+1, 1, 0) + f(index+1, 1, 1))%mod;
            result = result%mod;
            return result;
        }

        int xx = last;
        int value = (s[index]-'0');
        value = value-xx;
        if (value == 2 || value < 0) {
            return 0;
        }

        result+= f(index+1, 0, value);
        result = result%mod;
        return result;
    }

    if (present == 1) {
        result+= (f(index+1, 1, 0) + f(index+1, 1, 1))%mod;
        result = result%mod;
        return result;
    }

    result+= (f(index+1, 0, 0) + f(index+1, 0, 1))%mod;
    result = result%mod;
    return result;
}

int main()
{
//    freopen ("input.txt", "r", stdin);

    cin >> b;
    s = b;
    n = b.size();
    memset (dp, -1, sizeof(dp));

    int result;
    if (b[0] >= '0' && b[0] <= '2') {
        if (b[0] == '2') {
            cout << "0" << endl;
            return 0;
        }
        if (b[0] == '0') {
            result = f (1, 0, 0);
            cout << result << endl;
            return 0;
        }

        result = f (1, 0, 1);

        cout << result << endl;
        return 0;
    }

    if (b[0] == '?') {
        result = f (1, 1, 0) + f (1, 1, 1);
        result = result % mod;

        result += f (1, 0, 0);
        result = result%mod;

        result += f (1, 0, 1);
        result = result%mod;
        cout << result << endl;
        return 0;
    }

    result = f (1, 1, 0) + f (1, 1, 1);
    result = result%mod;
    cout << result << endl;

    return 0;
}