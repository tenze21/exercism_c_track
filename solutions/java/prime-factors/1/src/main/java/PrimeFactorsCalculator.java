import java.util.ArrayList;
import java.util.List;

class PrimeFactorsCalculator {

    List<Long> calculatePrimeFactorsOf(long number) {
        List<Long> pFactors= new ArrayList<>();
        long factor=2;
        while(number>1){
            if(number % factor == 0){
                pFactors.add(factor);
                number/=factor;
                continue;
            }
            ++factor;
        }
        return pFactors;
    }
}