

class Solution {
public:
// brute force -> fails , if matrix already has -1, look at the constraints ,ask GPT, very high time complexity
 //   void row(int row , vector<vector<int>>&matrix ){
//  for(int j = 0 ; j < matrix[0].size() ; j++){
//     if(matrix[row][j] != 0 && matrix[row][j] != -1) matrix[row][j] = -1;
//  }
// }
// void column(int col , vector<vector<int>>& matrix ){
//  for(int i = 0 ; i < matrix.size() ; i++){
//     if(matrix[i][col] !=0 && matrix[i][col] != -1) matrix[i][col] = -1;
//  }
// }

    // void setZeroes(vector<vector<int>>& matrix) {
//         for( int i = 0 ; i < matrix.size() ; i++){
//             for(int j = 0 ; j < matrix[0].size() ; j++){
//                 if(matrix[i][j] == 0) 
//                 {
//                  row(i , matrix );
//                  column(j , matrix );
//                 }
//             }
//         }

//       for( int i = 0 ; i < matrix.size() ; i++){
//             for(int j = 0 ; j <matrix[0].size() ; j++){
//                 if(matrix[i][j] == -1) matrix[i][j] = 0;
//             }
//       }



// better solution->
void setZeroes(vector<vector<int>>& matrix) {
vector<int>rows(matrix.size() , 0);
vector<int>cols(matrix[0].size() , 0);


for(int i = 0 ; i <rows.size() ; i ++){
    for(int j = 0 ; j < cols.size() ; j++){
        if(matrix[i][j] == 0 ) {
            rows[i] = 1;
            cols[j] = 1;
        }
    }
}

for(int i = 0 ; i <rows.size() ; i ++){
    for(int j = 0 ; j < cols.size() ; j++){
     if(rows[i] == 1 || cols[j] ==1) {matrix[i][j] = 0;}
 
    }
}

    }
};