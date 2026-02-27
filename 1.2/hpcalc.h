/*
欢迎使用此高精度库!
作者:天辰
版本:1.2
使用说明:
	这是一个有符号整数高精度计算库,不支持浮点数运算。
	变量类型名称为HP。例: HP a=2;可以定义一个名为a的高精度变量,它存储的整数为2。
	可以直接使用数学运算符、位运算符、逻辑运算符进行运算。例: HP a = b+2-3;
	本库中包含乘方HP_pow()。例: HP_pow(a, b)会返回a的b次方。
    输入:
        使用std::cin进行输入。
	    或者使用getHP()输入一个高精度整数。例: a = getHP();
	    getHP()会先过滤不可见字符,然后开始输入,遇到非数字字符时结束输入。
	    如果没有输入数,高精度变量的值是EMPTY。
    输出:
    	使用std::cout进行输出。
    	或者使用putHP()输出一个高精度数。例: putHP(a);
		putHP()会额外输出一个换行符。
    错误返回值:
	    若出现已知错误,返回值都是EMPTY,即空值。
	    使用isEMPTY()获得一个HP变量是否是空值。例: if(a.isEMPTY())
    注意：
		1. 将HP转换为int或ll时,若HP值超过int或ll范围,返回值是0。
		2. 乘方运算限制：当指数的十进制位数超过16位时,判定结果过大,HP_pow()返回EMPTY。
		3. 负数取模规则：余数与被除数同号（例：(-7)%3=-1、7%(-3)=1）。
		4. 若参与运算的数包含EMPTY空值，数学运算符返回EMPTY，逻辑运算符返回false。
		5. 使用左移(<<)、右移(>>)时：
		   移动位数必须是非负整数，且不超过int最大值（2147483647）
           负数位移、过大位移或其他非法情况返回EMPTY
           对负数进行左移/右移，结果可能与内置int/ll类型的移位行为不同
          （尤其是右移，不保证保留符号位进行算术右移）
		6. 本库使用千进制（base-1000）内部存储，十进制压缩/解压对用户透明。
		7. 你可以从字符串构造一个高精度整数。 例:HP a = "-3298239482049823094328";
		   若此字符串不是一个数，变量的值是EMPTY。
		8. 若计算结果出现错误，即某些位上的值是负数，返回值是EMPTY。
    其他内置函数:
        clear():将变量的值清空为EMPTY。
        length()、size():获取变量绝对值的位数。EMPTY返回0。
        sign():获取变量的符号。正数为1, 负数为-1, 0为0。EMPTY变量的返回值为0。
        GetDigit(int p):获取从末位开始第p位的数字。若p超出范围，返回0。若变量为EMPTY，返回0。
        AppendZero(int m):在变量末尾加入m个0。要求m为正数，且添加0后总长度不超过1e8。
        RemoveTail(int m):移除末尾的m位。要求m为正数。若m超过原长度，结果为0。
		AppendZero与RemoveTail正常执行则返回0,出现错误返回1。
    祝您使用愉快!
    若发现问题,请向lyrTianChen09@outlook.com反馈。
天辰还开发了一个高精度计算器。获取方式：
	链接: https://pan.baidu.com/s/1X_E5OkSiDlJ-IigefdfurA
	提取码: b2ef
*/
/*
Welcome to this high-precision library!
Authors: TianChen
Version: 1.2
Instructions:
    This is a signed arbitrary-precision integer library.
	Floating-point operations are not supported.
    The type name is HP. Example: HP a = 2; defines a high-precision variable a with value 2.
    You can directly use arithmetic operators, bitwise operators, and comparison operators.
    Example: HP a = b + 2 - 3;
    This library provides HP_pow() for exponentiation.
    Example: HP_pow(a, b) returns a raised to the power b.
	Input:
		You can use std::cin >> a;
		Or use getHP() to read a high-precision integer. Example: a = getHP();
		getHP() skips whitespace, reads digits until a non-digit is encountered.
		If no number is inputed, the HP variable is set to EMPTY.
	Output:
		You can use std::cout << a;
		Or use putHP(a) to print a high-precision number.
		putHP() will print an extra line break.
	Error handling:
		Known errors return EMPTY (empty/invalid value).
		Use isEMPTY() to check: if (a.isEMPTY()) ...
	Notes:
		1. Converting HP to int or long long returns 0 if the value is out of range.
		2. Exponentiation limit: if the exponent has more than 16 decimal digits,
		   HP_pow() returns EMPTY.
		3. Modulo rule for negative numbers: remainder has the same sign as the dividend
		   (e.g. (-7) % 3 == -1, 7 % (-3) == 1).
		4. If any operand is EMPTY:
			 - arithmetic operators return EMPTY
			 - comparison & logical operators return false
		5. For left shift (<<) and right shift (>>):
		   Shift amount must be a non-negative integer ≤ INT_MAX (2147483647)
		   Negative shift amount, too large shift, or invalid input returns EMPTY
		   For negative numbers, shift results may differ from built-in int/long long behavior
		   (especially right shift,
		    which is not guaranteed to be arithmetic shift preserving sign bit)
		6. Uses base-1000 internal storage.
		   Decimal compression/decompression is handled transparently.
		7. You can construct a HP number from a string. e.g.:HP a = "-3298239482049823094328";
		   If the string is not a number, the HP value will be EMPTY.
		8. If a calculation error occurs (i.e., negative values in some digits),
		   the return value is EMPTY.
	Other built-in functions:
		clear(): Clears the variable's value to EMPTY.
		length(), size(): Gets the number of digits of the variable's absolute value.
		                  The return value of EMPTY is 0.
		sign(): Gets the sign of the variable. Returns 1 for positive, -1 for negative, 0 for zero.
		        The return value of EMPTY is 0.
		GetDigit(int p): Gets the p-th digit starting from the least significant digit (rightmost).
		                 Returns 0 if p is out of range.
						 Returns 0 if the variable is EMPTY.
        AppendZero(int m): Appends m zeros to the end of the variable.
		                   Requires m to be positive,
						   and the total length after appending must not exceed 1e8.
        RemoveTail(int m): Removes m digits from the end of the variable.
		                   Requires m to be positive.
						   If m exceeds the original length, the result is 0.
		If AppendZero or RemoveTail runs correctly, the return value is 0.
		If an error occurs, the return value is 1.
	Enjoy using it!
	Please report bugs to: lyrTianChen09@outlook.com
TianChen also developed a high-precision calculator.
	Download link:
    https://pan.baidu.com/s/1X_E5OkSiDlJ-IigefdfurA
    Extract code: b2ef
*/

#ifndef GRNUM_DEF_H
#define GRNUM_DEF_H 1031149997108990

#include<vector>
#include<string>
#include<iostream>

