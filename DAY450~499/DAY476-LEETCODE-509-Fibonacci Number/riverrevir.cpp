int fib(int n) {
        if (n < 2) return n;
        
        int a = 0, b = 1;
        
        for (int i = 1; i <= n - 1; i++) { 
            int sum = a + b;
            a = b;
            b = sum;
        }
        
        return b;
    }
