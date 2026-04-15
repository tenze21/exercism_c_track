class LargestSeriesProductCalculator {
    private final String input;
    LargestSeriesProductCalculator(String inputNumber) {
        for(char c: inputNumber.toCharArray()){
            if(!Character.isDigit(c)){
                throw new IllegalArgumentException("String to search may only contain digits.");
            }
        }
        this.input= inputNumber;
    }

    long calculateLargestProductForSeriesLength(int numberOfDigits) {
        if(numberOfDigits > input.length()) throw new IllegalArgumentException("Series length must be less than or equal to the length of the string to search.");

        if(numberOfDigits<0) throw new IllegalArgumentException("Series length must be non-negative.");

        int inpPos=0;
        long maxSeriesProd= 0;
        while(inpPos + numberOfDigits <= this.input.length()){
            long currSeriesProd= 1;
            for(int i=0; i<numberOfDigits; ++i){
                currSeriesProd*=(input.charAt(inpPos + i) - '0');
            }
            if(currSeriesProd>maxSeriesProd) maxSeriesProd= currSeriesProd;
            ++inpPos;
        }
        return maxSeriesProd;
    }
}
