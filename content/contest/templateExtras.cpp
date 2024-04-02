template <class K, class V> ostream &operator<<(ostream &s, const pair<K, V> &p)
{
    s << '<' << p.first << ", " << p.second << '>';
    return s;
}

template <class T, class = typename T::value_type, class = typename enable_if<!is_same<T, string>::value>::type>
ostream &operator<<(ostream &s, const T &v)
{
    s << "[";
    for (auto &x : v)
        s << x << ", ";
    if (v.size())
        s << "\b\b";
    s << "]";
    return s;
}

void _print() { cerr << "]\n"; }
template <typename T, typename... V> void _print(T t, V... v)
{
    cerr << t;
    if (sizeof...(v))
        cerr << ", ";
    _print(v...);
}

#define dbb(x...)                                                             \
    cerr << "\e[91m" << __func__ << ":" << __LINE__ << " [" << #x << "] = ["; _print(x); cerr << "\e[39m" << flush;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rand(int lo, int hi){if(lo > hi) swap(lo,hi); return lo + rng() % (hi - lo + 1);} //returns in the range [lo, hi]