struct F{

	long long num, den ; 

	bool operator < (F c) const{ return (num*c.den) < (den*c.num) ; }

} ;
