class PrimeCalculator {

    int nth(int nth) {
        if(nth == 0){
            throw new IllegalArgumentException();
        }
        switch (nth) {
            case 1 -> {
                return 2;
            }
            case 2 -> {
                return 3;
            }
            case 3 -> {
                return 5;
            }
            case 4 -> {
                return 7;
            }
            case 5 -> {
                return 9;
            }
            default -> {
            }
        }

        int limit= nth * (int)(Math.log(nth) + Math.log(Math.log(nth))) + 3;
        int[] nbrArr= new int[limit];
        int count=0;

        for(int i=2; i<limit; ++i){
            if(nbrArr[i]==0){
                ++count;
                if(count==nth) return i;
                for(int j=i+i; j<limit; j+=i) nbrArr[j]=1;
            }
        }
        return 0;
    }
}
