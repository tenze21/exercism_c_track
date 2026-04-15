import java.util.ArrayList;
import java.util.List;

class Matrix {
    List<int[]> matrix= new ArrayList<>();    
    Matrix(String matrixAsString) {
        int newLineIdx= matrixAsString.indexOf('\n');
        if(newLineIdx < 0){
            String[] arr= matrixAsString.split(" ");
            int[] temp= new int[arr.length];
            for(int i=0; i<arr.length; ++i){
                temp[i]= Integer.parseInt(arr[i]);
            }
            matrix.add(temp);
            return;
        }

        int rowLen=0;
        for(int col=0; col<matrixAsString.length() && matrixAsString.charAt(col)!='\n'; ++col){
            if(matrixAsString.charAt(col)!=' ') ++rowLen;
        }
        int[] tempArr= new int[rowLen];
        String[] newLineSplit= matrixAsString.split("\n");
        for(int i=0; i<newLineSplit.length; ++i){
            String[] spaceSplit= newLineSplit[i].split(" ");
            for(int j=0; j<spaceSplit.length; ++j){
                tempArr[j]= Integer.parseInt(spaceSplit[j]);
            }
            matrix.add(tempArr);
            tempArr= new int[rowLen];
        }
    }

    int[] getRow(int rowNumber) {
        return matrix.get(rowNumber - 1);
    }

    int[] getColumn(int columnNumber) {
        int[] col= new int[matrix.size()];
        for(int row=0; row<matrix.size(); ++row){
            col[row]= matrix.get(row)[columnNumber - 1];
        }
        return col;
    }
}