namespace grnum{
	typedef std::vector<int> vi;
	typedef std::string str;
	typedef long long ll;
	const char Ope[] = "*/^%";//运算符 operator
	const int JW = 1000;//千进制 base-1000 storage
	const int BIT_JW = 1024;//1024进制，用于位运算
	const int KAR_LIMIT = 128;
	//使用Karatsuba算法的长度最小值 Mininum length for using Karatsuba
	vi EMPTY(1, 0);//Error时返回值 Invalid/empty value(error indicator)
	//EMPTY特征: EMPTY[0] = 0    Feature of EMPTY: EMPTY[0] = 0
	vi ONE(2, 0), M_ONE(2, 0), ZERO(2, 0);//1 -1 0
	vi BI(3, 0);//1024
	vi 	TWO(2, 0), TEN(2, 0);
	char FirstInit = 1;//第一次执行构造函数时初始化全局变量
	//Initialize global variables on first constructor execution
	const int MAX_INT = 2147483647, MIN_INT = -2147483648;
	const ll MAX_LL =  9223372036854775807ll, MIN_LL = -9223372036854775807ll-1;
	void init(){
		ONE[1] = ONE[0] = 1;
		M_ONE[0] = -1, M_ONE[1] = 1;
		ZERO[0] = 1;
		BI[0] = 2, BI[1] = 24, BI[2] = 1;
		TWO[0] = 1, TWO[1] = 2;
		TEN[0] = 1, TEN[1] = 10;
	}

	//数相关函数 functions about numbers
	int max(int x, int y) {return x>y ? x : y;}
	int min(int x, int y) {return x<y ? x : y;}
	int abs(int x) {return x>0 ? x : -x;}
	void swap(int &x, int &y) {int t = x; x = y, y = t;}
	int intTOone(int x) {return x>0 ? 1 : -1;}
	int sqrt(int x){
		ll l = 0, r = x, m;
		while(l < r){
			m = (l+r+1) >> 1;
			if(m*m <= x) l = m;
			else r = m-1;
		}
		return l;
	}

	//字符相关函数 functions about characters
	char PosiNega(char x) {return x=='+' ? '-' : '+';}
	char signOFmul(char x, char y) {return x==y ? '+' : '-';}
	char IsDigit(char t) {return t>='0' && t<='9';}// 是数字
	char IsSign(char t) {return t=='+' || t=='-';}// 是正负号
	char IsOpe(char x){//是运算符
	    for(auto ch : Ope)
	        if(ch && ch==x) return 1;
	    return 0;
	}

	//数和符号转换函数 functions about converting of numbers and characters
	char intTOsign(int x) {return x>=0 ? '+' : '-';}
	char signTOint(char x) {return x=='+' ? 1 : -1;}
	char llTOsign(ll x) {return x>=0 ? '+' : '-';}

	//vector相关函数 functions about vector
	char HP_IsZERO(vi &a) {return abs(a[0])==1 && !a[1];}//是0 Checks if the value is 0
	char HP_IsONE(vi &a) {return a[0]==1 && a[1]==1;}//是1 Checks if the value is 1
	char HP_IsM_ONE(vi &a) {return a[0]==-1 && a[1]==1;}//是-1 Checks if the value is -1
	void VecSwap(vi &a, vi &b) {a.swap(b);}
	void AllResize(int n, vi &a, vi &b, vi &c){
		a.resize(n), b.resize(n), c.resize(n);
		a[0] = intTOone(a[0])*n;
		b[0] = intTOone(b[0])*n;
		c[0] = intTOone(c[0])*n;
	}//运算之前统一长度防止指针越界
	//Unify lengths before operations to prevent index out of bounds
	void HP_PopFrontZero(vi &a){
        int n = abs(a[0]);
        int f = a[0] > 0 ? 1 : -1;
        while(n>1 && a[n]==0) n--, a.pop_back();
        a[0] = n*f;
	}//去除前导零 Remove leading zeros
	short HP_VecCmp(vi &a, vi &b){
        int na=abs(a[0]), nb=abs(b[0]), i;
        if(na != nb) return na>nb ? 1 : -1;
        for(i=na; i>0; i--)
            if(a[i] != b[i]) return a[i]>b[i] ? 1 : -1;
        return 0;
	}//无符号整数比较大小 Compare unsigned integers
	void HP_reverse(vi &a){
	    int n = abs(a[0]), i;
	    for(i=1; i+i<=n; i++)
	        swap(a[i], a[n-i+1]);
	}//倒序存储 Reverse the vector storage
	vi HP_zip(vi a){//十进制压为千进制 Compress decimal to thousand-based
	    int f = a[0]>0 ? 1 : -1, n = abs(a[0]), i;
	    a.resize(n+5, 0);
	    int nb = (n+2)/3;
	    vi b(nb+5, 0);
	    for(i=1; i<=n; i+=3) b[i/3+1] = a[i+2]*100+a[i+1]*10+a[i];
	    b[0] = f*nb;
	    HP_PopFrontZero(b);
	    return b;
	}
	vi HP_unzip(vi a){//千进制解压为十进制 Decompress thousand-based to decimal
	    int f = a[0]>0 ? 1 : -1, n = abs(a[0]), i;
	    a.resize(n+5, 0);
	    int nb = (n<<1)+n;//n*3
	    vi b(nb+5, 0);
	    for(i=1; i<=n; i++){
	        b[i*3-3+1] = a[i]%10;
	        b[i*3-3+2] = a[i]/10%10;
	        b[i*3-3+3] = a[i]/100;
	    }
	    b[0] = f*nb;
	    HP_PopFrontZero(b);
	    return b;
	}
	ll HP_vecTOll(vi b){//高精度转为ll    Convert high-precision to long long
	    ll ans = 0; int nb = abs(b[0]);
		if(nb > 5) return 0;//可能溢出
	    while(nb) ans = ans*JW+b[nb--];
	    return ans;
	}
	vi HP_intTOvec(int ai){
		vi b(1, 0);
		int nb = 0;
		int sign = intTOone(ai);
		ai = abs(ai);
		while(ai){
			b.push_back(ai%JW);
			ai /= JW, nb++;
		}
		b[0] = nb*sign;
		return b;
	}
	char HP_NumCheck(vi a){
		int na = abs(a[0]);
		for(; na; na--)
			if(a[na] < 0) return 1;
		return 0;
	}//合法:0 不合法:1    Valid:0 Invalid:1

	//高精度计算函数声明
	//Declarations of high-precision calculation functions
	vi HP_Plus(vi a, vi b);
	vi HP_Minus(vi a, vi b);
	vi HP_Multiply(vi a, vi b);
	vi HP_Karatsuba(int n, vi a, vi b);
	vi HP_SimMul(vi a, vi b);
	char HP_DivCmp(int r, int n, vi &a, vi &b);
	vi HP_Divide(vi a, vi b);
	vi HP_Power(vi a, ll b);
	vi HP_Module(vi a, vi b);

