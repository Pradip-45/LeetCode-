class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> arr(n , vector<int>(n));
        int minr = 0;
        int minc = 0;
        int maxr = n-1;
        int maxc = n-1;

        int value = 1;


        while(minr<=maxr && minc<=maxc){
            for(int j= minc; j<=maxc;j++){
           arr[minr][j] = value++;
        }
        minr++;

        if(minr>maxr || minc>maxc) break;

        for(int i=minr; i<=maxr; i++){
            arr[i][maxc] = value++;
        }
        maxc--;

        if(minr>maxr || minc>maxc) break;

        for(int j=maxc; j>=minc; j--){
            arr[maxr][j] = value++;
        }
        maxr--;

        if(minr>maxr || minc>maxc) break;

        for(int i=maxr; i>=minr; i--){
            arr[i][minc] = value++;
        }
        minc++;
        }
        return arr;
    }
};