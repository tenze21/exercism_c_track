
class Matrix {
    private final int[][] rows; 
    private final int[][] cols;  
    Matrix(String matrixAsString) {
        String[] rowSplit= matrixAsString.split("\n");
        final int rowSize= rowSplit.length;
        final int colSize= rowSplit[0].split(" ").length;
        this.rows= new int[rowSize][colSize];
        this.cols= new int[colSize][rowSize];

        int rowPos=0;
        int colPos=0;
        for(String row: rowSplit){
            String[] colSplit= row.split(" ");
            for(String col: colSplit){
                rows[rowPos][colPos]= Integer.parseInt(col);
                cols[colPos][rowPos]= Integer.parseInt(col);
                ++colPos;
            }
            ++rowPos;
            colPos=0;
        }
        
    }

    int[] getRow(int rowNumber) {
        return this.rows[rowNumber - 1];
    }

    int[] getColumn(int columnNumber) {
        return this.cols[columnNumber - 1];
    }
}
