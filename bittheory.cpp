Decimal convert to Binary 

string convert2binary(long long n){
    if ( n == 0) return "0";
    string res = "";
    while(n != 1){
        if(n % 2 == 1) res += '1';
        else res += '0';
        n/=2;
    }
    res += '1';
    reverse(res.begin(), res.end());
    return res;
}



TC - logN
SC - logN


long long convert2decimal(string n){
    long long ans = 0 , p2 = 1;
    long long len = n.size();
    for(long long i = len - 1;i>= 0;i--){
        if(n[i] == '1') ans += p2;
        p2 *= 2;
    }
    return ans;
}



TC - O(N)
SC - O(1)


OPERATOR 

AND 
All true - true
1 false - false

OR 
All false - false
1 true - true

XOR 
No. of ones is odd - 1
No. of ones is even - 0

Also same bits - 0
Diff bits - 1

##
SHIFT

>> - right shift  (right mein shift)

X = 13 >> 1                  01101 
X = 6                            00110

13 >> 2  = 3 


Formula - x>>k = x/(2^k) 


LEFT shift 

13 << 1 = 26
FORMULA 
x << k = x * (2^k)

(Overflow at (2^31 -1)<< 1)



NOT (~) 

 ## for storing a  negative number computer does two’s compliment of the number 
31st bit is for sign 



SWAP

void swap(long long &a,long long &b){
    a = a^b;    
    b = a^b;    // yaha a = a^b i.e     b = (a^b)^b i.e. b = a
    a = a^b;    // yaha a = a^b and b = a   therefore a = b
    // swapped
}






CHECK  IF ith bit is SET or Not

2 ways 

bool checkIthIsBitSet(long long n,long long i){
    // using left shift operator
    return (n & (1<<i)) != 0; // 1 ko i  times left mein bheja baki sab bit 0 honge aur fir AND kiya toh ith wala if 1 then 1 else 0
}


bool checkIthIsBitSet2(long long n,long long i){
    // using right shift operator
    n = n >> i;
    return (n & 1) != 0;
}



Using left shift  
1 ko ith left shift kiya 

00000….10000…
Fir & liya 

Using right shift 
Wo number ko ith right shift diya aur first bit 1 or 0 check kar liye 

TC - O(1)

SET ith bit (make 1)

OR operation with (1 << i)
1 ko left shift kiya i se aur fir or kar diya 



void setIthBit(long long &n,long long i){
    n = n|(1 << i);
}



long long a = 5;
    setIthBit(a,1);
    // 101
    cout<<a<<endl;
    // 111

Clear ith bit (make 0)

First convert 1<<i to its one’s compliment and then & with number 
…….00100
~(1 << i) -  11…….011
And with number to unset or clear ith bit

void clearIthBit(long long &n,long long i){
    n = n& (~(1<<i));
}


   // a =  111


    clearIthBit(a,1);
    cout<<a<<endl;
    // 101


Toggle ith bit 
If 1 make it 0 
Else make it 1

Using XOR operator 
1 << i to make 001000..0
Then xor operator with number  

void toggle(long long &n,long long i){
    n = n^(1<<i);
}



Clear the rightmost bit 

N = 16 
10000
 N - 1 = 15
01111

Right most bit hatke saare uske pehle wale one ho gaye toh hum 
Iska fayda utha kar & kar denge 



void removeTheLastSetBit(long long &n){
    n = n & (n-1);
 }




Check if power of 2 or not 

Anding with uske piche wala number 
Agar hoga power of 2 toh uss number mein sirf ek he bit set hoga  wo bhi unset kiya  toh 0 he banega n 
bool checkIfPowerOf2(long long n){
    return (n&(n-1)) == 0;
}


Count no. of Set bits 

// 1st way 
long long countNoOfSetBits(long long n){
    long long cnt = 0;
    while(n != 0){
        cnt += n&1;
        n = n >> 1;
    }
    return cnt;
}


// 2nd way 
long long countNoOfSetBits2(long long n){
    long long cnt = 0;
    while(n != 0){
        cnt++;
        n = n&(n-1);
    }
    return cnt;
}

Or SIMPLY 
Use builtin function 
__builtin_popcount(n)


POWER SET using bits 


If n = 3
8 subsets aayenge in the form  
 
4 2 1                                                   4 zero fir 4 one                            
4 2 1             				2 zero 2 one fir same repeat 
   2 1					1 zero 1 one aur repeat 
   2 1    
      1
      1 
      1 
      1
   

Code  - 

vector<vector<long long>> powerSet(long long n){
    vector<vector<long long>> ans;


    for(long long i = 0;i<(1<<n);i++){
        vector<long long> temp;
        for(long long j = 0;j<n;j++){
            if(i & (1<<j)) temp.push_back(j + 1);
        }
        ans.push_back(temp);
    }


    return ans;
}






If N is given and Xor from 1 to N is to calculated toh pattern banta hai wo dekh le 



Code
Xor from 1 to N 
 
long long xorFrom1toN(long long num){
     // TC - O(1)
     // 1 and N included
    if(num % 4 == 1) return 1;
    else if(num % 4 == 2) return num + 1;
    else if(num % 4 == 3) return 0;
    else return num;
}


// XOR from L to R


long long xorFromLtoR(long long l,long long r){
    // l and r included
    // TC - O(1)
    return xorFrom1toN(r) ^ xorFrom1toN(l-);
}


DIVIDE TWO long longEGERS without division or multiplication operator

long long divide(long long dividend, long long divisor) {
        if(dividend == divisor) return 1;
        bool sign = true;


        if(dividend >= 0 && divisor < 0) sign = false;
        if(dividend < 0 && divisor > 0) sign  = false;


        long n = abs(dividend);
        long d = abs(divisor);
        long quotient = 0;
        // break down long longo 2 ke power ke multiple aur fir add kiya unko wahi ans
        while(n >= d){
            long long cnt = 0;
            while(n >= (d << (cnt+1))){ // d << (cnt + 1) == d * 2^(cnt+1)
                cnt++;
            }
            quotient += (1 << cnt); // 1 << cnt == 2 ^ cnt
            n-= (d<<cnt);
        }


        if(quotient == (1<<31) && sign == true) return long long_MAX;
        if(quotient == (1<<31) && sign == false) return long long_MIN;
        return sign ? quotient : (-1 * quotient);
       


    }

