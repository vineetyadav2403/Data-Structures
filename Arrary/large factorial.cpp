https://www.interviewbit.com/problems/large-factorial/

string Solution::solve(int A) {
    string solution = "1";
    int product;
    for(int i=2;i<=A;i++) {
        int carry=0;
        for(int j=solution.size()-1;j>=0;j--) {
            product = (i * (solution[j] - '0')) + carry;
            solution[j] = '0' + (product%10);
            carry = product/10;
        }
        if(carry!=0)
            solution = to_string(carry) + solution;
    }
    return solution;
}
