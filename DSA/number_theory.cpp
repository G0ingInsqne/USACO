/*
number theory template
includes: 
    ceil
    binary exponentiation
    modular inverse
    gcd
    lcm
    line segment intersection test
    primality test
    sieve of eratosthenes
    prime generation
    factoring a number
    counting divisors of a number
    checking whether a number is a perfect square
    checking whether a number is square of a prime
    obtaining divisors of a number
*/


// ceil 
long long aceil(long long num, long long denom)
{
    return (num + denom - 1) / denom;
}

// binary exponentiation - computes a^b mod m
// a^(b^c) = binpow(a, binpow(b, c, m - 1), m)

long long binpow(long long a, long long b, long long m = 1e9 + 7) 
{
    a %= m;
    long long res = 1;
    while(b > 0) 
    {
        if(b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

//computes the modular inverse of a mod m, requires binpow function
//m must be prime, uses fermat's little theorem
long long modinv(long long a, long long m = 1e9 + 7)
{
	return binpow(a, m - 2, m);
}

// greatest common divisor
long long gcd(long long a, long long b)
{
    return __gcd(a, b);
}

// least common multiple
long long lcm(long long a, long long b)
{
    return (a / gcd(a, b)) * b;
}

//tests primality of a number
bool isprime(long long n) 
{ 
    if(n <= 1) return 0; 
	if(n <= 3) return 1; 
	if(n % 2 == 0 || n % 3 == 0) return 0; 
	for(long long i = 5; i * i <= n; i += 6) if (n % i == 0 || n % (i+2) == 0) return 0; 
	return 1; 
} 

//runs sieve of eratosthenes
bitset<15000150> prime; 
void sieve(int n) 
{ 
	for(long long i = 0; i <= n; i++) prime[i] = 1;
	for(long long p = 2; p * p <= n; p++) 
		if(prime[p]) for(long long i = p * p; i <= n; i += p) prime[i] = false; 
	prime[1] = prime[0] = 0;
} 
	 
//generates all primes up to and including a number
bool __primes_generated__ = 0;
vector<long long> genprimes(int n) 
{
    vector<long long> primelist;
    __primes_generated__ = 1;
    sieve(n + 1);
    for(long long i = 2; i <= n; i++) if (prime[i]) primelist.push_back(i);
    return primelist;
}

//checks if a number is a perfect square
bool isSquare(long long n)
{
    long long x = sqrt(n);
    return x * x == n;
}

//checks if a number is a square of a prime
bool sqprime(long long n)
{
    if(!isSquare(n)) return 0;
    long long x = sqrt(n);
    return isprime(x);
}

//computes number of factors of a number
//requires genprimes, isSquare, sqprime, sieve
long long factornum(long long n)
{
    int ans = 1;
    for(long long p : primes)
    {
        if(p * p * p > n) break;
        int cnt = 1;
        while(n % p == 0)
        {
            n /= p;
            cnt++;
        }
        ans *= cnt;
    }
    if(isprime(n)) ans *= 2;
    else if(sqprime(n)) ans *= 3;
    else if(n != 1) ans *= 4;
    return ans;
}

//gets all factors of a number
//requires sieve, genprimes (call genprimes in main)
vector<long long> factors(long long n) 
{
    if(!__primes_generated__) 
    {
        cout << "Call genprimes you dope" << endl;
        exit(1);
    }
    vector<long long> facs;

    for(long long i = 0; primelist[i] * primelist[i] <= n && i < primelist.size(); i++) 
    {
        if(n % primelist[i] == 0) 
        {
            while (n % primelist[i] == 0) 
            {
                n /= primelist[i];
                facs.push_back(primelist[i]);
            }
        }
    }
    if(n > 1) facs.push_back(n);
    sort(facs.begin(), facs.end());
    return facs;
}

//gets all divisors of a number
vector<long long> divisors(long long n) 
{ 
    vector<long long> divs;
    for(long long i = 1; i * i <= n; i++) 
    { 
        if(n % i == 0) 
        { 
            if(n / i == i) divs.push_back(i);
            else divs.push_back(i), divs.push_back(n / i);
        } 
    } 
    return divs;
} 
