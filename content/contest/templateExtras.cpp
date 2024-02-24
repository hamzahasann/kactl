#ifndef LOCAL
    #define NDEBUG
#endif
#define split(s, d, v) vector<string> v; split2(s, d, v); //split(string, delimiters, vector<string)
void split2(string &str, string del, vector<string> &s){unsigned int l = 0,i = 0;for(; i < str.size() ; i++)for(auto &j: del)if(str[i] == j)
{if(l < i) s.push_back(string(str.begin()+l, str.begin()+i));l = i+1;break;} if(l < i) s.push_back(string(str.begin()+l, str.begin()+i));}
template<class K, class V>ostream& operator<<(ostream&s,const pair<K,V>&p){s<<'<'<<p.first<<", "<<p.second<<'>';return s;}
template<class T, class=typename T::value_type, class=typename enable_if<!is_same<T,string>::value>::type>
ostream& operator<<(ostream&s,const T&v){s<<'[';for(auto&x:v){s<<x<<", ";} if(v.size()) s<<"\b\b"; s<<']';return s;}
void debug_out(vector<string> args, int idx, int LINE_NUM) {cerr << endl;}
template <typename Head, typename... Tail> void debug_out(vector<string> args, int idx, int LINE_NUM, Head H, Tail... T) {
    if(idx > 0) cerr << ", "; else cerr << "Line(" << LINE_NUM << ") ";
    cerr << args[idx] << " = " << H;
    debug_out(args, idx + 1, LINE_NUM, T...);
}
template<typename... All> void debug_out(string s, int idx, int LINE_NUM, All... VA_ARGS){
    split(s, ", ", args);
    debug_out(args, idx, LINE_NUM, VA_ARGS...);
}
#ifdef LOCAL
    #define dbb(...) debug_out(#__VA_ARGS__, 0, __LINE__, __VA_ARGS__)
    #define db(n) cout<<"here "<<n<<"\n";
    #define DB(n) cout << "$|" << n << "|$\n";
#else
    #define dbb(...) 11
    #define db(n) 22
    #define DB(n) 33
#endif
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rand(int lo, int hi){if(lo > hi) swap(lo,hi); return lo + rng() % (hi - lo + 1);} //returns in the range [lo, hi]