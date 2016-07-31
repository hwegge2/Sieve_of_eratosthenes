#include <iostream>
#include <cmath>        //for the use of the squareroot function
#include <sstream>	//used for string stream function to display contents
#include <cstdlib>
#include <string>

const int MAXSIZE = 1000;

using namespace std;

/*
* fills the array, primes, with all the prime
* numbers between 2 and n inclusive using the Eratosthenes
* sieve algorithm. The number are placed in ascending order
* in the array and the size variable is the number of
* prime numbers less than or equals to n: primes[0] = 2,
* primes[1] = 3, primes[2] = 5, primes[3] = 7, ...
* @param primes - the array containing the prime numbers
* @param n - the smallest integers greater than or equals
* to the largest prime number generated
* @param size - the number of prime numbers generated.
*/

void generate(int primes[], int n, int& size)
{
  int prime_list[MAXSIZE];
  int  negative_test = 0;
  int t = 0 ;

   for (int i=0; i <= MAXSIZE; i++)	//for loop creates an array from 2 to n
  {
  	 if(i < n-1)
   	{
  	 prime_list[i] = 2 + i;
   	}
  }
  for(int i=0; i<sqrt(n); i++)		//for loop uses seive algorithm to change composite numbers to -1
    {
   	for (int j= i+1; j<MAXSIZE && prime_list[i] !=-1; j++)
   	{
    	if (prime_list[j] % prime_list[i] == 0)
    	prime_list[j] = -1;
   	}
    }
  for (negative_test = 0;negative_test <= n-1; negative_test++)		//for loop removes the -1 to leave only the primes in the array
	{
		if(prime_list[negative_test] != -1)
		{
			primes[t++] = prime_list[negative_test];
		size++;
		}

	}

}


/* This method determines whether a number is prime.
* @param n - a positive integer
* @return true if n is prime; otherwise, false
*/
bool isPrime(int n)
{
 bool prime = true;

 for(int i = 2; i<=sqrt(n); i++)	//uses the sieve algorithm to determine if a number is prime or composite
 {
  if(n % i == 0)
  prime = false;
 }
 return prime;		//returns the boolean back to the int main() function
}


/* This function creates a string formatted as a set
* using the elements of array stored in position
* 0...size-1.
* examples: {}, {2}, and {2,3,5,7}
* @param array - the array whose elements are to be
* used to create the string
* @param size - the number of elements in the array
*/
string arrayToString(const int array[], int size)
{
  stringstream primerstring;	//converts the array to a string and sends it back to the int main() function for output
  primerstring << "{";
  int i;
  for(i=0;i<size-1;i++)
  {
   primerstring<<array[i]<<",";
  }
    primerstring<< array[size-1]<<"}";
    return primerstring.str();

}


/*
* This function computes the sum of elements of
* array: array[0]+array[1]+...+array[size-1]
* @param array - the array whose elements are to be
* used to be added
* @return the sum of elements array[0] through array[size-1].
*/
int sum(const int array[], int size)
{
  int i, prime_sum = 0;		//this function sums all the numbers in the array
  for(i=0;i<=size;i++)
  prime_sum = prime_sum + array[i];
  return prime_sum;
}


int main()
{
  int mystery[MAXSIZE];
  int n,size,k;		//n represent the array that is generated from 2 to n. k is used to determing if the user submitted number is prime or composite
  cout << "This program generates all prime numbers between 2 and n."<<endl;
  cout <<"Enter n>";
  cin >> n;
  size = 0;
  if (n > MAXSIZE || n < 2 )
  cout << "Sorry, can only generate primes less than or equal to 1000."<<endl;
  else
  {
    generate(mystery, n, size);		//sends the numbers to the generate function to create the array of primes
    cout<<"The sum of "<<arrayToString(mystery, size)<<","<< endl;	//converts the array to a string in the arrayToString function and displays it
    cout<<"the primes less than or equal to "<<n<< " is "<<sum(mystery,size)<<"."<<endl;	//adds the numbers in the array in the sum function
    cout<<endl;
    cout<<"Enter a number k in the range[1,"<<size<<"]> ";
    cin>>k;
    cout<<"The prime number in position "<<k<<" is "<<mystery[k-1]<<"."<<endl;
    cout<<endl;
    cout<<"Enter a positive integer>";
    cin>>k;
    if(isPrime(k))	//determines if the user submitted integer is prime or composite in the isPrime function
     cout<<k<<" is a prime number."<<endl;
    else
     cout<<k<<" is a composite number."<<endl;
  }


  return 0;
}
