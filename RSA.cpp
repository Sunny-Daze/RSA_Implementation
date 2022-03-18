#include<bits/stdc++.h>
using namespace std;

#define nline "\n"
#define tab "\t"
#define ll long long

int main() {
// ios_base::sync_with_stdio(false);
// cin.tie(NULL);
// cout.tie(NULL);

	cout << "-------------------------------------   RSA   -------------------------------------\n\n";

	cout << "Enter the data -> ";
	int data;
	cin >> data;

	cout << "\n---->Generating public key - " << nline << nline;
	cout << "->Choose two prime numbers : " << nline;
	int p = 47, q = 89;
	cout << tab << tab << "    p = 3, q = 7" << nline;
	int n = p * q;
	cout << tab << tab << "    p x q = " << n << nline;
	cout << tab << tab << "    n = " << n << nline;
	cout << "->Euler's totient : phi(n) = phi(p * q)" << nline;
	cout << tab << tab << "  = phi(p) x phi(q)" << nline;
	cout << tab << tab << "  = (p - 1) x (q - 1)" << nline;
	int totient = (p - 1) * (q - 1);
	cout << tab << tab << "    " << p - 1 << " x " << q - 1 << " = " << totient << nline;
	int e = 2;
	while (e < totient) {
		if (__gcd(e, totient) == 1) break;
		else e++;
	}
	cout << "->Choosing 'e' such that [1 <= e <= phi(n)] and coprime to phi(n) : e = " << e << nline;
	cout << "-->>Public Key => (" << e << "," << " " << n << ")" << nline;

	cout << "\n---->Generating private key - " << nline << nline;
	cout << tab << tab << "    ed = 1 mod(phi(n))" << nline;
	cout << "Since d is multiplicative inverse of e : " << nline;
	cout << tab << tab << "    d = (1 + (k * totient)) / e" << nline;
	int k = 2;
	cout << tab << tab << "      = (1 + ( " << k << " * " <<  totient << ")) / "  << e << nline;
	int d = (1 + (k * totient)) / e;
	cout << tab << tab << "      = " << d << nline;
	cout << "-->>Private Key => (" << d << "," << " " << n << ")" << nline;

	int c = pow(data, e);
	c = c % n;
	int m = pow(c, d);
	m = m % n;

	cout << "\n---->Message to be encrypted :- " << data << nline;

	cout << "\n---->Encrypting the Data - " << nline;
	cout << tab << tab << "  data^e mod n" << nline;
	cout << tab << tab << "  " << data << "^" << e << " mod " << n << nline;
	cout << tab << tab << "  =>" << c << nline;

	cout << "\n---->Decrypting the Data - " << nline;
	cout << tab << tab << "  c^d mod n" << nline;
	cout << tab << tab << "  " << c << "^" << d << " mod " << n << nline;
	cout << tab << tab << "  =>" << m << nline;
	cout << "Orignal message sent = " << data << nline;

	return 0;
}