	//高精度位运算函数声明
	//Declarations of high-precision bitwise functions
	vi HP_ThouToBit(vi a);
	vi HP_BitToThou(vi a);
	vi HP_LeftPush(vi a, int b);
	vi HP_RightPush(vi a, int b);
	vi HP_BitAnd(vi a, vi b);
	vi HP_BitOr(vi a, vi b);
	vi HP_BitXor(vi a, vi b);
	vi HP_BitNot(vi a);

	class HP{
		private:
			vi num;//高精度数,千进制 high-precision number, thousand-based

		public:
    		/*
            变量命名规则:
            	以变量x为例。
            	若名称形如x,说明x是一个vi
            	若名称形如xi,说明xi是一个int或ll
            	若名称形如xbi,说明xbi是一个HP
			*/
			/*
			Variable naming rules:
				Take variable x as an example:
				If named x, it is a vi;
				if xi, it is an int or ll;
				if xbi, it is an HP.
   			*/

			//构造函数 Constructors
			HP(){
				num.clear(); num.push_back(0);
				if(FirstInit){
					FirstInit = 0;
					init();
				}
			}
			HP(int xi){
				if(!xi){
					num.push_back(1);
					num.push_back(0);
					return;
				}
				char z = intTOsign(xi);
				xi = abs(xi);
				vi temp(1, 0);
				while(xi){
					temp.push_back(xi%10);
					xi /= 10;
				}
				int len = temp.size()-1;
				temp[0] = signTOint(z)*len;
				num = HP_zip(temp);
				if(FirstInit){
					FirstInit = 0;
					init();
				}
			}
			HP(ll xi){
				if(!xi){
					num.push_back(1);
					num.push_back(0);
					return;
				}
				char z = llTOsign(xi);
				xi = xi>0 ? xi : -xi;
				vi temp(1, 0);
				while(xi){
					temp.push_back(xi%10);
					xi /= 10;
				}
				int len = temp.size()-1;
				temp[0] = signTOint(z)*len;
				num = HP_zip(temp);
				if(FirstInit){
					FirstInit = 0;
					init();
				}
			}
			HP(vi &v){
				num = v;
				if(FirstInit){
					FirstInit = 0;
					init();
				}
			}
			HP(str s){
				num.clear(), num.push_back(0);
				int n = 0, f=1;
				for(auto ch : s){
					if(IsDigit(ch)){
						n++;
						num.push_back(ch-48);
					}else if(IsSign(ch)){
						if(!n) f = -1;
						else{
							n = -1;
							break;
						}
					}else{
						n = -1;
						break;
					}
				}
				if(n > 0){
					num[0] = n*f;
					HP_reverse(num);
					num = HP_zip(num);
				}else num = EMPTY;
				if(FirstInit){
					FirstInit = 0;
					init();
				}
			}
			HP(const char *p){
				num.clear(), num.push_back(0);
				int n = 0, f = 1;
				char ch;
				for(; (ch=*p); p++){
					if(IsDigit(ch)){
						n++;
						num.push_back(ch-48);
					}else if(IsSign(ch)){
						if(!n) f = -1;
						else{
							n = -1;
							break;
						}
					}else{
						n = -1;
						break;
					}
				}
				if(n > 0){
					num[0] = n*f;
					HP_reverse(num);
					num = HP_zip(num);
				}else num = EMPTY;
				if(FirstInit){
					FirstInit = 0;
					init();
				}
			}

			//析构函数 Destructor
			~HP() {num.clear(); num.shrink_to_fit();}

			bool isEMPTY() const {return num[0] == 0;}
			//是否为错误值 Checks if it is the empty (error) value
    		void clear() {num.clear(), num.push_back(0);}//清空 clear
			int length() const {
				int n = abs(num[0]), ret = n*3;
				if(n == 0) return 0;
				if(num[n] < 100) ret--;
				if(num[n] < 10) ret--;
				return ret;
			}
			int size() const {
				int n = abs(num[0]), ret = n*3;
				if(n == 0) return 0;
				if(num[n] < 100) ret--;
				if(num[n] < 10) ret--;
				return ret;
			}
			int sign() const {
				if(num[0] > 0) return 1;
				else if(num[0] < 0) return -1;
				else return 0;
			}
			int GetDigit(int p) const {
				int n = abs(num[0]);
				if(n == 0) return 0;
				if(p>n*3 || p<1) return 0;//越界 out of range
				int x = p/3, y = p%3;
				if(y == 0) return num[x]/100;
				else if(y == 1) return num[x+1]%10;
				else return num[x+1]/10%10;
			}
			int AppendZero(int m){
				if(m<1) return 1;
				if(size()+m>1e8) return 1;
				int n = abs(num[0]), i;
				if(n == 0) return 1;
				int x = m/3, y = m%3;
				num.resize(n+x+5);
				for(i=1; i<=n; i++) num[i+x] = num[i], num[i] = 0;
				n += x;
				num[0] = intTOone(num[0])*n;
				if(y) num = HP_Multiply(num, HP_Power(TEN, y));
				return 0;
			}
			int RemoveTail(int m){
				if(m < 1) return 1;
				int n = abs(num[0]), i;
				if(n == 0) return 1;
				int x = m/3, y = m%3;
				if(n <= x) num = ZERO;
				else{
					for(i=1; i<=n-x; i++) num[i] = num[i+x];
					for(i=n; i>n-x; i--) num[i] = 0;
					n -= x;
					num[0] = intTOone(num[0])*n;
					if(y) num = HP_Divide(num, HP_Power(TEN, y));
				}
				return 0;
			}

			//重载运算符 Overloaded operator
			HP operator + (const HP &bbi) const {
				vi a = this->num, b = bbi.num;
				if(!a[0] || !b[0]) return HP(EMPTY);
				vi c = HP_Plus(a, b);
				return HP(c);
			}
			HP operator + (const int bi) const {
				return *this + HP(bi);
			}
			HP operator + (const ll bi) const {
				return *this + HP(bi);
			}
			friend HP operator + (const int ai, const HP &bbi){
				return HP(ai) + bbi;
			}
			friend HP operator + (const ll ai, const HP &bbi){
				return HP(ai) + bbi;
			}

			HP operator - (const HP &bbi) const {
				vi a = this->num, b = bbi.num;
				if(!a[0] || !b[0]) return HP(EMPTY);
				vi c = HP_Minus(a, b);
				return HP(c);
			}
			HP operator - (const int bi) const {
				return *this - HP(bi);
			}
			HP operator - (const ll bi) const {
				return *this - HP(bi);
			}
			friend HP operator - (const int ai, const HP &bbi){
				return HP(ai) - bbi;
			}
			friend HP operator - (const ll ai, const HP &bbi){
				return HP(ai) - bbi;
			}
			friend HP operator - (const HP &bbi){
				vi b = bbi.num;
				b[0] = -b[0];
				return HP(b);
			}

