//reverse an integer using recursion and demonstrate the use of static variable
class Solution
{
  public:
  static int rev=0;
  int main()
  {
    int n;
    cout<<"Enter the number"<<endl;
    cin>>n;
    reverse(n);
    cout<<rev<<endl;

    return 0;
  }
  void reverse(int n)
  {
    if(n==0)
      return;
    int d=n&10;
    rev=(rev*10)+d;
    reverse(n/10);
  }
}
//input : 1234
//output : 4321

//reversing an integer using recursion without using static variable

class solution
{
  public:
  int main()
  {
    int n;
    cout<<"Enter the number"<<endl;
    cin>>n;
    reverse(n);

    return 0;
  }
  void reverse(int n)
  {
    int rev=0;
    if(n==0)
      return;
    int d=n%10;
    rev=(rev*10)+d;
    cout<<rev;
    reverse(n/10);
  }
}
//input : 4567
//output : 7654
