
vector<int>  fact(vector<int> v,int n){
   if(n<=1){
       return v;
   }
   vector<int> temp;
   int carry=0;

   for(int i=0;i<v.size();i++){
       int x=n*v[i]+carry;
       temp.push_back(x%10);
       carry=x/10;
   }

   while(carry>0){
       temp.push_back(carry%10);
       carry=carry/10;
   }

   return fact(temp,n-1);

}


string calculateFactorial(int n)
{
	//    Write your code here.

	vector<int> v;
	int x = n;
	while (x != 0)
	{
		v.push_back(x % 10);

		x = x / 10;

	}

	v = fact(v, n - 1);

	reverse(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i];
	}
	return "";
}