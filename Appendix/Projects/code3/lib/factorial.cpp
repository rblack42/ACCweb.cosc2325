unsigned int factorial(unsigned int val) {
    return val <= 1 ? val : factorial(val-1)*val;
}

