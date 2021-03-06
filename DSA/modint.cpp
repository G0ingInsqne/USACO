// an integer number that can be used for modular arithmetic, will be modded with every operation

template<int MD> struct modint {
	static const int mod = MD;
	int v; explicit operator int() const { return v; } // explicit -> don't silently convert to int
	modint() { v = 0; }
	modint(int _v) { v = (-MD < _v && _v < MD) ? _v : _v % MD; if(v < 0) v += MD; }
	friend bool operator == (const modint& a, const modint& b) { return a.v == b.v; }
	friend bool operator != (const modint& a, const modint& b) { return !(a == b); }
	friend bool operator < (const modint& a, const modint& b) { return a.v < b.v; }
	friend ostream& operator << (ostream& os, const modint& m) { os << m.v; return os; }
	friend istream& operator >> (istream& is, modint& m) { int x; is >> x; m.v = x; return is; }
	modint& operator += (const modint& m) { if((v += m.v) >= MD) v -= MD; return *this; }
	modint& operator -= (const modint& m) { if((v -= m.v) < 0) v += MD; return *this; }
	modint& operator *= (const modint& m) { v = v * m.v % MD; return *this; }
	modint& operator /= (const modint& m) { return (*this) *= inv(m); }
	friend modint pow(modint a, int p) { modint ans = 1; assert(p >= 0); for(; p; p /= 2, a *= a) if(p & 1) ans *= a; return ans; }
	friend modint inv(const modint& a) { assert(a.v != 0); return pow(a, MD - 2); }		
	modint operator - () const { return modint(-v); }
	modint& operator ++ () { return *this += 1; }
	modint& operator -- () { return *this -= 1; }
	friend modint operator + (modint a, const modint& b) { return a += b; }
	friend modint operator - (modint a, const modint& b) { return a -= b; }
	friend modint operator * (modint a, const modint& b) { return a *= b; }
	friend modint operator / (modint a, const modint& b) { return a /= b; }
};
using mint = modint<MOD>;
