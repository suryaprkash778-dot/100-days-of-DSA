int fib(int n){
    int l=1,r=1,fib;
    if(n==0)
        return 0;
    if(n ==1 || n ==2)
        return 1;
    for(int i=2;i<n;i++){
        fib = l+r;
        l=r;
        r=fib;
    }
    return fib;
}
