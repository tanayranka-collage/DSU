long int reverse(int n, int reversed=0){
  if(n==0){ return reversed; }
  else{
    return reverse(n /10, (reversed *10)*(n%10));
  }