			HP operator * (const HP &bbi) const {
				vi a = this->num, b = bbi.num;
				if(!a[0] || !b[0]) return HP(EMPTY);
				vi c = HP_Multiply(a, b);
				return HP(c);
			}
			HP operator * (const int bi) const {
				return *this * HP(bi);
			}
			HP operator * (const ll bi) const {
				return *this * HP(bi);
			}
			friend HP operator * (const int ai, const HP &bbi){
				return HP(ai) * bbi;
			}
			friend HP operator * (const ll ai, const HP &bbi){
				return HP(ai) * bbi;
			}

			HP operator / (const HP &bbi) const {
				vi a = this->num, b = bbi.num;
				if(!a[0] || !b[0]) return HP(EMPTY);
				if(HP_IsZERO(b)) return HP(EMPTY);
				//除以0,错误 Division by zero, Error
				else{
					vi c = HP_Divide(a, b);
					return HP(c);
				}
			}
			HP operator / (const int bi) const {
				return *this / HP(bi);
			}
			HP operator / (const ll bi) const {
				return *this / HP(bi);
			}
			friend HP operator / (const int ai, const HP &bbi){
				return HP(ai) / bbi;
			}
			friend HP operator / (const ll ai, const HP &bbi){
				return HP(ai) / bbi;
			}

			HP operator % (const HP &bbi) const {
				vi a = this->num, b = bbi.num;
				if(!a[0] || !b[0]) return HP(EMPTY);
				if(HP_IsZERO(b)) return HP(EMPTY);
				//模0,错误 Module by zero, Error
				else{
					vi c = HP_Module(a, b);
					return HP(c);
				}
			}
			HP operator % (const int bi) const {
				return *this % HP(bi);
			}
			HP operator % (const ll bi) const {
				return *this % HP(bi);
			}
			friend HP operator % (const int ai, const HP &bbi){
				return HP(ai) % bbi;
			}
			friend HP operator % (const ll ai, const HP &bbi){
				return HP(ai) % bbi;
			}

			//乘方 power
			friend HP HP_pow(HP abi, HP bbi){
				vi a = abi.num, b = bbi.num;
				if(!a[0] || !b[0]) return HP(EMPTY);
				if(b[0] < 0) return HP(EMPTY);//负次幂 negative exponent(not supported)
				if(HP_IsZERO(a) && HP_IsZERO(b)) return HP(EMPTY);//0^0无意义 0^0 is undefined
				if(HP_IsZERO(b)) return HP(ONE);//a^0 = 1 (a!=0)
				if(HP_IsZERO(a)) return HP(ZERO);//0^b = 0 (b!=0)
				if(HP_IsONE(a)) return HP(ONE);//1^a = 1
				if(HP_IsM_ONE(a)) return (b[1]&1) ? HP(M_ONE) : HP(ONE);//-1^a
				if(abs(a[0])>1 || a[1]>1){
					if(b[0] > 5) return HP(EMPTY);
				}//结果过大 result considered too large
				vi c = HP_Power(a, HP_vecTOll(b));
				return HP(c);
			}
			friend HP HP_pow(HP abi, int bi){
				return HP_pow(abi, HP(bi));
			}
			friend HP HP_pow(HP abi, ll bi){
				return HP_pow(abi, HP(bi));
			}
			friend HP HP_pow(int ai, HP bbi){
				return HP_pow(HP(ai), bbi);
			}
			friend HP HP_pow(ll ai, HP bbi){
				return HP_pow(HP(ai), bbi);
			}

			HP operator << (const HP &bbi) const {
				if(this->num[0] == 0) return HP(EMPTY);
				if(bbi.num[0] <= 0) return HP(EMPTY);
				if(bbi > MAX_INT) return HP(EMPTY);
				vi a = this->num;
				int b = int(bbi);
				vi c = HP_LeftPush(a, b);
				return HP(c);
			}
			HP operator << (const int &bi) const {
				return *this << HP(bi);
			}
			HP operator << (const ll &bi) const {
				return *this << HP(bi);
			}
			friend HP operator << (const int ai, const HP bbi){
				return HP(ai) << bbi;
			}
			friend HP operator << (const ll ai, const HP bbi){
				return HP(ai) << bbi;
			}

			HP operator >> (const HP &bbi) const {
				if(this->num[0] == 0) return HP(EMPTY);
				if(bbi.num[0] <= 0) return HP(EMPTY);
				if(bbi > MAX_INT) return HP(EMPTY);
				vi a = this->num;
				int b = int(bbi);
				vi c = HP_RightPush(a, b);
				return HP(c);
			}
			HP operator >> (const int &bi) const {
				return *this >> HP(bi);
			}
			HP operator >> (const ll &bi) const {
				return *this >> HP(bi);
			}
			friend HP operator >> (const int &ai, const HP &bbi){
				return HP(ai) >> bbi;
			}
			friend HP operator >> (const ll &ai, const HP &bbi){
				return HP(ai) >> bbi;
			}

			HP operator & (const HP &bbi) const {
				vi a = this->num, b = bbi.num;
				if(!a[0] || !b[0]) return HP(EMPTY);
				vi c = HP_BitAnd(a, b);
				return HP(c);
			}
			HP operator & (const int &bi) const {
				return *this & HP(bi);
			}
			HP operator & (const ll &bi) const {
				return *this & HP(bi);
			}
			friend HP operator & (const int &ai, const HP &bbi){
				return HP(ai) & bbi;
			}
			friend HP operator & (const ll &ai, const HP &bbi){
				return HP(ai) & bbi;
			}

			HP operator | (const HP &bbi) const {
				vi a = this->num, b = bbi.num;
				if(!a[0] || !b[0]) return HP(EMPTY);
				vi c = HP_BitOr(a, b);
				return HP(c);
			}
			HP operator | (const int &bi) const {
				return *this | HP(bi);
			}
			HP operator | (const ll &bi) const {
				return *this | HP(bi);
			}
			friend HP operator | (int &ai, const HP &bbi){
				return HP(ai) | bbi;
			}
			friend HP operator | (ll &ai, const HP &bbi){
				return HP(ai) | bbi;
			}

			HP operator ^ (const HP &bbi) const {
				vi a = this->num, b = bbi.num;
				if(!a[0] || !b[0]) return HP(EMPTY);
				vi c = HP_BitXor(a, b);
				return HP(c);
			}
			HP operator ^ (const int &bi) const {
				return *this ^ HP(bi);
			}
			HP operator ^ (const ll &bi) const {
				return *this ^ HP(bi);
			}
			friend HP operator ^ (const int &ai, const HP &bbi){
				return HP(ai) ^ bbi;
			}
			friend HP operator ^ (const ll &ai, const HP &bbi){
				return HP(ai) ^ bbi;
			}

			friend HP operator ~ (const HP &abi){
				vi a = abi.num;
				if(!a[0]) return HP(EMPTY);
				vi b = HP_BitNot(a);
				return HP(b);
			}

