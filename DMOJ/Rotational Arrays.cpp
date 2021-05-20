
1

2

3

4

5

6

7

8

9

10

11

12

13

14

15

16

17

18

19

20

21

22

23

24

25

26

27

28

29

30

31

32

33

34

35

36

37

38

39

40

41

42

43

44

45

46

47

48

49

50

51

52

53

54

55

56

57

58

	

#include<bits/stdc++.h>

#define ll long long 

using namespace std ; 

const int maxn = 1e5 + 5 ; 

ll a[maxn], n ; 

ll solve(int t){

	if(t == n) return 1e18 ; 

	ll ans = 0 ; 

	for(int i = 0 ; i < t ; i++){
		
		vector<int> v ; 

		for(int j = i ; j < n ; j+=t) v.push_back(a[j+1]) ;

		sort(v.begin(), v.end()) ; 

		ll med = v[(v.size()+1)/2 - 1] ;

		for(int j = i ; j < n ; j+=t){
			ans += 1LL*abs(a[j+1] - med) ; 
		} 

	}

	return ans ;

}

int main(){

	cin >> n ; 
	
	for(int i = 1 ; i <= n ; i++) cin >> a[i] ; 

	if(n == 1){
		cout << "0\n" ; 
		return 0 ; 
	}

	ll resp = 1e18 ; 

	for(int i = 1 ; i * i <= n ; i++){
		if(n%i) continue ; 
		resp = min(resp, solve(i)) ;
		resp = min(resp, solve(n/i)) ;
	}

	cout << resp << "\n" ; 

}