			bool operator > (const HP &bbi) const {
				vi a = this->num, b = bbi.num;
				if(!a[0] || !b[0]) return false;
				int na = a[0], nb = b[0];
				//异号 different signs
				if(na>0 && nb<0) return true;
				if(na<0 && nb>0) return false;
				//同号 the same sign
				int f = intTOone(na), i;
				na = abs(na), nb = abs(nb);
				if(na > nb) return f>0 ? true : false;
				if(na < nb) return f>0 ? false : true;
				for(i=na; i; i--){
					if(a[i] > b[i]) return f>0 ? true : false;
					if(a[i] < b[i]) return f>0 ? false : true;
				}
				return false;//相等 equal
			}
			bool operator > (const int bi) const {
				return *this > HP(bi);
			}
			bool operator > (const ll bi) const {
				return *this > HP(bi);
			}
			friend bool operator > (const int ai, const HP &bbi){
				return HP(ai) > bbi;
			}
			friend bool operator > (const ll ai, const HP &bbi){
				return HP(ai) > bbi;
			}

			bool operator >= (const HP &bbi) const {
				vi a = this->num, b = bbi.num;
				if(!a[0] || !b[0]) return false;
				int na = a[0], nb = b[0];
				if(na>0 && nb<0) return true;
				if(na<0 && nb>0) return false;
				int f = intTOone(na), i;
				na = abs(na), nb = abs(nb);
				if(na > nb) return f>0 ? true : false;
				if(na < nb) return f>0 ? false : true;
				for(i=na; i; i--){
					if(a[i] > b[i]) return f>0 ? true : false;
					if(a[i] < b[i]) return f>0 ? false : true;
				}
				return true;//相等 equal
			}
			bool operator >= (const int bi) const {
				return *this >= HP(bi);
			}
			bool operator >= (const ll bi) const {
				return *this >= HP(bi);
			}
			friend bool operator >= (const int ai, const HP &bbi){
				return HP(ai) >= bbi;
			}
			friend bool operator >= (const ll ai, const HP &bbi){
				return HP(ai) >= bbi;
			}

			bool operator < (const HP &bbi) const {
				vi a = this->num, b = bbi.num;
				if(!a[0] || !b[0]) return false;
				int na = a[0], nb = b[0];
				if(na>0 && nb<0) return false;
				if(na<0 && nb>0) return true;
				int f = intTOone(na), i;
				na = abs(na), nb = abs(nb);
				if(na > nb) return f>0 ? false : true;
				if(na < nb) return f>0 ? true : false;
				for(i=na; i; i--){
					if(a[i] > b[i]) return f>0 ? false : true;
					if(a[i] < b[i]) return f>0 ? true : false;
				}
				return false;//相等 equal
			}
			bool operator < (const int bi) const {
				return *this < HP(bi);
			}
			bool operator < (const ll bi) const {
				return *this < HP(bi);
			}
			friend bool operator < (const int ai, const HP &bbi){
				return HP(ai) < bbi;
			}
			friend bool operator < (const ll ai, const HP &bbi){
				return HP(ai) < bbi;
			}

			bool operator <= (const HP &bbi) const {
				vi a = this->num, b = bbi.num;
				if(!a[0] || !b[0]) return false;
				int na = a[0], nb = b[0];
				if(na>0 && nb<0) return false;
				if(na<0 && nb>0) return true;
				int f = intTOone(na), i;
				na = abs(na), nb = abs(nb);
				if(na > nb) return f>0 ? false : true;
				if(na < nb) return f>0 ? true : false;
				for(i=na; i; i--){
					if(a[i] > b[i]) return f>0 ? false : true;
					if(a[i] < b[i]) return f>0 ? true : false;
				}
				return true;//相等 equal
			}
			bool operator <= (const int bi) const {
				return *this <= HP(bi);
			}
			bool operator <= (const ll bi) const {
				return *this <= HP(bi);
			}
			friend bool operator <= (const int ai, const HP &bbi){
				return HP(ai) <= bbi;
			}
			friend bool operator <= (const ll ai, const HP &bbi){
				return HP(ai) <= bbi;
			}

			bool operator == (const HP &bbi) const {
				vi a = this->num, b = bbi.num;
				if(!a[0] || !b[0]) return false;
				if(a[0] != b[0]) return false;
				int n = abs(a[0]), i;
				for(i=n; i; i--){
					if(a[i] != b[i]) return false;
				}
				return true;
			}
			bool operator == (const int bi) const {
				return *this == HP(bi);
			}
			bool operator == (const ll bi) const {
				return *this == HP(bi);
			}
			friend bool operator == (const int ai, const HP &bbi){
				return HP(ai) == bbi;
			}
			friend bool operator == (const ll ai, const HP &bbi){
				return HP(ai) == bbi;
			}

			bool operator != (const HP &bbi) const {
				vi a = this->num, b = bbi.num;
				if(!a[0] || !b[0]) return false;
				if(a[0] != b[0]) return true;
				int n=abs(a[0]), i;
				for(i=n; i; i--){
					if(a[i] != b[i]) return true;
				}
				return false;
			}
			bool operator != (const int bi) const {
				return *this != HP(bi);
			}
			bool operator != (const ll bi) const {
				return *this != HP(bi);
			}
			friend bool operator != (const int ai, const HP &bbi){
				return HP(ai) != bbi;
			}
			friend bool operator != (const ll ai, const HP &bbi){
				return HP(ai) != bbi;
			}

			operator int() const {
				if(*this>MAX_INT || *this<MIN_INT) return 0;
				vi b = HP_unzip(this->num);
				if(!b[0]) return 0;
				int ai = 0, na = abs(b[0]), f = intTOone(b[0]), i;
				for(i=na; i; i--) ai = ai*10+b[i];
				ai = ai*f;
				return ai;
			}
			operator ll() const {
				if(*this>MAX_LL || *this<MIN_LL) return 0;
				vi b = HP_unzip(this->num);
				if(!b[0]) return 0;
				ll ai = 0, na = abs(b[0]), f = intTOone(b[0]), i;
				for(i=na; i; i--) ai = ai*10+b[i];
				ai = ai*f;
				return ai;
			}

			HP operator += (const HP &bbi){
				*this = *this + bbi;
				return *this;
			}
			HP operator += (const int bi){
				*this = *this + HP(bi);
				return *this;
			}
			HP operator += (const ll bi){
				*this = *this + HP(bi);
				return *this;
			}

			HP operator -= (const HP &bbi){
				*this = *this - bbi;
				return *this;
			}
			HP operator -= (const int bi){
				*this = *this - HP(bi);
				return *this;
			}
			HP operator -= (const ll bi){
				*this = *this - HP(bi);
				return *this;
			}

			HP operator *= (const HP &bbi){
				*this = *this * bbi;
				return *this;
			}
			HP operator *= (const int bi){
				*this = *this * HP(bi);
				return *this;
			}
			HP operator *= (const ll bi){
				*this = *this * HP(bi);
				return *this;
			}

			HP operator /= (const HP &bbi){
				*this = *this / bbi;
				return *this;
			}
			HP operator /= (const int bi){
				*this = *this / HP(bi);
				return *this;
			}
			HP operator /= (const ll bi){
				*this = *this / HP(bi);
				return *this;
			}

			HP operator %= (const HP &bbi){
				*this = *this % bbi;
				return *this;
			}
			HP operator %= (const int bi){
				*this = *this % HP(bi);
				return *this;
			}
			HP operator %= (const ll bi){
				*this = *this % HP(bi);
				return *this;
			}

			HP operator >>= (const HP &bbi){
				*this = *this >> bbi;
				return *this;
			}
			HP operator >>= (const int bi){
				*this = *this >> HP(bi);
				return *this;
			}
			HP operator >>= (const ll bi){
				*this = *this >> HP(bi);
				return *this;
			}

			HP operator <<= (const HP &bbi){
				*this = *this << bbi;
				return *this;
			}
			HP operator <<= (const int bi){
				*this = *this << HP(bi);
				return *this;
			}
			HP operator <<= (const ll bi){
				*this = *this << HP(bi);
				return *this;
			}

			HP operator &= (const HP &bbi){
				*this = *this & bbi;
				return *this;
			}
			HP operator &= (const int &bi){
				*this = *this & HP(bi);
				return *this;
			}
			HP operator &= (const ll &bi){
				*this = *this & HP(bi);
				return *this;
			}

			HP operator |= (const HP &bbi){
				*this = *this | bbi;
				return *this;
			}
			HP operator |= (const int &bi){
				*this = *this | HP(bi);
				return *this;
			}
			HP operator |= (const ll &bi){
				*this = *this | HP(bi);
				return *this;
			}
			HP operator ^= (const HP &bbi){
				*this = *this ^ bbi;
				return *this;
			}
			HP operator ^= (const int &bi){
				*this = *this ^ HP(bi);
				return *this;
			}
			HP operator ^= (const ll &bi){
				*this = *this ^ HP(bi);
				return *this;
			}

			HP operator ++ (){
				*this = *this + HP(1);
				return *this;
			}
			HP operator ++ (int flag){
				HP temp = *this;
				*this = *this + HP(1);
				return temp;
			}

			HP operator -- (){
				*this = *this - HP(1);
				return *this;
			}
			HP operator -- (int flag){
				HP temp = *this;
				*this = *this - HP(1);
				return temp;
			}

			//输入重载运算符 Overloaded input operator
			friend std::istream& operator>> (std::istream &is, HP &cbi){
				vi a(1, 0);//空值,初始值 EMPTY, the original value
				int na = 0;//数长度 length of the number
				char za = 0;//符号 sign(+/-)
				char t;//临时字符 temporary character
				while(is.get(t)){
					if(t<=32 && na) break;
					// 读完之后不可见字符 invisible characters after reading in
					if(t == '\n'){//遇到换行符(ASCII < 20) line break (ASCII < 20)
						if(na) break;
						//已经有数字,输入结束 there have been digits, input ends
						else continue;//还没有数字,继续输入
						//there haven't been digits, continue to input
					}
					if(!is || t==EOF) break;// 输入结束 end of input
					if(IsSign(t)){// 是正负号   the character is a sign
						if(na) break;// 已经开始输入数字了 have started to read in digits
						else if(za) break;// 已经有符号了 have a symbol already
						else za = t;
					}else if(IsOpe(t)) break;// 是其他运算符 other calculation characters
					else if(IsDigit(t)){
						a.push_back(t-48);
						na++;
					}//读入数字 read in digits
					else break;//其他字符 other characters
				}
				if(t >= 32) is.putback(t);
				if(!za) za = '+';
				a[0] = na*signTOint(za);
				if(!a[0]) cbi.num = EMPTY;
				else{
					HP_reverse(a);
					cbi.num = HP_zip(a);
				}
				return is;
			}
			//输出重载运算符 Overloaded output operator
			friend std::ostream& operator<< (std::ostream &os, const HP cbi){
				vi c = HP_unzip(cbi.num);
				if(HP_IsZERO(c)) c[0] = 1;
				if(!c[0]) return os;
				int nc = abs(c[0]);
				os << (c[0]<0 ? "-" : "");
				for(; nc; nc--) os << c[nc];
				return os;
			}

			friend int putHP(HP cbi);
	};

	//从我的GreatCalculator搬来的高精度计算函数
	//High-precision functions adapted from my GreatCalculator
	vi HP_Plus(vi a, vi b){
	    char za=intTOsign(a[0]), zb=intTOsign(b[0]), zc;
	    int na=abs(a[0]), nb=abs(b[0]);
		if(!na || !nb) return EMPTY;
		if(za=='+' && zb=='-'){
			a[0] = abs(a[0]), b[0]=abs(b[0]);
			return HP_Minus(a, b);
		}//a+(-b)=a-b
		else if(za=='-' && zb=='+'){
			VecSwap(a, b);
			a[0] = abs(a[0]), b[0]=abs(b[0]);
			return HP_Minus(a, b);
		}//(-a)+b=b-a
	    else{
			if(za=='-' && zb=='-') zc = '-';//(-a)+(-b)=-(a+b)
			else zc = '+';
			int nc = max(na, nb); vi c(1, 0);
			AllResize(nc+5, a, b, c);
			for(int i=1; i<=nc; i++){
				c[i] += a[i]+b[i];
				c[i+1] += c[i]/JW, c[i] %= JW;
			}
			if(c[nc+1]) nc++;
			c[0] = nc*signTOint(zc);
			if(HP_NumCheck(c)) c = EMPTY;
			return c;
		}
	}
	vi HP_Minus(vi a, vi b){
	    char za=intTOsign(a[0]), zb=intTOsign(b[0]);
	    if(za=='+' && zb=='-'){
	        a[0] = abs(a[0]), b[0]=abs(b[0]);
	        return HP_Plus(a, b);
	    }//a-(-b)=a+b
	    else if(za=='-' && zb=='+'){
	        a[0]=-abs(a[0]), b[0]=-abs(b[0]);
	        return HP_Plus(a, b);
	    }//-a-b = (-a)+(-b)
	    else{
	        //a-b = a-b
	        if(za=='-' && zb=='-'){
	            VecSwap(a, b);//(-a)-(-b) = b-a
	            a[0] = -a[0], b[0]=-b[0];
	        }
	        char zc = '+';
	        if(HP_VecCmp(a, b) < 0){
	            zc = PosiNega(zc);
	            VecSwap(a, b);
	        }
	        int na=abs(a[0]), nb=abs(b[0]), i;
			if(!na || !nb) return EMPTY;
	        a.resize(na+5), b.resize(na+5);
	        for(i=1; i<=na; i++){
	            a[i] -= b[i];
	            if(a[i] < 0) a[i]+=JW, a[i+1]--;
	        }
	        a[0] = na*signTOint(zc);
	        HP_PopFrontZero(a);
			if(HP_NumCheck(a)) a = EMPTY;
	        return a;
	    }
	}
	vi HP_Karatsuba(int n, vi a, vi b){
	    int i, j;
	    vi c(n+n+5, 0);
	    if(n < KAR_LIMIT){
	        for(i=1; i<=n; i++)
	            for(j=1; j<=n; j++)
	                c[i+j-1] += a[i]*b[j];
	        return c;
	    }

	    int m = n>>1;
	    vi aa(n-m+5, 0), bb(n-m+5, 0);
	    for(i=1; i<=n-m; i++){
	        aa[i] = a[m+i];
	        bb[i] = b[m+i];
	    }
	    vi z2 = HP_Karatsuba(n-m, aa, bb);
	    vi z0 = HP_Karatsuba(m, a, b);
	    vi as(n-m+5, 0), bs(n-m+5, 0);
	    for(i=1; i<=n-m; i++){
	        as[i] = a[i+m];
	        bs[i] = b[i+m];
	        if(i <= m) {
	            as[i] += a[i];
	            bs[i] += b[i];
	        }
	    }
	    vi z1 = HP_Karatsuba(n-m, as, bs);

	    for(i=1; i<=((n-m)<<1); i++){
	        z1[i] -= z2[i];
	        z1[i] -= z0[i];
	    }
	    //c = z2*JW^2m + z1*JW^m + z0
	    for(i=1; i<=((n-m)<<1); i++) c[i+m+m] += z2[i];
	    for(i=1; i<=((n-m)<<1); i++) c[i+m] += z1[i];
	    for(i=1; i<=(m<<1); i++) c[i] += z0[i];
	    return c;
	}
	vi HP_SimMul(vi a, vi b){
	    char za=intTOsign(a[0]), zb=intTOsign(b[0]);
	    char zc = signOFmul(za, zb);
	    int na=abs(a[0]), nb=abs(b[0]);
	    int nc = na+nb, i, j;
	    a.resize(nc+1, 0);
	    b.resize(nc+1, 0);
	    vi c(nc+5, 0);
	    for(i=1; i<=na; i++)
	        for(j=1; j<=nb; j++)
	            c[i+j-1] += a[i]*b[j];
	    for(j=1; j<=nc; j++) c[j+1] += c[j]/JW, c[j] %= JW;
	    while(c[nc+1]) nc++;
	    c[0] = nc*signTOint(zc);
	    HP_PopFrontZero(c);
		if(HP_NumCheck(c)) c = EMPTY;
	    return c;
	}
	vi HP_Multiply(vi a, vi b){
	    char za=intTOsign(a[0]), zb=intTOsign(b[0]);
	    char zc = signOFmul(za, zb);
	    int na=abs(a[0]), nb=abs(b[0]);
		if(!na || !nb) return EMPTY;
	    int nc = na+nb;
	    a.resize(nc+1, 0);
	    b.resize(nc+1, 0);
	    if(na<KAR_LIMIT || nb<KAR_LIMIT) return HP_SimMul(a, b);
	    if(na<sqrt(nb) || nb<sqrt(na)) return HP_SimMul(a, b);
	    vi c = HP_Karatsuba(nc, a, b);
	    int limit = c.size()-1;
	    for(int i=1; i<limit; i++){
	        c[i+1] += c[i]/JW, c[i] %= JW;
	        if(c[i] < 0) c[i] += JW, c[i+1]--;
	    }
	    nc = limit;
	    while(nc>1 && !c[nc]) nc--;
	    c.resize(nc + 1);
	    c[0] = nc*signTOint(zc);
		if(HP_NumCheck(c)) c = EMPTY;
	    return c;
	}//感谢星星老师和Gemini帮忙调试乘法算法!
	 //Thanks to Teacher Stars and Gemini for helping debug the multiplication algorithm!
	char HP_DivCmp(int r, int n, vi &a, vi &b){
	    if(a[r+n] > 0) return true;
	    if(a[r+n] < 0) return false;
	    for(int i=n; i>0; i--){
	        if(a[r+i-1] > b[i]) return true;
	        if(a[r+i-1] < b[i]) return false;
	    }
	    return true;
	}
	vi HP_Divide(vi a, vi b){
	    char za=intTOsign(a[0]), zb=intTOsign(b[0]);
	    char zc = signOFmul(za, zb);
	    int na=abs(a[0]), nb=abs(b[0]);
		if(!na || !nb) return EMPTY;
		if(na < nb) return ZERO;
	    int nc = na-nb+5;
		vi c(1, 0);
	    AllResize(nc+5, a, b, c);
	    int i, j;
	    for(i=na-nb+1; i>0; i--){
	        while(HP_DivCmp(i, nb, a, b)){
	            for(j=1; j<=nb; j++){
	                a[i+j-1] -= b[j];
	                if(a[i+j-1] < 0) a[i+j-1]+=JW, a[i+j]--;
	            }
	            c[i]++;
	        }
	    }
	    c[0] = nc*signTOint(zc);
	    HP_PopFrontZero(c);
		if(HP_NumCheck(c)) c = EMPTY;
	    return c;
	}
	vi HP_Power(vi a, ll b){
	    vi c = ONE;
		while(b){
			if(b & 1) c = HP_Multiply(c, a), b--;
			else a = HP_Multiply(a, a), b >>= 1;
		}
		if(HP_NumCheck(c)) c = EMPTY;
		return c;
	}
	vi HP_Module(vi a, vi b){
	    int na=abs(a[0]), nb=abs(b[0]);
		if(!na || !nb) return EMPTY;
		if(na < nb) return a;
	    int nc = na-nb+5;
	    a.resize(nc+5), b.resize(nc+5);
	    int i, j;
	    for(i=na-nb+1; i>0; i--){
	        while(HP_DivCmp(i, nb, a, b)){
	            for(j=1; j<=nb; j++){
	                a[i+j-1] -= b[j];
	                if(a[i+j-1] < 0) a[i+j-1]+=JW, a[i+j]--;
	            }
	        }
	    }
	    HP_PopFrontZero(a);
		if(HP_NumCheck(a)) a = EMPTY;
	    return a;
	}

	HP HP_pow(int ai, int bi){
		return HP_pow(HP(ai), HP(bi));
	}
	HP HP_pow(int ai, ll bi){
		return HP_pow(HP(ai), HP(bi));
	}
	HP HP_pow(ll ai, int bi){
		return HP_pow(HP(ai), HP(bi));
	}
	HP HP_pow(ll ai, ll bi){
		return HP_pow(HP(ai), HP(bi));
	}

	vi HP_ThouToBit(vi a){
		//千进制转为1024进制补码
		vi b(1, 0);
		int nb = 1;//符号位占1位
		if(HP_IsZERO(a)) a[0] = abs(a[0]);
		int sign = intTOone(a[0]);
		a[0] = abs(a[0]);
		while(!HP_IsZERO(a)){
			b.push_back(HP_vecTOll(HP_Module(a, BI)));
			nb++;
			a = HP_Divide(a, BI);
		}
		if(sign > 0) b.push_back(0);
		else b.push_back(1);
		if(sign < 0){//取补码
			int i;
			for(i=1; i<=nb; i++) b[i] = BIT_JW-1-b[i];
			b.push_back(0);//多一位进位
			b[1]++;
			for(i=1; i<=nb; i++){
				b[i+1] += b[i]>>10;
				b[i] &= BIT_JW-1;
			}
			if(b[nb+1]) nb++;
		}
		b[0] = nb;
		return b;
	}
	vi HP_BitToThou(vi a){
		int na = a[0];
		int sign = a[na] ? -1 : 1;
		if(sign == -1){//负数
			sign = -1;
			a[1]--;
			int i;
			for(i=1; i<=na; i++){
				if(a[i] < 0){
					a[i] += BIT_JW;
					a[i+1]--;
				}
			}
			while(na>1 && !a[na]) na--;
			for(i=1; i<=na; i++) a[i] = BIT_JW-1-a[i];
		}
		na--;//去掉符号位
		vi b(2, 0);
		b[0] = 1;
		for(; na; na--){
			b = HP_Plus(HP_Multiply(b, BI), HP_intTOvec(a[na]));
		}
		b[0] *= sign;
		HP_PopFrontZero(b);
		return b;
	}
	vi HP_LeftPush(vi a, int b){
		if(b == 0) return a;
		a = HP_ThouToBit(a);
		int na = a[0], t = b/10, i;
		if(!na) return EMPTY;
		b %= 10;
		for(i=a[0]; i; i--) a[i+t] = a[i];
		for(i=1; i<=t; i++) a[i] = 0;
		a[0] = na+t;
		a = HP_BitToThou(a);
		if(b) a = HP_Multiply(a, HP_Power(TWO, b));
		if(HP_NumCheck(a)) a = EMPTY;
		return a;
	}
	vi HP_RightPush(vi a, int b){
		if(b == 0) return a;
		a = HP_ThouToBit(a);
		int na = a[0], t = b/10, i;
		if(!na) return EMPTY;
		int sign = a[na];
		b %= 10;
		na -= t;
		if(na < 1) return sign ? M_ONE : ZERO;
		for(i=1; i<=na; i++) a[i] = a[i+t];
		for(; i<=a[0]; i++) a[i] = sign ? 1023 : 0;
		a[0] = na;
		a = HP_BitToThou(a);
		if(b) a = HP_Divide(a, HP_Power(TWO, b));
		if(HP_NumCheck(a)) a = EMPTY;
		return a;
	}
	vi HP_BitAnd(vi a, vi b){
		int na = abs(a[0]), nb = abs(b[0]);
		if(!na || !nb) return EMPTY;
		int nc = max(na, nb), i;
		vi c(1, 0);
		AllResize(nc+5, a, b, c);
		a = HP_ThouToBit(a);
		b = HP_ThouToBit(b);
		na = a[0], nb = b[0], c[0] = nc = max(na, nb);
		for(i=1; i<=nc; i++) c[i] = a[i]&b[i];
		c = HP_BitToThou(c);
		if(HP_NumCheck(c)) c = EMPTY;
		return c;
	}
	vi HP_BitOr(vi a, vi b){
		int na = abs(a[0]), nb = abs(b[0]);
		if(!na || !nb) return EMPTY;
		int nc = max(na, nb), i;
		vi c(1, 0);
		AllResize(nc+5, a, b, c);
		a = HP_ThouToBit(a);
		b = HP_ThouToBit(b);
		na = a[0], nb = b[0], c[0] = nc = max(na, nb);
		for(i=1; i<=nc; i++) c[i] = a[i]|b[i];
		c = HP_BitToThou(c);
		if(HP_NumCheck(c)) c = EMPTY;
		return c;
	}
	vi HP_BitXor(vi a, vi b){
		int na = abs(a[0]), nb = abs(b[0]);
		if(!na || !nb) return EMPTY;
		int nc = max(na, nb), i;
		vi c(1, 0);
		AllResize(nc+5, a, b, c);
		a = HP_ThouToBit(a);
		b = HP_ThouToBit(b);
		na = a[0], nb = b[0],c[0] = nc = max(na, nb);
		for(i=1; i<=nc; i++) c[i] = a[i]^b[i];
		c = HP_BitToThou(c);
		if(HP_NumCheck(c)) c = EMPTY;
		return c;
	}
	vi HP_BitNot(vi a){
		a = HP_ThouToBit(a);
		int na = a[0], i;
		if(!na) return EMPTY;
		for(i=1; i<=na; i++) a[i] = a[i]^(BIT_JW-1);
		a = HP_BitToThou(a);
		if(HP_NumCheck(a)) a = EMPTY;
		return a;
	}

	HP getHP(){
		vi a(1, 0);
		int na = 0;// 长度 length
		char za = 0, t;// +-
		while((t = getchar())){
			if(t<=32 && na) break;
			// 读完之后不可见字符 invisible characters after reading in
			if(t == '\n'){//遇到换行符(ASCII < 20) line break (ASCII < 20)
				if(na) break;//已经有数字,输入结束 there have been digits, input ends
				else continue;//还没有数字,继续输入
				//there haven't been digits, continue to input
			}
			if(t == EOF) break;// 输入结束 end of input
			if(IsSign(t)){// 是正负号   the character is a sign
				if(na) break;// 已经开始输入数字了 have started to read in digits
				else if(za) break;// 已经有符号了 have a symbol already
				else za = t;
			}else if(IsOpe(t)) break;// 是其他运算符 other calculation characters
			else if(IsDigit(t)){
				a.push_back(t-48);
				na++;
			}//读入数字 read in digits
			else break;//其他字符 other characters
		}
		if(!za) za = '+';
		a[0] = na*signTOint(za);
		if(!a[0]) return HP(EMPTY);
		HP_reverse(a);
		a = HP_zip(a);
		return HP(a);
	}
	int putHP(HP cbi){
		vi c = HP_unzip(cbi.num);
		if(HP_IsZERO(c)) c[0] = 1;
		char zc = intTOsign(c[0]);
		if(zc == '-') putchar('-');
		int nc = abs(c[0]);
		if(!nc) return 1;//EMPTY
		for(; nc; nc--) putchar(c[nc]+48);
		putchar('\n');
		return 0;//无错误 nothing is wrong
	}
}

#endif
